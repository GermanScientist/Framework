#ifndef PLAYER_H
#define PLAYER_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>

#include <GL/glew.h>

#include <myFramework/entity.h>

class Player : public Entity
{
public:
	Player();
	virtual ~Player();
	void update(float _deltaTime);

private:

};

#endif /* PLAYER */