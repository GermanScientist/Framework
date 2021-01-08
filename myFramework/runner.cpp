#include <myFramework/runner.h>

//Constructor
Runner::Runner()
{
    renderer = new Renderer(1920, 1080);
}

//Destructor
Runner::~Runner()
{

}

//Run the scene
void Runner::run(Scene* _scene) {
    
    //Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
    computeMatricesFromInputs(renderer->getWindow(), renderer->getWidth(), renderer->getHeight());

    //Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Update the scene
    _scene->update();

    // Swap buffers
    glfwSwapBuffers(renderer->getWindow());
    glfwPollEvents();

    if (glfwWindowShouldClose(renderer->getWindow()) == 1 || glfwGetKey(renderer->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        _scene->exit();
    }

    //This doesn't seem to be needed
    /*
    //Close OpenGL window and terminate GLFW
    //glfwTerminate();
    */
}