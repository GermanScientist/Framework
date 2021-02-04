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
#include <myFramework/mesh.h>
#include <myFramework/vector.h>

#include <myFramework/model.h>
#include <myFramework/sprite.h>
#include <myFramework/cube.h>

class Entity
{
	public:
		Entity();
		virtual ~Entity();

		Vector position;
		Vector scale;
		Vector rotation;

		Material* getMaterial() { return material; };
		Mesh* getMesh() { return mesh; };

		Model* getModel() { return model; };
		Sprite* getSprite() { return sprite; };
		Cube* getCube() { return cube; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

		void addModel(const char* _path, const char* _imagepath);
		void addSprite(const std::string& _imagepath);
		void addCube(const char* _imagepath);

	private:
		Model* model;
		Sprite* sprite;
		Cube* cube;
		
	protected:
		Material* material;
		Mesh* mesh;

		unsigned int width;
		unsigned int height;
};

#endif /* ENTITY_H */