#ifndef VBOINDEXER_H
#define VBOINDEXER_H

#include <vector>
#include <map>

#include <glm/glm.hpp>
#include <string.h>

///@brief Indexes all the vertices, UVs and normals in the VBO
void indexVBO(
	std::vector<glm::vec3>& in_vertices,
	std::vector<glm::vec2>& in_uvs,
	std::vector<glm::vec3>& in_normals,

	std::vector<unsigned short>& out_indices,
	std::vector<glm::vec3>& out_vertices,
	std::vector<glm::vec2>& out_uvs,
	std::vector<glm::vec3>& out_normals
);

#endif