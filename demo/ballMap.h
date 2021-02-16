#ifndef BALLMAP_H
#define BALLMAP_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/sprite.h>
#include <myFramework/entity.h>

class BallMap : public Entity
{
public:
	BallMap();
	virtual ~BallMap();
	void update(float _deltaTime);

private:

};

#endif /* BALLMAP_H */