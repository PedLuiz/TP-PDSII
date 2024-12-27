#ifndef SISTEMA_H
#define SISTEMA_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class Sistema {
    private:
        std::vector<Jogador> jogadores;
        std::fstream jogadores("jogadores.txt");
    public:
        void loadSistema();
        void saveSistema();
        void cadastrarJogador(std::string apelido, std::string nome);
        void printSistema();
        void printLeaderBoard();
        void removerJogador(std::string apelido);
};

#endif