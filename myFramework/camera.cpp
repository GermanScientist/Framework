#include <myFramework/camera.h>

Camera::Camera()
{
	// Initial position : on +Z
	position = Vector3(0, 0, 0);
	offset = Vector3(0, 0, -45);
	position += offset;

	localPosition = glm::vec3(position.x, position.y, position.z);

	//Initial horizontal angle : toward -Z
	initialHorizontalAngle = 2.733f;
	horizontalAngle = initialHorizontalAngle;

	//Initial vertical angle : none
	verticalAngle = 1.485f;

	//Initial Field of View
	initialFoV = 60.0f;

	speed = 50.0f;
	mouseSpeed = 0.0035f;
}

Camera::~Camera()
{
}

//Control camera using keyboard input
void Camera::computeMatricesFromInputs(GLFWwindow* _window, unsigned int _width, unsigned int _height, float _deltaTime)
{
	//Sets the localposition to the position
	localPosition = glm::vec3(position.x, position.y, position.z);

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
	glm::vec3 right = glm::vec3(sin(-horizontalAngle - initialHorizontalAngle / 2.0f), 0, cos(-horizontalAngle - initialHorizontalAngle / 2.0f));

	// Up vector
	glm::vec3 up = glm::cross(right, direction);


	//Move forward
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
		localPosition += direction * _deltaTime * speed;
	}

	//Move backward
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
		localPosition -= direction * _deltaTime * speed;
	}

	//Strafe right
	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
		localPosition += right * _deltaTime * speed;
	}

	//Strafe left
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
		localPosition -= right * _deltaTime * speed;
	}

	float FoV = initialFoV;

	//Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	projectionMatrix = glm::perspective(glm::radians(FoV), (float)_width / (float)_height, 0.1f, 500.0f);

	//View matrix
	//Camera matrix
	viewMatrix = glm::lookAt(localPosition, localPosition + direction, up);
    /*std::cout << position.x << " + " << position.y << " + " << position.z << " + " << horizontalAngle << " + " << verticalAngle << "\n";*/

	position = Vector3(localPosition.x, localPosition.y, localPosition.z);
}
