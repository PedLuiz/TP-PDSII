#include "ProjetoFinal/include/Sistema.hpp"
#include <algorithm>

Sistema::Sistema(){
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    num_jogadores_cadastrados = 0;
}

Sistema::~Sistema(){
    arq_jogadores.close();
}


std::vector<std::string> nomes_jogos = {"REVERSI", "LIG4", "VELHA"};

void Sistema::cadastrarJogador(std::string apelido, std::string nome){
    Jogador aux(apelido, nome);
    vetor_jogadores.push_back(aux);
    num_jogadores_cadastrados++;
}

void Sistema::loadSistema(){
    while (!arq_jogadores.eof()){
        Jogador aux;
        std::string input;
        arq_jogadores >> input;
        aux.setNome(input);
        arq_jogadores >> input;
        aux.setApelido(input);
        int stat;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                arq_jogadores >> stat;
                aux.setStat(i, j, stat);
            }
        }
        vetor_jogadores.push_back(aux);
    }
}

void Sistema::saveSistema(){
    std::vector<Jogador> iterator it;
    for (it = vetor_jogadores.begin(); it!=vetor_jogadores.end(); it++){
        arq_jogadores << it->getNome() << std::endl << it->getApelido() << std::endl;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                arq_jogadores << it->getStat(i, j);
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
        vetor_jogadores.sort(comparaApelido);
    }
    if (parametro == 'N') {
        vetor_jogadores.sort(comparaNome);
    }
    std::vector<Jogador> iterator it;
    for (it = vetor_jogadores.begin(); it!=vetor_jogadores.end(); it++){
        std::cout << it->nome << std::endl << it->apelido << std::endl;
        for (int i=0; i<3; i++){
            std::cout << nomes_jogos[i] << " - V: " << it->getStat(i, 0) << " D: " << it->getStat(i, 1) << std::endl;
        }
    }
}

bool Sistema::comparaStatsReversi(Jogador & J1, Jogador & J2){ //o critério de colocação considerado será a diferença de vitórias e derrotas de cada jogador em cada jogo
    int desempenho_J1 = J1.getStat(0, 0) - J1.getStat(0, 1); 
    int desempenho_J2 = J2.getStat(0, 0) - J2.getStat(0, 1);
    if (desempenho_J1 <= desempenho_J2) return true;
    else return false;
}

bool Sistema::comparaStatsLig4(Jogador & J1, Jogador & J2){ 
    int desempenho_J1 = J1.getStat(1, 0) - J1.getStat(1, 1); 
    int desempenho_J2 = J2.getStat(1, 0) - J2.getStat(1, 1);
    if (desempenho_J1 <= desempenho_J2) return true;
    else return false;
}

bool Sistema::comparaStatsVelha(Jogador & J1, Jogador & J2){ 
    int desempenho_J1 = J1.getStat(2, 0) - J1.getStat(2, 1); 
    int desempenho_J2 = J2.getStat(2, 0) - J2.getStat(2, 1);
    if (desempenho_J1 >= desempenho_J2) return true;
    else return false;
}

void Sistema::printLeaderBoard(){
    std::vector<Jogador> iterator it;
    for (int i=0; i<3; i++){
        if (i==0) vetor_jogadores.sort(comparaStatsReversi);
        if (i==1) vetor_jogadores.sort(comparaStatsLig4);
        if (i==2) vetor_jogadores.sort(comparaStatsVelha);
        for (it = vetor_jogadores.begin(); it!=vetor_jogadores.end; it++){
            std::cout << nomes_jogos[i] << ":" << std::endl;
            std::cout << it->getNome() << " [" << it->getApelido() << "]:" << std::endl;
            std::cout << it->getStat(i,0) << " VITÓRIAS" << std::endl;
            std::cout << it->getStat(i,1) << " DERROTAS" << std::endl;
        }
    }
}

void Sistema::removerJogador(std::string apelido){
    std::vector<Jogador> iterator it;
    for (it = vetor_jogadores.begin(); it!= vetor_jogadores.end(); it++){
        if (it->getApelido() == apelido){
            vetor_jogadores.erase(it);
            break;
        }
    }
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::out);
    saveSistema();
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}