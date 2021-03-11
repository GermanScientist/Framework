#include <myFramework/renderer.h>

//Constructor
Renderer::Renderer(unsigned int _width, unsigned int _height)
{
	//Assign values
	windowWidth = _width;
	windowHeight = _height;

	//Initialize the renderer
	this->initialize();
}

//Destructor
Renderer::~Renderer()
{
	
}

//Intialize renderer
int Renderer::initialize()
{
	//Initialise GLFW library
	if(!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW library \n");
		return -1;
	}

    //Set the window hints
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(windowWidth, windowHeight, "Demo", NULL, NULL);
	
    if(window == NULL) {
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}
	
    glfwMakeContextCurrent(window);

	//Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW library \n");
		return -1;
	}

	//Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	//Hide the mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Enable depth test
	glEnable(GL_DEPTH_TEST);
	
    //Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	//Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	return 0;
}

//Render the scene
void Renderer::renderScene(Scene* _scene) {

	//Clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Get viewmatrix from Camera (Camera position and direction)
	viewMatrix = _scene->getCamera()->getViewMatrix();
	projectionMatrix = _scene->getCamera()->getProjectionMatrix();

	//The first matrix is the identity matrix
	glm::mat4 modelMatrix = glm::mat4(1.0f);

	//Render the scene
	renderEntity(_scene, modelMatrix);

	// Swap buffers
	glfwSwapBuffers(window);
	glfwPollEvents();
}

//Render entity
void Renderer::renderEntity(Entity* _entity, glm::mat4 _modelMatrix) {

	//Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_entity->position.x, _entity->position.y, _entity->position.z));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_entity->rotation.x, _entity->rotation.y, _entity->rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_entity->scale.x, _entity->scale.y, _entity->scale.z));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	_modelMatrix *= modelMatrix;

	//Check wheter we need to render any models
	Model* model = _entity->getModel();

	if (model != nullptr) {
		//Render the Model
		this->renderModel(model, _modelMatrix);
	}

	//Check wheter we need to render any models
	Sprite* sprite = _entity->getSprite();

	if (sprite != nullptr) {
		
		//Render the Sprite
		this->renderSprite(sprite, _modelMatrix);
	}

	//Check wheter we need to render any cubes
	Cube* cube = _entity->getCube();

	if (cube != nullptr) {

		//Render the Sprite
		this->renderCube(cube, _modelMatrix);
	}

	//Render all children of this entity
	std::vector<Entity*> children = _entity->getChildren();
	
	for(Entity* c : children)
	{
		this->renderEntity(c, _modelMatrix);
	}
}

//Render a sprite
void Renderer::renderSprite(Sprite* _sprite, glm::mat4 _modelMatrix)
{
	glm::mat4 modelMatrix = _modelMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	//A pointer to the shader
	Shader* shader = _sprite->getMaterial()->getShader();

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	GLuint matrixID = shader->getMatrixID();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	
    glBindTexture(GL_TEXTURE_2D, _sprite->getMaterial()->getTexture());
	
    //Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = shader->getTextureID();
	glUniform1i(textureID, 0);

	//1st attribute buffer : vertices
	GLuint vertexPositionID = shader->getVertexPositionID();
	glEnableVertexAttribArray(vertexPositionID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getMesh()->getVertexbuffer());
	glVertexAttribPointer(vertexPositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//2nd attribute buffer : UVs
	GLuint vertexUVID = shader->getVertexUVID();
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getMesh()->getUvbuffer());
	glVertexAttribPointer(vertexUVID, 2, GL_FLOAT, GL_FALSE,  0, (void*)0);

	//Draw the triangles
	glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

	glDisableVertexAttribArray(vertexPositionID);
	glDisableVertexAttribArray(vertexUVID);
}

//Render a cube
void Renderer::renderCube(Cube* _cube, glm::mat4 _modelMatrix)
{
	glm::mat4 modelMatrix = _modelMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	//A pointer to the shader
	Shader* shader = _cube->getMaterial()->getShader();

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	GLuint matrixID = shader->getMatrixID();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	//Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = shader->getTextureID();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _cube->getMaterial()->getTexture());

	glUniform1i(textureID, 0);

	//1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _cube->getMesh()->getVertexbuffer());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _cube->getMesh()->getUvbuffer());
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

//Render a model
void Renderer::renderModel(Model* _model, glm::mat4 _modelMatrix)
{
	//############   RENDER THE SHADOWMAP   ##############
	
	//A pointer to the shader
	Shader* shader = _model->getMaterial()->getShader();
	Mesh* mesh = _model->getMesh();

	//Render to our framebuffer
	glBindFramebuffer(GL_FRAMEBUFFER, _model->getMesh()->getFramebufferShadowmap());

	//Render on the whole framebuffer, complete from the lower left corner to the upper right
	glViewport(0, 0, 1024, 1024); 

	//Use our shader
	glUseProgram(shader->getDepthProgramID());

	glm::vec3 dirLight = glm::vec3(01.2f, -2, 2);

	// Compute the MVP matrix from the light's point of view
	glm::mat4 depthProjectionMatrix = glm::ortho<float>(-10, 10, -10, 10, -10, 20);
	glm::mat4 depthViewMatrix = glm::lookAt(dirLight, glm::vec3(0, 0, 0), glm::vec3(0, -1, 0));

	glm::mat4 depthModelMatrix = glm::mat4(1.0) * _modelMatrix;
	glm::mat4 depthMVP = depthProjectionMatrix * depthViewMatrix * depthModelMatrix;

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	glUniformMatrix4fv(shader->getDepthMatrixID(), 1, GL_FALSE, &depthMVP[0][0]);

	//1rst attribute buffer : vertices
	glEnableVertexAttribArray(shader->getDepthVertexPositionModelspaceID());
	glBindBuffer(GL_ARRAY_BUFFER, mesh->getVertexbuffer());
	glVertexAttribPointer(shader->getDepthVertexPositionModelspaceID(), 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getElementbuffer());

	//Draw the triangles
	glDrawElements(GL_TRIANGLES, mesh->getIndices().size(), GL_UNSIGNED_SHORT, (void*)0);

	glDisableVertexAttribArray(shader->getDepthVertexPositionModelspaceID());

	//############   RENDER THE MODEL   ##############

	//Render to the screen
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glViewport(0, 0, windowWidth, windowHeight); // Render on the whole framebuffer, complete from the lower left corner to the upper right

	//Use our shader
	glUseProgram(shader->getProgramID());

	glm::mat4 modelMatrix = _modelMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	glm::mat4 biasMatrix(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);

	glm::mat4 depthBiasMVP = biasMatrix * depthMVP;

	//Get a handle for our "MVP" uniform
	GLuint matrixID = shader->getMatrixID();
	GLuint viewMatrixID = shader->getViewMatrixID();
	GLuint modelMatrixID = shader->getModelMatrixID();
	GLuint depthBiasID = shader->getDepthBiasID();
	GLuint dirLightID = shader->getDirLightID();

	//Get a handle for our buffers
	GLuint vertexPositionModelspaceID = shader->getVertexPositionModelspaceID();
	GLuint vertexUVID = shader->getVertexUVID();
	GLuint vertexNormalModelspaceID = shader->getVertexNormalModelspaceID();

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);

	glUniformMatrix4fv(depthBiasID, 1, GL_FALSE, &depthBiasMVP[0][0]);

	glUniform3f(dirLightID, dirLight.x, dirLight.y, dirLight.z);

	//Light position
	glm::vec3 lightPos = glm::vec3(-10, -7, 7);
	glUniform3f(shader->getLightID(), lightPos.x, lightPos.y, lightPos.z);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	//Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = shader->getTextureID();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model->getMaterial()->getTexture());

	glUniform1i(textureID, 0);

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, mesh->getDepthTexture());
	glUniform1i(shader->getShadowMapID(), 1);

	//1st attribute buffer : vertices
	glEnableVertexAttribArray(vertexPositionModelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, _model->getMesh()->getVertexbuffer());
	glVertexAttribPointer(vertexPositionModelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//2nd attribute buffer : UVs
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, _model->getMesh()->getUvbuffer());
	glVertexAttribPointer(vertexUVID, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//3nd attribute buffer : Normals
	glEnableVertexAttribArray(vertexNormalModelspaceID);
	glBindBuffer(GL_ARRAY_BUFFER, _model->getMesh()->getNormalbuffer());
	glVertexAttribPointer(vertexNormalModelspaceID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//Bind the index buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _model->getMesh()->getElementbuffer());

	//Draw the triangles
	glDrawElements(GL_TRIANGLES, _model->getMesh()->getIndices().size(), GL_UNSIGNED_SHORT, (void*)0);

	glDisableVertexAttribArray(vertexPositionModelspaceID);
	glDisableVertexAttribArray(vertexUVID);
	glDisableVertexAttribArray(vertexNormalModelspaceID);
}