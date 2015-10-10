
#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__

#include <GL/glut.h>
#include "Table.h"
#include "Car.h"
#include "Orange.h"
#include "Roadside.h"

	class Game_manager {
	private:
		Table _table;
		Car _vrum;
		Roadside _road;
		Orange _mrOrange[3];
	public:
		Game_manager();
		void display();
		void reshape(GLsizei h,GLsizei w);
		void keyPressed();
		void onTimer();
		void idle();
		void update(double delta);
		void init();
		void setTable(Table t);
		Table getTable();
	};

#endif