#ifndef SISTEMA_H
#define SISTEMA_H

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class Sistema {
    private:
        std::vector<Jogador> vetor_jogadores;
        std::fstream arq_jogadores;
        int num_jogadores_cadastrados;
    public:
        Sistema();
        void loadSistema();
        void saveSistema();
        void cadastrarJogador(std::string apelido, std::string nome);
        bool comparaApelido(Jogador & J1, Jogador & J2);
        bool comparaNome(Jogador & J1, Jogador & J2);
        void printSistema(char parametro);
        bool comparaStatsReversi(Jogador &J1, Jogador & J2);
        bool comparaStatsLig4(Jogador &J1, Jogador & J2);
        bool comparaStatsVelha(Jogador &J1, Jogador & J2);
        void printLeaderBoard();
        void removerJogador(std::string apelido);
};

#endif