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
		Model(const char* _path, const char* _imagepath);
		virtual ~Model();

		Material* getMaterial() { return material; };
		Mesh* getMesh() { return mesh; };

	private:
		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals;

		Material* material;
		Mesh* mesh;
};

#endif /* MODEL_H */
