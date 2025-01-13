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

    string comando, apelido, nome;

    
    while(true) {
        Menu();
        cout<< "Digite um comando: "<< endl;
        cin >> comando;

        if (comando=="CJ"){
            cin>> apelido>> nome;
            sistema.cadastrarJogador(nome, apelido);
        }

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
