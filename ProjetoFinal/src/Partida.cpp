#include <iostream>
#include <cstdlib>
#include <map>
#include <thread> 
#include <chrono>
#include <ctime>

#include "Partida.hpp"

using namespace std;

void flush();
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
        case 'C':
            executarMinado();
            break;
        default:
            cout << "ERRO: jogo selecionado invalido" << endl; 
            break;
    }
}

void Partida::finalizarPartida(char modelo) {
    cls();

    cout << endl << "+=++=++=++=++=++=+ FIM DE JOGO +=++=++=++=++=++=+" << endl << endl;
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


        cout<< endl << "Jogador(a) " << vencedor->getApelido() << "[" << peca_vencedor << "]" << " e' o vencedor da partida!!!";

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

        vencedor->setStat(stat_jogo, 0, (vencedor->getStat(stat_jogo, 0) + 1)); // incrementa vitorias
        perdedor->setStat(stat_jogo, 1, (perdedor->getStat(stat_jogo, 1) + 1)); // incrementa derrota 
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
        if (rodada > 1) {
            cls();
            cout << "========================== REVERSI =============================" << endl << endl;
        } 
        jogador_atual = pecas_jogadores[reversi->getTurno()];
        cout << endl << "Rodada " << rodada << ", vez do jogador " << jogador_atual->getApelido() << "[" << reversi->getTurno() << "]:" <<  endl << endl;

        reversi->printTabuleiroPossivel(); 
        resultado = reversi->countPieces();
        cout << endl << pecas_jogadores['X']->getApelido() << "[X]: " << resultado['X'] << " pontos | " << pecas_jogadores['O']->getApelido() << "[O]: " << resultado['O'] << " pontos" << endl;

        if (reversi->getPossiveisJogadas().empty()) {
            cout << "Jogador " << reversi->getTurno() << " nao possui jogadas disponiveis. Pressione [ENTER] para passar o turno..." << endl; cin.get();
            reversi->trocaTurno(); rodada++;
            continue;
        }

        while (true) {
            cout << endl << "Jogador(a) " << jogador_atual->getApelido() << "[" << reversi->getTurno() << "]" << " insira um comando no formato <linha> <coluna>" << endl;

            while (!(cin >> x >> y)) {
                flush();
                cout << "ERRO: Formato de entrada invalido, digite um inteiro" << endl;
            }   
            cin.get();

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
            cout << endl << "Jogador(a) " << jogador_atual->getApelido() << "[" << liga4->getTurno() << "]" << ", escolha uma coluna (1 a 7): ";

            while (!(cin >> coluna)) {
                flush();
                cout << "ERRO: Formato de entrada invalido, digite um inteiro" << endl;
            }
            cin.get();

            jogada = {coluna, 0};
            
            if (liga4->isJogadaValida(jogada)) 
                break;
        }
        liga4->fazerJogada(jogada);

        rodada++;
    }

    finalizarPartida('L');
}

void Partida::executarVelha() {
    cout << endl << "========================== BEM VINDO AO JOGO DA VELHA =============================" << endl << endl;

    JogoDaVelha * jogo_da_velha = dynamic_cast<JogoDaVelha*> (jogo);

    atribuirPecas();
    
    int rodada = 1;
    while(!jogo_da_velha->isEstadoFinal()){
        if (rodada > 1) {
            cls();
            cout << "========================== JOGO DA VELHA =============================" << endl << endl;
        }

        jogador_atual = pecas_jogadores[jogo_da_velha->getTurno()];
        cout << endl << "Rodada " << rodada << ", vez do jogador(a) " << jogador_atual->getApelido() << "[" << jogo_da_velha->getTurno() << "]:" << endl << endl;

        jogo_da_velha->printTabuleiro();
        
        pair <int, int> jogada;
        while (true) {
            cout << endl << "Jogador(a) " << jogador_atual->getApelido() << "[" << jogo_da_velha->getTurno() << "]" << " insira um comando no formato <linha> <coluna>" << endl;
            while (!(cin >> jogada.first >> jogada.second)) {
                flush();
                cout << "ERRO: Formato de entrada invalido, digite um inteiro" << endl;
            }
            cin.get();
            if (jogo_da_velha->isJogadaValida(jogada)) {
                break;
            }

        }
        jogo_da_velha->fazerJogada(jogada);
        rodada++;
    }

    finalizarPartida('V');
}

void Partida::executarMinado() 
{
    cout << endl << "========================== BEM VINDO AO CAMPO MINADO =============================" << endl << endl;

    CampoMinado *jogo_campo_minado = new CampoMinado(7, 7, 10);

    if (!jogo_campo_minado) 
    {
        cout << "Erro ao acessar o jogo Campo Minado!" << endl;
        return;
    }

    atribuirPecas();

    int rodada = 1;
    while (!jogo_campo_minado->isEstadoFinal()) 
    {
        if (rodada > 1) 
        {
            cls(); 
            cout << "========================== CAMPO MINADO =============================" << endl << endl;
        }

        jogador_atual = pecas_jogadores[jogo_campo_minado->getTurno()];

        if (jogador_atual == nullptr) 
        {
            cout << "Erro: Jogador atual não foi inicializado corretamente!" << endl;
            return;
        }

        cout << endl << "Rodada " << rodada << ", vez do jogador(a) " << jogador_atual->getApelido() 
             << "[" << jogo_campo_minado->getTurno() << "]:" << endl << endl;

        jogo_campo_minado->printTabuleiro();

        pair<int, int> jogada;
        char comando;
        while (true) 
        {
            cout << endl << "Jogador(a) " << jogador_atual->getApelido() 
                 << "[" << jogo_campo_minado->getTurno() << "] insira um comando no formato <linha> <coluna> ou <linha> <coluna> F para sinalizar:" << endl;
            
            cin >> jogada.first >> jogada.second;
            
            if (cin.peek() == ' ') 
            {
                cin >> comando;
            } 
            else 
            {
                comando = ' ';
            }
            cin.get(); 

            if (jogo_campo_minado->isJogadaValida(jogada)) 
            {
                if (comando == 'F' || comando == 'f') 
                {
                    jogo_campo_minado->colocarSinalizador(jogada);
                } 
                else 
                {
                    jogo_campo_minado->fazerJogada(jogada);
                }
                break;
            } 
            else 
            {
                cout << "Jogada inválida, tente novamente." << endl;
            }
        }

        rodada++;
    }

    jogo_campo_minado->revelarTabuleiro();
    cout << "Jogo encerrado!" << endl;

    char vencedor = jogo_campo_minado->getVencedor();
    finalizarPartida(vencedor);
}


void flush() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void cls() {
    #ifdef _WIN32
        system("cls");
    #else   
        system("clear");
    #endif
}