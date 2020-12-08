#include <myFramework/camera.h>
#include<iostream>

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
void computeMatricesFromInputs(GLFWwindow* window, float deltaTime)
{
	// Get mouse position
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);
	cursor = glm::vec3( xpos, ypos, 0 );

	// Right and Up vector
	glm::vec3 right = glm::vec3(1, 0, 0);
	glm::vec3 up = glm::vec3(0, -1, 0);
    glm::vec3 forward = glm::vec3(0, 0, 1);

	static glm::vec3 offset = glm::vec3( 0, 0, 0 );
	static glm::vec3 position = glm::vec3( 0, 0, 800 ) + offset;
	float speed = 300.0f; // units / second

	// Move up
	if (glfwGetKey( window, GLFW_KEY_UP ) == GLFW_PRESS){
		position += up * deltaTime * speed;
	}
	// Move down
	if (glfwGetKey( window, GLFW_KEY_DOWN ) == GLFW_PRESS){
		position -= up * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey( window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey( window, GLFW_KEY_LEFT ) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}
    // Move forward
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        position -= forward * deltaTime * speed;
    }
    // Move backwards
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        position += forward * deltaTime * speed;
    }

	// View matrix
	viewMatrix = glm::lookAt(position, position + glm::vec3(0, 0, -1), glm::vec3(0, 1, 0));
    std::cout << position.z << "\n";
}