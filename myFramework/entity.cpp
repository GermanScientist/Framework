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

	model = nullptr;
	sprite = nullptr;
	cube = nullptr;
}

//Destructor
Entity::~Entity()
{
}

//Add child
void Entity::addChild(Entity* _child)
{
	//Set this class as the parent
	_child->parent = this;

	//Add the child to the list of children
	this->children.push_back(_child);
}

//Remove child
void Entity::removeChild(Entity* _child)
{
	//The iterator iterates through the list of children
	std::vector<Entity*>::iterator iterator = std::find(children.begin(), children.end(), _child);

	//If the iterator finds _child
	if (iterator != children.cend()) {

		//Store the index
		int index = std::distance(children.begin(), iterator);

		//Set the child's parent to null
		_child->parent = nullptr;

		//Erase the child from the list of children
		children.erase(children.begin() + index);
	}
}

//Adds model to entity
void Entity::addModel()
{
	if (model != nullptr) {
		delete model;
		model = nullptr;
	}

	model = new Model();
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

//Adds cube to entity
void Entity::addCube(const char* _imagepath)
{
	if (cube != nullptr) {
		delete cube;
		cube = nullptr;
	}

	cube = new Cube(_imagepath);
}
