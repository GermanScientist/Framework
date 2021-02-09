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

		///@brief Generates and binds the buffers for the Mesh
		///@param _vertices A list of vectors representing the vertices.
		///@param _vertices A list of vectors representing the UV data.
		///@param _vertices A list of vectors representing the normals.
		///@return void
		void generateBuffers(std::vector<glm::vec3>& _vertices, std::vector<glm::vec2>& _uvs, std::vector<glm::vec3>& _normals);

		///@brief Generates and binds the buffers for the Mesh
		///@param _vertexBufferdata A list of floats representing the vertices.
		///@param _uvBufferdata A list of floats representing the UVs.
		///@return void
		void generateBuffers(std::vector<GLfloat>& _vertexBufferdata, std::vector<GLfloat>& _uvBufferdata);

		///@brief Gets the vertex buffer
		///@return vertexbuffer
		GLuint getVertexbuffer() { return vertexbuffer; };

		///@brief Gets the UV buffer
		///@return uvbuffer
		GLuint getUvbuffer() { return uvbuffer; };

		///@brief Gets the normal buffer
		///@return normalbuffer
		GLuint getNormalbuffer() { return normalbuffer; };

		///@brief Gets the vertices of the Mesh
		///@return vertices
		std::vector<glm::vec3> getVertices() { return vertices; };

		///@brief Gets the UVs of the Mesh
		///@return UVs
		std::vector<glm::vec2> getUvs() { return uvs; };

		///@brief Gets the normals of the Mesh
		///@return normals
		std::vector<glm::vec3> getNormals() { return normals; };

	private:
		///@brief The vertex buffer of the Mesh
		GLuint vertexbuffer;

		///@brief The UV buffer of the Mesh
		GLuint uvbuffer;

		///@brief The normal buffer of the Mesh
		GLuint normalbuffer;

		///@brief The vertex array ID of the Mesh
		GLuint vertexArrayID;

		///@brief The list of vertices of this Mesh
		std::vector<glm::vec3> vertices;

		///@brief The list of UVs of this Mesh
		std::vector<glm::vec2> uvs;

		///@brief The list of normals of this Mesh
		std::vector<glm::vec3> normals;

		///@brief The vertex buffer data of this Mesh
		std::vector<GLfloat> vertexBufferdata;

		///@brief The UV buffer data of this Mesh
		std::vector<GLfloat> uvBufferdata;
};

#endif /* MESH_H */