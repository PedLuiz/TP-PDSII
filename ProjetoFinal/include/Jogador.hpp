#ifndef JOGADOR_H
#define JOGADOR_H

#include <iostream>

class Jogador {
    private:
        std::string nome;
        std::string apelido;
        int stats[3][2];
    public:
        std::string getNome();
        void setNome(std::string nome);
        std::string getApelido();
        void setApelido(std::string apelido);
        int getStat(int stat, int jogo);
        void setStat(int stat, int jogo, int value);
        //stat: 0 = vitórias | 1 = derrotas
        //jogo: 0 = Reversi | 1 = Lig4 | 2 = Velha
};

#endif