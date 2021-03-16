#include "grassFloor.h"

//Constructor
GrassFloor::GrassFloor()
{
    this->addModel();
    this->getModel()->loadTexture("assets/demo/grass/GrassTexture.dds");
    this->getModel()->loadObject("assets/demo/grass/grass.obj");
}

//Destructor
GrassFloor::~GrassFloor()
{

}

//Update function
void GrassFloor::update(float _deltaTime) {}