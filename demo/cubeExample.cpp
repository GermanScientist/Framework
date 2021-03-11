#include "cubeExample.h"

//Constructor
CubeExample::CubeExample()
{
    //this->addCube("assets/demo/cube/cube.dds");
    this->addModel("assets/demo/cube/cube.obj", "assets/demo/cube/cube.dds");
}

//Destructor
CubeExample::~CubeExample()
{

}

//Update function
void CubeExample::update(float _deltaTime) {}