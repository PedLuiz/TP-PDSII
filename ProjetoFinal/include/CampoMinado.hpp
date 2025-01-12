#ifndef CAMPOMINADO_H
#define CAMPOMINADO_H

#include "Jogo.hpp"
#include <utility>

using namespace std;

class CampoMinado : public Jogo {
private:
    int linhas;
    int colunas;
    char turno_atual;
    char perdedor;
    int numBombas;
    bool jogoAtivo;
    int jogadasRestantes;

    vector<vector<char>> tabuleiro_visivel;
    void colocarBombas();
    int contarBombasAdjacentes(int linha, int coluna) const;

public:
    CampoMinado(int linhas, int colunas, int numBombas);
    char getVencedor() override;
    void setTurno();
    char getTurno();
    bool isEstadoFinal() override;
    void fazerJogada(pair<int, int> jogada) override;
    bool isJogadaValida(pair<int, int> jogada) override;
    void colocarSinalizador(pair<int, int>);
    void printTabuleiro() override;
    void revelarTabuleiro();
    
    ~CampoMinado();
};

#endif
