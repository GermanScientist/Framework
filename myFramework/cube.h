#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/mesh.h>
#include <myFramework/material.h>

class Cube
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		Mesh* getMesh() { return mesh; };
		Material* getMaterial() { return material; };

	private:
		Material* material;
		Mesh* mesh;
};

#endif /* CUBE_H */
