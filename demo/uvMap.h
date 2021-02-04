#ifndef UVMAP_H
#define UVMAP_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/Entity.h>

class UvMap : public Entity
{
public:
	UvMap();
	virtual ~UvMap();
	void update(float _deltaTime);

private:

};

#endif /* UVMAP_H */