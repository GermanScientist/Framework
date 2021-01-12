#include "myScene.h"

//Constructor
MyScene::MyScene(Renderer* _renderer)
{
    renderer = _renderer;

    cube = new Cube("assets/cubetest/uvtemplate.DDS");
    cubeModel = new Model("assets/modeltest/cube.obj", "assets/modeltest/cube.DDS");
    ballModel = new Model("assets/modeltest/ball.obj", "assets/modeltest/ball.DDS");
    houseModel = new Model("assets/modeltest/house.obj", "assets/modeltest/house.DDS");

    uvTemplate = new Sprite("assets/cubetest/uvtemplate.tga");
    cubeMap = new Sprite("assets/modeltest/cube.tga");
    ballMap = new Sprite("assets/modeltest/ball.tga");
    houseMap = new Sprite("assets/modeltest/house.tga");
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

    // Render all models/sprites (Type*, xpos, ypos, zpos, xscale, yscale, zscale, xrot, yrot, zrot)
    renderer->renderSprite(uvTemplate, -32, -5, 0.0f, 0.025f, 0.025f, 1.0f, 0.0f);
    renderer->renderSprite(cubeMap, -8, -5, 0.0f, 0.050f, 0.050f, 1.0f, 0.0f);
    renderer->renderSprite(ballMap, 6, -5, 0.0f, 0.015f, 0.015f, 1.0f, 0.0f);
    renderer->renderSprite(houseMap, 28, -5, 0.0f, 0.010f, 0.010f, 1.0f, 0.0f);

    renderer->renderCube(cube, -32, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
    renderer->renderModel(cubeModel, -8, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
    renderer->renderModel(ballModel, 6, 10, 0.0f, 3.0f, 3.0f, 3.0f, rot_X, 0.0f, 22.0f);
    renderer->renderModel(houseModel, 28, 15, 0.0f, 2.0f, 2.0f, 2.0f, rot_X, 0.0f, 22.0f);

    //Update X rotation
    rot_X += 3.141592 / 5 * _deltaTime;
}