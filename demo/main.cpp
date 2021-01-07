// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <myFramework/camera.h>

#include "scene.h"

int main(void)
{
    Renderer* renderer = new Renderer(1920, 1080);

    Scene* scene = new Scene(renderer);

    //When the application is running
    do {
        //Update deltaTime
        float deltaTime = renderer->updateDeltaTime();

        //Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
        computeMatricesFromInputs(renderer->getWindow(), renderer->getWidth(), renderer->getHeight(), deltaTime);

        //Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Update the scene
        scene->update(deltaTime);

        // Swap buffers
        glfwSwapBuffers(renderer->getWindow());
        glfwPollEvents();

    } //Close the application when the window is closed (ESC or closing the window)
    while (glfwGetKey(renderer->getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(renderer->getWindow()) == 0);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
