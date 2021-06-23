#ifndef SCREEN_4_H
#define SCREEN_4_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"
#include "screen_0.h"
#include "screen_2.h"


class screen_4: public cScreen
{
public:
    screen_4(void);
    virtual int Run(sf::RenderWindow &App);
};
screen_4::screen_4(void){

}

int screen_4::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Clock clock;
    sf::Time czas,czas1;
    clock.restart();
    napis n1;
    sf::Sprite table;
    sf::Texture tekstura_table;
    if(!tekstura_table.loadFromFile("screen4.png")){
        exit(-1);
    }
    table.setTexture(tekstura_table);
    Score t;
    std::string manual;
    manual="Witaj w mojej grze SUPER SPACESHIP, celem gry jest uzyskannie\n"
           "najwyzszego mozliwego wyniku. Sterowanie przedstawione ponizej\n"
           "Twoje zdrowie wynosi 150HP, tracisz je zderzajac sie z obiektami\n"
           "lub otrzymujac obrazenia od wrogich statkow. Za kazdy zniszczony\n"
           "obiekt otrzymujesz punkty:5 za meteoryty i 50 za wrogie staki. \n"
           "Milej zabawy~Dawid Sobczak/n";
    while (Running)
    {
        while (App.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            if (Event.type == sf::Event::KeyPressed && Event.key.code==sf::Keyboard::Escape)
            {
                return (1);
            }
            if (Event.type == sf::Event::KeyPressed && Event.key.code==sf::Keyboard::Enter)
            {
                return (2);
            }
        }
        App.clear();
        if(czas.asSeconds()>1)
        {
        clock.restart();
        }
        czas=clock.getElapsedTime();
        App.draw(table);
        n1.animuj(App,czas);
        t.text(App,manual);


        App.display();
    }
    return (-1);
}

#endif // SCREEN_4_H
