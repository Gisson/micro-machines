#pragma once
#include <iostream>
#include <stdio.h>
#include <GL/glut.h>

class BmpRead {
private:
	 char* _fileName;
	 GLuint _width, _height;
	 char* _data;

public:
	BmpRead(char*);
	GLuint getWidth();
	GLuint getHeight();
	char* getFileName();
	char* getData();
	void setFileName(char*);
	char* load();
};