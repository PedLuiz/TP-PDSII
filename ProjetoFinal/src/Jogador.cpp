#include "ProjetoFinal/include/Jogador.hpp"

std::string Jogador::getNome(){
    return this->nome;
}

void Jogador::setNome(std::string nome){
    this->nome = nome;
}

std::string Jogador::getApelido(){
    return this->apelido;
}

void Jogador::setApelido(std::string apelido){
    this->apelido = apelido;
}

int getStat(int stat, int jogo){
    return stats[jogo][stat];
}

int setStat(int stat, int jogo, int value){
    stats[jogo][stat] = value;
}