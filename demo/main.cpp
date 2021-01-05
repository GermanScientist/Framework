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

    Cube* cube = new Cube("assets/cubetest/uvtemplate.DDS");
    Model* cubeModel = new Model("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");
    Model* ballModel = new Model("assets/modeltest/ball.obj", "assets/modeltest/ball.DDS");
    Model* houseModel = new Model("assets/modeltest/house.obj", "assets/modeltest/house.DDS");

    Sprite* uvTemplate = new Sprite("assets/cubetest/uvtemplate.tga");
    Sprite* cubeMap = new Sprite("assets/modeltest/cube.tga");
    Sprite* ballMap = new Sprite("assets/modeltest/ball.tga");
    Sprite* houseMap = new Sprite("assets/modeltest/house.tga");

    do {
        // Update deltaTime
        float deltaTime = renderer.updateDeltaTime();

        // Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
        computeMatricesFromInputs(renderer.getWindow(), renderer.getWidth(), renderer.getHeight(), deltaTime);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        static float rot_X = 0.0f;

        // Render all models/sprites (Type*, xpos, ypos, zpos, xscale, yscale, zscale, xrot, yrot, zrot)
        renderer.renderSprite(uvTemplate, -32, -5, 0.0f, 0.025f, 0.025f, 1.0f, 0.0f);
        renderer.renderSprite(cubeMap, -8, -5, 0.0f, 0.050f, 0.050f, 1.0f, 0.0f);
        renderer.renderSprite(ballMap, 6, -5, 0.0f, 0.015f, 0.015f, 1.0f, 0.0f);
        renderer.renderSprite(houseMap, 28, -5, 0.0f, 0.010f, 0.010f, 1.0f, 0.0f);

        renderer.renderCube(cube, -32, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
        renderer.renderModel(cubeModel, -8, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
        renderer.renderModel(ballModel, 6, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
        renderer.renderModel(houseModel, 28, 15, 0.0f, 2.0f, 2.0f, 2.0f, rot_X, 0.0f, 22.0f);

        rot_X += 3.141592 / 5 * deltaTime;

        // Swap buffers
        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(renderer.getWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
        glfwWindowShouldClose(renderer.getWindow()) == 0);

    delete uvTemplate;
    delete cubeMap;
    delete cube;
    delete cubeModel;
    delete ballModel;
    delete houseModel;

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}
