#include "cubeExample.h"

//Constructor
CubeExample::CubeExample()
{
    //this->addCube("assets/demo/cube/cube.dds");
    this->addModel();
    this->getModel()->loadTexture("assets/demo/cube/cube.dds");

    if (true) //If true: Load .obj file
        this->getModel()->loadObject("assets/demo/cube/cube.obj");
    else //If false: load cube (gives error popup)
        this->getModel()->loadCube();
    
}

//Destructor
CubeExample::~CubeExample()
{

}

//Update function
void CubeExample::update(float _deltaTime) {}