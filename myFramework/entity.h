#ifndef ENTITY_H
#define ENTITY_H

#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <myFramework/material.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

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

		Material* getMaterial() { return material; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };
		
		std::string getType() { return type; };

	private:
		
	protected:
		Material* material;

		unsigned int width;
		unsigned int height;

		std::string type;
};

#endif /* ENTITY_H */