#ifndef CUBEEXAMPLE_H
#define CUBEEXAMPLE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/entity.h>

class CubeExample : public Entity
{
public:
	CubeExample();
	virtual ~CubeExample();
	void update(float _deltaTime);

private:

};

#endif /* CUBEEXAMPLE_H */