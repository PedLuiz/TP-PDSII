#include "JogoDaVelha.hpp"
#include <iostream>

JogoDaVelha::JogoDaVelha() : Jogo(3, 3) {
    turno = 'X';
}

char JogoDaVelha::getVencedor(){
    //checa colunas:
    for (int j=0; j<3; j++){
        if (tabuleiro[0][j] != ' '){
            bool vencedorFound = true;
            for (int i=1; i<3; i++){
                char anterior = tabuleiro[i-1][j];
                if (tabuleiro[i][j] != anterior) vencedorFound = false;
            }
            if (vencedorFound == true) return tabuleiro[0][j];
        }
    }
    //checa linhas:
    for (int i=0; i<3; i++){
        if (tabuleiro[i][0]!=' '){
            bool vencedorFound = true;
            for (int j=1; j<3; j++){
                char anterior = tabuleiro[i][j-1];
                if (tabuleiro[i][j] != anterior) vencedorFound = false;
            }
            if (vencedorFound == true) return tabuleiro[i][0];
        }
    }
    //checa diagonais:
        //diagonal principal:
    if (tabuleiro[0][0] != ' '){
        bool vencedorFound = true;
        for (int i=1; i<3; i++){
            char anterior = tabuleiro[i-1][i-1];
                if (tabuleiro[i][i] != anterior) vencedorFound = false;
        }
        if (vencedorFound == true) return tabuleiro[0][0];
    }
        //diagonal secundária:
    if (tabuleiro[2][0] != ' '){
        bool vencedorFound = true;
        for (int i=1; i>=0; i--){
            int j=1;
            char anterior = tabuleiro[i+1][j-1];
            if (tabuleiro[i][j] != anterior) vencedorFound = false;
            j++;
        }
        if (vencedorFound == true) return tabuleiro[2][0];
    }
    return ' ';
}

bool JogoDaVelha::isEstadoFinal(){
    bool estado_final = true;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (tabuleiro[i][j] == ' ') {
                estado_final = false;
                return estado_final;
            }
        }
    }
    return estado_final;
}

void JogoDaVelha::alternaTurno(){
    if (turno == 'X') turno = 'O';
    else turno = 'X';
}

char JogoDaVelha::getTurno(){
    return turno;
}

bool JogoDaVelha::isJogadaValida(std::pair<int,int> jogada){
    if (jogada.first > 0 && jogada.first < 4 && jogada.second > 0 && jogada.second < 4) {
        if (tabuleiro[jogada.first-1][jogada.second-1] == ' ') return true;
    }
    std::cout << "ERRO: jogada inválida" << std::endl;
    return false;
}

void JogoDaVelha::fazerJogada(std::pair<int, int> jogada){
    tabuleiro[jogada.first-1][jogada.second-1] = turno;
}

void JogoDaVelha::printTabuleiro(){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            std::cout << tabuleiro[i][j];
            if(j<2) std::cout << "|";
            else std::cout << std::endl;
        }
    }
}