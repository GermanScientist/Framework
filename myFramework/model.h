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

#include <myFramework/entity.h>
#include <myFramework/mesh.h>

class Model : public Entity
{
	public:
		Model(const char* _path, const char* _imagepath);
		virtual ~Model();

		Mesh* getMesh() { return mesh; };

	private:
		Mesh* mesh;
};

#endif /* MODEL_H */
