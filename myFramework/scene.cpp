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
void Scene::updateEntity(Entity* _entity, float _deltaTime) {

	// call update() for this entity
	_entity->update(_deltaTime);

	//Render all children of this entity
	std::vector<Entity*> children = _entity->getChildren();

	for (Entity* c : children)
		this->updateEntity(c, _deltaTime);
}