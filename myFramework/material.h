#ifndef MATERIAL_H
#define MATERIAL_H

#include <iostream>
#include <cstdio>

#include <GL/glew.h>

#include <myFramework/textureloader.h>

class Material
{
	public:
		Material(const char* _imagepath);
		virtual ~Material();

		GLuint getTexture() { return texture; };

	private:
		GLuint texture;
};

#endif /* MATERIAL_H */