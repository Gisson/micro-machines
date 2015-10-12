#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include "Orange.h"
#include <GL/glut.h>
#include "Table.h"
#include "Car.h"

#include "Roadside.h"

	class Game_manager {
	private:
		GameObject *_obj[3];
		Table _table;
		Car _vrum;
		Roadside _road;
		Orange _mrOrange[3];
		int oldTimeSinceStart = 0;
	public:
		Game_manager();
		void display();
		void reshape(GLsizei h,GLsizei w);
		void keyPressed(int key, int x, int y);
		void onTimer();
		void idle();
		void update(double delta);
		void init();
		void setTable(Table t);
		Table getTable();
	};

#endif