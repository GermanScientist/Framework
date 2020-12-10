#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstdio>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/material.h>

class Cube
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };

		Material* getMaterial() { return material; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint vertexArrayID;

		Material* material;

		unsigned int width;
		unsigned int height;
};

#endif /* CUBE_H */
