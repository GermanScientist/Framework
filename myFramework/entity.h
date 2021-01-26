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
#include <myFramework/vector.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		Vector position;
		Vector scale;
		Vector rotation;

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