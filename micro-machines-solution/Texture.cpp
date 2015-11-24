#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

GLuint Texture::loadBMP_custom(const char *imagepath) {
	

	/*GLuint textureID;

	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	
#ifdef __linux__
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
#else
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, data);
#endif

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	std::cout << "LOAD SUCCESS" << std::endl;
	_tex = textureID;
	return textureID;*/
	return 0;
}

void Texture::setTexture(GLuint tex)
{
	_tex = tex;
}

GLuint Texture::getTexture()
{
	return _tex;
}
