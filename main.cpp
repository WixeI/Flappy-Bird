#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>

#include <Player.h>
#include <Canos.h>

using namespace sf;


int main()
{
    /// FRAMERATE E RENDER DE JANELA
    sf::RenderWindow window(sf::VideoMode(central.janelaX, central.janelaY), "Fake Bird");
    window.setFramerateLimit(30);

    /// OBJETOS CRIADOS

    int teste = 0;

    srand(time(NULL));

    Player flappy;

    Canos canin[3];

    int canosNaTela = 1;

    /// FUNÇÕES

    /// FUNDO
    sf::Texture texturaFundo;
    sf::Sprite spriteFundo;
    texturaFundo.loadFromFile("C:/Users/paulo/Desktop/Programas/Game1/res/fundo3.png");
    spriteFundo.setTexture(texturaFundo);

    /// JANELA ABERTA
    while (window.isOpen())
    {


        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        teste++;

        /// CASO QUEIRA COLOCAR UM TIQUE
        if (central.relogio.getElapsedTime().asSeconds() >= central.delay){


        /// SISTEMA DE COLISÃO
        int cont = 0;
        while (cont != 3){
            canin[cont].colisao(&flappy);
            cont++;
        }
        cont = 0;


        /// UPDATE
        flappy.updatePcVelocidade();


        if (teste % 56 == 0 && canosNaTela <2 /*&& central.relogio.getElapsedTime().asSeconds() > 1*/){

            canosNaTela ++;
            central.relogio.restart();
        }






        /// DESENHO
        window.clear(sf::Color(220, 220, 255));
        window.draw(spriteFundo);



        //window.draw(flappy.pcHitbox);
        window.draw(flappy.spriPlayer);

        for (int i = 0; i < canosNaTela; i++){
            canin[i].updateCanos();
            window.draw(canin[i].canoAlto);
            window.draw(canin[i].canoBaixo);

        }

        while(cont != 3){
            window.draw(canin[cont].sprite);
            window.draw(canin[cont].spriteBocaDoCano);

            window.draw(canin[cont].spriteBaixo);
            window.draw(canin[cont].spriteBocaDoCanoBaixo);
            cont++;
        }



        /*for (int i = 0; i < canosNaTela; i++){
        window.draw(canin[i].canoAlto);
        window.draw(canin[i].canoBaixo);
        }*/

        window.display();



        /// PARTE DO TIQUE
        //relogio.restart();

        }
        /// COMANDOS DE TECLADO
        flappy.pcBaterAsa();


    }

    return 0;
}






