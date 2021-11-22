#include <iostream>
#include "Game.h"
#include"Player.h"
#include"Menu.h"
#include<time.h>
#include"About.h"
#include"ScoreList.h"
#include"LeaderBoard.h"

int sceneIndex = 0;

int main()
{
    ScoreList score_list;
    score_list.loadFromFile();
    RenderWindow window(VideoMode(1920,1080), "Don't Touch My Town", Style::Titlebar | Style::Close);
    window.setFramerateLimit(144);


    //Init srand
    cout << "Hello im running" << std::endl;
    srand(static_cast<unsigned>(time(NULL)));
    //Init Game Engine

     Game game(&score_list);
     game.setWindow(&window);
     Menu menu(1920, 1080, &score_list);
     menu.setWindow(&window);
     LeaderBoard leaderboard(1920,1080, &score_list);
     leaderboard.setWindow(&window);
     About about(1920, 1080);
     about.setWindow(&window);


     //เชื่อมเข้าด้วยกันใช้scene
     vector <Scene*> scenes;
     scenes.push_back(&menu);
     scenes.push_back(&game);
     scenes.push_back(&leaderboard);
     scenes.push_back(&about);

     float deltaTime;
     Clock clock;
    //Game loop
     while (game.running())
     {
         deltaTime = clock.restart().asSeconds();
         //Update
         scenes[sceneIndex]->update(deltaTime);
         //Render
         scenes[sceneIndex]->render();
         leaderboard.updatedata();

     }
     //End of application
     score_list.saveToFile();
    return 0;
}