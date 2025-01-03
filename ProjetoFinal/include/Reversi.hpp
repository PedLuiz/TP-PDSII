#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "Jogo.hpp"
#include <vector>

using namespace std;

class Reversi : public Jogo{
private:
    bool isTurnoX;

public:
    Reversi();

    vector<pair<int,int>> getPossiveisJogadaas();

    bool estaNoTabuleiro(pair<int,int> jogada);

    vector<int> countPieces() const; 

    char getVencedor() override;

    bool isEstadoFinal() override;

    char getTurno() override;

    void fazerJogada(pair<int, int> jogada) override;

    bool isJogadaValida(pair<int,int> jogada);

};

#endif