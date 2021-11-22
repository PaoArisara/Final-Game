#pragma once
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Scene.h"
#include"ScoreList.h"
#define Max_menu 6

using namespace sf;
using namespace std;
                                      
class Menu : public Scene 
{
public:
	Music music;

	Menu(float width, float height, ScoreList* score_list);
	void update(float deltaTime);
	void render();
	void moveUp();
	void moveDown();
	inline int MenuPressed()
	{
		return mainMenuSelected;
	}
	~Menu();
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

