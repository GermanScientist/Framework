#include "myScene.h"

//Constructor
MyScene::MyScene()
{
    //Add cube example
    cubeExample = new CubeExample();
    cubeExample->position = Vector3(-32.0f, 10.0f, 0.0f);
    cubeExample->scale = Vector3(3.0f, 3.0f, 3.0f);
    cubeExample->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(cubeExample);

    //Add myCube
    myCube = new MyCube();
    myCube->position = Vector3(-8.0f, 10.0f, 0.0f);
    myCube->scale = Vector3(3.0f, 3.0f, 3.0f);
    myCube->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(myCube);

    //Add myBall
    myHouse = new MyHouse();
    myHouse->position = Vector3(28.0f, 15.0f, 0.0f);
    myHouse->scale = Vector3(2.0f, 2.0f, 2.0f);
    myHouse->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addChild(myHouse);

    //Add uvMap
    uvMap = new UvMap();
    uvMap->position = Vector3(-32.0f, -5.0f, 0.0f);
    uvMap->scale = Vector3(0.025f, 0.025f, 1.0f);
    addChild(uvMap);

    //Add cubeMap
    cubeMap = new CubeMap();
    cubeMap->position = Vector3(-8.0f, -5.0f, 0.0f);
    cubeMap->scale = Vector3(0.05f, 0.05f, 1.0f);
    addChild(cubeMap);

    //Add ballMap
    ballMap = new BallMap();
    ballMap->position = Vector3(6.0f, -5.0f, 0.0f);
    ballMap->scale = Vector3(0.015f, 0.015f, 1.0f);
    addChild(ballMap);

    //Add houseMap
    houseMap = new HouseMap();
    houseMap->position = Vector3(28.0f, -5.0f, 0.0f);
    houseMap->scale = Vector3(0.01f, 0.01f, 1.0f);
    addChild(houseMap);
}

//Destructor
MyScene::~MyScene()
{
    //Remove cubeExample
    removeChild(cubeExample);
    delete cubeExample;

    //Remove myCube
    removeChild(myCube);
    delete myCube;

    //Remove myHouse
    removeChild(myHouse);
    delete myHouse;

    //Remove uvMap
    removeChild(uvMap);
    delete uvMap;

    //Remove cubeMap
    removeChild(cubeMap);
    delete cubeMap;

    //Remove ballMap
    removeChild(ballMap);
    delete ballMap;

    //Remove houseMap
    removeChild(houseMap);
    delete houseMap;
}

//Update function
void MyScene::update(float _deltaTime) {

}