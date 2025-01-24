#ifndef REVERSI_HPP
#define REVERSI_HPP

/**
 * @file Reversi.hpp
 * @brief Declaração da classe Reversi.
 * 
 * Este arquivo define a classe Reversi, que herda de Jogo e implementa
 * as regras específicas do jogo Reversi. Ele gerencia o tabuleiro,
 * os turnos dos jogadores, e a lógica para determinar o vencedor.
 * 
 */

#include "Jogo.hpp"
#include <vector>
#include <map>

using namespace std;

/**
 * @class Reversi
 * @brief Classe que implementa a lógica do jogo Reversi.
 * 
 * A classe Reversi herda de Jogo e implementa métodos específicos para controlar
 * o fluxo do jogo, validar jogadas, trocar turnos, e verificação de estado final do jogo.
 */
class Reversi : public Jogo {
private:
    /// @brief Controla qual jogador está no turno atual ('X' ou 'O').
    bool isTurnoX;

public:

    /// @brief Construtor
    Reversi();

    /**
     * @brief Obtém as possíveis jogadas para o jogador atual.
     * 
     * Retorna um vetor de pares (linha, coluna) representando as coordenadas
     * válidas para o jogador fazer a próxima jogada.
     * 
     * @return Vetor de pares de inteiros representando as coordenadas de jogadas possíveis.
     */
    vector<pair<int, int>> getPossiveisJogadas();

    /**
     * @brief Obtém as peças que seriam convertidas com uma jogada.
     * 
     * Dado uma jogada, essa função retorna as peças que seriam convertidas,
     * ou seja, as peças adversárias que seriam trocadas de cor.
     * 
     * @param jogada Posição (linha, coluna) da jogada a ser realizada.
     * @return Vetor de pares (linha, coluna) das peças que seriam convertidas.
     */
    vector<pair<int, int>> getPecasConvertidas(pair<int, int> jogada);

    /**
     * @brief Verifica se uma jogada está dentro dos limites do tabuleiro.
     * 
     * Verifica se a posição fornecida (linha, coluna) está dentro do tabuleiro de Reversi.
     * 
     * @param jogada Posição (linha, coluna) da jogada a ser verificada.
     * @return `true` se a jogada está no tabuleiro, `false` caso contrário.
     */
    bool estaNoTabuleiro(pair<int, int> jogada);

    /// @brief Realiza a contagem de peças de cada jogador
    /// @return map que relaciona a peça, `X` ou `O`, ao número
    map<char, int> countPieces() const;

    char getVencedor() override;

    bool isEstadoFinal() override;

    char getTurno() override;

    /// @brief Troca o turno entre os jogadores. 
    void trocaTurno();

    void fazerJogada(pair<int, int> jogada) override;

    bool isJogadaValida(pair<int, int> jogada) override;

    /**
     * @brief Gera um tabuleiro que marca todas as jogadas válidas no turno
     * 
     * Retorna um tabuleiro onde as jogadas válidas no turno atual são marcadas com +,
     * sem fazer a alteração real no tabuleiro.
     * 
     * @return Matriz do tabuleiro possível
     */
    vector<vector<char>> getTabuleiroPossivel();

    /// @brief Printa o tabuleiro atualizado com as jogadas válidas do turno atual
    void printTabuleiroPossivel();

    void printTabuleiro() override;

};

#endif // REVERSI_HPP
