#include "player.h"

//Constructor
Player::Player()
{
    this->addModel();
    this->getModel()->loadTexture("assets/demo/cube/cube.dds");
    this->getModel()->loadObject("assets/demo/cube/cube.obj");
}

//Destructor
Player::~Player()
{

}

//Update function
void Player::update(float _deltaTime) {}