#include <myFramework/entity.h>

//Constructor
Entity::Entity()
{
	//These will be set correctly while loading the textures
	width = 0;
	height = 0;

	//Assign properties
	position = new Vector3(0, 0, 0);
	scale = new Vector3(1, 1, 1);
	rotation = new Vector3(0, 0, 0);

	type = "";
}

//Destructor
Entity::~Entity()
{
	delete position;
	delete scale;
	delete rotation;
}