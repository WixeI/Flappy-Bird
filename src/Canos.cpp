#include <iostream>
#include "Canos.h"
#include <SFML/Graphics.hpp>
#include <Central.h>
#include <Player.h>

Canos::Canos()
{

    canoAlto.setSize({tamanhoX, tamanhoYCanoAlto});
    canoAlto.setPosition(posicaoX, posicaoYCanoAlto);
    canoAlto.setFillColor(sf::Color(60, 170, 20));

    canoBaixo.setSize({tamanhoX, tamanhoYCanoBaixo});
    canoBaixo.setPosition(posicaoX, posicaoYCanoBaixo);
    canoBaixo.setFillColor(sf::Color(60, 170, 20));

    /// INICIALIZAÇÃO DOS SPRITES DO CANO DE CIMA
    texture.loadFromFile("C:/Users/paulo/Desktop/Programas/Game1/res/canoRepete.png");
    sprite.setTexture(texture);

    sprite.setPosition(posicaoX - 2, posicaoYCanoAlto);
    sprite.setTextureRect(sf::IntRect(0, 0, 34, int(posicaoYCanoAlto + tamanhoYCanoAlto) - 30));

    textureBocaDoCano.loadFromFile("C:/Users/paulo/Desktop/Programas/Game1/res/bocaDoCano.png");
    spriteBocaDoCano.setTexture(textureBocaDoCano);
    spriteBocaDoCano.setPosition(posicaoX - 2, tamanhoYCanoAlto - 30);

    /// INICIALIZAÇÃO DOS SPRITES DO CANO DE BAIXO

    spriteBaixo.setTexture(texture);
    spriteBocaDoCanoBaixo.setTexture(textureBocaDoCano);

    spriteBaixo.setPosition(posicaoX, posicaoYCanoBaixo + 30);
    spriteBaixo.setTextureRect(sf::IntRect(0, 0, 34, int(tamanhoYCanoBaixo) - 30));
    textureBocaDoCanoBaixo.loadFromFile("C:/Users/paulo/Desktop/Programas/Game1/res/bocaDoCanoBaixo.png");
    spriteBocaDoCanoBaixo.setTexture(textureBocaDoCanoBaixo);
    spriteBocaDoCanoBaixo.setPosition(posicaoX + tamanhoX + 2, canoBaixo.getPosition().y);

}

Canos::~Canos()
{
    //dtor
}

void Canos::updateCanos() {
    if (central.jogavel == true){
        if (canoAlto.getPosition().x + tamanhoX > 0) {
            canoAlto.move(velocidadeCanos,0);
            canoBaixo.move(velocidadeCanos,0);

            sprite.setPosition(canoAlto.getPosition().x - 2, canoAlto.getPosition().y);
            spriteBocaDoCano.setPosition(canoAlto.getPosition().x - 2, canoAlto.getSize().y - 30);

            spriteBaixo.setPosition(canoBaixo.getPosition().x - 2, canoBaixo.getPosition().y + 30);
            spriteBocaDoCanoBaixo.setPosition(canoBaixo.getPosition().x - 2, canoBaixo.getPosition().y);

        } else {

            tamanhoYCanoAlto = (rand() % (central.janelaY*70)/100) + ((central.janelaY * 5)/100);
            posicaoYCanoBaixo = tamanhoYCanoAlto + abertura;

            canoAlto.setSize({tamanhoX, tamanhoYCanoAlto});

            canoBaixo.setSize({tamanhoX, (central.janelaY - tamanhoYCanoAlto) - abertura});

            canoAlto.setPosition(posicaoX, posicaoYCanoAlto);
            canoBaixo.setPosition(posicaoX, posicaoYCanoBaixo);

            sprite.setPosition(canoAlto.getPosition().x - 2, canoAlto.getPosition().y);
            sprite.setTextureRect(sf::IntRect(0, 0, 34, int(posicaoYCanoAlto + tamanhoYCanoAlto) - 30));

            spriteBaixo.setPosition(canoBaixo.getPosition().x -2, canoBaixo.getPosition().y + 30);
            spriteBaixo.setTextureRect(sf::IntRect(0, 0, 34, int(tamanhoYCanoBaixo) - 30));
            spriteBocaDoCanoBaixo.setPosition(canoBaixo.getPosition().x + tamanhoX + 2, canoBaixo.getPosition().y);

        }

    }

}

void Canos::colisao(Player* player){

    /// CHECAR SE O CANO JÁ PASSOU DO PLAYER
    if (player->pcHitbox.getPosition().x - (canoAlto.getPosition().x + canoAlto.getSize().x) < 0 ){
       /// COLISÃO COM AMBOS OS CANOS EM X
        if (canoAlto.getPosition().x - (player->posicaoInicialX + player->pcHitbox.getSize().x) < 0){

            ///COLISÃO COM O CANO ALTO EM Y
            if (player->pcHitbox.getPosition().y - (canoAlto.getPosition().y + canoAlto.getSize().y) < 0){

                central.jogavel = false;
                player->pcHitbox.setFillColor(sf::Color(60,20,230));
                player->spriPlayer.setColor(sf::Color(255,100,100));
                player->jogavel = false;

            }

            ///COLISÃO COM O CANO BAIXO EM Y
            if (canoBaixo.getPosition().y - (player->pcHitbox.getPosition().y + player->pcHitbox.getSize().y) < 0){

                central.jogavel = false;
                player->pcHitbox.setFillColor(sf::Color(60,20,230));
                player->spriPlayer.setColor(sf::Color(255,100,100));
                player->jogavel = false;
            }

        }


    }

}
