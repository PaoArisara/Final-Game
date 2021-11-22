#include "About.h"

About::About(float width, float height)
{
		if (!font.loadFromFile("Fonts/SM.ttf"))
			printf("Can't load");

		//64010997 Arisara Ngamchawiworawet
		menu[1].setFont(font);
		menu[1].setFillColor(Color::Blue);
		menu[1].setString("64010997 Arisara Ngamchawiworawet");
		menu[1].setOrigin(menu[1].getLocalBounds().width / 2, menu[1].getLocalBounds().height / 2);
		menu[1].setCharacterSize(40);
		menu[1].setPosition(300, 990);

		//Score
		menu[0].setFont(font);
		menu[0].setFillColor(Color::Blue);
		menu[0].setString("BACK");
		menu[0].setOrigin(menu[0].getLocalBounds().width / 2, menu[0].getLocalBounds().height / 2);
		menu[0].setCharacterSize(100);
		menu[0].setPosition(1700, 20);

		mainMenuSelected = 0;
	}

	void About::update(float deltaTime)
	{
		pollEvent();
		this->bgTexture.loadFromFile("character/about.png");
		this->bgSprite.setTexture(bgTexture);

	}

	About::~About()
	{

	}

	void About::pollEvent()
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


	void About::render()
	{
		this->window->clear();
		this->window->draw(this->bgSprite);
		for (int i = 0; i < 2; i++)
		{
			window->draw(menu[i]);
		}
		this->window->display();
		
	}


	void About::select()
	{
		if (mainMenuSelected == 0)
		{
			sceneIndex = 0;
		}
	}
