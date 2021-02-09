#include <myFramework/runner.h>

//Constructor
Runner::Runner()
{
    renderer = new Renderer(1920, 1080);
}

//Destructor
Runner::~Runner()
{
    delete renderer;
}

//Run the scene
void Runner::run(Scene* _scene) {
    
    //Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
    _scene->getCamera()->computeMatricesFromInputs(renderer->getWindow(), renderer->getWidth(), renderer->getHeight(), getDeltaTime());

    //Update the scene
    _scene->updateEntity(_scene, getDeltaTime());

    //Render the scene
    renderer->renderScene(_scene);

    if (glfwWindowShouldClose(renderer->getWindow()) == 1 || glfwGetKey(renderer->getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        _scene->exit();
    }

    //This doesn't seem to be needed
    /*
    //Close OpenGL window and terminate GLFW
    //glfwTerminate();
    */
}

//Update delta time function
float Runner::getDeltaTime() {

    //LastTime is initialised only the first time this function is called
    static double lastTime = glfwGetTime();

    //Get the current time
    double currentTime = glfwGetTime();

    //Compute time difference between current and last time
    float deltaTime = float(currentTime - lastTime);

    //For the next frame, the "last time" will be "now"
    lastTime = currentTime;

    //Return deltatime
    return deltaTime;
}