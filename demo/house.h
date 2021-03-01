#ifndef HOUSE_H
#define HOUSE_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/entity.h>

class House : public Entity
{
public:
	House();
	virtual ~House();
	void update(float _deltaTime);

private:

};

#endif /* HOUSE_H */