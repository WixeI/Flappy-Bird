#ifndef CENTRAL_H
#define CENTRAL_H
#include <SFML/Graphics.hpp>


static class Central {
public:

            Central();
            virtual ~Central();

    ///INFORMA��ES DA JANELA
        /// ATRIBUTOS
            int janelaX = 300;
            int janelaY = 450;
            int framerate = 30;

        /// M�TODOS
            void getJanela (sf::RenderWindow &window);



    /// MEDIDAS DE TEMPO
        /// ATRIBUTOS
            sf::Clock relogio;

            float delay = 0;

        /// M�TODOS


    /// FOR�AS
        /// ATRIBUTOS
            float gravidade = janelaY/300;

        /// M�TODOS


    ///  CONTROLES DO JOGO
        /// ATRIBUTOS
            bool jogavel = true;

        /// M�TODOS

    ///  COLIS�ES
        /// ATRIBUTOS


        /// M�TODOS




private:

protected:


}central;

#endif // CENTRAL_H
