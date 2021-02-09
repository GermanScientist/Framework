/**
 * @file objloader.h
 *
 * @brief The Objloader header file.
 *
 * This file is part of myFramework, a 3D OpenGL framework.
 *
 * - Copyright 2020 Jack Hulspas
 *   - Initial commit
 */

#ifndef OBJLOADER_H
#define OBJLOADER_H

#include <vector>
#include <stdio.h>
#include <string>
#include <cstring>

#include <glm/glm.hpp>

///@brief Reads the .OBJ file and fills the given lists.
///@param _path The file location of the .OBJ that's supposed to be loaded.
///@param _out_vertices The list of vertices that will be filled.
///@param _out_uvs The list of UVs that will be filled.
///@param _out_normals The list of normals that will be filled.
///@return bool.
bool loadOBJ(const char* _path, std::vector<glm::vec3> &_out_vertices,  std::vector<glm::vec2> &_out_uvs,  std::vector<glm::vec3> &_out_normals);

#endif