/**
 * @file cube.h
 *
 * @brief The Cube header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <cstdio>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/mesh.h>
#include <myFramework/material.h>

class Cube
{
	public:
		///@brief Constructor of the Cube
		///@param _imagepath The file location of the image.
        Cube(const char* _imagepath);

		///@brief Destructor of the Cube
		virtual ~Cube();

		///@brief Get the mesh of the Cube
		///@return mesh
		Mesh* getMesh() { return mesh; };

		///@brief Get the material of the Cube
		///@return material
		Material* getMaterial() { return material; };

	private:
		///@brief The material of the Cube
		Material* material;

		///@brief The mesh of the Cube
		Mesh* mesh;
};

#endif /* CUBE_H */
