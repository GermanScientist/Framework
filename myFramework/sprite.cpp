#include <myFramework/sprite.h>

//Constructor
Sprite::Sprite(const std::string& _imagepath)
{
	//Get the type of the entity
	type = "Sprite";

	//Create a material
	material = new Material();
	material->loadTGA(_imagepath);
	material->getShader()->load2DShaders();

	mesh = new Mesh();
	mesh->generateSpriteBuffers(material);
}

//Destructor
Sprite::~Sprite()
{
	delete material;
	delete mesh;
}