#include "myHouse.h"

//Constructor
MyHouse::MyHouse()
{
    this->addModel("assets/modeltest/house.obj", "assets/modeltest/house.DDS");
}

//Destructor
MyHouse::~MyHouse()
{

}

//Update function
void MyHouse::update(float _deltaTime) {
    
}