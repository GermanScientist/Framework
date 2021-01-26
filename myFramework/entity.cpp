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
}

//Destructor
Entity::~Entity()
{
}