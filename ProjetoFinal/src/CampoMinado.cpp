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

int CampoMinado::contarBombasAdjacentes(int linha, int coluna) const 
{
    int contador = 0;
    for (int i = -1; i <= 1; i++) 
    {
        for (int j = -1; j <= 1; j++) 
        {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < linhas &&
                novaColuna >= 0 && novaColuna < colunas &&
                tabuleiro_visivel[novaLinha][novaColuna] == 'B') 
            {
                contador++;
            }
        }
    }
    return contador;
}

void CampoMinado::colocarSinalizador(pair<int, int> jogada) 
{
    int linha = jogada.first;
    int coluna = jogada.second;

    if (tabuleiro_visivel[linha][coluna] == ' ') 
    {
        tabuleiro_visivel[linha][coluna] = 'F'; 
    } 
    else if (tabuleiro_visivel[linha][coluna] == 'F') 
    {
        tabuleiro_visivel[linha][coluna] = ' ';
    } 
    else 
    {
        cout << "Não é possível colocar um sinalizador nesta célula." << endl;
    }
}



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
    int coluna, linha;
    linha = jogada.first;
    coluna = jogada.second;
    if(isJogadaValida(jogada)){
        tabuleiro[linha][coluna] = tabuleiro_visivel[linha][coluna];
        jogadasRestantes -= 1;
        count_jogadas += 1;
        if(tabuleiro[linha][coluna] == 'B'){
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
    int coluna, linha;
    coluna = jogada.first;
    linha = jogada.second;
    if(coluna <= colunas && coluna >0 && linha <= linhas && linha > 0){
        if(tabuleiro_visivel[linha][coluna] == ' ')
            return true;
            else{
                cout << "A coordenada já está revelada! Por favor escolha outra." << endl;
                return false;
            }
    }
    else{
        cout << "Coordenada inválida! Por favor Escolha uma coluna entre 1 a " << M << " e linha entre 1 a " << N << "." << endl;
        return false;
    }
}

void CampoMinado::printTabuleiro() {
    // Imprime os índices das colunas
    cout << "    ";  // Espaço para os índices das linhas
    for (int j = 0; j < colunas; j++) {
        cout << j << "   ";  // Índice da coluna
    for (int j = 0; j < M; j++) {
        cout << j+1 << "   ";  // Índice da coluna
    }
    cout << endl;

    // Imprime o tabuleiro linha por linha, com os índices das linhas
    for (int i = 0; i < linhas; i++) {
        cout << i << " ";  // Índice da linha
        for (int j = 0; j < colunas; j++) {
            cout << "| " << tabuleiro_visivel[i][j] << " ";
    for (int i = 0; i < N; i++) {
        cout << i+1 << " ";  // Índice da linha
        for (int j = 0; j < M; j++) {
            cout << "| " << tabuleiro_visivel[j][i] << " ";
        }
        cout << "|" << endl << endl;
    }
}

void CampoMinado::revelarTabuleiro() {
    // Imprime os índices das colunas
    cout << "    ";  // Espaço para os índices das linhas
    for (int j = 0; j < M; j++) {
        cout << j+1 << "   ";  // Índice da coluna
    }
    cout << endl;

    // Imprime o tabuleiro linha por linha, com os índices das linhas
    for (int i = 0; i < N; i++) {
        cout << i+1 << " ";  // Índice da linha
        for (int j = 0; j < M; j++) {
            cout << "| " << tabuleiro_visivel[j][i] << " ";
        }
        cout << "|" << endl << endl;
    }
}

CampoMinado::~CampoMinado() {
    // Destrutor
}

