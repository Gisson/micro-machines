#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include <memory>
#include <vector>
#include <GL/glut.h>
#include <algorithm>
#include "Orange.h"
#include "Butter.h"

#include "Table.h"
#include "Car.h"

#include "Roadside.h"

	class Game_manager {
	private:
		Table* _table;
		Car* _vrum;
		Roadside* _road;
		Orange* _mrOrange[3];
		Butter* _mrButter[5];
		bool _isWired = false;
		int oldTimeSinceStart = 0;
		std::vector<GameObject*> _elements;
	public:
		Game_manager();
		void display();
		void reshape(GLsizei h,GLsizei w);
		void specialKeyPressed(int key, int x, int y);
		void onTimer();
		void idle();
		void update(double delta);
		void init();
		void keyPressed(unsigned char, int,int);
		void setTable(Table t);
		Table getTable();
		bool isWired();
	};

#endif