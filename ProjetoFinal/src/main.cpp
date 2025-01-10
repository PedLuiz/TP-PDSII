#include "../include/Liga4.hpp"
#include "../include/JogoDaVelha.hpp"
#include "../include/Reversi.hpp"
#include "../include/Sistema.hpp"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void executarReversi();

void executarLiga4() {
    Liga4 jogo;
    pair<int, int> jogada;
    int coluna;
    char vencedor;

    cout << "Bem-vindo ao jogo Liga 4!" << endl;

    while (!jogo.isEstadoFinal()) {
        imprimirTabuleiroLiga4(jogo);
        cout << "Jogador " << jogo.getTurnoAtual() << ", escolha uma coluna (1 a 7): ";
        cin >> coluna;

        if (coluna < 1 || coluna > 7) {
            cout << "Entrada inválida. Escolha uma coluna entre 1 e 7." << endl;
            continue;
        }

        jogada = make_pair(coluna, 0);

        if (jogo.isJogadaValida(jogada)) {
            jogo.fazerJogada(jogada);
            vencedor = jogo.getVencedor();
            if (vencedor != ' ') {
                imprimirTabuleiroLiga4(jogo);
                cout << "Parabéns, Jogador " << vencedor << "! Você venceu!" << endl;
                return;
            }
        } else {
            cout << "Coluna cheia. Tente outra." << endl;
        }
    }

    imprimirTabuleiroLiga4(jogo);
    cout << "Jogo encerrado. Foi um empate!" << endl;
}

void imprimirTabuleiroLiga4(Liga4& jogo) {
    cout << "Tabuleiro atual:" << endl;
    for (int linha = 0; linha < 6; linha++) {
        for (int coluna = 0; coluna < 7; coluna++) {
            cout << '|' << jogo.getTabuleiro()[linha][coluna];
        }
        cout << '|' << endl;
    }
    cout << "1  2  3  4  5  6  7" << endl; // Para indicar as colunas
}

void executarJogoDaVelha();

int main(){

    Sistema sistema;
    sistema.loadSistema();

    while(true) {
        
        string entrada, comando, nome, apelido1, apelido2;
        char ordem, jogo;

        getline(cin, entrada);
        if(entrada.empty()){
            cout << "Entrada inválida! Por favor tente novamente." << endl;
            continue;
        }
        istringstream iss(entrada);
        iss >> comando;

        if(comando == "CJ"){
            iss >> apelido1;
            getline(iss, nome);
            nome = nome.substr(1);
            sistema.cadastrarJogador(apelido1, nome);
        }

        else if(comando == "RJ"){
            iss >> apelido1;
            sistema.removerJogador(apelido1);
        }

        else if(comando == "LJ"){
            iss >> ordem;
            sistema.printSistema(ordem);
        }

        else if(comando == "EP"){
            iss >> jogo;
            iss >> apelido1;
            iss >> apelido2;
            //verificar se os apelidos já estão cadastrados, se não, casdastra-los***
            //if (!sistema.isJogadorCadastrado(apelido1))
            //  cout << "Jogador " << apelido1 << " não cadastrado! Cadastre-o primeiro." << endl;
            //  continue;
            //if (!sistema.isJogadorCadastrado(apelido2))
            //  cout << "Jogador " << apelido2 << " não cadastrado! Cadastre-o primeiro." << endl;
            //  continue;
            switch (jogo) {
                case 'R':
                    executarReversi(/*adicionar Parametros, sistema, apelido1, apelido2??*/);
                    break;
                case 'V':
                    executarJogoDaVelha(/*adicionar Parametros, sistema, apelido1, apelido2??*/);
                    break;
                case 'L':
                    executarLiga4(/*adicionar Parametros, sistema, apelido1, apelido2??*/);
                    break;
                default:
                    cout << "Jogo inválido! Escolha 'R', 'V, ou 'L'." << endl;
                    break;
            }
        }

        else if(comando == "FS") break;

        else cout << "Comando Inválido!" << endl;

    }
    sistema.saveSistema();
    cout << "Sistema finalizado com sucesso!" << endl;
}

void executarReversi(){
    
}

void executarLiga4(){
    //sistema.atualizaStats(apelido, stats) ??
}

void executarJogoDaVelha(){

}

