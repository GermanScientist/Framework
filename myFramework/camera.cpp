#include <myFramework/camera.h>

//Gets the view matrix
glm::mat4 viewMatrix;
glm::mat4 getViewMatrix(){
	return viewMatrix;
}

//Gets the cursor
glm::vec3 cursor = glm::vec3( 0, 0, 0 );
glm::vec3 getCursor(){
	return cursor;
}

//Control camera using keyboard input
void computeMatricesFromInputs(GLFWwindow* _window, float _deltaTime)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(_window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );

	// Right and Up vector
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);
    glm::vec3 forward = glm::vec3(0, 0, 1);

	static glm::vec3 offset = glm::vec3( 0, 0, -30);
	static glm::vec3 position = glm::vec3( 0, 0, 0 ) + offset;
	float speed = 300.0f; // units / second

	// Move up
	if (glfwGetKey(_window, GLFW_KEY_UP) == GLFW_PRESS){
		position += up * _deltaTime * speed;
	}
	// Move down
	if (glfwGetKey(_window, GLFW_KEY_DOWN) == GLFW_PRESS){
		position -= up * _deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS){
		position += right * _deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS){
		position -= right * _deltaTime * speed;
	}
    // Move forward
    if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
        position -= forward * _deltaTime * speed;
    }
    // Move backwards
    if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
        position += forward * _deltaTime * speed;
    }

	// View matrix
	viewMatrix = glm::lookAt(position, position + glm::vec3(0, 0, 1), glm::vec3(0, -1, 0));
    //std::cout << position.x << " + " << position.y << " + " << position.z << "\n";
}