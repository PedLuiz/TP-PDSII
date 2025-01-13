#include "Sistema.hpp"
#include "Jogador.hpp"
#include <algorithm>

Sistema::Sistema(){
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
    num_jogadores_cadastrados = 0;
}

Sistema::~Sistema(){
    arq_jogadores.close();
}

std::vector<std::string> nomes_jogos = {"REVERSI", "LIG4", "VELHA"};

void Sistema::cadastrarJogador(std::string nome, std::string apelido){
    if (apelido.empty() || nome.empty()){
        std::cout << "ERRO: dados incorretos" << std::endl;
        return;
    }
    for (int i=0; i < vetor_jogadores.size(); i++){
        if (vetor_jogadores[i].Jogador::getApelido() == apelido) {
            std::cout << "ERRO: jogador repetido" << std::endl;
            return;
        }
    } 
    Jogador aux(nome, apelido);
    vetor_jogadores.push_back(aux);
    num_jogadores_cadastrados++;
    // saveSistema();
    std::cout << "Jogador " << apelido << " cadastrado com sucesso" << std:: endl;
}

void Sistema::loadSistema(){
    std::string nome, apelido;
    int stat;

    while (true) {
        if (!std::getline(arq_jogadores, nome) || nome.empty()) break;

        if (!std::getline(arq_jogadores, apelido) || apelido.empty()) break;

        cadastrarJogador(nome, apelido);
        Jogador* adicionado = &vetor_jogadores.back();

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                if (!(arq_jogadores >> stat)) break;
                adicionado->setStat(i, j, stat);
            }
        }

        arq_jogadores.ignore(10000, '\n'); // ignora \n no final da leitura da ultima estatistica
    }
}

void Sistema::saveSistema(){
    std::ofstream output("jogadores.txt", std::ios::trunc);

    for (int i=0; i < vetor_jogadores.size(); i++){
        output << vetor_jogadores[i].getNome() << std::endl << vetor_jogadores[i].getApelido() << std::endl;
        for (int i=0; i<3; i++){
            for (int j=0; j<2; j++){
                output << vetor_jogadores[i].getStat(i, j);
                if(j == 0){
                    output << " ";
                }
            }
            output << std::endl;
        }
    }
    output.close();
}

void Sistema::printSistema(char parametro){
    if (parametro == 'A') {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaApelido);
    }
    else if (parametro == 'N') {
        std::sort(vetor_jogadores.begin(), vetor_jogadores.end(), Jogador::comparaNome);
    }
    for (int i=0; i < vetor_jogadores.size(); i++){
        std::cout << vetor_jogadores[i].getNome() << std::endl << vetor_jogadores[i].getApelido() << std::endl;
        for (int j=0; j<3; j++){
            std::cout << nomes_jogos[j] << " - V: " << vetor_jogadores[i].getStat(j, 0) << " D: " << vetor_jogadores[i].getStat(j, 1) << std::endl;
        }
        std::cout << std::endl;
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
    std::cout << "Jogador " << apelido << " removido com sucesso" << std::endl;
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::out);
    saveSistema();
    arq_jogadores.close();
    arq_jogadores.open("jogadores.txt", std::fstream::in | std::fstream::out | std::fstream::app);
}