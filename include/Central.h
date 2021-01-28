#ifndef CENTRAL_H
#define CENTRAL_H
#include <SFML/Graphics.hpp>


static class Central {
public:

            Central();
            virtual ~Central();

    ///INFORMAÇÕES DA JANELA
        /// ATRIBUTOS
            int janelaX = 300;
            int janelaY = 450;
            int framerate = 30;

        /// MÉTODOS
            void getJanela (sf::RenderWindow &window);



    /// MEDIDAS DE TEMPO
        /// ATRIBUTOS
            sf::Clock relogio;

            float delay = 0;

        /// MÉTODOS


    /// FORÇAS
        /// ATRIBUTOS
            float gravidade = janelaY/300;

        /// MÉTODOS


    ///  CONTROLES DO JOGO
        /// ATRIBUTOS
            bool jogavel = true;

        /// MÉTODOS

    ///  COLISÕES
        /// ATRIBUTOS


        /// MÉTODOS




private:

protected:


}central;

#endif // CENTRAL_H
