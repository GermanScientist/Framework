// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include <myFramework/camera.h>
#include <myFramework/runner.h>

#include "myScene.h"

//Main function
int main(void)
{
    //Initiate the runner class
    Runner runner;

    //Initiate the scene
    MyScene* scene = new MyScene();

    //Run the scene
    while (scene->getIsRunning()) {
        runner.run(scene);
    }

    //Delete the scene when it's not running anymore
    delete scene;

    return 0;
}