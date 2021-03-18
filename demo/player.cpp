#include "player.h"

//Constructor
Player::Player()
{
    this->addModel();
    this->getModel()->loadTexture("assets/demo/cube/cube.dds");
    this->getModel()->loadObject("assets/demo/cube/cube.obj");

    speed = 400;
    degrees = 30;
}

//Destructor
Player::~Player()
{

}

//Update function
void Player::update(float _deltaTime) {

    this->rotation.x += Vector::deg2rad(degrees) * _deltaTime * speed;
}