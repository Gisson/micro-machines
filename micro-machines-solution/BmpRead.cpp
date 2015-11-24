#include "BmpRead.h"

BmpRead::BmpRead(char *filename)
{
	_fileName = filename;
}

GLuint BmpRead::getWidth()
{
	return _width;
}

GLuint BmpRead::getHeight()
{
	return _height;
}

char * BmpRead::getFileName()
{
	return _fileName;
}

char * BmpRead::getData()
{
	return _data;
}

void BmpRead::setFileName(char *filename)
{
	_fileName = filename;
}

char* BmpRead::load()
{
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int imageSize;


	FILE * file = fopen(_fileName, "rb");
	if (!file) {
		printf("Image could not be opened!\n");
		return 0;
	}
	if (fread(header, 1, 54, file) != 54) {
		printf("Not a correct BMP file!\n");
		return false;
	}
	if (header[0] != 'B' || header[1] != 'M') {
		printf("Not a correct BMP file\n");
		return 0;
	}
	dataPos = *(int*)&(header[10]);
	imageSize = *(int*)&(header[34]);
	_width = *(int*)&(header[18]);
	_height = *(int*)&(header[22]);

	imageSize = _width*_height * 3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

	_data = new char[imageSize];

	size_t a;
	if ((a = fread(_data, sizeof(unsigned char), imageSize, file)) != imageSize)
		std::cout << a << " " << imageSize << " The Image could not be loaded" << std::endl;
	fclose(file);
	
	std::cout <<"Load success" << std::endl;
	return _data;
}
