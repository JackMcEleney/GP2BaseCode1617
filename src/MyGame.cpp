#include "MyGame.h"


MyGame::MyGame()
{
	m_VBO = 0;
	m_VAO = 0;
}

MyGame::~MyGame()
{

}

void MyGame::initScene()
{
	GameApplication::initScene();
}

void MyGame::destroyScene()
{
	GameApplication::destroyScene();
}

void MyGame::render()
{
	GameApplication::render();
}

void MyGame::update()
{
	GameApplication::update();
}