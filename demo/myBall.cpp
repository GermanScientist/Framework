#include "myBall.h"

//Constructor
MyBall::MyBall()
{
    this->addModel("assets/modeltest/ball.obj", "assets/modeltest/ball.DDS");
}

//Destructor
MyBall::~MyBall()
{

}

//Update function
void MyBall::update(float _deltaTime) {
    
    //Rotate this object
    rotation.x += 300 * _deltaTime;
}