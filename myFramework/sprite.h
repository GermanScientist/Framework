#ifndef SPRITE_H
#define SPRITE_H

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

class Sprite : public Entity
{
	public:
		Sprite(const std::string& _imagepath);
		virtual ~Sprite();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };
		
		Material* getMaterial() { return material; };
		
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
		Material* material;

		GLuint vertexbuffer;
		GLuint uvbuffer;
};

#endif /* SPRITE_H */
