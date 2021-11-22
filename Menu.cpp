#include "Menu.h"

Menu::Menu(float width, float height,ScoreList* score_list)
{

	if (!font.loadFromFile("Fonts/SM.ttf"))
		printf("Can't load");

	window = nullptr;

	//Don't Touch My Town
	menu[5].setFont(font);
	menu[5].setFillColor(Color::Blue);
	menu[5].setString("Don't Touch My Town");
	menu[5].setOrigin(menu[5].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[5].setCharacterSize(100);
	menu[5].setPosition(520, 50);

	//64010997 Arisara Ngamchawiworawet
	menu[4].setFont(font);
	menu[4].setFillColor(Color::White);
	menu[4].setString("64010997 Arisara Ngamchawiworawet");
	menu[4].setOrigin(menu[4].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[4].setCharacterSize(40);
	menu[4].setPosition(50, 990);
	//Play
	menu[0].setFont(font);
	menu[0].setFillColor(Color::Red);
	menu[0].setString("PLAY");
	menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
	menu[0].setCharacterSize(100);
	menu[0].setPosition(870,300);

	//Score
	menu[1].setFont(font);
	menu[1].setFillColor(Color::White);
	menu[1].setString("LEADER BOARD");
	menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
	menu[1].setCharacterSize(100);
	menu[1].setPosition(730,450);

	//ABOUT
	menu[2].setFont(font);
	menu[2].setFillColor(Color::White);
	menu[2].setString("ABOUT");
	menu[2].setOrigin(menu[2].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[2].setCharacterSize(100);
	menu[2].setPosition(850, 550);

	//EXIT
	menu[3].setFont(font);
	menu[3].setFillColor(Color::White);
	menu[3].setString("EXIT");
	menu[3].setOrigin(menu[3].getLocalBounds().width / 2, menu[2].getLocalBounds().height / 2);
	menu[3].setCharacterSize(100);
	menu[3].setPosition(870,700);

	mainMenuSelected = 0;
}

void Menu::update(float deltaTime)
{
	pollEvent();
	this->bgTexture.loadFromFile("character/bgs1.png");
	this->bgSprite.setTexture(bgTexture);

}

Menu::~Menu()
{

}

void Menu::pollEvent()
{
	Event ev;
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case Event::KeyReleased:
			switch (ev.key.code)
			{
			case Keyboard::Up:
				moveUp();
				break;
			case Keyboard::Down:
				moveDown();
				break;
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


void Menu::render()
{
	this->window->clear();
	this->window->draw(this->bgSprite);

	for (int i = 0; i < 6; i++)
	{
		window->draw(menu[i]);
	}
	this->window->display();
}


void Menu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		menu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		menu[mainMenuSelected].setFillColor(Color::Red);

	}
}

void Menu::moveDown()
{

	if (mainMenuSelected + 1 <= Max_menu)
	{
		menu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 4)
		{
			mainMenuSelected = 0;
		}
		menu[mainMenuSelected].setFillColor(Color::Red);
	}
}

void Menu::select()
{
	if (mainMenuSelected == 0)
	{
		sceneIndex = 1;
	}
	else if (mainMenuSelected == 1)
	{
		sceneIndex = 2;
		if (!music.openFromFile("Sound/4.wav"))
		{
			cout << "error music" << endl;
		}
		music.play();
		music.setVolume(30);
		music.setLoop(false);
	}
	else if (mainMenuSelected == 2)
	{
		sceneIndex = 3;
		if (!music.openFromFile("Sound/4.wav"))
		{
			cout << "error music" << endl;
		}
		music.play();
		music.setVolume(30);
		music.setLoop(false);
	}
	else if (mainMenuSelected == 3)
	{
		window->close();
	}
}