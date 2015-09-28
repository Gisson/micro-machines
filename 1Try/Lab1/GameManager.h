
#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <GL/glut.h>

	class Game_manager {

	public:
		Game_manager();
		void display();
		void reshape(GLsizei h,GLsizei w);
		void keyPressed();
		void onTimer();
		void idle();
		void update();
		void init();
	};

#endif