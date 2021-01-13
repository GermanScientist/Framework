#include <myFramework/sprite.h>

//Constructor
Sprite::Sprite(const std::string& _imagepath)
{
	//Create a material
	material = new Material();
	material->loadTGA(_imagepath);
	material->load2DShaders();

	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A sprite has 1 face (quad) with 2 triangles each, so this makes 1*2=2 triangles, and 2*3 vertices
	GLfloat g_vertex_buffer_data[18] = {
		 0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f,
		-0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f,
		-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,

		-0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,
		 0.5f * material->getWidth(),  0.5f * material->getHeight(), 0.0f,
		 0.5f * material->getWidth(), -0.5f * material->getHeight(), 0.0f
	};

	// Two UV coordinates for each vertex.
	GLfloat g_uv_buffer_data[12] = {
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,

		0.0f, 0.0f,
		1.0f, 0.0f,
		1.0f, 1.0f
	};

	//Generate buffers
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}

//Destructor
Sprite::~Sprite()
{
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);

	delete material;
}