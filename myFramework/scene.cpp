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

void Scene::removeEntity(Entity* _entity) {
    
    std::vector<Entity*>::iterator iterator = std::find(entities.begin(), entities.end(), _entity);

    if (iterator != entities.cend()) {
        int index = std::distance(entities.begin(), iterator);

        entities.erase(entities.begin() + index);
    }
}