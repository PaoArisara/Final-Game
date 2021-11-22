#define _CRT_SECURE_NO_WARNINGS
#include "LeaderBoard.h"
#include<stdio.h>

LeaderBoard::LeaderBoard(float width, float height, ScoreList* score_list)
{
	if (!font.loadFromFile("Fonts/SM.ttf"))
		printf("Can't load");


	window = nullptr;
	FILE* fp;
	fp = fopen("Highscore.txt", "r");
	char temp[100];
	char point[100];
	for (int i = 0; i <= 4; i++)
	{
		
		text_num[i].setFont(font);
		text_num[i].setCharacterSize(50);
		text_num[i].setFillColor(Color::Black);
		text_num[i].setString(to_string(i + 1));
		text_num[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2, text_num[i].getLocalBounds().height / 2));
		text_num[i].setPosition(Vector2f(550.f, 250.f + 120.f *i));
		fscanf(fp, "%s", &temp);
		text_name[i].setFont(font);
		text_name[i].setCharacterSize(50);
		text_name[i].setFillColor(Color::Black);
		text_name[i].setString(temp);
		text_name[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2, text_num[i].getLocalBounds().height / 2));
		text_name[i].setPosition(Vector2f(600.f, 250.f + 120.f*i));
		fscanf(fp, "%s", &point);
		text_score[i].setFont(font);
		text_score[i].setCharacterSize(50);
		text_score[i].setFillColor(Color::Black);
		text_score[i].setString(point);
		text_score[i].setOrigin(Vector2f(text_num[i].getLocalBounds().width / 2, text_num[i].getLocalBounds().height / 2));
		text_score[i].setPosition(Vector2f(1280.f, 250.f + 120.f * i));
	}
	fclose(fp);
	//64010997 Arisara Ngamchawiworawet
	menu[2].setFont(font);
	menu[2].setFillColor(Color::Blue);
	menu[2].setString("64010997 Arisara Ngamchawiworawet");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setCharacterSize(40);
	menu[2].setPosition(300, 990);
	//Play
	menu[1].setFont(font);
	menu[1].setFillColor(Color::Red);
	menu[1].setString("LEADER BOARD");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setCharacterSize(100);
	menu[1].setPosition(750, 60);

	//Score
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Blue);
	menu[0].setString("BACK");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setCharacterSize(100);
	menu[0].setPosition(1700, 950);

	mainMenuSelected = 0;
}

void LeaderBoard::update(float deltaTime)
{
	pollEvent();
	this->bgTexture.loadFromFile("character/s.png");
	this->bgSprite.setTexture(bgTexture);

}

void LeaderBoard::updatedata()
{
	FILE* fp;
	fp = fopen("Highscore.txt", "r");
	char temp[100];
	char point[100];
	for (int i = 0; i <= 4; i++)
	{
		fscanf(fp, "%s", &temp);
		text_name[i].setString(temp);
		
		fscanf(fp, "%s", &point);
		text_score[i].setString(point);
		
	}
	fclose(fp);
}

LeaderBoard::~LeaderBoard()
{

}

void LeaderBoard::pollEvent()
{
	Event ev;
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::KeyReleased:
			switch (ev.key.code)
			{
			case Keyboard::Enter:
				select();
				break;
			case Keyboard::Escape:
				window->close();
				break;
			}
			break;
		case  Event::Closed:
			window->close();
			break;
		}
	}
}


void LeaderBoard::render()
{
	this->window->clear();
	this->window->draw(this->bgSprite);
	for (int i = 0; i < 5; i++)
	{
		window->draw(menu[i]);
		window->draw(text_num[i]);
		window->draw(text_name[i]);
		window->draw(text_score[i]);
	}
	this->window->display();
}


void LeaderBoard::select()
{
	if (mainMenuSelected == 0)
	{
		sceneIndex = 0;
	}
}