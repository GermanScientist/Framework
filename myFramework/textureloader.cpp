#include <myFramework/textureloader.h>

//The constructor
Textureloader::Textureloader()
{
	height = 0;
	width = 0;
}

//The destructor
Textureloader::~Textureloader()
{
	
}

//Load MBP file
GLuint Textureloader::loadCustomBMP(const char* _imagepath){

	printf("Reading image %s\n", _imagepath);

	//Data read from the header of the BMP file
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;
	unsigned int width, height;
	
	//Actual RGB data
	unsigned char* data;

	//Open the file
	FILE* file = fopen(_imagepath, "rb");
	if (!file){
		printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", _imagepath);
		getchar();
		
		return 0;
	}

	//Read the header, i.e. the 54 first bytes
	//If it's less than 54 bytes are read, problem
	if (fread(header, 1, 54, file)!=54){ 
		printf("Not a correct BMP file\n");
		fclose(file);
		
		return 0;
	}
	//A BMP files always begins with "BM"
	if (header[0]!='B' || header[1]!='M'){
		printf("Not a correct BMP file\n");
		fclose(file);
		
		return 0;
	}

	//Make sure this is a 24bpp file
	if (*(int*)&(header[0x1E])!=0) {
		printf("Not a correct BMP file\n");
		fclose(file); 
		
		return 0;
	}
	if (*(int*)&(header[0x1C])!=24) {
		printf("Not a correct BMP file\n");
		fclose(file);
		
		return 0;
	}

	//Read the information about the image
	dataPos = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width = *(int*)&(header[0x12]);
	height = *(int*)&(header[0x16]);

	//Some BMP files are misformatted, guess missing information
	//3 : one byte for each Red, Green and Blue component
	if (imageSize==0)    
		imageSize=width*height*3;
	//The BMP header is done that way
	if (dataPos==0)      
		dataPos=54; 

	//Create a buffer
	data = new unsigned char [imageSize];

	//Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);

	//Everything is in memory now, the file can be closed.
	fclose (file);

	//Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	
	//"Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	//Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	//OpenGL has now copied the data. Free our own version
	delete [] data;

	//Trillering filters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	
	//Generate mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);

	//Return the ID of the texture we just created
	return textureID;
}

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

//Load DDS file
GLuint Textureloader::loadDDS(const char* _imagepath){
	
	//Header characters
	unsigned char header[124];

	//Open the file
	FILE* file; 
	file = fopen(_imagepath, "rb");
	if (file == NULL){
		printf("%s could not be opened. Are you in the right directory ? Don't forget to read the FAQ !\n", _imagepath); getchar();
		return 0;
	}
   
	//Verify the type of file
	char filecode[4]; 
	fread(filecode, 1, 4, file);
	
	if (strncmp(filecode, "DDS ", 4) != 0) { 
		fclose(file);
		return 0; 
	}
	
	//Get the surface description
	fread(&header, 124, 1, file);

	unsigned int height = *(unsigned int*)&(header[8]);
	unsigned int width = *(unsigned int*)&(header[12]);
	unsigned int linearSize = *(unsigned int*)&(header[16]);
	unsigned int mipMapCount = *(unsigned int*)&(header[24]);
	unsigned int fourCC = *(unsigned int*)&(header[80]);
 
	unsigned char* buffer;
	unsigned int bufsize;
	
	//Conclude size including mipmaps
	bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize; 
	buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char)); 
	fread(buffer, 1, bufsize, file);
	
	//Close tje file
	fclose(file);

	unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4; 
	unsigned int format;
	switch(fourCC) 
	{ 
	case FOURCC_DXT1: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT; 
		break; 
	case FOURCC_DXT3: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT; 
		break; 
	case FOURCC_DXT5: 
		format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT; 
		break; 
	default: 
		free(buffer); 
		return 0; 
	}

	//Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	//"Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);	
	
	unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16; 
	unsigned int offset = 0;

	//Load mipmaps
	for (unsigned int level = 0; level < mipMapCount && (width || height); ++level) 
	{ 
		unsigned int size = ((width+3)/4) * ((height+3)/4) * blockSize; 
		glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height,  
			0, size, buffer + offset); 
	 
		offset += size; 
		width  /= 2; 
		height /= 2; 

		// Deal with Non-Power-Of-Two textures. This code is not included in the webpage to reduce clutter.
		if(width < 1) width = 1;
		if(height < 1) height = 1;
	} 

	//Free the buffer
	free(buffer); 

	//Return texture ID
	return textureID;
}

//Load TGA file
GLuint Textureloader::loadTGA(const std::string& _imagepath)
{
	std::cout << "Loading TGA: " << _imagepath << std::endl;

	//Open file location
	FILE* file;
	unsigned char type[4];
	unsigned char info[6];

	file = fopen(_imagepath.c_str(), "rb");

	if (!file) {
		std::cout << "error: unable to open file" << std::endl;
		return 0;
	}

	if (!fread(&type, sizeof(char), 3, file)) return 0;
	fseek(file, 12, SEEK_SET);
	if (!fread(&info, sizeof(char), 6, file)) return 0;

	//Image type needs to be 2 (color) or 3 (grayscale)
	if (type[1] != 0 || (type[2] != 2 && type[2] != 3))
	{
		std::cout << "error: image type neither color or grayscale" << std::endl;
		fclose(file);
		return 0;
	}

	//Get image data
	unsigned char* data;
	unsigned char bitdepth;

	width = info[0] + info[1] * 256;
	height = info[2] + info[3] * 256;
	bitdepth = info[4] / 8;

	if (bitdepth != 1 && bitdepth != 3 && bitdepth != 4) {
		std::cout << "bytecount not 1, 3 or 4" << std::endl;
		fclose(file);
		return 0;
	}

	//Check if the image's width and height is a power of 2.
	if ((width & (width - 1)) != 0) 
		std::cout << "warning: " << _imagepath << "’s width is not a power of 2" << std::endl;
	
	if ((height & (height - 1)) != 0) 
		std::cout << "warning: " << _imagepath << "’s height is not a power of 2" << std::endl;
	
	if (width != height) 
		std::cout << "warning: " << _imagepath << " is not square" << std::endl;

	//Set imagesize
	unsigned int imagesize = width * height * bitdepth;

	//Create a buffer
	data = new unsigned char[imagesize];

	//Read the actual data from the file into the buffer
	if (!fread(data, 1, imagesize, file)) 
		return 0;

	//Close the file
	fclose(file);

	//Create one OpenGL texture
	//Be sure to also delete it from where you called this with glDeleteTextures()
	GLuint textureID;
	glGenTextures(1, &textureID);

	//"Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	//Filter the Texture
	unsigned char filter = 1;
	switch (filter) {
	
	//No filtering.
	case 0:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
	
	//Linear filtering.
	case 1:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		break;
	
	//Bilinear filtering.
	case 2:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		break;
	
	//Trilinear filtering.
	case 3:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		break;
	
	//No filtering.
	default:
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		break;
	}

	//Wrapping
	//GL_REPEAT, GL_MIRRORED_REPEAT or GL_CLAMP_TO_EDGE
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//Handle transparency and grayscale and give the image to OpenGL
	switch (bitdepth) {
	case 4:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data);
		break;
	case 3:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
		break;
	case 1:
		glTexImage2D(GL_TEXTURE_2D, 0, GL_LUMINANCE, width, height, 0, GL_LUMINANCE, GL_UNSIGNED_BYTE, data);
		break;
	default:
		std::cout << "error: bitdepth not 4, 3, or 1" << std::endl;
		break;
	}

	//OpenGL has now copied the data. Free our own version
	delete[] data;

	//Return the ID of the texture we just created
	return textureID;
}