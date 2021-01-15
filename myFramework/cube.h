#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/entity.h>
#include <myFramework/mesh.h>

class Cube : public Entity
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		Mesh* getMesh() { return mesh; };

	private:
		Mesh* mesh;
};

#endif /* CUBE_H */
