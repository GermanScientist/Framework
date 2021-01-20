#include <myFramework/shader.h>

//Constructor
Shader::Shader()
{

}

//Destructor
Shader::~Shader()
{
	// Cleanup VBO and shader
	glDeleteProgram(programID);
}

//Load 2D shaders
void Shader::load2DShaders() {
	programID = this->loadShaders("shaders/2D/sprite.vert", "shaders/2D/sprite.frag");;

	//Use our shader
	glUseProgram(programID);
	
	//Get a handle for our shader uniforms
	matrixID = glGetUniformLocation(programID, "MVP");
	textureID = glGetUniformLocation(programID, "textureSampler");

	vertexPositionID = glGetAttribLocation(programID, "vertexPosition");
	vertexUVID = glGetAttribLocation(programID, "vertexUV");
}

//Load 3D shoaders
void Shader::load3DShaders() {
	programID = this->loadShaders("shaders/3D/model.vert", "shaders/3D/model.frag");;

	//Use our shader
	glUseProgram(programID);

	//Get a handle for our shader uniforms
	matrixID = glGetUniformLocation(programID, "MVP");
	viewMatrixID = glGetUniformLocation(programID, "V");
	modelMatrixID = glGetUniformLocation(programID, "M");

	vertexPositionModelspaceID = glGetAttribLocation(programID, "vertexPosition_modelspace");
	vertexUVID = glGetAttribLocation(programID, "vertexUV");
	vertexNormalModelspaceID = glGetAttribLocation(programID, "vertexNormal_modelspace");

	textureID = glGetUniformLocation(programID, "myTextureSampler");
	vertexUVID = glGetAttribLocation(programID, "vertexUV");

	lightID = glGetUniformLocation(programID, "LightPosition_worldspace");
}

//Load shaders from file location
GLuint Shader::loadShaders(const std::string& _vertex_file_path, const std::string& _fragment_file_path)
{
	// Create the shaders
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// Read the Vertex Shader code from the file
	std::string vertexShaderCode;
	std::ifstream vertexShaderStream(_vertex_file_path.c_str(), std::ios::in);

	//Checks whether the vertex shader stream is open
	if (vertexShaderStream.is_open()) {
		std::string line = "";
		while (getline(vertexShaderStream, line)) {
			vertexShaderCode += "\n" + line;
		}
		vertexShaderStream.close();
	}
	else {
		printf("Can't to open %s.\n", _vertex_file_path.c_str());
		getchar();
		return 0;
	}

	// Read the Fragment Shader code from the file
	std::string fragmentShaderCode;
	std::ifstream fragmentShaderStream(_fragment_file_path.c_str(), std::ios::in);

	//Checks whether the vertex shader stream is open
	if (fragmentShaderStream.is_open()) {
		std::string line = "";
		while (getline(fragmentShaderStream, line)) {
			fragmentShaderCode += "\n" + line;
		}
		fragmentShaderStream.close();
	}
	else {
		printf("Can't to open %s.\n", _fragment_file_path.c_str());
		getchar();
		return 0;
	}

	GLint result = GL_FALSE;
	int infoLogLength;

	// Compile Vertex Shader
	printf("Compiling shader : %s\n", _vertex_file_path.c_str());
	char const* vertexSourcePointer = vertexShaderCode.c_str();
	glShaderSource(vertexShaderID, 1, &vertexSourcePointer, NULL);
	glCompileShader(vertexShaderID);

	// Check Vertex Shader
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0) {
		std::vector<char> vertexShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(vertexShaderID, infoLogLength, NULL, &vertexShaderErrorMessage[0]);
		printf("%s\n", &vertexShaderErrorMessage[0]);
	}

	// Compile Fragment Shader
	printf("Compiling shader : %s\n", _fragment_file_path.c_str());
	char const* fragmentSourcePointer = fragmentShaderCode.c_str();
	glShaderSource(fragmentShaderID, 1, &fragmentSourcePointer, NULL);
	glCompileShader(fragmentShaderID);

	// Check Fragment Shader
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &result);
	glGetShaderiv(fragmentShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0) {
		std::vector<char> fragmentShaderErrorMessage(infoLogLength + 1);
		glGetShaderInfoLog(fragmentShaderID, infoLogLength, NULL, &fragmentShaderErrorMessage[0]);
		printf("%s\n", &fragmentShaderErrorMessage[0]);
	}

	// Link the program
	printf("Linking program\n");
	GLuint programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	// Check the program
	glGetProgramiv(programID, GL_LINK_STATUS, &result);
	glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);

	if (infoLogLength > 0) {
		std::vector<char> programErrorMessage(infoLogLength + 1);
		glGetProgramInfoLog(programID, infoLogLength, NULL, &programErrorMessage[0]);
		printf("%s\n", &programErrorMessage[0]);
	}

	//Delete the shaders
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}