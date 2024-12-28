#ifndef SISTEMA_H
#define SISTEMA_H

#include "Jogador.hpp"
#include <iostream>
#include <list>
#include <fstream>

class Sistema {
    private:
        std::list<Jogador> lista_jogadores;
        std::fstream arq_jogadores("jogadores.txt");
        int num_jogadores_cadastrados;
    public:
        Sistema();
        void loadSistema();
        void saveSistema();
        void cadastrarJogador(std::string apelido, std::string nome);
        bool comparaApelido(Jogador & J1, Jogador & J2);
        bool comparaNome(Jogador & J1, Jogador & J2);
        void printSistema(char parametro);
        void printLeaderBoard();
        void removerJogador(std::string apelido);
};

#endif