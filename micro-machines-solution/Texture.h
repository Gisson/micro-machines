

#pragma once
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>


class Texture {
private:
	GLuint _tex;
public:
	Texture();
	~Texture();
	GLuint loadBMP_custom(const char *imagepath);
	void setTexture(GLuint);
	GLuint getTexture();
};

