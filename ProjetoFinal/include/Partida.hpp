#ifndef PARTIDA_HPP
#define PARTIDA_HPP

/***
 * @file Partida.hpp
 * @brief Declaração da classe Partida
 * 
 * Este arquivo define a classe que executa partidas entre jogadores
 */


#include "Jogo.hpp"
#include "Jogador.hpp"
#include "Reversi.hpp"
#include "Liga4.hpp"
#include "JogoDaVelha.hpp"
#include "CampoMinado.hpp"
#include "Sistema.hpp"

#include <map>

using namespace std;

/**
 * @class Partida
 * @brief Controla o fluxo de uma partida de um jogo.
 * 
 * Classe responsável por 
 * - Determinação de peças 
 * - Sorteio de jogador inicial
 * - Controle de fluxo, de acordo com o tipo de jogo escolhido
 * - Atualização das estatísticas dos jogadores
 */

class Partida {
private:
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogador_atual;

    /// @brief Mapeia as peças ('X' e 'O') para seus respectivos jogadores.
    map<char, Jogador*> pecas_jogadores;
    Jogo* jogo;

    void executarReversi();
    void executarLiga4();
    void executarVelha();
    void executarMinado();

public:
    /// @brief Construtor 
    /// @param j1 
    /// @param j2 
    /// @param jogo Jogo escolhido 
    Partida(Jogador* j1, Jogador* j2, Jogo* jogo);

    /// @brief Determina aleatoriamente qual jogador será o X e por consequência começará
    void sortearJogadorInicial();
    
    void atribuirPecas();
    
    /**
     * @brief Inicia a partida e controla o fluxo do jogo.
     * 
     * Com base no modelo informado, a função executa o jogo correspondente
     * e gerencia a alternância entre os jogadores.
     * 
     * @param modelo Caractere representando o jogo escolhido:
     *        - 'R' para Reversi
     *        - 'L' para Liga4
     *        - 'V' para Jogo da Velha
     *        - 'C' para Campo Minado
     */
    void iniciarPartida(char modelo);

    /// @brief Finaliza a partida e atualiza estatísticas
    /// @param modelo [R]eversi, [L]iga4, [V]elha, [C]ampo Minado
    void finalizarPartida(char modelo);

    /// @brief Verifica se o modelo passado como parametro em main.cpp pertence a um jogo válido
    /// @param modelo 
    static bool isJogoValido(string modelo);
};

#endif