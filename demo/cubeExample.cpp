#include "cubeExample.h"

//Constructor
CubeExample::CubeExample()
{
    //this->addCube("assets/demo/cube/cube.dds");
    this->addModel();
    this->getModel()->loadTexture("assets/demo/cube/cube.dds");
    this->getModel()->loadObject("assets/demo/cube/cube.obj");
}

//Destructor
CubeExample::~CubeExample()
{

}

//Update function
void CubeExample::update(float _deltaTime) {}