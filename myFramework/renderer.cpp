#include <myFramework/camera.h>
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

	//Get all the sprites in the scene
	std::vector<Entity*> entities = _scene->getEntities();

	//Go through the list of sprites
	for (Entity* entity : entities)
	{
		//And render the corresponding entity
		if (entity->getType() == "Sprite")
			renderSprite((Sprite*)entity);

		if (entity->getType() == "Cube")
			renderCube((Cube*)entity);

		if (entity->getType() == "Model")
			renderModel((Model*)entity);
	}

	// Swap buffers
	glfwSwapBuffers(window);
	glfwPollEvents();
}

//Render a sprite
void Renderer::renderSprite(Sprite* _sprite)
{
    //Get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix(); 
	glm::mat4 projectionMatrix = getProjectionMatrix();

	//Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_sprite->position.x, _sprite->position.y, _sprite->position.z));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_sprite->rotation.x, _sprite->rotation.y, _sprite->rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_sprite->scale.x, _sprite->scale.y, _sprite->scale.z));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	GLuint matrixID = _sprite->getMaterial()->getShader()->getMatrixID();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	
    glBindTexture(GL_TEXTURE_2D, _sprite->getMaterial()->getTexture());
	
    //Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = _sprite->getMaterial()->getShader()->getTextureID();
	glUniform1i(textureID, 0);

	//1st attribute buffer : vertices
	GLuint vertexPositionID = _sprite->getMaterial()->getShader()->getVertexPositionID();
	glEnableVertexAttribArray(vertexPositionID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getVertexbuffer());
	glVertexAttribPointer(vertexPositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	//2nd attribute buffer : UVs
	GLuint vertexUVID = _sprite->getMaterial()->getShader()->getVertexUVID();
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getUvbuffer());
	glVertexAttribPointer(vertexUVID, 2, GL_FLOAT, GL_FALSE,  0, (void*)0);

	//Draw the triangles
	glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

	glDisableVertexAttribArray(vertexPositionID);
	glDisableVertexAttribArray(vertexUVID);
}

//Render a cube
void Renderer::renderCube(Cube* _cube)
{
	//Get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix();
	glm::mat4 projectionMatrix = getProjectionMatrix();

	//Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_cube->position.x, _cube->position.y, _cube->position.z));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_cube->rotation.x, _cube->rotation.y, _cube->rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_cube->scale.x, _cube->scale.y, _cube->scale.z));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	GLuint matrixID = _cube->getMaterial()->getShader()->getMatrixID();
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	//Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = _cube->getMaterial()->getShader()->getTextureID();
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
void Renderer::renderModel(Model* _model)
{
	//Get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix();
	glm::mat4 projectionMatrix = getProjectionMatrix();

	//Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_model->position.x, _model->position.y, _model->position.z));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_model->rotation.x, _model->rotation.y, _model->rotation.z);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_model->scale.x, _model->scale.y, _model->scale.z));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	//Get a handle for our "MVP" uniform
	GLuint matrixID = _model->getMaterial()->getShader()->getMatrixID();
	GLuint viewMatrixID = _model->getMaterial()->getShader()->getViewMatrixID();
	GLuint modelMatrixID = _model->getMaterial()->getShader()->getModelMatrixID();

	//Get a handle for our buffers
	GLuint vertexPositionModelspaceID = _model->getMaterial()->getShader()->getVertexPositionModelspaceID();
	GLuint vertexUVID = _model->getMaterial()->getShader()->getVertexUVID();
	GLuint vertexNormalModelspaceID = _model->getMaterial()->getShader()->getVertexNormalModelspaceID();

	//Send our transformation to the currently bound shader, in the "MVP" uniform
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(modelMatrixID, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(viewMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);

	glm::vec3 lightPos = glm::vec3(4, 4, 4);
	glUniform3f(_model->getMaterial()->getShader()->getLightID(), lightPos.x, lightPos.y, lightPos.z);

	//Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	//Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = _model->getMaterial()->getShader()->getTextureID();
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model->getMaterial()->getTexture());

	glUniform1i(textureID, 0);

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

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, _model->getMesh()->getVertices().size());

	glDisableVertexAttribArray(vertexPositionModelspaceID);
	glDisableVertexAttribArray(vertexUVID);
	glDisableVertexAttribArray(vertexNormalModelspaceID);
}