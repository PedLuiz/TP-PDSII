#include "Liga4.hpp"
#include <iostream>

using namespace std;

    Liga4::Liga4 () : Jogo(7, 6){} 

    char Liga4::getVencedor() {
    // Verificar linhas, colunas e todas as diagonais para encontrar um vencedor
    for (int linha = 0; linha < 6; linha++) {
        for (int coluna = 0; coluna < 7; coluna++) {
            char jogador = tabuleiro[coluna][linha];
            if (jogador != ' ') {
                // Verificar horizontal
                if (coluna + 3 < 7 &&
                    jogador == tabuleiro[coluna + 1][linha] &&
                    jogador == tabuleiro[coluna + 2][linha] &&
                    jogador == tabuleiro[coluna + 3][linha]) {
                    return jogador;
                }
                // Verificar vertical
                if (linha + 3 < 6 &&
                    jogador == tabuleiro[coluna][linha + 1] &&
                    jogador == tabuleiro[coluna][linha + 2] &&
                    jogador == tabuleiro[coluna][linha + 3]) {
                    return jogador;
                }
                // Verificar diagonal descendente
                if (coluna + 3 < 7 && linha + 3 < 6 &&
                    jogador == tabuleiro[coluna + 1][linha + 1] &&
                    jogador == tabuleiro[coluna + 2][linha + 2] &&
                    jogador == tabuleiro[coluna + 3][linha + 3]) {
                    return jogador;
                }
                // Verificar diagonal ascendente
                if (coluna + 3 < 7 && linha - 3 >= 0 &&
                    jogador == tabuleiro[coluna + 1][linha - 1] &&
                    jogador == tabuleiro[coluna + 2][linha - 2] &&
                    jogador == tabuleiro[coluna + 3][linha - 3]) {
                    return jogador;
                    }
                }
            }
        }
    return ' '; // Sem vencedor
    }

    bool Liga4::isEstadoFinal() {
    if (getVencedor() != ' ') return true;

    // Verificar se o tabuleiro está cheio
    for (int coluna = 0; coluna < 7; coluna++) {
        if (tabuleiro[coluna][0] == ' ') return false;
    }

    return true; // Tabuleiro cheio ou há um vencedor
    }

    char Liga4::getTurno() {
        return turno_atual;
    }

    void Liga4::setTurno(){//troca o turno a cada jogada válida
        if(turno_atual == 'X') turno_atual = 'O';
        else if(turno_atual == 'O') turno_atual = 'X';
        else cerr << "Erro Inesperado: turno_atual possui um valor inválido (" << turno_atual << " )." << endl;
    }

    void Liga4::fazerJogada(pair<int, int> jogada) {
        int coluna = jogada.first;

        if(isJogadaValida(jogada)){
            for(int i=5; i>=0; i--){//percorre a coluna de baixo pra cima até encontrar a primeira casa vazia
                if(tabuleiro[coluna-1][i]=='X' || tabuleiro[coluna-1][i]=='O')
                    continue;
                else{
                    tabuleiro[coluna-1][i] = turno_atual;
                    Liga4::setTurno();
                    return;
                }
            }
        }
        else
            cout << "Digite uma coluna válida: ";
    }

    bool Liga4::isJogadaValida(pair<int, int> jogada) {
        int coluna = jogada.first;

        if(coluna>=1 && coluna<=7){
            if(tabuleiro[coluna-1][0]=='X' || tabuleiro[coluna-1][0]=='O'){
                cout << "Coluna escolhida já foi totalmente preenchida!" << endl;
                return false;
                }
                else return true;
        }
            else {
                cout << "Coluna Inválida! Escolha entre 1 e 7" << endl;
                return false;
            }
    }

    void Liga4::printTabuleiro(){
            cout << "Tabuleiro atual:" << endl;
        for (int linha = 0; linha < 6; linha++) {
            for (int coluna = 0; coluna < 7; coluna++) {
                cout << '|' << tabuleiro[linha][coluna];
            }
            cout << '|' << endl;
        }
        cout << "1  2  3  4  5  6  7" << endl; // Para indicar as colunas
    }

    Liga4::~Liga4(){}

