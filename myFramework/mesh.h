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

#include <myFramework/objloader.h>

class Mesh
{
	public:
		Mesh();
		virtual ~Mesh();

		void loadObject(const char* _path);
		void generateBuffers(std::string _type);

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

		void createCubeData();
};

#endif /* MESH_H */