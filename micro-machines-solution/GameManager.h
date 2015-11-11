#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include <memory>
#include <vector>

#include <algorithm>
#include <GL/glut.h>
#include "LightSource.h"
#include "Orange.h"
#include "Butter.h"
#include "Table.h"
#include "Car.h"
#include "Roadside.h"
#include "SeeFullRoadCamera.h"
#include "FollowCarCamera.h"
#include "OrthogonalCamera.h"
#include "Candle.h"


#define  ACELARATION_NUMBER  5.0
#define  ANGLE_TURN  2.0
#define  ZERO		 0.0
#define	 VIEWPORT_X  0.0
#define  VIEWPORT_Y  0.0
#define  WINDOW_SIZE 5.0
#define  FOVY		 45
#define  ORANGE_NR   1
#define  BUTTER_NR   1

	class Game_manager {
	private:
		Table* _table;
		Car* _vrum;
		Roadside* _road;
		OrthogonalCamera* _orthoCam;
		FollowCarCamera *_followCar;
		SeeFullRoadCamera *_fullRoad;
		LightSource *_sun;
		std::vector<Candle*> _candles;

		bool keyUp=false,keyDown=false,keyRight=false,keyLeft=false,lightEnabled=true;

		bool _isWired = false;
		int oldTimeSinceStart = 0;
		std::vector<GameObject*> _elements;
		int camera_number = 1;
	public:
		Game_manager();
		void display();
		void reshape(GLsizei h,GLsizei w);
		void specialKeyPressed(int key, int x, int y);
		void specialKeyUp(int key,int x,int y);
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