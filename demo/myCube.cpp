#include "myCube.h"

//Constructor
MyCube::MyCube()
{
    this->addModel("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");

    //Add myBall
    myBall = new MyBall();
    myBall->position = Vector3(5.0f, 0.0f, 0.0f);
    myBall->scale = Vector3(1.5f, 1.5f, 1.5f);
    myBall->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(myBall);
}

//Destructor
MyCube::~MyCube()
{
    //Remove myBall
    removeChild(myBall);
    delete myBall;
}

//Update function
void MyCube::update(float _deltaTime) {
    
    //Rotate this object
    rotation.x += 300 * _deltaTime;
}