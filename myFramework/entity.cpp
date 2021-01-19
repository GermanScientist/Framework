#include <myFramework/entity.h>

//Constructor
Entity::Entity()
{
	//These will be set correctly while loading the textures
	width = 0;
	height = 0;

	//Assign properties
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;

	scale.x = 1.0f;
	scale.y = 1.0f;
	scale.z = 1.0f;

	rotation.x = 0.0f;
	rotation.y = 0.0f;
	rotation.z = 0.0f;

	type = "";
}

//Destructor
Entity::~Entity()
{
}