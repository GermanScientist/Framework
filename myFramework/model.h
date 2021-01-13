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
#include <myFramework/objloader.h>
#include <myFramework/Entity.h>

class Model : public Entity
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

	private:
		GLuint vertexbuffer;
		GLuint uvbuffer;
		GLuint normalbuffer;

		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;
};

#endif /* MODEL_H */
