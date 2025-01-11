#ifndef CAMPOMINADO_H
#define CAMPOMINADO_H

#include "Jogo.hpp"
#include <utility>

using namespace std;

class CampoMinado : public Jogo {
private:
    int linhas;
    int colunas;
    int numBombas;
    bool jogoAtivo;
    int jogadasRestantes;

    vector<vector<char>> tabuleiro;
    void colocarBombas();
    int contarBombasAdjacentes(int linha, int coluna) const;

public:
    CampoMinado(int linhas, int colunas, int numBombas);
    char getVencedor() override;
    bool isEstadoFinal() override;
    void fazerJogada(pair<int, int> jogada) override;
    bool isJogadaValida(pair<int, int> jogada) override;
    void colocarSinalizador(pair<int, int>) override;
    void revelarTabuleiro();
    
    ~CampoMinado();
};

#endif
