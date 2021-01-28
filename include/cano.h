#ifndef CANO_H
#define CANO_H
#include <SFML/Graphics.hpp>
#include <Central.h>

class cano
{
    public:
        int abertura = 80;
        int x;
        int y = (400 - abertura);
        sf::RectangleShape hitbox;


        void criaCano (sf::RenderWindow &window);
        cano(int x);
        virtual ~cano();


    protected:

    private:



};

#endif // CANO_H
