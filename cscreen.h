#ifndef CSCREEN_H
#define CSCREEN_H
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <stdlib.h>
#include <vector>


class cScreen
{
public :
    virtual int Run (sf::RenderWindow &App) = 0;
};

#endif // CSCREEN_H
