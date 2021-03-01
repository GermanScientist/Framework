#include "grassFloor.h"

//Constructor
GrassFloor::GrassFloor()
{
    this->addModel("assets/demo/grass/grass.obj", "assets/demo/grass/GrassTexture.dds");
}

//Destructor
GrassFloor::~GrassFloor()
{

}

//Update function
void GrassFloor::update(float _deltaTime) {}