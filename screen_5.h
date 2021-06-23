#ifndef SCREEN_5_H
#define SCREEN_5_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"
#include "screen_0.h"
#include "screen_2.h"


class screen_5: public cScreen
{
public:
    screen_5(void);
    virtual int Run(sf::RenderWindow &App);
};
screen_5::screen_5(void){

}

int screen_5::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Clock clock;
    sf::Time czas;
    sf::Font Font;
    sf::Text wynik_,your_name;
    if (!Font.loadFromFile("arial.ttf"))
    {
        exit (-1);
    }
    wynik_.setFont(Font);
    your_name.setFont(Font);
    wynik_.setCharacterSize(80);
    your_name.setCharacterSize(80);
    //wynik.setPosition(wynik)
    clock.restart();
    napis n1;
    std::fstream plik;
    std::string wynik;
    plik.open("wynik.txt",std::ios::in);
    if(!plik)
    {
        std::cout<<":("<<std::endl;
        return(-1);
    }
    else
    {
        plik>>wynik;
        wynik_.setString("Your score:\n"+wynik);
        wynik_.setPosition(400-wynik_.getLocalBounds().width/2,260);
        wynik_.setFillColor(sf::Color::White);

        std::cout<<":)"<<std::endl;
        plik.close();
    }
    std::string name="";
    your_name.setString("Name:"+name);
    your_name.setPosition(400-your_name.getLocalBounds().width/2,460);


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
                std::fstream plik1;
                plik1.open("wyniki.txt",std::ios::out|std::ios::app);
                if(!plik1){
                    std::cout<<":("<<std::endl;    }
                else
                {
                    plik1<<"\n";
                    plik1<<name+" "+wynik;
                    std::cout<<":)"<<std::endl;
                    plik1.close();
                }
                return (1);
            }
            if (Event.type == sf::Event::TextEntered)
            {
                if(name.size()<3){
                name +=Event.text.unicode;

                your_name.setString("Name:"+name);
                your_name.setPosition(400-your_name.getLocalBounds().width/2,460);
                your_name.setFillColor(sf::Color::White);
                }
            }

        }
        App.clear();



        if(czas.asSeconds()>1)
        {
        clock.restart();
        }
        czas=clock.getElapsedTime();
        n1.animuj(App,czas);
        App.draw(wynik_);
        App.draw(your_name);



        App.display();
        }

    return (-1);
}


#endif // SCREEN_5_H
