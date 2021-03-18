#ifndef MYSCENE_H
#define MYSCENE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/scene.h>
#include <myFramework/vector.h>

#include "house.h"

class MyScene : public Scene
{
public:
    MyScene();
	virtual ~MyScene();
	void update(float _deltaTime);

private:

    House* house;
};

#endif /* MYSCENE_H */