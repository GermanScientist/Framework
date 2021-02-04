#ifndef MYBALL_H
#define MYBALL_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/Entity.h>

class MyBall : public Entity
{
public:
	MyBall();
	virtual ~MyBall();
	void update(float _deltaTime);

private:

};

#endif /* MYBALL_H */