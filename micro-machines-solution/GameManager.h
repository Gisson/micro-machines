#ifndef __GAMEMANAGER_H__
#define __GAMEMANAGER_H__
#include <memory>
#include <vector>

#include <algorithm>

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
#include "Player.h"


#define  ACELARATION_NUMBER  5.0
#define  ANGLE_TURN  2.0
#define  ZERO		 0.0
#define	 VIEWPORT_X  0.0
#define  VIEWPORT_Y  0.0
#define  WINDOW_SIZE 5.0
#define  FOVY		 45
#define  ORANGE_NR   10
#define  BUTTER_NR   1
#define  CANDLE_NR	 6
#define	 PAUSE_FILENAME "Pause.bmp"
#define	 ENDGAME_FILENAME "gameover.bmp"


	class Game_manager {
	private:
		Table* _table;
		Car* _vrum;
		Roadside* _road;
		OrthogonalCamera* _orthoCam;
		FollowCarCamera *_followCar;
		SeeFullRoadCamera *_fullRoad;
		std::vector<LightSource*> _candles;
		Player* _player;
		Texture* _pause,*_endGame;

		bool keyUp , keyDown, keyRight, keyLeft, lightEnabled, globalOn, goroud, candlesOn; 

		bool _isWired = false;
		int oldTimeSinceStart = 0;
		std::vector<GameObject*> _elements;
		LightSource* _globalLight;
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
		void clearGM();
		bool dead,paused;
		Texture* getpauseTexture();
		Texture* getEndGameTexture();

	};

#endif