/**
 * @file model.h
 *
 * @brief The Model header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstdio>
#include <vector>

#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>

#include <myFramework/mesh.h>
#include <myFramework/material.h>
#include <myFramework/objloader.h>

class Model
{
	public:
		///@brief Constructor of the Model
		///@param _path The file location of the .obj file.
		///@param _imagepath The file location of the texture.
		Model(const char* _path, const char* _imagepath);

		///@brief Destructor of the Model
		virtual ~Model();

		///@brief Gets the material of this Model.
		///@return Material* material.
		Material* getMaterial() { return material; };

		///@brief Gets the mesh of this Model.
		///@return Mesh* mesh.
		Mesh* getMesh() { return mesh; };

	private:
		///@brief List of vertices of this Model.
		std::vector<glm::vec3> vertices;

		///@brief List of UVs of this Model.
		std::vector<glm::vec2> uvs;

		///@brief List of normals of this Model.
		std::vector<glm::vec3> normals;

		///@brief The material of this Model.
		Material* material;

		///@brief The mesh of this Model.
		Mesh* mesh;
};

#endif /* MODEL_H */
