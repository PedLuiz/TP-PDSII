#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi() : isTurnoX(true), Jogo(8, 8) {
    tabuleiro[3][3] = 'X';
    tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = 'O';
    tabuleiro[4][3] = 'O';
}


char Reversi::getVencedor() {

}

bool Reversi::isEstadoFinal() {}

char Reversi::getTurno() {
    if (isTurnoX) {
        isTurnoX = false;
        return 'X';
    } else {
        isTurnoX = true;
        return 'O';
    }
}



void Reversi::fazerJogada(pair<int, int> jogada) { //jogada = (x, y)
    int x = jogada.first;
    int y = jogada.second;

    if (isJogadaValida(jogada)) {
        char jogador = getTurno();
        tabuleiro[x][y] = jogador;
    } else {
        cout << "ERRO: jogada invalida" << endl;
    }
}

bool Reversi::isJogadaValida(pair<int,int> jogada) {}

int main () {
    Reversi* test = new Reversi(); 

    test->printTabuleiro();
    return 0;
}