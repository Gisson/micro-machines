#pragma once
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
#include "BmpRead.h"


class Texture {
private:
	BmpRead *bmp;
	GLuint _tex;
public:
	Texture();
	~Texture();
	void loadBMP_custom(char *imagepath);
	void setTexture(GLuint);
	GLuint getTexture();
};

