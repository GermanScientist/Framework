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
#include <myFramework/scene.h>
#include <myFramework/vector.h>

#include "cubeExample.h"

#include "myCube.h"
#include "myBall.h"
#include "myHouse.h"

#include "uvMap.h"
#include "cubeMap.h"
#include "ballMap.h"
#include "houseMap.h"

class MyScene : public Scene
{
public:
    MyScene();
	virtual ~MyScene();
	void update(float _deltaTime);

private:

    CubeExample* cubeExample;

    MyCube* myCube;
    MyBall* myBall;
    MyHouse* myHouse;

    UvMap* uvMap;
    CubeMap* cubeMap;
    BallMap* ballMap;
    HouseMap* houseMap;

    float rotationSpeed;
};

#endif /* MYSCENE_H */