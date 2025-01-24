#ifndef JOGO_HPP
#define JOGO_HPP

/**
 * @file Jogo.hpp
 * @brief Declaração da classe Jogo e métodos relacionados
 * 
 * Este arquivo define a classe base para os diferentes jogos de tabuleiro.
 * Ele contém métodos virtuais puros que precisam ser implementados em quaisquer
 * classes derivadas
 */

#include <vector>

using namespace std;

/**
 * @class Jogo
 * @brief Classe abstrata para jogos de tabuleiro.
 * 
 * Estabelece a interface e interações básicas esperadas de um jogo de tabuleiro.
 *  
 */

class Jogo {
protected:
    /// @brief Número de linhas
    const int M;

    /// @brief Número de colunas 
    const int N;

    /// @brief Matriz de armazenamento do tabuleiro
    vector<vector<char>> tabuleiro;

public:
    /// @brief Construtor.
    /// @param M Dimensão das linhas.
    /// @param N Dimensão das colunas.
    Jogo (int M, int N); 

    /// @brief Metodo que determina o vencedor do Jogo.
    /// @return Caracteres 'X' ou 'O' relativos a peça do jogador vencedor ou ' ' em caso de empate.
    virtual char getVencedor() = 0;

    /// @brief Checa se o jogo terminou
    /// @return `true` se não existem jogadas disponíveis, `false` caso contrário
    virtual bool isEstadoFinal() = 0;

    /// @brief Retorna qual jogador possui o turno atual
    /// @return 'X' ou 'O'.
    virtual char getTurno() = 0;

    ///@brief Recebe um par de coordenadas (i, j) e, se for uma jogada valida, atualiza o tabuleiro conforme o jogador que tem o turno.
    virtual void fazerJogada(pair<int, int> jogada) = 0;

    /// @brief Retorna, a depender das regras específicas de cada jogo, se uma jogada é válida
    /// @param jogada 
    virtual bool isJogadaValida(pair<int,int> jogada) = 0;

    /// @brief Impressão no terminal do tabuleiro do jogo.
    virtual void printTabuleiro();
};


#endif
