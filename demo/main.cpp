// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <myFramework/renderer.h>
#include <myFramework/camera.h>
#include <myFramework/sprite.h>
#include <myFramework/cube.h>

int main(void)
{
    Renderer renderer(1280, 720);

    Sprite* pencils = new Sprite("assets/pencils.tga");
    Sprite* kingkong = new Sprite("assets/kingkong.tga");
    Sprite* rgba = new Sprite("assets/rgba.tga");
    Cube* cube = new Cube("assets/uvtemplate.DDS");

    do {
        // Update deltaTime
        float deltaTime = renderer.updateDeltaTime();

        // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
        computeMatricesFromInputs(renderer.getWindow(), deltaTime);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::vec3 cursor = getCursor(); // from Camera
        // printf("(%f,%f)\n",cursor.x, cursor.y);

        // Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
        static float rot_z = 0.0f;
        renderer.renderSprite(pencils, 10, 12, 0.0f, 0.04f, 0.04f, 1.0f, 0.0f);
        renderer.renderSprite(kingkong, -15, 5, 0.0f, 0.05f, 0.05f, 1.0f, 0.0f);
        renderer.renderSprite(rgba, 0, -10, 0.0f, 0.04f, 0.04f, 1.0f, rot_z);
        renderer.renderCube(cube, 0, 0, 0.0f, 3.0f, 3.0f, 3.0f, 0.0f);
        rot_z += 3.141592f / 2 * deltaTime;

        // Swap buffers
        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(renderer.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(renderer.getWindow()) == 0);

    delete pencils;
    delete kingkong;
    delete rgba;
    delete cube;

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
