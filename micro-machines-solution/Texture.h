#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#pragma once
#include <GL/glut.h>

class Texture {
public:
	Texture();
	~Texture();
	static GLuint loadBMP_custom(const char *imagepath);
};

#endif