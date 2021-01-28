#include "cano.h"
#include <SFML/Graphics.hpp>
#include <Central.h>

cano::cano(int x)

{
    cano::x = x;
    hitbox.setSize(sf::Vector2f(x,50));
    hitbox.setPosition(200, 200);
    hitbox.setFillColor(sf::Color(20,222,120));
}


void cano::criaCano (sf::RenderWindow &window){


            window.draw(hitbox);


        }


cano::~cano()
{
    //dtor
}

