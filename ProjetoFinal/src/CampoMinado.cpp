#include "CampoMinado.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

CampoMinado::CampoMinado(int linhas, int colunas, int numBombas) :
    Jogo(colunas, linhas),
    numBombas(numBombas),
    perdedor(' '),
    jogoAtivo(true),
    jogadasRestantes(linhas*colunas-numBombas),
    count_jogadas(0),
    tabuleiro_visivel(colunas, vector<char>(linhas, ' ')){
    }

void CampoMinado::colocarBombas() 
{
    srand(time(nullptr)); 
    int bombasColocadas = 0;

    while (bombasColocadas < numBombas) 
    {
        int linha = rand() % linhas;
        int coluna = rand() % colunas;

        if (tabuleiro_visivel[linha][coluna] != 'B') 
        {
            tabuleiro_visivel[linha][coluna] = 'B';
            bombasColocadas++;
        }
    }
}


int CampoMinado::contarBombasAdjacentes(int linha, int coluna) const{}

void CampoMinado::colocarSinalizador(pair<int, int>){}

char CampoMinado::getVencedor(){
    if(perdedor == ' ')  return ' ';//empate
    else if(perdedor == 'O') return 'X';
    else if(perdedor == 'X') return 'O';
    else cerr << "Perdedor está com um valor inválido: (" << perdedor << "). Corrigir erro!!!" << endl;
}

bool CampoMinado::isEstadoFinal(){
    if(jogadasRestantes <= 0){
        jogoAtivo = false;
        return true;
    }
        else if(jogoAtivo == false) return true;
        else return false;
}

void CampoMinado::setTurno(){//troca de turno a cada jogada válida
    if(turno_atual == 'X') turno_atual = 'O';
        else if(turno_atual == 'O') turno_atual = 'X';
        else cerr << "Erro Inesperado: turno_atual possui um valor inválido (" << turno_atual << " )." << endl;
}

char CampoMinado::getTurno(){
    return turno_atual;
}


void CampoMinado::fazerJogada(pair<int, int> jogada){
    int coluna_jogada, linha_jogada;
    coluna_jogada = jogada.first;
    linha_jogada = jogada.second;
    if(isJogadaValida(jogada)){
        tabuleiro[coluna_jogada][linha_jogada] = tabuleiro_visivel[coluna_jogada][linha_jogada];
        jogadasRestantes -= 1;
        count_jogadas += 1;
        if(tabuleiro[coluna_jogada][linha_jogada] == 'B'){
            //Inicialmente perdedor = ' ', se um jogador perder na rodada anterior, o atributo perdedor vai ser setado como 'X' ou 'O'
            //Caso na próxima jogada o outro jogador perca, será considerado empate
            if(perdedor == 'O' || perdedor == 'X'){
                perdedor = ' ';
            }
            perdedor = turno_atual;
            //o jogo só irá ser encerrado se um jogador encontrar uma primeira bomba e os dois jogadores tiverem a mesma quantidade de jogadas;
            if(count_jogadas%2==0) jogoAtivo = false;
        }
        setTurno();
    }
}

bool CampoMinado::isJogadaValida(pair<int, int> jogada){
    int coluna_jogada, linha_jogada;
    coluna_jogada = jogada.first;
    linha_jogada = jogada.second;
    if(coluna_jogada <= colunas && coluna_jogada >0 && linha_jogada <= linhas && linha_jogada > 0){
        if(tabuleiro_visivel[coluna_jogada][linha_jogada] == ' ')
            return true;
            else{
                cout << "A coordenada já está revelada! Por favor escolha outra." << endl;
                return false;
            }
    }
    else{
        cout << "Coordenada inválida! Por favor Escolha uma coluna entre 1 a " <<colunas<< " e linha entre 1 a " << linhas << "." << endl;
        return false;
    }
}

void CampoMinado::printTabuleiro(){//imprime o tabuleiro apenas com as já escolhidas pelos jogadores
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "| " << tabuleiro_visivel[i][j]  << " ";
        }
        cout << "|" << endl << endl;
    }
}

void CampoMinado::revelarTabuleiro(){//Revela o tabuleiro com todas as bombas
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            cout << "| " << tabuleiro[i][j]  << " ";
        }
        cout << "|" << endl << endl;
    }
}

CampoMinado::~CampoMinado() {
    // Destrutor
}

