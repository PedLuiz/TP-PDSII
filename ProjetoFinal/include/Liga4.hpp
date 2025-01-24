#ifndef LIGA4_HPP
#define LIGA4_HPP

/**
 * @file Liga4.hpp
 * @brief Declaração do Liga4
 * 
 * Este arquivo define a classe derivada Liga4, herdeira de Jogo, que implementa a lógica
 * e regras específicas do jogo Liga4. Ele gerencia o tabuleiro, turno dos jogadores
 * e a lógica de determinação do vencedor. 
 */

#include "Jogo.hpp"

using namespace std;

/**
 * @class Liga4
 * @brief Classe que implementa a lógica do jogo Liga4
 * 
 * A classe Liga4 herda de Jogo e além de implementar os métodos virtuais puros da classe abstrata pai,
 * estabelece funções específicas de validação de jogadas, troca de turnos e verificação de estado final
 */
class Liga4 : public Jogo {
private:
    int contador_jogadas = 0;
    char turno_atual = 'X';
public:
    
    /// @brief Construtor
    Liga4();
    char getVencedor() override;
    bool isEstadoFinal() override;
    char getTurno() override;

    /// @brief Realiza a troca de turnos entre os jogadores
    void setTurno();
    void fazerJogada(pair<int, int> jogada) override;
    bool isJogadaValida(pair<int, int> jogada) override;
    void printTabuleiro() override;

    /// @brief Destrutor
    ~Liga4();
};

#endif
