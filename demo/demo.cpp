// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <myFramework/renderer.h>
#include <myFramework/camera.h>
#include <myFramework/sprite.h>

int main( void )
{
	Renderer renderer(1280, 720);

	do {
		// Update deltaTime
		float deltaTime = renderer.updateDeltaTime();

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window(), deltaTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glm::vec3 cursor = getCursor(); // from Camera
		// printf("(%f,%f)\n",cursor.x, cursor.y);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
