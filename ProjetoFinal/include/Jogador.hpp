#ifndef JOGADOR_H
#define JOGADOR_H

/**
 * @file Jogador.hpp
 * @brief Declaração da classe Jogador .
 * 
 * Arquivo define a estrutura de dados base de um Jogador e métodos relacionados,
 * inicializadores e atualizações de estatísticas
 * 
 */

#include <iostream>

/**
 * @class Jogador
 * @brief Classe base de Jogador
 */

class Jogador {
    private:
        std::string nome;
        std::string apelido;
        int stats[4][2];
    public:
        /// @brief Construtor
        Jogador(std::string nome, std::string apelido);

        /// @brief Getter do nome do Jogador
        std::string getNome();

        /// @brief Setter do Nome do Jogador
        void setNome(std::string nome);
        
        /// @brief Getter do apelido do Jogador
        std::string getApelido();

        /// @brief setter do apelido do Jogador
        void setApelido(std::string apelido);
        
        /// @brief Compara a igualdade entre dois nomes de jogadores
        /// @param J1 
        /// @param J2 
        /// @return `true` se forem iguais, `false` caso contrário
        static bool comparaNome(Jogador & J1, Jogador & J2);

        /// @brief Compara a igualdade entre dois apelidos de jogadores
        /// @param J1 
        /// @param J2 
        /// @return `true` se forem iguais, `false` caso contrário
        static bool comparaApelido(Jogador & J1, Jogador & J2);

        /**
         * @brief Getter de estatística.
         * @param jogo [0]REVERSI, [1]LIGA4, [2]JOGO DA VELHA, [3]CAMPO MINADO.
         * @param stat [0]VITORIA, [1]DERROTA.
         * @return estatística espécifica de determinado jogo.
         */
        int getStat(int jogo, int stat);

        /**
         * @brief Setter de estatística.
         * @param jogo [0] REVERSI, [1] LIGA4, [2] JOGO DA VELHA, [3] CAMPO MINADO.
         * @param stat [0] VITORIA, [1] DERROTA.
         * @param value valor a ser atualizado.
         * @return estatística espécifica de determinado jogo.
         */
        void setStat(int jogo, int stat, int value);

        /// @brief Comparador de estatística Reversi
        /// @param J1 
        /// @param J2 
        /// @return `true` se desempenho de J1 é maior ou igual à J2, `false` caso contrário
        static bool comparaStatsReversi(Jogador &J1, Jogador & J2);
        
        /// @brief Comparador de estatística Liga4
        /// @param J1 
        /// @param J2 
        /// @return `true` se desempenho de J1 é maior ou igual à J2, `false` caso contrário
        static bool comparaStatsLig4(Jogador &J1, Jogador & J2);
        
        /// @brief Comparador de estatística Jogo da Velha
        /// @param J1 
        /// @param J2 
        /// @return `true` se desempenho de J1 é maior ou igual à J2, `false` caso contrário
        static bool comparaStatsVelha(Jogador &J1, Jogador & J2);
        
        /// @brief Comparador de estatística Campo Minado
        /// @param J1 
        /// @param J2 
        /// @return `true` se desempenho de J1 é maior ou igual à J2, `false` caso contrário
        static bool comparaStatsCampo(Jogador &J1, Jogador & J2);
};

#endif