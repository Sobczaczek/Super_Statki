#ifndef SCREEN_2_H
#define SCREEN_2_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include "cscreen.h"
#include "fstream"

class screen_2 : public cScreen
{
private:
public:
    screen_2(void){};
    virtual int Run(sf::RenderWindow &App);
};
//

//KLASA STATEK
class Statek{
public:
    Statek(float pX,float pY);
    ~Statek(){};

    void spawn(sf::RenderWindow &App);
    void ruch(sf::RenderWindow &App);
    void animacja(Statek s);
    float pozycjaX;
    float pozycjaY;
    float zdrowie;
    int nr_tekstura=0;
    sf::Texture tekstura_1;
    sf::Texture tekstura_2;
    sf::RectangleShape zdrowie_;
    sf::Sprite model_statku;
private:
};
Statek::Statek(float pX,float pY){
   pozycjaX=pX;
   pozycjaY=pY;
   zdrowie=150;
   zdrowie_.setPosition({625,42});
   zdrowie_.setFillColor(sf::Color::Red);
   zdrowie_.setSize({(zdrowie),20});

}
void Statek::spawn(sf::RenderWindow &App){

    if(!tekstura_1.loadFromFile("statek_1_1.png")){
        exit(-1);
    }
    if(!tekstura_2.loadFromFile("statek_1_2.png")){
        exit(-1);
    }
    model_statku.setTexture(tekstura_1);
    model_statku.setPosition(pozycjaX,pozycjaY);
    model_statku.setScale(3,3);
    App.draw(model_statku);
    App.draw(zdrowie_);
}
void Statek::ruch(sf::RenderWindow &App){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
       if(pozycjaY>80)
       {
       model_statku.move( 0.f, -5.f );
       pozycjaY=pozycjaY-5.f;
       }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if(pozycjaY<App.getSize().y-(model_statku.getLocalBounds().height*model_statku.getScale().y))
        {
        model_statku.move( 0.f, 5.f );
        pozycjaY=pozycjaY+5.f;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if(pozycjaX>0)
        {
        model_statku.move( -5.f, 0.f );
        pozycjaX=pozycjaX-5.f;
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if(pozycjaX<App.getSize().x-(model_statku.getLocalBounds().width*model_statku.getScale().x))
        {
        model_statku.move( 5.f, 0.f);
        pozycjaX=pozycjaX+5.f;
        }
    }
}

//KONIEC KLASY

//KLASA ENEMY
class Enemy{
public:
    Enemy(){}
    ~Enemy(){}
    float pozycjaX;
    float pozycjaY;
    virtual void spawn(sf::RenderWindow &App){}
private:
};
//
class Enemy_obj:public Enemy{
public:
    sf::Sprite model_obj;
    sf::Vector2f currVelocity;
    Enemy_obj(float pX,float pY)
            : currVelocity(0.f, 1.0f)
        {
        pozycjaX=pX;
        pozycjaY=pY;
        }
    void spawn(sf::RenderWindow &App){
        sf::Texture tekstura_1;
        if(!tekstura_1.loadFromFile("obj_1_1.png")){
            exit(-1);
        }
        model_obj.setTexture(tekstura_1);
        model_obj.setScale(0.3,0.3);
        model_obj.setOrigin(model_obj.getLocalBounds().width/2,model_obj.getLocalBounds().height/2);
        sf::Vector2f model_statkuPozycja;
        App.draw(model_obj);
    }

};
class Enemy_statek:public Enemy{
public:
    sf::Sprite model_statek;
    int hp_points=100;
    sf::Vector2f currVelocity;
    Enemy_statek(float pX,float pY)
            : currVelocity(0.f, 1.0f)
        {
        pozycjaX=pX;
        pozycjaY=pY;
        }
    void spawn(sf::RenderWindow &App){
        sf::Texture tekstura_1;
        if(!tekstura_1.loadFromFile("statek_2_1.png")){
            exit(-1);
        }
        model_statek.setTexture(tekstura_1);
        model_statek.setScale(0.3,0.3);
        model_statek.setOrigin(model_statek.getLocalBounds().width/2,model_statek.getLocalBounds().height/2);
        sf::Vector2f model_statkuPozycja;
        App.draw(model_statek);
    }

};
//KONIEC KLASY
//KLASA POCISK
class Pocisk{
public:
    sf::RectangleShape shape;
    sf::Vector2f currVelocity;
    float maxPredkosc;
    int damage;
    Pocisk(float rozmiar = 5.f)
            : currVelocity(0.f, -4.0f)
        {
            this->shape.setSize(sf::Vector2f(rozmiar,2*rozmiar));
            this->shape.setFillColor(sf::Color::Magenta);
            this->damage=rand()%30+20;
        }
private:
};
//KONIEC KLASY
//Klasa wynik
class Score{
private:
    sf::Font Font;
    sf::Text wynik;
    sf::Text zdrowie_text;
    sf::Text tekst;

public:
    Score(){};
    int score=0;
    void spawn(sf::RenderWindow &App){

        if (!Font.loadFromFile("arial.ttf"))
        {
            exit (-1);
        }
        wynik.setFont(Font);
        zdrowie_text.setFont(Font);
        wynik.setCharacterSize(30);
        zdrowie_text.setCharacterSize(30);
        auto score_string = std::to_string(score);
        wynik.setString("SCORE:\n"+score_string);
        zdrowie_text.setString("HEALTH");
        wynik.setFillColor(sf::Color::Black);
        zdrowie_text.setFillColor(sf::Color::Black);
        zdrowie_text.setPosition({ 645, 0 });
        wynik.setPosition({ 10, 0 });
        App.draw(wynik);
        App.draw(zdrowie_text);
    }
    void text(sf::RenderWindow &App, std::string &txt){
        if (!Font.loadFromFile("arial.ttf"))
        {
            exit (-1);
        }
        tekst.setFont(Font);
        tekst.setCharacterSize(20);
        tekst.setFillColor(sf::Color::White);
        tekst.setString(txt);
        tekst.setPosition({80,50});
        App.draw(tekst);
    }
    void update(sf::RenderWindow &App,int scoreplus){
        score=score+scoreplus;
        auto score_string = std::to_string(score);
        wynik.setString(score_string);
        App.draw(wynik);
    }
    void save(std::fstream &plik){
        //plik<<""<<std::endl;
        plik<<std::to_string(score)<<std::endl;
    }
};
//



int screen_2::Run(sf::RenderWindow &App)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture tekstura_2;
            if(!tekstura_2.loadFromFile("tlo1.jfif")){
                exit(-1);
            }
            sf::Sprite tlo(tekstura_2);
            //...
            sf::Texture tekstura_4;
            if(!tekstura_4.loadFromFile("screen1.png")){
                exit(-1);
            }
            sf::Sprite screen1(tekstura_4);
            //...
            sf::Texture tekstura_3;
            if(!tekstura_2.loadFromFile("pixil-frame-0.png")){
                exit(-1);
            }
            sf::Sprite tlo1(tekstura_3);
            sf::Texture tekstura_5;
            if(!tekstura_5.loadFromFile("healthbar.png")){
                exit(-1);
            }
            sf::Sprite tlo2(tekstura_5);
            tlo2.setPosition({0,0});
            //...
            Statek s1(350,700);
            //...
            std::vector<Enemy_statek> enemies;
            int enemyspawn=10;
            //...
            Score score1;
            //...
            int enemydown;
            int obj_down;
            //...
            Pocisk p1;
            Pocisk p2;
            std::vector<Pocisk> pociski;
            std::vector<Pocisk> pociski2;
            //...
            std::vector<Enemy_obj> objects;
            int obj_number=20;
            //...
            sf::Clock clock;
            sf::Time czas;
            clock.restart();
            //...



    while (Running)
    {
        App.clear(sf::Color::Black);
        while (App.pollEvent(Event))
        {
            if(Event.type == sf::Event::Closed)
            {
                return (-1);
            }
            if( (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::Escape)||s1.zdrowie<=0)
            {
                std::fstream plik;
                plik.open("wynik.txt",std::ios::out|std::ios::trunc);
                if(!plik){
                    std::cout<<":("<<std::endl;
                    return(1);    }
                else
                {
                    score1.save(plik);
                    std::cout<<":)"<<std::endl;
                    plik.close();
                    return(5);
                }

            }
            if (Event.type == sf::Event::KeyReleased && Event.key.code == sf::Keyboard::Space )
            {
                p1.shape.setPosition(s1.pozycjaX+(s1.model_statku.getLocalBounds().width*s1.model_statku.getScale().x)/2,s1.pozycjaY);
                pociski.push_back(Pocisk(p1));
            }

            if(Event.type==sf::Event::KeyPressed){
                switch (Event.key.code)
                {
                case sf::Keyboard::W:
                    s1.nr_tekstura=1;
                    //if(Event.type==sf::Event::KeyReleased){
                    //    s1.nr_tekstura==0;
                   // }


                    break;
                case sf::Keyboard::S:

                    break;
                case sf::Keyboard::A:

                    break;
                case sf::Keyboard::D:

                    break;
                default:
                    break;
                }
            }
        }

        //respawn obiektów
        if (enemyspawn < 2)
        {
            enemyspawn++;
        }
        if(enemyspawn >= 2 && enemies.size() < 3)
        {
            //int r=rand()%200;
            if(czas.asSeconds()>2){
            Enemy_statek e1(rand() % App.getSize().x, rand() % 10);
            e1.model_statek.setPosition(rand() % App.getSize().x, rand() % 10);
            enemies.push_back(e1);
            enemyspawn = 0;
            }
        }
        if (obj_number < 4)
        {
            obj_number++;
        }

        if(obj_number >= 4 && objects.size() < 10)
        {
            Enemy_obj o1(rand() % App.getSize().x,0);
            o1.model_obj.setPosition(rand() % App.getSize().x,rand()% 1+ 80);
            objects.push_back(Enemy_obj(o1));
            obj_number = 0;
        }
        //
        for(size_t i = 0; i < objects.size(); i++)
        {
           objects[i].model_obj.move(objects[i].currVelocity);
           objects[i].model_obj.rotate(rand()%1+2);
           if (objects[i].model_obj.getPosition().x < 0 || objects[i].model_obj.getPosition().x > App.getSize().x
               || objects[i].model_obj.getPosition().y < 0 || objects[i].model_obj.getPosition().y > App.getSize().y)
           {
               objects.erase(objects.begin() + i);
           }
           else
           {
           for (size_t k = 0; k < objects.size(); k++)
           {
               if (objects[i].model_obj.getGlobalBounds().intersects(s1.model_statku.getGlobalBounds()))
               {
                objects.erase(objects.begin() + i);
                s1.zdrowie=s1.zdrowie-1;
                if(s1.zdrowie>0){
                s1.zdrowie_.setSize({(s1.zdrowie),20});
                }
                break;
               }
           }
           }
        }
        //
        for(size_t i = 0; i < enemies.size(); i++)
        {
           enemies[i].model_statek.move(enemies[i].currVelocity);
           if(enemies[i].model_statek.getPosition().x>=s1.model_statku.getPosition().x+s1.model_statku.getGlobalBounds().width/2
                   &&enemies[i].model_statek.getPosition().y<s1.model_statku.getGlobalBounds().top){
               enemies[i].model_statek.move( -2.f, 0.f );
           }
           if(enemies[i].model_statek.getPosition().x<s1.model_statku.getPosition().x+s1.model_statku.getGlobalBounds().width/2
                   &&enemies[i].model_statek.getPosition().y<s1.model_statku.getGlobalBounds().top){
               enemies[i].model_statek.move( 2.f, 0.f );
           }
           if(enemies[i].model_statek.getPosition().x>s1.model_statku.getPosition().x&&
                   enemies[i].model_statek.getPosition().x<s1.model_statku.getPosition().x+s1.model_statku.getGlobalBounds().width){
               int time_interval=rand()%100;
               if(time_interval==5||time_interval==10){
               p2.shape.setPosition(enemies[i].model_statek.getGlobalBounds().left+enemies[i].model_statek.getGlobalBounds().width/2,
               enemies[i].model_statek.getGlobalBounds().top+enemies[i].model_statek.getGlobalBounds().height);
               pociski2.push_back(Pocisk(p2));
           }
           }
           if (enemies[i].model_statek.getPosition().x < 0 || enemies[i].model_statek.getPosition().x > App.getSize().x
               || enemies[i].model_statek.getPosition().y < 0 || enemies[i].model_statek.getPosition().y > App.getSize().y
                   ||enemies[i].model_statek.getGlobalBounds().intersects(s1.model_statku.getGlobalBounds()))
           {
               enemies.erase(enemies.begin() + i);
           }
        }
        for (size_t i = 0; i < pociski.size(); i++)
        {
            pociski[i].shape.move(pociski[i].currVelocity);
            if (pociski[i].shape.getPosition().x < 0 || pociski[i].shape.getPosition().x > App.getSize().x
                || pociski[i].shape.getPosition().y < 0 || pociski[i].shape.getPosition().y > App.getSize().y)
            {
                pociski.erase(pociski.begin() + i);
            }
            else
            {
            for (size_t k = 0; k < enemies.size(); k++)
            {
                if (pociski[i].shape.getGlobalBounds().intersects(enemies[k].model_statek.getGlobalBounds()))
                {
                 pociski.erase(pociski.begin() + i);
                 enemies[k].hp_points=enemies[k].hp_points-pociski[i].damage;
                 if(enemies[k].hp_points<=0){
                     enemydown=enemydown+1;
                 enemies.erase(enemies.begin() + k);
                 score1.update(App,50);
                 }
                 break;
                }

            }
            for (size_t k = 0; k < objects.size(); k++)
            {
                if (pociski[i].shape.getGlobalBounds().intersects(objects[k].model_obj.getGlobalBounds()))
                {
                 pociski.erase(pociski.begin() + i);
                 obj_down=obj_down+1;
                 objects.erase(objects.begin() + k);
                 score1.update(App,5);
                 break;
                }

            }
            }

            }
        for (size_t i = 0; i < pociski2.size(); i++)
        {
            pociski2[i].currVelocity=sf::Vector2f(0.0f,5.f);
            pociski2[i].shape.setFillColor(sf::Color::Yellow);
            pociski2[i].shape.move(pociski2[i].currVelocity);
            if (pociski2[i].shape.getPosition().x < 0 || pociski2[i].shape.getPosition().x > App.getSize().x
                || pociski2[i].shape.getPosition().y < 0 || pociski2[i].shape.getPosition().y > App.getSize().y)
            {
                pociski2.erase(pociski2.begin() + i);
            }
            if(pociski2[i].shape.getGlobalBounds().intersects(s1.model_statku.getGlobalBounds())){
                    int damage=rand()%5+10;
                s1.zdrowie=s1.zdrowie-damage;
                if(s1.zdrowie>0){
                s1.zdrowie_.setSize({(s1.zdrowie),20});
                }
                pociski2.erase(pociski2.begin() + i);
            }
        }
    //rysuj
        if(czas.asSeconds()>2)
        {
        clock.restart();
        }
        czas=clock.getElapsedTime();
        std::cout<<czas.asSeconds()<<std::endl;
    s1.ruch(App);
    for (size_t i = 0; i < enemies.size(); i++)
         {
             enemies[i].spawn(App);


         }
    for (size_t i = 0; i < pociski.size(); i++)
         {
             App.draw(pociski[i].shape);
         }
    for (size_t i = 0; i < pociski2.size(); i++)
         {
             App.draw(pociski2[i].shape);
         }
    for (size_t i = 0; i < objects.size(); i++)
         {
             objects[i].spawn(App);
         }
    App.draw(tlo2);
    score1.spawn(App);
    s1.spawn(App);
    App.display();
    }
    return -1;
}

#endif // SCREEN_2_H
