#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <Central.h>

class Player
{
    public:
        /// ATRIBUTOS
        float posicaoInicialX = central.janelaX/6.5;
        float posicaoInicialY = central.janelaY/3.5;
        float pcVelocidade = 0;

        bool jogavel = true;

        sf::RectangleShape pcHitbox;

        sf::Texture texPlayer;
        sf::Sprite spriPlayer;

        /// MÉTODOS
        Player();

        virtual ~Player();

        void updatePcVelocidade();

        void pcBaterAsa();


    protected:

    private:
};

#endif // PLAYER_H
