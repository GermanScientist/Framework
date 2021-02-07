#include "cubeExample.h"

//Constructor
CubeExample::CubeExample()
{
    this->addCube("assets/cubetest/uvtemplate.DDS");
}

//Destructor
CubeExample::~CubeExample()
{

}

//Update function
void CubeExample::update(float _deltaTime) {
    
    //Rotate this object
    rotation.x += 300 * _deltaTime;
}