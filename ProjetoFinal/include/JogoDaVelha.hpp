#ifndef VELHA_H
#define VELHA_H
#include "Jogo.hpp"

class JogoDaVelha : public Jogo::Jogo {
    public:
        JogoDaVelha();
        char Jogo::getVencedor() override;
        bool Jogo::isEstadoFinal() override;
        char Jogo::getTurno() override;
        void Jogo::fazerJogada(pair<int, int> jogada) override;
        bool Jogo::isJogadaValida(pair<int,int> jogada) override;
          
}

#endif