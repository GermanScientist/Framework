#ifndef MYHOUSE_H
#define MYHOUSE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/Entity.h>

class MyHouse : public Entity
{
public:
	MyHouse();
	virtual ~MyHouse();
	void update(float _deltaTime);

private:

};

#endif /* MYHOUSE_H */