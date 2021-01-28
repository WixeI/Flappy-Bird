#include "Player.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <Central.h>

Player::Player()
{

    pcHitbox.setSize({(central.janelaY*4)/100, (central.janelaY*4)/100});
    pcHitbox.setFillColor(sf::Color(230,20,60));
    pcHitbox.setPosition(posicaoInicialX, posicaoInicialY);

    if (!texPlayer.loadFromFile("C:/Users/paulo/Desktop/Programas/Game1/res/teste2.png")){

        std::cout << "DEU RUIM O SPRITE DO PLAYER, ABIGO" << std::endl;

    }
    spriPlayer.setTexture(texPlayer);
    spriPlayer.setPosition(posicaoInicialX, posicaoInicialY);

}

Player::~Player()
{
    //dtor
}

void Player::updatePcVelocidade() {
    if (pcHitbox.getPosition().y < central.janelaY - (pcHitbox.getSize().y) ||
        pcHitbox.getPosition().y < (pcHitbox.getSize().y)){

        //if (pcHitbox.getPosition().x){
        if (jogavel == true){
            pcVelocidade += central.gravidade;
            pcHitbox.move(0,pcVelocidade);
        }

        spriPlayer.setPosition(pcHitbox.getPosition().x,pcHitbox.getPosition().y);
        //}

    }else {

        pcVelocidade = 0;

    }

}


void Player::pcBaterAsa(){
    if (jogavel == true){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            pcVelocidade = -(central.janelaY/50);
        }

    }

}
