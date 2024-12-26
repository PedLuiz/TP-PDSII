#ifndef JOGO_H
#define JOGO_H

#include <vector>

using namespace std;

class Jogo {
protected:
    const int M;
    const int N;
    vector<vector<char>> tabuleiro;

public:
    Jogo (int M, int N); 

    virtual vector<pair<int,int>> getJogadas() = 0;

    virtual char getVencedor() = 0;

    virtual bool isEstadoFinal() = 0;

    virtual char getTurno() = 0;

    virtual void fazerJogada(pair<int, int> jogada) = 0;

    virtual bool isJogadaValida(pair<int,int> jogada) = 0;

    virtual void printTabuleiro();
};


#endif
