#include "myScene.h"

//Constructor
MyScene::MyScene()
{
    //Add grass floor
    grassFloor = new GrassFloor();
    grassFloor->position = Vector3(0.0f, 0.0f, 0.0f);
    grassFloor->scale = Vector3(1.0f, 1.0f, 1.0f);
    grassFloor->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(grassFloor);

    //Add cube example
    cubeExample = new CubeExample();
    cubeExample->position = Vector3(18.0f, -3.9f, -20.0f);
    cubeExample->scale = Vector3(3.0f, 3.0f, 3.0f);
    cubeExample->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(cubeExample);

    //Add house
    house = new House();
    house->position = Vector3(-10.0f, 0.0f, 5.0f);
    house->scale = Vector3(3.5f, 3.5f, 3.5f);
    house->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(house);
}

//Destructor
MyScene::~MyScene()
{
    //Remove cubeExample
    removeChild(cubeExample);
    delete cubeExample;

    //Remove grass floor
    removeChild(grassFloor);
    delete grassFloor;

    //Remove house
    removeChild(house);
    delete house;
}

//Update function
void MyScene::update(float _deltaTime) {

}