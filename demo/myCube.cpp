#include "myCube.h"

//Constructor
MyCube::MyCube()
{
    this->addModel("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");
}

//Destructor
MyCube::~MyCube()
{

}

//Update function
void MyCube::update(float _deltaTime) {
    
}