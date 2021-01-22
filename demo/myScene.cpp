#include "myScene.h"

//Constructor
MyScene::MyScene()
{
    vector = new Vector3(-32, 10, 0);

    //Create cubes
    cube = new Cube("assets/cubetest/uvtemplate.DDS");
    cube->setPosition(-32.0f, 10.0f, 0.0f);
    cube->setScale(3.0f, 3.0f, 3.0f);
    cube->setRotation(0.0f, 0.0f, 22.0f);

    //Create models
    cubeModel = new Model("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");
    cubeModel->setPosition(-8.0f, 10.0f, 0.0f);
    cubeModel->setScale(3.0f, 3.0f, 3.0f);
    cubeModel->setRotation(0.0f, 0.0f, 22.0f);

    ballModel = new Model("assets/modeltest/ball.obj", "assets/modeltest/ball.DDS");
    ballModel->setPosition(6.0f, 10.0f, 0.0f);
    ballModel->setScale(3.0f, 3.0f, 3.0f);
    ballModel->setRotation(0.0f, 0.0f, 22.0f);

    houseModel = new Model("assets/modeltest/house.obj", "assets/modeltest/house.DDS");
    houseModel->setPosition(28.0f, 15.0f, 0.0f);
    houseModel->setScale(2.0f, 2.0f, 2.0f);
    houseModel->setRotation(0.0f, 0.0f, 22.0f);

    //Create sprites
    uvTemplate = new Sprite("assets/cubetest/uvtemplate.tga");
    uvTemplate->setPosition(-32.0f, -5.0f, 0.0f);
    uvTemplate->setScale(0.025f, 0.025f, 1.0f);

    cubeMap = new Sprite("assets/modeltest/cube.tga");
    cubeMap->setPosition(-8.0f, -5.0f, 0.0f);
    cubeMap->setScale(0.05f, 0.05f, 1.0f);

    ballMap = new Sprite("assets/modeltest/ball.tga");
    ballMap->setPosition(6.0f, -5.0f, 0.0f);
    ballMap->setScale(0.015f, 0.015f, 1.0f);

    houseMap = new Sprite("assets/modeltest/house.tga");
    houseMap->setPosition(28.0f, -5.0f, 0.0f);
    houseMap->setScale(0.01f, 0.01f, 1.0f);

    //Add everything to the entitylist, to be able to be rendered
    addEntity(cube);
    addEntity(cubeModel);
    addEntity(ballModel);
    addEntity(houseModel);
    addEntity(uvTemplate);
    addEntity(cubeMap);
    addEntity(ballMap);
    addEntity(houseMap);

    //Properties
    rotationSpeed = 300;
}

//Destructor
MyScene::~MyScene()
{
    //Delete sprites
    delete uvTemplate;
    delete cubeMap;
    delete ballMap;
    delete houseMap;

    //Delete cubes
    delete cube;

    //Delete models
    delete cubeModel;
    delete ballModel;
    delete houseModel;

    delete vector;

    removeEntity(cube);
    removeEntity(cubeModel);
    removeEntity(ballModel);
    removeEntity(houseModel);
    removeEntity(uvTemplate);
    removeEntity(cubeMap);
    removeEntity(ballMap);
    removeEntity(houseMap);
}

//Update function
void MyScene::update(float _deltaTime) {
    
    //Rotate models
    cube->rotation.x += rotationSpeed * _deltaTime;
    cubeModel->rotation.x += rotationSpeed * _deltaTime;
    ballModel->rotation.x += rotationSpeed * _deltaTime;
    houseModel->rotation.x += rotationSpeed * _deltaTime;
}