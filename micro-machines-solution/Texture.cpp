
#include "Texture.h"

Texture::Texture()
{
}

Texture::~Texture()
{
}

int Texture::loadTexture(char * path)
{
	char* data = 0;
	std::ifstream file;
	size_t size = 0;
	file.open(path, std::ios::in | std::ios::binary);
	

	file.seekg(0, std::ios::end);
	size = file.tellg();
	std::cout << "File size: " << size << std::endl;
	file.seekg(0, std::ios::beg);

	data = new char[size - 8 + 1];
	file.seekg(8); // skip the header
	file.read(data, size - 8);
	data[size] = '\0';
	std::cout << "Data size: " << file.tellg() << std::endl;
	// Create one OpenGL texture
	GLuint textureID;

	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
//#ifdef __linux__
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//#else
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
//#endif

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	std::cout << "LOAD SUCCESS" << std::endl;


	return 0;
}
