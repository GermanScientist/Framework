#include "myScene.h"

//Constructor
MyScene::MyScene()
{
    //----CREATE FLOOR----
    EntityContainer* floor = new EntityContainer(); //Create entity

    floor->rotation = Vector3(0.0f, 0.0f, 22.0f); //Set entity rotation

    floor->addModel(); //Add a model to the entity
    floor->getModel()->loadTexture("assets/demo/grass/GrassTexture.dds"); //Load texture to model
    floor->getModel()->loadObject("assets/demo/grass/grass.obj"); //Load .obj file to model

    addChild(floor); //Add floor to the list of children of this scene


    //----CREATE CUBE----
    EntityContainer* cube = new EntityContainer(); //Create entity

    cube->position = Vector3(18.0f, -3.9f, -20.0f); //Set entity position
    cube->scale = Vector3(3.0f, 3.0f, 3.0f); //Set entity scale
    cube->rotation = Vector3(0.0f, 0.0f, 22.0f); //Set entity rotation

    cube->addModel(); //Add a model to the entity
    cube->getModel()->loadTexture("assets/demo/cube/cube.dds"); //Load texture to model

    if (false) //If true: Load .obj file
        cube->getModel()->loadObject("assets/demo/cube/cube.obj"); //Load .obj file to model
    else //If false: load cube (gives error popup)
        cube->getModel()->loadCube(); //Load cube to the model

    addChild(cube); //Add cube to the list of children of this scene

    
    //----CREATE FLOOR----
    EntityContainer* house = new EntityContainer(); //Create entity

    house->position = Vector3(-10.0f, -0.4f, 5.0f); //Set entity position
    house->scale = Vector3(3.5f, 3.5f, 3.5f); //Set entity scale
    house->rotation = Vector3(0.0f, 0.0f, 22.0f); //Set entity rotation

    house->addModel(); //Add model to entity
    house->getModel()->loadTexture("assets/demo/house/House.dds"); //Load texture to the model.
    house->getModel()->loadObject("assets/demo/house/house.obj"); //Load obj to the model.

    addChild(house); //Add floor to the list of children of this scene

    //----SET CAMERA POSITION----
    this->getCamera()->position = Vector3(0, -25, -60);
}

//Destructor
MyScene::~MyScene()
{
    //Remove house
    removeChild(house);
    delete house;
}

//Update function
void MyScene::update(float _deltaTime) {

}