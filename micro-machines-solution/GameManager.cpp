#include <iostream>

#include "GameManager.h"


Game_manager::Game_manager() {

	_orthoCam = new OrthogonalCamera(-WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE, -WINDOW_SIZE, WINDOW_SIZE);
	_fullRoad = new SeeFullRoadCamera(FOVY, 1, 3, -3);
	_followCar = new FollowCarCamera(FOVY, 1, 1, -1);

	_elements = std::vector<GameObject*>();
/*
	aux = new LightSource(_candles.size());
	Vector3 *v1 = new Vector3(0, 0, 3.15);
	Vector3* v2 = new Vector3(1, 1, 1);
	Candle *newCandle = new Candle(v1, v2);
	

	aux->setPosition(newCandle->getPosition()->getX(), newCandle->getPosition()->getY(), newCandle->getPosition()->getZ()+0.2,1);
	aux->setDirection(1, 1, 1);
	aux->setSpecular(1.0, 1.0, 1.0, 1.0);
	aux->setDiffuse(1.0, 1.0, 1.0, 1.0);
	aux->setAmbient(0.2, 0.2, 0.2, 1.0);

	_elements.push_back(newCandle);*/
//	png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

}


void Game_manager::specialKeyPressed(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		keyUp = true;
		_vrum->acelarate(ACELARATION_NUMBER);
		break;
	case GLUT_KEY_DOWN:
		keyDown = true;
		_vrum->breakAcelaration(-ACELARATION_NUMBER);
		break;
	case GLUT_KEY_LEFT:
		keyLeft = true;
		_vrum->turn(ANGLE_TURN);
		break;
	case GLUT_KEY_RIGHT:
		keyRight = true;
		_vrum->turn(-ANGLE_TURN);
		break;
	}
}
void Game_manager::specialKeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		keyUp = false;
		break;
	case GLUT_KEY_DOWN:
		keyDown = false;
		break;
	case GLUT_KEY_LEFT:
		keyLeft = false;
		break;
	case GLUT_KEY_RIGHT:
		keyRight = false;
		break;
	}

}
void Game_manager::keyPressed(unsigned char key, int x, int y)
{

	switch (key) {
	case 'a':
		_isWired == true ? _isWired = false : _isWired = true;
		std::cout << (_isWired ? "Wired mode on" : "Wired mode off") << std::endl;
		break;
	case '1':
		std::cout << (camera_number != 1 ? "Using Camera 1" : "") << std::endl;
		camera_number = 1;
		break;
	case '2':
		std::cout << (camera_number != 2 ? "Using Camera 2" : "") << std::endl;
		camera_number = 2;
		_fullRoad->computeProjectionMatrix();
		break;
	case '3':
		std::cout << (camera_number!=3 ? "Using Camera 3" : "") << std::endl;
		camera_number = 3;
		_followCar->computeProjectionMatrix();
		break;

	case 'l':
		lightEnabled ? lightEnabled = false : lightEnabled = true;
		std::cout << (lightEnabled ? "Light calculation on" : "Light calculation off") << std::endl;
		break;
	
	case 'n':
		globalOn ? globalOn = false : globalOn = true;
		std::cout << (globalOn ? "Global light on" : "Global light off") << std::endl;
		break;


	case 'g':
		goroud ? goroud = false: goroud = true;
		std::cout << (goroud ? "Goroud shading on" : "Flat shading on") << std::endl;
		break;

	case 'c':
		candlesOn ? candlesOn = false : candlesOn = true;
		std::cout << (candlesOn ? "Candles on" : "Candles off") << std::endl;
		break;
	case 's':
		paused ? paused = false : paused = true;
		break;
	case 'r':
		if (dead) {
			std::cout << "Restart" << std::endl;
			clearGM();
		}
		break;
	default:
		std::cout << "Not supported" << std::endl;
		break;

	}

}

void Game_manager::onTimer()
{
}

void Game_manager::idle()
{
	
}

void Game_manager::update(double delta)
{
	if (paused)return;
	if (keyUp) {
		_vrum->acelarate(ACELARATION_NUMBER);
	}

	if (keyDown) {
		_vrum->breakAcelaration(-ACELARATION_NUMBER);
	}
	if (keyLeft) {
		_vrum->turn(ANGLE_TURN);
	}
	if (keyRight) {
		_vrum->turn(-ANGLE_TURN);
	}

	for (std::vector<LightSource*>::iterator it = _candles.begin(); it != _candles.end(); ++it)
		(*it)->setState(candlesOn?true:false);

	if (globalOn)
		_globalLight->setState(true);
	else
		_globalLight->setState(false);
	if (lightEnabled)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);
	if (goroud) {
		glShadeModel(GL_SMOOTH);
	}
	else
		glShadeModel(GL_FLAT);


	for (std::vector<GameObject*>::iterator it = _elements.begin(); it != _elements.end(); ++it) {
		/*for (std::vector<GameObject*>::iterator jt = it; jt != _elements.end(); ++jt) {
			std::cout << "for IT: " << (*it)->getPosition()->getX() << " " << (*it)->getPosition()->getY() << " RADIUS IT: " << (*it)->getHitBox()->getRadius() << " FOR JT:" << (*jt)->getPosition()->getX() << " " << (*jt)->getPosition()->getY() << " RADIUS JT: " << (*jt)->getHitBox()->getRadius() << std::endl;

			if ((*it)->checkHit(*jt) && (*it)!=(*jt)) {
			}
		}*/
		(*it)->update(delta);
	}
	bool didReallyHit = false;
	for (std::vector<GameObject*>::iterator it = _elements.begin(); it != _elements.end(); ++it) {
		if ((*it)->checkHit(_vrum)) didReallyHit = true; //TODO: CHANGE FUNCTION CHECKHIT IN ORANGE AND BUTTER
	}
	if (didReallyHit) {
		std::cout << _player->getLifes() << std::endl;
		if (_player->loseLife())
			std::cout << "Lost GAME!!!" << std::endl;
		if (_player->isDead()) dead = true;
	}
	else if(_vrum->getOutOfTable()){
		_player->loseLife();
		if (_player->isDead()) dead = true;
		_vrum->resetCar();
		_vrum->setOutOfTable(false);
	}
	
}

void Game_manager::init()
{
	srand(time(NULL));
	std::cout << "Initializing.." << std::endl;
	//Initializing bools
	keyUp = false; keyDown = false; keyLeft = false; keyRight = false; //Keys
	lightEnabled = true; globalOn = true; goroud = true; candlesOn = true;//lights
	paused = false; dead = false;//control bools

	

	//Initializing elements of the game
	_table = new Table();
	_elements.push_back(_table);
	_road = new Roadside();
	_elements.push_back(_road);
	for (int i = 0; i < ORANGE_NR; i++) {
		_elements.push_back(new Orange());
	}
	for (int i = 0; i < BUTTER_NR; i++) {
		_elements.push_back(new Butter());
	}
	for (int i = 0; i < CANDLE_NR; i++) {
		LightSource* lh = new LightSource(i + 1);
		lh->setPosition(-TABLE_SIZE / 2 + i, -TABLE_SIZE / 2 + i, 4, 1);
		lh->setAmbient(0.25, 0.25, 0.25, 1);
		lh->setDiffuse(0.25, 0.25, 0.25, 1);
		lh->setSpecular(0.25, 0.25, 0.25, 1);
		glLightf(GL_LIGHT0 + i, GL_CONSTANT_ATTENUATION, 0.5);
		glLightf(GL_LIGHT0 + i, GL_LINEAR_ATTENUATION, 0);
		glLightf(GL_LIGHT0 + i, GL_QUADRATIC_ATTENUATION, 0);
		_candles.push_back(lh);
		_elements.push_back(new Candle(new Vector3(lh->getX(), lh->getY(), lh->getZ())));
	}

	_vrum = new Car();
	_elements.push_back(_vrum);

	_globalLight = new LightSource(0);

	_globalLight->setPosition(0, 0, 4, 0);
	_globalLight->setSpecular(0.5, 0.5, 0.5, 1.0);
	_globalLight->setDiffuse(0.6, 0.6, 0.6, 1.0);
	_globalLight->setAmbient(0.8, 0.8, 0.8, 1.0);
	_player = new Player();

	_pause = new Texture();
	_pause->loadBMP_custom(PAUSE_FILENAME);
	_endGame = new Texture();
	_endGame->loadBMP_custom(ENDGAME_FILENAME);
}

void Game_manager::clearGM()
{
	free(_globalLight);
	for (LightSource* lh : _candles)
		free(lh);
	for (GameObject* go : _elements)
		go->release();
	free(_player);
}

void Game_manager::display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (paused) { //TODO: Adicionar aqui o tratamento da textura do pause
		glPushMatrix();
		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-5, 5, -5, 5, -5, 5);
		glBindTexture(GL_TEXTURE_2D, _pause->getTexture());

		glColor3f(1, 1, 1);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_POLYGON);
		glNormal3f(0, 0, 1);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(4.0, 4.0, 5.0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(4.0, -4.0, 5.0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-4.0, -4.0, 5.0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-4.0f, 4.0, 5.0);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glFinish();
		glutPostRedisplay();
		return;
	}
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	switch (camera_number) {
	case 1:
		_orthoCam->computeProjectionMatrix();
		break;
	case 2:
		_fullRoad->computeProjectionMatrix();
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(0, -6, 10, 0, 0, 0, 0, 0, 1);
		break;
	case 3:
		_followCar->computeProjectionMatrix();
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(_vrum->getPosition()->getX() + cos(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getY() + sin(_vrum->getAngle()*PI / 180) * -3, _vrum->getPosition()->getZ()+2,
			_vrum->getPosition()->getX(), _vrum->getPosition()->getY(), _vrum->getPosition()->getZ(),
			0, 0,1);
		break;
	default:
		break;

	}
	glMatrixMode(GL_MODELVIEW);

	/*///////////////////////////////OBJECT DRAWING AREA\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	if (!_isWired) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}

	for (GameObject* go : _elements) {
		go->draw();
	}
	if (globalOn) _globalLight->draw();
	if (candlesOn) {
		for (LightSource* lh : _candles)
			lh->draw();
	}
	_player->draw();
	glFlush();
	glutPostRedisplay();
}

void Game_manager::reshape(GLsizei w, GLsizei h) {
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(VIEWPORT_X, VIEWPORT_Y, w, h);
	GLfloat ratio = GLfloat(w) / GLfloat(h);
	if (camera_number == 1) {
		if (w > h) {
			_orthoCam->setLeft(-WINDOW_SIZE*ratio);
			_orthoCam->setRight(WINDOW_SIZE*ratio);
			_orthoCam->setBottom(-WINDOW_SIZE);
			_orthoCam->setTop(WINDOW_SIZE);
			

		}
		else {
			_orthoCam->setLeft(-WINDOW_SIZE);
			_orthoCam->setRight(WINDOW_SIZE);
			_orthoCam->setBottom(-WINDOW_SIZE / ratio);
			_orthoCam->setTop(WINDOW_SIZE / ratio);
		}
	}
	else if(camera_number==2 || camera_number==3){
		camera_number == 2 ? _fullRoad->setAspect(ratio):_followCar->setAspect(ratio);

		
	}
}


void Game_manager::setTable(Table t) {
	_table = &t;
}
Table Game_manager::getTable() {
	return *_table;
}

bool Game_manager::isWired()
{
	return _isWired;
}

Texture * Game_manager::getpauseTexture()
{
	return _pause;
}

Texture * Game_manager::getEndGameTexture()
{
	return _endGame;
}
