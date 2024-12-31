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

vector<int> Reversi::countPieces() const {
    int countX = 0;
    int countO = 0;
    vector<int> resultado;

    for (const auto &linha : tabuleiro) { 
        for (const char &unidade : linha) { 
            if (unidade == 'X') {
                countX++;
            } else if (unidade == 'O') {
                countO++;
            }
        }
    }
    resultado.push_back(countX);
    resultado.push_back(countO);

    return resultado;
}

bool Reversi::estaNoTabuleiro(pair<int, int> jogada) {
    int i = jogada.first;  
    int j = jogada.second; 

    if (i >= 0 && i < 8 && j >= 0 && j < 8) {
        return true; 
    } else {
        return false; 
    }
}

char Reversi::getVencedor(){
    vector<int> resultado;
    if (resultado[0]>resultado[1]){
        return 'X';
    }

    else if (resultado[0]<resultado[1]){
        return 'O';
    }

    else{
        return ' ';
    } 

}
