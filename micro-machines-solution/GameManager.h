#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include "Orange.h"
#include "Butter.h"
#include <GL/glut.h>
#include "Table.h"
#include "Car.h"

#include "Roadside.h"

	class Game_manager {
	private:
		GameObject *_obj[3];
		Table _table = Table();
		Car _vrum = Car();
		Roadside _road = Roadside();
		Orange _mrOrange[3];
		Butter _mrButter[5];
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