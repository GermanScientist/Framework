#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include <glm/glm.hpp>

bool loadOBJ(const char* _path, std::vector<glm::vec3> &_out_vertices,  std::vector<glm::vec2> &_out_uvs,  std::vector<glm::vec3> &_out_normals);

#endif