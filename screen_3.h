#ifndef SCREEN_3_H
#define SCREEN_3_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"
#include "fstream"



class screen_3: public cScreen
{
public:
    screen_3(void);
    virtual int Run(sf::RenderWindow &App);
};
screen_3::screen_3(void){

}


int screen_3::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Clock clock;
    sf::Time czas,czas1;
    clock.restart();
    sf::Sprite table;
    sf::Texture tekstura_highscoretable;
    if(!tekstura_highscoretable.loadFromFile("highscorestable.png")){
        exit(-1);
    }
    table.setTexture(tekstura_highscoretable);
    std::fstream plik1;
    std::vector<std::string> wyniki;

    plik1.open("wyniki.txt",std::ios::in);
    if(!plik1)
    {
        std::cout<<":("<<std::endl;
        return(-1);
    }
    else
    {
       std::cout<<":)"<<std::endl;

        plik1.close();
    }


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
        }
        App.clear();
        if(czas.asSeconds()>1)
        {
        clock.restart();
        }
        czas=clock.getElapsedTime();
        App.draw(table);

        App.display();
    }
    return (-1);
}

#endif // SCREEN_3_H
