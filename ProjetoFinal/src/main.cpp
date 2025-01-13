#include "Liga4.hpp"
#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Sistema.hpp"
#include "Partida.hpp"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void executarLiga4() {
    Liga4 jogo;
    pair<int, int> jogada;
    int coluna;
    char vencedor;

    cout << "Bem-vindo ao jogo Liga 4!" << endl;

    while (!jogo.isEstadoFinal()) {
        jogo.printTabuleiro();
        cout << "Jogador " << jogo.getTurno() << ", escolha uma coluna (1 a 7): ";
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
                jogo.printTabuleiro();
                cout << "Parabéns, Jogador " << vencedor << "! Você venceu!" << endl;
                return;
            }
        } else {
            cout << "Coluna cheia. Tente outra." << endl;
        }
    }
    jogo.printTabuleiro();
    cout << "Jogo encerrado. Foi um empate!" << endl;
}

void Menu();

int main(){

    Sistema sistema;
    sistema.loadSistema();
    
    Menu();
    
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
                    break;
                case 'V':
                    break;
                case 'L':
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

void Menu() {
    system("cls");
    cout << "============================================================SISTEMA DE JOGOS============================================================" << endl;
    cout << "COMANDOS:" << endl;
    cout << "\tCJ - CADASTRAR JOGADOR" << endl;
    cout << "\t\tInsira um <apelido> e um <nome> para cadastrar o jogador ao sistema" << endl;

    cout << "\tRJ - REMOVER JOGADOR"  << endl;
    cout << "\t\tInsira o <apelido> do jogador a ser removido" << endl;

    cout << "\tLJ - LISTAR JOGADORES" << endl;
    cout << "\t\tExibe uma lista dos jogadores cadastrados no sistema e suas estatisticas" << endl;

    cout << "\tEP - EXECUTAR PARTIDA" << endl;
    cout << "\t\tInsira o jogo a ser jogado (R)eversi, (L)iga4, Jogo da (V)elha e os apelidos dos dois jogadores" << endl;

    cout << "\tFS - FINALIZAR SISTEMA" << endl;
    cout << "\t\tEncerra a execucao do programa" << endl;

    cout << "=========================================================================================================================================" << endl;
}

void executarJogoDaVelha();
