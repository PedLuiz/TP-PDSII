#include <iostream>
#include <cstdlib>
#include <map>
#include <ctime>

#include "Partida.hpp"

using namespace std;

Partida::Partida(Jogador* j1, Jogador* j2, Jogo* jogo) : jogador1(j1), jogador2(j2), jogo(jogo) {
    sortearJogadorInicial();
    atribuirPecas();
}

void Partida::sortearJogadorInicial() {
    srand(time(NULL));

    if (rand() % 2 == 1) {
        swap(jogador1, jogador2);
    }

    cout << "Jogador " << jogador1->getApelido() << " joga com X" << endl;
    cout << "Jogador " << jogador2->getApelido() << " joga com O" << endl;
}

void Partida::atribuirPecas() {
    pecas_jogadores['X'] = jogador1;
    pecas_jogadores['O'] = jogador2;
}


// modelo => r = reversi, v = jogo da velha, l = liga4
void Partida::iniciarPartida(char modelo) {
    jogador_atual = jogador1;
    system("cls");
    switch (modelo) {
        case 'r':
            executarReversi();
            break;
        case 'l':
            executarLiga4();
            break;
        case 'v':
            executarVelha();
            break;
        default:
            cout << "ERRO: jogo selecionado invalido" << endl; 
            break;
    }
}

void Partida::finalizarPartida(char modelo) {
    jogo->printTabuleiro();
    char peca_vencedor = jogo->getVencedor();

    cout << endl << "+=++=++=++=+ FIM DE JOGO +=++=++=++=+" << endl;
    
    if (peca_vencedor == ' ') {
        cout << "Jogo terminou em EMPATE ";
        
        if (modelo == 'r') {
            Reversi* reversi = dynamic_cast<Reversi*> (jogo);
            map<char, int> resultado = reversi->countPieces(); 

            cout << "em " << resultado[peca_vencedor] << " pontos!";

        }
        cout << endl;

    } else {
        Jogador* vencedor = pecas_jogadores[peca_vencedor];
        Jogador* perdedor = (vencedor == jogador1) ? jogador2 : jogador1;


        cout << "Jogador " << vencedor->getApelido() << " e o vencedor da partida ";

        if (modelo == 'r') {
            Reversi* reversi = dynamic_cast<Reversi*> (jogo);
            map<char, int> resultado = reversi->countPieces(); 

            cout << "com " << resultado[peca_vencedor] << " pontos!"; 
        }

        cout << endl;
        
        int stat_jogo;
        if (modelo == 'r') {
            stat_jogo = 0;
        } else if (modelo == 'l') {
            stat_jogo = 1;
        } else if (modelo == 'v') {
            stat_jogo = 2;
        }

        vencedor->setStat(0, stat_jogo, vencedor->getStat(0, stat_jogo) + 1); // incrementa vitorias
        perdedor->setStat(1, stat_jogo, vencedor->getStat(0, stat_jogo) + 1); // incrementa derrota 
    }

}



