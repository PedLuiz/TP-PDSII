#include "Sistema.hpp"
#include "Jogador.hpp"
#include <algorithm>

Sistema::Sistema(){
    arq_jogadores.open("jogadores.txt", std::fstream::in);
    num_jogadores_cadastrados = 0;
}

Sistema::~Sistema(){
    arq_jogadores.close();
}


std::vector<std::string> nomes_jogos = {"REVERSI", "LIG4", "VELHA"};

void Sistema::cadastrarJogador(std::string nome, std::string apelido){
    if (apelido.empty() || nome.empty()){
        std::cout << "ERRO: dados incorretos " << nome << " | " << apelido <<std::endl;
        return;
    }
    for (int i=0; i < vetor_jogadores.size(); i++){
        if (vetor_jogadores[i].getApelido() == apelido) {
            std::cout << "ERRO: jogador repetido " << nome << " | " << apelido << std::endl;
            return;
        }
    } 
    Jogador aux(nome, apelido);
    vetor_jogadores.push_back(aux);
    num_jogadores_cadastrados++;
    std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std:: endl;
}

void Sistema::loadSistema(){
    while (!arq_jogadores.eof()){
        std::string nome;
        std::string apelido;
        arq_jogadores >> nome;
        arq_jogadores >> apelido;
        Jogador aux(nome, apelido);
        int stat;
        //Jogador * adicionado = &vetor_jogadores[vetor_jogadores.size()-1];
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
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::out);
    int end = vetor_jogadores.size();
    for (int i=0; i < end; i++){
        if (i>0) arq_jogadores << std::endl;
        arq_jogadores << vetor_jogadores[i].getNome() << std::endl << vetor_jogadores[i].getApelido() << std::endl;
        for (int j=0; j<3; j++){
            for (int k=0; k<2; k++){
                arq_jogadores << vetor_jogadores[i].getStat(j, k);
                if(k == 0){
                    arq_jogadores << " ";
                }
            }
            if (j<2) arq_jogadores << std::endl;
        }
    }
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::in);
}

void Sistema::printSistema(char parametro){
    if (parametro == 'A') {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaApelido);
    }
    else if (parametro == 'N') {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaNome);
    }
    for (int i=0; i < vetor_jogadores.size(); i++){
        std::cout << vetor_jogadores[i].getApelido() << " " << vetor_jogadores[i].getNome() << std::endl;
        for (int j=0; j<3; j++){
            std::cout << nomes_jogos[j] << " - V: " << vetor_jogadores[i].getStat(j, 0) << " D: " << vetor_jogadores[i].getStat(j, 1) << std::endl;
        }
    }
}

void Sistema::printLeaderBoard(){
    for (int i=0; i<3; i++){
        if (i==0) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsReversi);
        if (i==1) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsLig4);
        if (i==2) std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaStatsVelha);
        for (int j = 0; j != vetor_jogadores.size(); j++){
            std::cout << nomes_jogos[i] << ":" << std::endl;
            std::cout << vetor_jogadores[j].getNome() << " [" << vetor_jogadores[j].getApelido() << "]:" << std::endl;
            std::cout << vetor_jogadores[j].getStat(i,0) << " VITÓRIAS" << std::endl;
            std::cout << vetor_jogadores[j].getStat(i,1) << " DERROTAS" << std::endl;
        }
    }
}

void Sistema::removerJogador(std::string apelido){
    bool jogador_existente = false;
    for (int i = 0; i != vetor_jogadores.size(); i++){
        if (vetor_jogadores[i].getApelido() == apelido){
            vetor_jogadores.erase(vetor_jogadores.begin()+i);
            num_jogadores_cadastrados--;
            jogador_existente = true;
            break;
        }
    }
    if (!jogador_existente){
        std::cout << "ERRO: jogador inexistente" << std::endl;
        return;
    }
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::out);
    saveSistema();
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}