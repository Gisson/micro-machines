#include "Table.h"
#include "stdio.h"
Table::Table()
{
	setTexture(new Texture);
	getTexture()->loadBMP_custom(TABLE_FILENAME);
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
	glBindTexture(GL_TEXTURE_2D, getTexture()->getTexture());
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

	glPopMatrix();
}

void Table::update()
{
}