#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <cstdio>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/euler_angles.hpp>

#include <string>

#include <GL/glew.h>
#include <myFramework/material.h>
#include <myFramework/objloader.h>

class Model
{
	public:
		Model(const char* _path, const char* _imagepath);
		virtual ~Model();

		GLuint getVertexbuffer() { return vertexbuffer; };
		GLuint getUvbuffer() { return uvbuffer; };
		GLuint getNormalbuffer() { return normalbuffer; };
		
		std::vector<glm::vec3> getVertices() { return vertices; };
		std::vector<glm::vec2> getUvs() { return uvs; };
		std::vector<glm::vec3> getNormals() { return normals; };

		Material* getMaterial() { return material; };

		unsigned int getWidth() { return width; };
		unsigned int getHeight() { return height; };

		glm::vec3 position;
		glm::vec3 scale;
		glm::vec3 rotation;

		void setPosition(float _x, float _y, float _z) {
			position.x = _x;
			position.y = _y;
			position.z = _z;
		}

		void setScale(float _x, float _y, float _z) {
			scale.x = _x;
			scale.y = _y;
			scale.z = _z;
		}

		void setRotation(float _x, float _y, float _z) {
			rotation.x = _x;
			rotation.y = _y;
			rotation.z = _z;
		}

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint normalbuffer;

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

		Material* material;

		unsigned int width;
		unsigned int height;
};

#endif /* MODEL_H */
