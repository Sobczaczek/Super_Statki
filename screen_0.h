#ifndef SCREEN_0_H
#define SCREEN_0_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"

class screen_0 : public cScreen
{
private:
    bool playing;
public:
    screen_0(void);
    virtual int Run(sf::RenderWindow &App);
};
screen_0::screen_0(void)
{
    playing = false;
};
//
class napis{
public:
    void animuj(sf::RenderWindow &App,sf::Time &czas){

        sf::Texture tekstura_2;
        if(!tekstura_2.loadFromFile("napis2.png")){
            exit(-1);
        }
        sf::Sprite napis(tekstura_2);
        napis.setPosition(0,750);
        if(czas.asSeconds()>0&&czas.asSeconds()<0.7){
        App.draw(napis);
        }
    }
};
int screen_0::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture tekstura_1;
    if(!tekstura_1.loadFromFile("screen1.png")){
        exit(-1);
    }
    sf::Sprite screen1(tekstura_1);
    napis n1;
    sf::Clock clock;
    sf::Time czas;
    clock.restart();
    while (Running)
    {
        while (App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed ||(Event.type == sf::Event::KeyPressed && Event.key.code==sf::Keyboard::Escape))
            {
                return (-1);
            }
            if (Event.type == sf::Event::KeyPressed && Event.key.code==sf::Keyboard::Enter)
            {
                return (1);
            }
        }
        App.clear();
        if(czas.asSeconds()>1)
        {
        clock.restart();
        }
        czas=clock.getElapsedTime();

        App.draw(screen1);
        n1.animuj(App,czas);
        App.display();
    }
    return (-1);
}
#endif // SCREEN_0_H

