#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <GL/glut.h>
#include <SOIL.h>

class Texture  {
private:
	GLuint _tex;

public:
	Texture(GLuint);
	~Texture();
};


#endif