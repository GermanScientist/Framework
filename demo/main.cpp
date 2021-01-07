// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <myFramework/camera.h>
#include <myFramework/runner.h>

#include "scene.h"

int main(void)
{
    Runner runner;

    Scene* scene = new Scene(runner.getRenderer());

    //When the application is running
    do {
        runner.run(scene);

    } //Close the application when the window is closed (ESC or closing the window)
    while (glfwGetKey(runner.getRenderer()->getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(runner.getRenderer()->getWindow()) == 0);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
