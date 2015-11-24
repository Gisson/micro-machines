#include "Table.h"
#include "stdio.h"
Table::Table()
{

}

Table::~Table()
{

}


void Table::draw()
{

	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	{

		/* comment the material*/
		GLfloat amb[] = { 0.0f,0.0f,0.52f,1.0f };
		GLfloat diff[] = { 0.01f,0.01f,0.01f,1.0f };
		GLfloat spec[] = { 0.5f,0.5f,0.5f,1.0f };
		GLfloat shine = 32.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, amb);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, spec);
		glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, shine);
	}

	glBindTexture(GL_TEXTURE_2D, nuno);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	for (int i = -TABLE_SIZE / 2; i < TABLE_SIZE / 2; i++) {
		for (int j = -TABLE_SIZE / 2; j < TABLE_SIZE / 2; j++) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(i, j, TABLE_SIZE / 2);
			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(i+1, j, TABLE_SIZE / 2);
			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(i + 1, j + 1, TABLE_SIZE / 2);
			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(i, j + 1, TABLE_SIZE / 2);
		}
	}
	glEnd();
	glDisable(GL_TEXTURE_2D);

	//glColor3f(0.98f, 0.6f, 0.7f);
	//glutSolidCube(TABLE_SIZE);

	glPopMatrix();
}

void Table::update()
{
}

void Table::loadText() {
	bmp = new BmpRead("../wood.bmp");
	bmp->load();
	glGenTextures(1, &nuno);
	glBindTexture(GL_TEXTURE_2D, nuno);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
		bmp->getWidth(), bmp->getHeight(), 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp->getData());
}
