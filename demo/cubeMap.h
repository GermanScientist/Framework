#ifndef CUBEMAP_H
#define CUBEMAP_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/Entity.h>

class CubeMap : public Entity
{
public:
	CubeMap();
	virtual ~CubeMap();
	void update(float _deltaTime);

private:

};

#endif /* CUBEMAP_H */