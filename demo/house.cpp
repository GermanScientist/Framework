#include "house.h"

//Constructor
House::House()
{
    this->addModel("assets/demo/house/house.obj", "assets/demo/house/House.dds");
}

//Destructor
House::~House()
{

}

//Update function
void House::update(float _deltaTime) {}