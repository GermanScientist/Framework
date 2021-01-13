#ifndef MYSCENE_H
#define MYSCENE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/cube.h>
#include <myFramework/time.h>
#include <myFramework/scene.h>

class MyScene : public Scene
{
public:
    MyScene();
	virtual ~MyScene();
	void update(float _deltaTime);

private:
    Cube* cube;
    Model* cubeModel;
    Model* ballModel;
    Model* houseModel;

    Sprite* uvTemplate;
    Sprite* cubeMap;
    Sprite* ballMap;
    Sprite* houseMap;

    float rotationSpeed;
};

#endif /* MYSCENE_H */