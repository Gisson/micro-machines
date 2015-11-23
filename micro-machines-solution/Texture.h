#pragma once
#include <GL/glut.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <cstdio>
class Texture {
private:

public:
	Texture();
	~Texture();
	int loadTexture(char* path);

};