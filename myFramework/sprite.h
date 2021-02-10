/**
 * @file sprite.h
 *
 * @brief The Sprite header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/mesh.h>
#include <myFramework/material.h>

class Sprite
{
	public:
		///@brief Constructor of the Sprite.
		///@param _imagepath The file location of the texture.
		Sprite(const std::string& _imagepath);

		///@brief Destructor of the Sprite.
		virtual ~Sprite();

		///@brief Gets the material of the Sprite.
		///@return Material* material.
		Material* getMaterial() { return material; };

		///@brief Gets the mesh of the Sprite.
		///@return Mesh* mesh.
		Mesh* getMesh() { return mesh; }

	private:
		///@brief The material of the Sprite.
		Material* material;

		///@brief The material of the Mesh.
		Mesh* mesh;
};

#endif /* SPRITE_H */
