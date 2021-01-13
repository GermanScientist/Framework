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
#include <myFramework/Entity.h>

class Cube : public Entity
{
	public:
        Cube(const char* _imagepath);
		virtual ~Cube();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };

		Material* getMaterial() { return material; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;

		void setPosition(float _x, float _y, float _z) {
			position.x = _x;
			position.y = _y;
			position.z = _z;
		}

		void setScale(float _x, float _y, float _z) {
			scale.x = _x;
			scale.y = _y;
			scale.z = _z;
		}

		void setRotation(float _x, float _y, float _z) {
			rotation.x = _x;
			rotation.y = _y;
			rotation.z = _z;
		}

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint vertexArrayID;

		Material* material;

		unsigned int width;
		unsigned int height;
};

#endif /* CUBE_H */
