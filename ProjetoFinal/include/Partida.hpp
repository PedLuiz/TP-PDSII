#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "Jogo.hpp"
#include "Jogador.hpp"
#include "Sistema.hpp"

#include <map>

using namespace std;

class Partida {
private:
    Jogador* jogador1;
    Jogador* jogador2;
    Jogador* jogador_atual;

    map<Jogador*, char> pecas_jogadores;
    Jogo* Jogo;

public:
    Partida(Jogador* j1, Jogador* j2, Jogo* jogo);
    void sortearJogadorInicial();
    void atriburPecas();
    void iniciarPartida();
    void finalizarPartida();
    


};

#endif