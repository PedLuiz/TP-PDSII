#include "../include/Liga4.hpp"
#include <iostream>

using namespace std;

    Liga4::Liga4 () : Jogo(7, 6){} 

    char Liga4::getVencedor() {}

    bool Liga4::isEstadoFinal() {}

    char Liga4::getTurno() {
        return turno_atual;
    }

    void Liga4::setTurno(){
        if(turno_atual == 'X') turno_atual = 'O';
        else if(turno_atual == 'O') turno_atual = 'X';
        else cerr << "Erro Inesperado: turno_atual possui um valor inválido (" << turno_atual << " )." << endl;
    }

    void Liga4::fazerJogada(pair<int, int> jogada) {
        int coluna = jogada.first;

        if(isJogadaValida(jogada)){
            for(int i=5; i>=0; i--){
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

    Liga4::~Liga4(){}

