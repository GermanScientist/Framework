#include "scene.h"

//Constructor
Scene::Scene()
{
    //Initializes camera
    camera = new Camera();

    //Assign properties
    isRunning = true;
}

//Destructor
Scene::~Scene()
{
    delete camera;
}

//Update function
void Scene::update(float _deltaTime) {

}