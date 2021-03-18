/**
 * @file mesh.h
 *
 * @brief The Mesh header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef MESH_H
#define MESH_H

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

class Mesh
{
	public:
		///@brief Constructor of Mesh.
		Mesh();

		///@brief Destructor of Mesh.
		virtual ~Mesh();

		///@brief Generates the Mesh using it's vertices, uv's and normals.
		///@return void
		void generateMesh();

		///@brief Gets the vertex buffer.
		///@return GLuint vertexbuffer.
		GLuint getVertexbuffer() { return vertexbuffer; };

		///@brief Gets the UV buffer.
		///@return GLuint uvbuffer.
		GLuint getUvbuffer() { return uvbuffer; };

		///@brief Gets the normal buffer.
		///@return GLuint normalbuffer.
		GLuint getNormalbuffer() { return normalbuffer; };

		///@brief The list of vertices of this Mesh.
		std::vector<glm::vec3> vertices;

		///@brief The list of UVs of this Mesh.
		std::vector<glm::vec2> uvs;

		///@brief The list of normals of this Mesh.
		std::vector<glm::vec3> normals;

	private:
		///@brief The vertex buffer of the Mesh.
		GLuint vertexbuffer;

		///@brief The UV buffer of the Mesh.
		GLuint uvbuffer;

		///@brief The normal buffer of the Mesh.
		GLuint normalbuffer;

		///@brief The vertex array ID of the Mesh.
		GLuint vertexArrayID;

		///@brief The vertex buffer data of this Mesh.
		std::vector<GLfloat> vertexBufferdata;

		///@brief The UV buffer data of this Mesh.
		std::vector<GLfloat> uvBufferdata;
};

#endif /* MESH_H */