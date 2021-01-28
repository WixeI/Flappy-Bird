#include "Central.h"
#include <SFML/Graphics.hpp>


Central::Central()
{
    //ctor
}

Central::~Central()
{
    //dtor
}

void Central::getJanela (sf::RenderWindow &window) {


    janelaX = window.getSize().x;
    janelaY = window.getSize().y;

}

