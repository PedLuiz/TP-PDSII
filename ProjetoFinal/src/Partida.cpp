#include <iostream>
#include <cstdlib>
#include <map>
#include <thread> 
#include <chrono>
#include <ctime>

#include "Partida.hpp"

using namespace std;

void cls();

Partida::Partida(Jogador* j1, Jogador* j2, Jogo* jogo) : jogador1(j1), jogador2(j2), jogo(jogo) {
    sortearJogadorInicial();
}

void Partida::sortearJogadorInicial() {
    srand(time(NULL));

    if (rand() % 2 == 1) {
        swap(jogador1, jogador2);
    }
}

void Partida::atribuirPecas() {
    pecas_jogadores['X'] = jogador1;
    pecas_jogadores['O'] = jogador2;

    cout << "Jogador " << jogador1->getApelido() << " joga com X" << endl;
    cout << "Jogador " << jogador2->getApelido() << " joga com O" << endl;
}


// modelo => r = reversi, v = jogo da velha, l = liga4
void Partida::iniciarPartida(char modelo) {
    jogador_atual = jogador1;
    system("cls");
    switch (modelo) {
        case 'R':
            executarReversi();
            break;
        case 'L':
            executarLiga4();
            break;
        case 'V':
            executarVelha();
            break;
        default:
            cout << "ERRO: jogo selecionado invalido" << endl; 
            break;
    }
}

void Partida::finalizarPartida(char modelo) {
    cls();

    cout << endl << "+=++=++=++=+ FIM DE JOGO +=++=++=++=+" << endl;
    jogo->printTabuleiro();

    char peca_vencedor = jogo->getVencedor();

    
    if (peca_vencedor == ' ') {
        cout << "Jogo terminou em EMPATE ";
        
        if (modelo == 'R') {
            Reversi* reversi = dynamic_cast<Reversi*> (jogo);
            map<char, int> resultado = reversi->countPieces(); 

            cout << "em " << resultado[peca_vencedor] << " pontos!";

        }
        cout << endl;

    } else {
        Jogador* vencedor = pecas_jogadores[peca_vencedor];
        Jogador* perdedor = (vencedor == jogador1) ? jogador2 : jogador1;


        cout << "Jogador " << vencedor->getApelido() << " e' o vencedor da partida!!!";

        if (modelo == 'R') {
            Reversi* reversi = dynamic_cast<Reversi*> (jogo);
            map<char, int> resultado = reversi->countPieces(); 

            cout << "com " << resultado[peca_vencedor] << " pontos!"; 
        }

        cout << endl;
        
        int stat_jogo;
        if (modelo == 'R') {
            stat_jogo = 0;
        } else if (modelo == 'L') {
            stat_jogo = 1;
        } else if (modelo == 'V') {
            stat_jogo = 2;
        }

        vencedor->setStat(0, stat_jogo, vencedor->getStat(0, stat_jogo) + 1); // incrementa vitorias
        perdedor->setStat(1, stat_jogo, vencedor->getStat(0, stat_jogo) + 1); // incrementa derrota 
    }

}

bool Partida::isJogoValido(string modelo) {
    vector<string> jogos {"REVERSI", "VELHA", "LIGA4", "CAMPO MINADO", "JOGO DA VELHA"};
    for (auto& jogo : jogos) {
        if (modelo == jogo)
            return true;
    }

    vector<string> iniciais {"R", "V", "C", "L"};
    for (auto& inicial : iniciais) {
        if (modelo == inicial)
            return true;
    }

    return false;
}

void Partida::executarReversi() {
    Reversi* reversi = dynamic_cast<Reversi*> (jogo);

    cout << "========================== BEM VINDO AO REVERSI =============================" << endl << endl;

    atribuirPecas();

    int x, y; 

    int rodada = 1;
    map<char, int> resultado;

    while (!reversi->isEstadoFinal()) {
        cout << "========================== REVERSI =============================" << endl << endl;
        if (rodada > 1) 
            cls();
        jogador_atual = pecas_jogadores[reversi->getTurno()];
        cout << endl << "Rodada " << rodada << ", vez do jogador " << jogador_atual->getApelido() << "[" << reversi->getTurno() << "]:" <<  endl << endl;

        reversi->printTabuleiroPossivel(); 
        resultado = reversi->countPieces();
        cout << pecas_jogadores['X']->getApelido() << "[X]: " << resultado['X'] << " pontos || " << pecas_jogadores['O']->getApelido() << "[O]: " << resultado['O'] << " pontos" << endl;

        if (reversi->getPossiveisJogadas().empty()) {
            cout << "Jogador " << reversi->getTurno() << " nao possui jogadas disponiveis. Passando turno..." << endl;
            this_thread::sleep_for(chrono::seconds(4));
            reversi->trocaTurno(); rodada++;
            continue;
        }

        while (true) {
            cout << "Insira um comando no formato <linha> <coluna>" << endl;
            cin >> x >> y;

            if (reversi->isJogadaValida({x-1, y-1}))
                break;
            cout << "ERRO: Jogada Invalida" << endl;
        }

        reversi->fazerJogada({x-1, y-1});
        
        rodada++;
    }

    finalizarPartida('R');
}

void Partida::executarLiga4(){
    cout << endl << "========================== BEM VINDO AO LIGA4 =============================" << endl << endl;

    cout << "O PRIMEIRO JOGADOR QUE FIZER UMA SEQUENCIA DE 4 'O' OU 'X' NA COLUNA, \nLINHA OU DIAGONAL GANHA A PARTIDA! BOA SORTE." << endl << endl;

    Liga4* liga4 = dynamic_cast<Liga4*> (jogo);

    atribuirPecas();

    int rodada = 1;

    pair<int, int> jogada;
    int coluna;

    while (!liga4->isEstadoFinal()) {
        if (rodada > 1) {
            cls();
            cout << "========================== LIGA4 =============================" << endl << endl;
        }
        
        jogador_atual = pecas_jogadores[liga4->getTurno()];

        cout << endl << "Rodada " << rodada << ", vez do jogador(a) " << jogador_atual->getApelido() << "[" << liga4->getTurno() << "]:" << endl << endl;

        liga4->printTabuleiro();

        while (true) {
            cout << "Jogador(a) " << jogador_atual->getApelido() << "[" << liga4->getTurno() << "]" << ", escolha uma coluna (1 a 7): ";
            cin >> coluna; cin.get();

            jogada = {coluna, 0};
            
            if (liga4->isJogadaValida(jogada)) 
                break;
        }
        liga4->fazerJogada(jogada);

        rodada++;
    }

    finalizarPartida('L');
}

void cls() {
    #ifdef _WIN32
        system("cls");
    #else   
        system("clear");
    #endif
}