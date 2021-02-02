#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/entity.h>

class Sprite : public Entity
{
	public:
		Sprite(const std::string& _imagepath);
		virtual ~Sprite();

	private:

};

#endif /* SPRITE_H */
