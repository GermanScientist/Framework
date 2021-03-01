#ifndef GRASSFLOOR_H
#define GRASSFLOOR_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/entity.h>

class GrassFloor : public Entity
{
public:
	GrassFloor();
	virtual ~GrassFloor();
	void update(float _deltaTime);

private:

};

#endif /* GRASSFLOOR_H */