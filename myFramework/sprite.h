#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/mesh.h>
#include <myFramework/material.h>

class Sprite
{
	public:
		Sprite(const std::string& _imagepath);
		virtual ~Sprite();

		Material* getMaterial() { return material; };
		Mesh* getMesh() { return mesh; }

	private:
		Material* material;
		Mesh* mesh;
};

#endif /* SPRITE_H */
