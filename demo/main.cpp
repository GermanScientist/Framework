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

    while (scene->getIsRunning()) {
        runner.run(scene);
    }

    delete scene;

    return 0;
}