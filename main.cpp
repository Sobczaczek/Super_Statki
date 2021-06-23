#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <screens.h>

int main(int argc, char** argv)
{
    std::vector<cScreen*> Screens;
    int screen = 0;
    sf::RenderWindow App(sf::VideoMode(800,800), "SUPER SPACESHIPS");
    App.setFramerateLimit(60);

    screen_0 s0;
    Screens.push_back(&s0);
    screen_1 s1;
    Screens.push_back(&s1);
    screen_2 s2;
    Screens.push_back(&s2);
    screen_3 s3;
    Screens.push_back(&s3);
    screen_4 s4;
    Screens.push_back(&s4);
    screen_5 s5;
    Screens.push_back(&s5);

    while (screen >= 0)
    {
        screen = Screens[screen]->Run(App);
    }

    return EXIT_SUCCESS;
}
