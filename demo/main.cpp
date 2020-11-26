#include <myFramework/runner.h>

int main( void )
{
	//The instance of the runner
	Runner runner;

	Renderer renderer(1280, 720);

	Sprite* pencils = new Sprite("assets/pencils.tga");

	do {
		// Update deltaTime
		float deltaTime = renderer.updateDeltaTime();

		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window(), deltaTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// glm::vec3 cursor = getCursor(); // from Camera
		// printf("(%f,%f)\n",cursor.x, cursor.y);

		//Render sprite
		renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(renderer.window()) == 0);

	delete pencils;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}