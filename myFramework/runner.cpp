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

void Runner::run(Scene* _scene) {
    
    //Update deltaTime
    deltaTime = renderer->updateDeltaTime();

    //Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
    computeMatricesFromInputs(renderer->getWindow(), renderer->getWidth(), renderer->getHeight(), deltaTime);

    //Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Update the scene
    _scene->update(deltaTime);

    // Swap buffers
    glfwSwapBuffers(renderer->getWindow());
    glfwPollEvents();
}