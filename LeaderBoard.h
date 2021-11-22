#pragma once
#include <SFML/Graphics.hpp>
#include"Scene.h"
#include"ScoreList.h"
#include<stdio.h>
#define Max_menu 5

using namespace sf;
using namespace std;

class LeaderBoard : public Scene
{
public:
	Text text_num[5];
	Text text_name[5];
	Text text_score[5];

	LeaderBoard(float width, float height, ScoreList* score_list);
	void update(float deltaTime);
	void updatedata();
	void render();
	//void moveUp();
	//void moveDown();
	inline int MenuPressed()
	{
		return mainMenuSelected;
	}
	~LeaderBoard();
	inline void setWindow(RenderWindow* window) { this->window = window; }

	void pollEvent();
	void select();

private:
	ScoreList* score_list;

	RenderWindow* window;
	int mainMenuSelected;
	Font font;
	Text menu[Max_menu];

	RectangleShape bg;
	Texture bgTexture;
	Sprite bgSprite;
	Event ev;
};

