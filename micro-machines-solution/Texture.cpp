#include "Texture.h"


Texture::Texture()
{
}


Texture::~Texture()
{
}

void Texture::loadBMP_custom(char *imagepath) {
	glEnable(GL_TEXTURE_2D);
	bmp = new BmpRead(imagepath);
	bmp->load();
	glGenTextures(1, &_tex);
	glBindTexture(GL_TEXTURE_2D, _tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		bmp->getWidth(), bmp->getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp->getData());
	glDisable(GL_TEXTURE_2D);
}

void Texture::setTexture(GLuint tex)
{
	_tex = tex;
}

GLuint Texture::getTexture()
{
	return _tex;
}
