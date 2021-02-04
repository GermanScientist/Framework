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
		Mesh();
		virtual ~Mesh();

		void generateModelBuffers(std::vector<glm::vec3>& _vertices, std::vector<glm::vec2>& _uvs, std::vector<glm::vec3>& _normals);
		void generateCubeBuffers(std::vector<GLfloat>& _vertexBufferdata, std::vector<GLfloat>& _uvBufferdata);
		void generateSpriteBuffers(std::vector<GLfloat>& _vertices, std::vector<GLfloat>& _uvs);

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };
		GLuint getNormalbuffer() { return normalbuffer; };

		std::vector<glm::vec3> getVertices() { return vertices; };
		std::vector<glm::vec2> getUvs() { return uvs; };
		std::vector<glm::vec3> getNormals() { return normals; };

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint normalbuffer;

		GLuint vertexArrayID;

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

		std::vector<GLfloat> vertexBufferdata;
		std::vector<GLfloat> uvBufferdata;
};

#endif /* MESH_H */