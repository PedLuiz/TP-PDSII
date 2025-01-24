#ifndef VELHA_HPP
#define VELHA_HPP

/**
 * @file JogoDaVelha.hpp
 * @brief Declaração do Jogo da Velha.
 * 
 * Este arquivo define a classe derivada Jogo da Velha, herdeira de Jogo. Implementa regras
 * específicas e gerencia a lógica do jogo e controle do tabuleiro. 
 */

#include "Jogo.hpp"

/**
 * @class JogoDaVelha
 * @brief Classe que implementa a lógica do Jogo da Velha
 * 
 * A classe JogoDaVelha herda de Jogo e implementa seus métodos virtuais puros,
 * controle de turno, validação de jogadas além de verificar o término do jogo.
 */
class JogoDaVelha : public Jogo {
    private:
        char turno;
    public:
        /// @brief Construtor.
        JogoDaVelha();

        char getVencedor() override;

        bool isEstadoFinal() override;

        /// @brief Faz a troca de turnos entre os jogadores
        void alternaTurno();

        char getTurno() override;

        /// @brief Retorna, a depender das regras específicas de cada jogo, se uma jogada é válida
        /// @param jogada 
        bool isJogadaValida(std::pair<int,int> jogada) override;
        
        ///@brief Recebe um par de coordenadas (i, j) e, se for uma jogada valida, atualiza o tabuleiro conforme o jogador que tem o turno.
        void fazerJogada(std::pair<int, int> jogada) override;
        
        void printTabuleiro();
};

#endif