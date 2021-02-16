#ifndef MYCUBE_H
#define MYCUBE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/entity.h>
#include "myBall.h"

class MyCube : public Entity
{
public:
    MyCube();
	virtual ~MyCube();
	void update(float _deltaTime);

private:
	MyBall* myBall;
};

#endif /* MYCUBE_H */