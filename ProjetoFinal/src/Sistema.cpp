#include "ProjetoFinal/include/Sistema.hpp"
#include <algorithm>
#include <vector>

Sistema::Sistema(){
    num_jogadores_cadastrados = 0;
}


void Sistema::cadastrarJogador(std::string apelido, std::string nome){
    Jogador aux(apelido, nome);
    lista_jogadores.push_back(aux);
    num_jogadores_cadastrados++;
}

void Sistema::loadSistema(){
    while (!arq_jogadores.eof()){
        Jogador aux;
        arq_jogadores >> aux.nome;
        arq_jogadores >> aux.apelido;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                arq_jogadores >> aux.stats[i][j];
            }
        }
        lista_jogadores.push_back(aux);
    }
}

void Sistema::saveSistema(){
    std::list<Jogador> iterator it;
    for (it = lista_jogadores.begin(); it!=lista_jogadores.end(); it++){
        arq_jogadores << it->nome << std::endl << it->apelido << std::endl;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                arq_jogadores << it->stats[i][j];
                if(j=0){
                    arq_jogadores << " ";
                }
            }
            arq_jogadores << std::endl;
        }
    }
}

bool Sistema::comparaApelido(Jogador & J1, Jogador & J2){
    std::string apelido1 = J1.getApelido();
    std::string apelido2 = J2.getApelido();
    int ultimo_index = std::min(apelido1.size(), apelido2.size());
    for (int i=0; i<ultimo_index; i++){
        if (apelido1[i] < apelido2[i]) return true;
        if (apelido1[i] > apelido2[i]) return false;
    }
    if (apelido2.size() != ultimo_index) return true;
    else return false;
}

bool Sistema::comparaNome(Jogador & J1, Jogador & J2){
    std::string nome1 = J1.getNome();
    std::string nome2 = J2.getNome();
    int ultimo_index = std::min(nome1.size(), nome2.size());
    for (int i=0; i<ultimo_index; i++){
        if (nome1[i] < nome2[i]) return true;
        if (nome1[i] > nome2[i]) return false;
    }
    if (nome2.size() != ultimo_index) return true;
    else return false;
}

void Sistema::printSistema(char parametro){
    if (parametro == 'A') {
        lista_jogadores.sort(comparaApelido);
    }
    if (parametro == 'N') {
        lista_jogadores.sort(comparaNome);
    }
    std::list<Jogador> iterator it;
    std::vector<std::string> nomes_jogos = {"REVERSI - ", "LIG4 - ", "VELHA - "};
    for (it = lista_jogadores.begin(); it!=lista_jogadores.end(); it++){
        std::cout << it->nome << std::endl << it->apelido << std::endl;
        for (int i=0; i<3; i++){
            std::cout << nomes_jogos[i] << "V: " << it->stats[i][0] << " D: " << it->stats[i][1] << std::endl;
        }
    }
}