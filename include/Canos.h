#ifndef CANOS_H
#define CANOS_H
#include <SFML/Graphics.hpp>
#include <Central.h>
#include <Player.h>
#include <stdlib.h>


class Canos
{
    public:
        /// ATRIBUTOS
        sf::RectangleShape canoAlto;
        sf::RectangleShape canoBaixo;

        float tamanhoX = central.janelaX/10;
        float abertura = (central.janelaY * 20)/100;
        float tamanhoYCanoAlto = (rand() % (central.janelaY*75)/100) + ((central.janelaY * 5)/100);
        float tamanhoYCanoBaixo = (central.janelaY - tamanhoYCanoAlto) - abertura;

        float posicaoX = central.janelaX;
        float posicaoYCanoAlto = 0;
        float posicaoYCanoBaixo = tamanhoYCanoAlto + abertura;

        float velocidadeCanos = -(central.janelaX/100);


        ///SPRITES DO CANO DE CIMA
        sf::Texture texture;
        sf::Sprite sprite;
        sf::Texture textureBocaDoCano;
        sf::Sprite spriteBocaDoCano;

        ///SPRITES DO CANO DE BAIXO
        sf::Texture textureBocaDoCanoBaixo;
        sf::Sprite spriteBocaDoCanoBaixo;
        sf::Sprite spriteBaixo;

        /// MÉTODOS
        Canos();
        virtual ~Canos();

        void updateCanos();

        void colisao(Player* player);

    protected:

    private:
};

#endif // CANOS_H
