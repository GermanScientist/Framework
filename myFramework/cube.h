#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/Entity.h>

class Cube : public Entity
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint vertexArrayID;
};

#endif /* CUBE_H */
