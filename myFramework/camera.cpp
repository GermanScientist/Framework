#include <myFramework/camera.h>

//Gets the view matrix
glm::mat4 viewMatrix;
glm::mat4 getViewMatrix(){
	return viewMatrix;
}

//Gets the projection matrix
glm::mat4 projectionMatrix;
glm::mat4 getProjectionMatrix() {
	return projectionMatrix;
}

// Initial position : on +Z
glm::vec3 offset = glm::vec3(0, 0, -45);
glm::vec3 position = glm::vec3(0, 0, 0) + offset;

//PI
float pi = 3.1415f;

// Initial horizontal angle : toward -Z
float horizontalAngle = pi;

// Initial vertical angle : none
float verticalAngle = 0.0f;

// Initial Field of View
float initialFoV = 60.0f;

float speed = 50.0f;
float mouseSpeed = 0.0035f;

//Control camera using keyboard input
void computeMatricesFromInputs(GLFWwindow* _window, unsigned int _width, unsigned int _height, float _deltaTime)
{
	//Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);
	
	//Reset mouse position next frame
	glfwSetCursorPos(_window, _width/2, _height/2);

	// Compute new orientation
	horizontalAngle += mouseSpeed * float(_width/2 - xpos);
	verticalAngle += mouseSpeed * float(_height/2 - ypos);

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(cos(verticalAngle) * sin(-horizontalAngle), sin(verticalAngle), cos(verticalAngle) * cos(-horizontalAngle));

	// Right vector
	glm::vec3 right = glm::vec3(sin(-horizontalAngle - pi / 2.0f), 0, cos(-horizontalAngle - pi / 2.0f));

	// Up vector
	glm::vec3 up = glm::cross(right, direction);


	//Move forward
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
		position += direction * _deltaTime * speed;
	}

	//Move backward
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
		position -= direction * _deltaTime * speed;
	}

	//Strafe right
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
		position += right * _deltaTime * speed;
	}

	//Strafe left
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
		position -= right * _deltaTime * speed;
	}

	float FoV = initialFoV;

	//Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projectionMatrix = glm::perspective(glm::radians(FoV), (float)_width / (float)_height, 0.1f, 100.0f);

	//View matrix
	//Camera matrix
	viewMatrix = glm::lookAt(position, position + direction, up);
    std::cout << position.x << " + " << position.y << " + " << position.z << " + " << horizontalAngle << "\n";
}