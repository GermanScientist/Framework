#include <myFramework/camera.h>
#include <myFramework/renderer.h>

Renderer::Renderer(unsigned int _width, unsigned int _height)
{
	windowWidth = _width;
	windowHeight = _height;

	this->initialize();
}

Renderer::~Renderer()
{
	
}

//Intialize renderer
int Renderer::initialize()
{
	// Initialise GLFW library
	if( !glfwInit() )
	{
		fprintf(stderr, "Failed to initialize GLFW library \n");
		return -1;
	}

    //Set the window hints
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_SAMPLES, 4);

	// Open a window and create its OpenGL context
	window = glfwCreateWindow(windowWidth, windowHeight, "Demo", NULL, NULL);
	
    if(window == NULL) {
		fprintf( stderr, "Failed to open GLFW window.\n" );
		glfwTerminate();
		return -1;
	}
	
    glfwMakeContextCurrent(window);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW library \n");
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	
    // Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	return 0;
}

//Update delta time function
float Renderer::updateDeltaTime() {
	
    // lastTime is initialised only the first time this function is called
	static double lastTime = glfwGetTime();
	
    // get the current time
	double currentTime = glfwGetTime();

	// Compute time difference between current and last time
	float deltaTime = float(currentTime - lastTime);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
	return deltaTime;
}

//Render a sprite
void Renderer::renderSprite(Sprite* _sprite, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rot)
{
    // get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix(); 
	glm::mat4 projectionMatrix = getProjectionMatrix();

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_posX, _posY, _posZ));
	glm::mat4 rotationMatrix    = glm::eulerAngleYXZ(0.0f, 0.0f, _rot);
	glm::mat4 scalingMatrix     = glm::scale(glm::mat4(1.0f), glm::vec3(_scaleX, _scaleY, _scaleZ));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint matrixID = glGetUniformLocation(_sprite->getMaterial()->getProgramID(), "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	
    glBindTexture(GL_TEXTURE_2D, _sprite->getMaterial()->getTexture());
	
    // Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID  = glGetUniformLocation(_sprite->getMaterial()->getProgramID(), "textureSampler");
	glUniform1i(textureID, 0);

	// 1st attribute buffer : vertices
	GLuint vertexPositionID = glGetAttribLocation(_sprite->getMaterial()->getProgramID(), "vertexPosition");
	glEnableVertexAttribArray(vertexPositionID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getVertexbuffer());
	glVertexAttribPointer(vertexPositionID, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : UVs
	GLuint vertexUVID = glGetAttribLocation(_sprite->getMaterial()->getProgramID(), "vertexUV");
	glEnableVertexAttribArray(vertexUVID);
	glBindBuffer(GL_ARRAY_BUFFER, _sprite->getUvbuffer());
	glVertexAttribPointer(vertexUVID, 2, GL_FLOAT, GL_FALSE,  0, (void*)0);

	// Draw the triangles
	glDrawArrays(GL_TRIANGLES, 0, 2*3); // 2*3 indices starting at 0 -> 2 triangles

	glDisableVertexAttribArray(vertexPositionID);
	glDisableVertexAttribArray(vertexUVID);
}

//Render a cube
void Renderer::renderCube(Cube* _cube, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rotX, float _rotY, float _rotZ)
{
	// get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix();
	glm::mat4 projectionMatrix = getProjectionMatrix();

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_posX, _posY, _posZ));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_rotX, _rotY, _rotZ);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_scaleX, _scaleY, _scaleZ));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint matrixID = glGetUniformLocation(_cube->getMaterial()->getProgramID(), "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	// Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = glGetUniformLocation(_cube->getMaterial()->getProgramID(), "textureSampler");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _cube->getMaterial()->getTexture());

	glUniform1i(textureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _cube->getVertexbuffer());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _cube->getUvbuffer());
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}

//Render a model
void Renderer::renderModel(Model* _model, float _posX, float _posY, float _posZ, float _scaleX, float _scaleY, float _scaleZ, float _rotX, float _rotY, float _rotZ)
{
	// get viewmatrix from Camera (Camera position and direction)
	glm::mat4 viewMatrix = getViewMatrix();
	glm::mat4 projectionMatrix = getProjectionMatrix();

	// Build the Model matrix
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(_posX, _posY, _posZ));
	glm::mat4 rotationMatrix = glm::eulerAngleYXZ(_rotX, _rotY, _rotZ);
	glm::mat4 scalingMatrix = glm::scale(glm::mat4(1.0f), glm::vec3(_scaleX, _scaleY, _scaleZ));

	glm::mat4 modelMatrix = translationMatrix * rotationMatrix * scalingMatrix;

	glm::mat4 MVP = projectionMatrix * viewMatrix * modelMatrix;

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	GLuint matrixID = glGetUniformLocation(_model->getMaterial()->getProgramID(), "MVP");
	glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);

	// Set our "textureSampler" sampler to user Texture Unit 0
	GLuint textureID = glGetUniformLocation(_model->getMaterial()->getProgramID(), "textureSampler");
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _model->getMaterial()->getTexture());

	glUniform1i(textureID, 0);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, _model->getVertexbuffer());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, _model->getUvbuffer());
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, _model->getVertices().size());

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}