#ifndef SCREEN_1_H
#define SCREEN_1_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"

class screen_1 : public cScreen
{
private:
    bool playing;
public:
    screen_1(void);
    virtual int Run(sf::RenderWindow &App);
};

screen_1::screen_1(void)
{
    playing = false;
}
class Button{
private:
public:
    sf::Sprite przycisk;
    float pozycjaX,pozycjaY;
    Button(){};
    void draw(sf::RenderWindow &App,sf::Sprite &b1){
    App.draw(b1);
    }
};

int screen_1::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    int alpha = 0;
    int menu = 0;

    Button play_,conti_,exit_,high_;
    //przyciski
    sf::Texture tekstura_play;
    if(!tekstura_play.loadFromFile("play.png")){
        exit(-1);
    }
    play_.przycisk.setTexture(tekstura_play);
    play_.przycisk.setPosition({213,239});
    sf::Texture tekstura_play_1;
    if(!tekstura_play_1.loadFromFile("play1.png")){
        exit(-1);
    }
    sf::Texture tekstura_conti;
    if(!tekstura_conti.loadFromFile("continue.png")){
        exit(-1);
    }
    conti_.przycisk.setTexture(tekstura_conti);
    conti_.przycisk.setPosition({213,239});
    sf::Texture tekstura_conti_1;
    if(!tekstura_conti_1.loadFromFile("continue1.png")){
        exit(-1);
    }
    sf::Texture tekstura_highscores;
    if(!tekstura_highscores.loadFromFile("highscores.png")){
        exit(-1);
    }
    high_.przycisk.setTexture(tekstura_highscores);
    high_.przycisk.setPosition({213,360});
    sf::Texture tekstura_highscores_1;
    if(!tekstura_highscores_1.loadFromFile("highscores1.png")){
        exit(-1);
    }
    sf::Texture tekstura_exit;
    if(!tekstura_exit.loadFromFile("exit.png")){
        exit(-1);
    }
    exit_.przycisk.setTexture(tekstura_exit);
    exit_.przycisk.setPosition({213,480});
    sf::Texture tekstura_exit_1;
    if(!tekstura_exit_1.loadFromFile("exit1.png")){
        exit(-1);
    }


    while (Running)
    {
        while (App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Up:
                    if(menu==0){
                        menu=3;
                    }
                    else if(menu==3){
                        menu=1;
                    }
                    else if(menu==1){
                        menu=0;
                    }
                    break;
                case sf::Keyboard::Down:
                    if(menu==0){
                        menu=1;
                    }
                    else if(menu==1){
                        menu=3;
                    }
                    else if(menu==3){
                        menu=0;
                    }
                    break;
                case sf::Keyboard::Enter:
                    if (menu == 0)
                    {
                        playing = true;
                        return (4);
                    }
                    if(menu==1)
                    {
                        return(3);
                    }
                    else
                    {
                        return (-1);
                    }
                    break;
                default:
                    break;
                }
            }

        }
        if (menu == 0)
        {
            play_.przycisk.setTexture(tekstura_play_1);
            conti_.przycisk.setTexture(tekstura_conti_1);
            high_.przycisk.setTexture(tekstura_highscores);
            exit_.przycisk.setTexture(tekstura_exit);
        }
        if(menu==1){
            play_.przycisk.setTexture(tekstura_play);
            conti_.przycisk.setTexture(tekstura_conti);
            high_.przycisk.setTexture(tekstura_highscores_1);
            exit_.przycisk.setTexture(tekstura_exit);
        }
        if(menu==3){
            play_.przycisk.setTexture(tekstura_play);
            conti_.przycisk.setTexture(tekstura_conti);
            high_.przycisk.setTexture(tekstura_highscores);
            exit_.przycisk.setTexture(tekstura_exit_1);
        }
        if(menu==2)
        {
            play_.przycisk.setTexture(tekstura_play_1);
            conti_.przycisk.setTexture(tekstura_conti_1);
            high_.przycisk.setTexture(tekstura_highscores);
            exit_.przycisk.setTexture(tekstura_exit);
        }
        App.clear();
        App.draw(Sprite);
            if (playing)
            {
                conti_.draw(App,conti_.przycisk);
            }
            else
            {
                play_.draw(App,play_.przycisk);
            }
            high_.draw(App,high_.przycisk);
            exit_.draw(App,exit_.przycisk);
        App.display();
    }
    return (-1);
}

#endif // SCREEN_1_H
