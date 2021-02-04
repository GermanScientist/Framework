#include "myScene.h"

//Constructor
MyScene::MyScene()
{
    uvMap = new UvMap();
    uvMap->position = Vector3(-32.0f, -5.0f, 0.0f);
    uvMap->scale = Vector3(0.025f, 0.025f, 1.0f);
    addEntity(uvMap);

    myCube = new MyCube();
    myCube->position = Vector3(-8.0f, 10.0f, 0.0f);
    myCube->scale = Vector3(3.0f, 3.0f, 3.0f);
    myCube->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addEntity(myCube);

    cubeExample = new CubeExample();
    cubeExample->position = Vector3(-32.0f, 10.0f, 0.0f);
    cubeExample->scale = Vector3(3.0f, 3.0f, 3.0f);
    cubeExample->rotation = Vector3(0.0f, 0.0f, 22.0f);
    addEntity(cubeExample);
}

//Destructor
MyScene::~MyScene()
{
    removeEntity(uvMap);
    delete uvMap;

    removeEntity(myCube);
    delete myCube;

    removeEntity(cubeExample);
    delete cubeExample;
}

//Update function
void MyScene::update(float _deltaTime) {
    
}