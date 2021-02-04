#include <myFramework/entity.h>

//Constructor
Entity::Entity()
{
	//These will be set correctly while loading the textures
	width = 0;
	height = 0;

	//Assign properties
	position = Vector3(0, 0, 0);
	scale = Vector3(1, 1, 1);
	rotation = Vector3(0, 0, 0);

	type = "";

	model = nullptr;
	sprite = nullptr;
}

//Destructor
Entity::~Entity()
{
}

//Adds model to entity
void Entity::addModel(const char* _path, const char* _imagepath)
{
	if (model != nullptr) {
		delete model;
		model = nullptr;
	}

	model = new Model(_path, _imagepath);
}

//Adds model to entity
void Entity::addSprite(const std::string& _imagepath)
{
	if (sprite != nullptr) {
		delete sprite;
		sprite = nullptr;
	}

	sprite = new Sprite(_imagepath);
}
