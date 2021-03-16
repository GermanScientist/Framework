#include "house.h"

//Constructor
House::House()
{
    this->addModel();
    this->getModel()->loadTexture("assets/demo/house/House.dds");
    this->getModel()->loadObject("assets/demo/house/house.obj");
}

//Destructor
House::~House()
{

}

//Update function
void House::update(float _deltaTime) {}