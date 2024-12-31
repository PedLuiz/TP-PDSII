#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi() : isTurnoX(true), Jogo(8, 8) {
    tabuleiro[3][3] = 'X';
    tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = 'O';
    tabuleiro[4][3] = 'O';
}

vector<pair<int,int>> Reversi::getPossiveisJogadaas() {

}

vector<pair<int, int>> Reversi::getPecasConvertidas(pair<int,int> jogada) {
    // Retorna uma lista de pecas que serao convertidas ao fazer determinada jogada;
    int x_start = jogada.first;
    int y_start = jogada.second;

    if (!estaNoTabuleiro(jogada)) {
        return {};
    }
    
    char jogador = getTurno();

    char other_piece;
    if (jogador == 'X') {
        other_piece = 'O';
    } else {
        other_piece = 'X';
    }

    tabuleiro[x_start][y_start] = jogador;
    
    vector<pair<int, int>> directions = {
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    
    vector<pair<int, int>> pecas_convertidas;

    for (const auto& direcao : directions) {
        int next_x = direcao.first; 
        int next_y = direcao.second; 

        int x = jogada.first;
        int y = jogada.second;

        x += next_x;
        y += next_y;

        if (!estaNoTabuleiro({x, y})) 
            continue;

        while (tabuleiro[x][y] == other_piece) {
            x += next_x;
            y += next_y;

            if (!estaNoTabuleiro({x, y})) 
                break;
        }

        if (!estaNoTabuleiro({x, y}))
            continue;

        if (tabuleiro[x][y] == jogador) {
            // Encontramos a outra peca do mesmo tipo, agora fazemos o caminho inverso e adicionando as
            //  coordenadas ao vetor de pecas convertidas
            while (true) {
                x -= next_x;
                y -= next_y;
                if ((x == x_start) && (y == y_start)) {
                    break;
                }
                pecas_convertidas.push_back({x, y});
            }
        }

        tabuleiro[x_start][y_start] = ' ';
        return pecas_convertidas;
    }
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

bool Reversi::isJogadaValida(pair<int,int> jogada) {
    int curr_x = jogada.first;
    int curr_y = jogada.second;

    if ((tabuleiro[curr_x][curr_y] != ' ') || (!estaNoTabuleiro(jogada))) {
        return false;
    }

    vector<pair<int, int>> pecas_convertidas = getPecasConvertidas(jogada);

    if (pecas_convertidas.size() == 0) 
        return false; 

    return true;
}

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
