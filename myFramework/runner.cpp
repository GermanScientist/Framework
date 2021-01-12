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
void Runner::run(MyScene* _scene) {
    
    //Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
    computeMatricesFromInputs(renderer->getWindow(), renderer->getWidth(), renderer->getHeight(), getDeltaTime());

    //Clear the screen
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Update the scene
    _scene->update(getDeltaTime());

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