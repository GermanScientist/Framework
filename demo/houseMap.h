#ifndef HOUSEMAP_H
#define HOUSEMAP_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/Entity.h>

class HouseMap : public Entity
{
public:
	HouseMap();
	virtual ~HouseMap();
	void update(float _deltaTime);

private:

};

#endif /* HOUSEMAP_H */