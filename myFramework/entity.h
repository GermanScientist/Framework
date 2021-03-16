/**
 * @file entity.h
 *
 * @brief The Entity header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

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
		///@brief Constructor of this Entity
		Entity();

		///@brief Destructor of this Entity
		virtual ~Entity();

		///@brief The position of this Entity
		Vector position;

		///@brief The scale of this Entity
		Vector scale;

		///@brief The rotation of this Entity
		Vector rotation;

		///@brief Get the material of this Entity
		///@return Material*  material
		Material* getMaterial() { return material; };

		///@brief Get the mesh of this Entity
		///@return Mesh* mesh
		Mesh* getMesh() { return mesh; };

		///@brief Get the model of this Entity
		///@return Model* model
		Model* getModel() { return model; };

		///@brief Get the sprite of this Entity
		///@return Sprite* sprite
		Sprite* getSprite() { return sprite; };

		///@brief Get the cube of this Entity
		///@return Cube* cube
		Cube* getCube() { return cube; };

		///@brief Get the width of this Entity
		///@return unsigned int width
		unsigned int getWidth() { return width; };

		///@brief Get the height of this Entity
		///@return unsigned int height
		unsigned int getHeight() { return height; };

		///@brief Adds a child to the list of children in this Entity
		///@param _child The child the user wants to add.
		///@return void
		void addChild(Entity* _child);

		///@brief Removes a child from the list of children in this Entity
		///@param _child The child the user wants to remove.
		///@return void
		void removeChild(Entity* _child);

		///@brief Adds a model to this Entity
		///@param _path The file location of the .obj file.
		///@param _imagepath The file location of the texture.
		///@return void
		void addModel();

		///@brief Adds a sprite to this Entity
		///@param _imagepath The file location of the texture.
		///@return void
		void addSprite(const std::string& _imagepath);

		///@brief Adds a cube to this Entity
		///@param _imagepath The file location of the texture.
		///@return void
		void addCube(const char* _imagepath);

		///@brief Gets the list of children of this Entity
		///@return std::vector<Entity*> children
		std::vector<Entity*> getChildren() { return children; };

		///@brief The update function for the children of this Entity
		///@return void
		virtual void update(float deltaTime) = 0;

	private:

		///@brief The parent of this Entity
		Entity* parent;

		///@brief The list of children of this Entity
		std::vector<Entity*> children;

		///@brief The model of this Entity
		Model* model;

		///@brief The sprite of this Entity
		Sprite* sprite;

		///@brief The cube of this Entity
		Cube* cube;
		
	protected:
		///@brief The material of this Entity
		Material* material;

		///@brief The mesh of this Entity
		Mesh* mesh;

		///@brief The width of this Entity
		unsigned int width;

		///@brief The height of this Entity
		unsigned int height;
};

#endif /* ENTITY_H */