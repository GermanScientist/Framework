#include "myScene.h"

//Constructor
MyScene::MyScene(Renderer* _renderer)
{
    renderer = _renderer;

    //Create models
    cube = new Cube("assets/cubetest/uvtemplate.DDS");
    cube->setPosition(-32.0f, 10.0f, 0.0f);
    cube->setScale(3.0f, 3.0f, 3.0f);
    cube->setRotation(0.0f, 0.0f, 22.0f);

    cubeModel = new Model("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");
    ballModel = new Model("assets/modeltest/ball.obj", "assets/modeltest/ball.DDS");
    houseModel = new Model("assets/modeltest/house.obj", "assets/modeltest/house.DDS");

    //Create uvTemplate
    uvTemplate = new Sprite("assets/cubetest/uvtemplate.tga");
    uvTemplate->setPosition(-32.0f, -5.0f, 0.0f);
    uvTemplate->setScale(0.025f, 0.025f, 1.0f);
    uvTemplate->setRotation(0.0f, 0.0f, 0.0f);

    //Create cubemap
    cubeMap = new Sprite("assets/modeltest/cube.tga");
    cubeMap->setPosition(-8.0f, -5.0f, 0.0f);
    cubeMap->setScale(0.05f, 0.05f, 1.0f);
    cubeMap->setRotation(0.0f, 0.0f, 0.0f);

    //Create ballmap
    ballMap = new Sprite("assets/modeltest/ball.tga");
    ballMap->setPosition(6.0f, -5.0f, 0.0f);
    ballMap->setScale(0.015f, 0.015f, 1.0f);
    ballMap->setRotation(0.0f, 0.0f, 0.0f);

    //Create housemap
    houseMap = new Sprite("assets/modeltest/house.tga");
    houseMap->setPosition(28.0f, -5.0f, 0.0f);
    houseMap->setScale(0.01f, 0.01f, 1.0f);
    houseMap->setRotation(0.0f, 0.0f, 0.0f);
}

//Destructor
MyScene::~MyScene()
{
    delete uvTemplate;
    delete cubeMap;
    delete ballMap;
    delete houseMap;

    delete cube;
    delete cubeModel;
    delete ballModel;
    delete houseModel;
}

//Update function
void MyScene::update(float _deltaTime) {

    //X rotation
    static float rot_X = 0.0f;

    //Render all sprites
    renderer->renderSprite(uvTemplate);
    renderer->renderSprite(cubeMap);
    renderer->renderSprite(ballMap);
    renderer->renderSprite(houseMap);
    
    //Render all models
    renderer->renderCube(cube);
    cube->rotation.x = rot_X;

    renderer->renderModel(cubeModel, -8, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
    renderer->renderModel(ballModel, 6, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
    renderer->renderModel(houseModel, 28, 15, 0.0f, 2.0f, 2.0f, 2.0f, rot_X, 0.0f, 22.0f);

    //Update X rotation
    rot_X += 3.141592 / 5 * _deltaTime;
}