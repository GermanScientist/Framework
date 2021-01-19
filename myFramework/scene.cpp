#include "scene.h"

//Constructor
Scene::Scene()
{
    //Assign properties
    isRunning = true;
}

//Destructor
Scene::~Scene()
{
}

//Update function
void Scene::update(float _deltaTime) {

}

void Scene::addEntity(Entity* _entity)
{
    entities.push_back(_entity);
}