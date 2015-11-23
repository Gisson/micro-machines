#include "Table.h"



Table::Table()
{
	glEnable(GL_TEXTURE_2D);
	GLuint tex_2d;

	tex_2d = SOIL_load_OGL_texture
		(
			"mesatextura.png",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MULTIPLY_ALPHA
			);

	if (0 == tex_2d)
	{
		std::cout << "SOIL loading error: '%s'\n", SOIL_last_result();
	}

	setTexture(tex_2d);
	glDisable(GL_TEXTURE_2D);
}

Table::~Table()
{
}


void Table::draw()
{
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, getTexture());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-3.0f, -3.0f, 3.0f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-3.0f, 3.0f, 3.0f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(3.0f, 3.0f, 3.0f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(3.0f, -3.0f, 3.0f);
	glEnd();
	

	//glColor3f(0.98f, 0.6f, 0.7f);
	//glutSolidCube(TABLE_SIZE);
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void Table::update()
{
}
