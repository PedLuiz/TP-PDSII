#include "Liga4.hpp"
#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Sistema.hpp"
#include "CampoMinado.hpp"
#include "Partida.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

void Menu();

void toUpper(string& str);

void pause();

void clear();

int main(){
    clear();
    Sistema sistema;
    sistema.loadSistema();

    string comando, apelido, nome;

    while(true) {
        Menu();
        cout << "Digite um comando: ";
        cin >> comando; cin.get();
        toUpper(comando);

        if (comando=="CJ"){
            cout << "Insira o apelido e o nome (respectivamente)"<< endl;
            cin >> apelido; cin.get();
            
            getline(cin, nome); 

            sistema.cadastrarJogador(nome, apelido);

            pause();
        }

        else if (comando=="RJ"){
            cout << "Insira o apelido do jogador a ser removido"<<endl;
            getline(cin, apelido);
            sistema.removerJogador(apelido);
            pause();
        }

        else if (comando=="LJ"){
            int num_jogadores = sistema.getNumJogadores();
            if (num_jogadores == 0){
                cout << "NENHUM JOGADOR CADASTRADO NO SISTEMA" << endl << endl;
                pause();
                continue;
            }
            string opcao;
            char op;
            while(true) {
                cout << "Selecione o modo de ordenacao" << endl;
                cout << "\t-[N] para ordernar por nome" << endl;
                cout << "\t-[A] para ordernar por apelido" << endl;
                cout << "\t-[C] para exibir a Tabela de Classificacao" << endl;
                
                cout << "Comando: ";
                cin >> opcao; cin.get();
                toUpper(opcao);

                op = opcao[0]; 
                if ((op == 'N') || (op == 'A') || (op == 'C')) 
                    break;
                
                cout << "ERRO, por favor insira um modo de ordenacao valido" << endl;
            }

            clear();
            cout << "------------------------------------------------------------------------------" << endl;
            if (op == 'C') {
                cout << "\t\t\t\tLEADERBOARD" << endl << endl;
                sistema.printLeaderBoard();
            }

            else {
                cout <<  "\t\t\tJOGADORES CADASTRADOS  [" << num_jogadores << "]" << endl << endl;
                cout << "APELIDO  |  NOME" << endl << endl;
                sistema.printSistema(op);
            }
            cout << "------------------------------------------------------------------------------" << endl;
            pause();
        }

        else if (comando=="EP"){
            if (sistema.getNumJogadores() == 0) {
                cout << "NENHUM JOGADOR CADASTRADO, ABORTANDO PARTIDA...";
                pause();
                continue;
            }
            string jogo;
            cout << "Insira o jogo a ser jogado([R]eversi, Jogo da [V]elha, [L]iga4, [C]ampo Minado): ";
            getline(cin, jogo);
            toUpper(jogo);

            if (!Partida::isJogoValido(jogo)) {
                while (true) {
                    cout << "Insira um tipo valido de jogo ou digite [sair] para cancelar a partida" << endl;
                    getline(cin, jogo);
                    toUpper(jogo);
                    if ((jogo == "SAIR") || (Partida::isJogoValido(jogo)))
                       break;
                }
            }

            if(!Partida::isJogoValido(jogo)) 
                continue;
            
            char modelo = jogo[0];

            cout << "Insira o apelido dos dois jogadores participantes" << endl;
            string apelido_j1, apelido_j2;

            cin >> apelido_j1 >> apelido_j2; cin.get(); 

            Jogador* jogador1 = sistema.getJogador(apelido_j1);
            
            if (!jogador1) {
                while (true) {
                    cout << "Insira um apelido valido para J1 ou digite <sair> para cancelar a partida" << endl;
                    getline(cin, apelido_j1);
                    if (apelido_j1 == "sair") {
                        break;
                    }
                    jogador1 = sistema.getJogador(apelido_j1);
                    if (jogador1) {
                        break;
                    }
                }
            }
            if (!jogador1) 
                continue;

            Jogador* jogador2 = sistema.getJogador(apelido_j2);
            if (!jogador2) {
                while (true) {
                    cout << "Insira um apelido valido para J2 ou digite <sair> para cancelar a partida" << endl;
                    getline(cin, apelido_j2);
                    if (apelido_j2 == "sair") {
                        break;
                    }
                    jogador2 = sistema.getJogador(apelido_j2);
                    if (jogador2) {
                        break;
                    }
                }
            }

            if ((jogador1) && (jogador2)) {
                Jogo* jogo;

                if (modelo == 'R') {
                    jogo = new Reversi();
                } 
                else if (modelo == 'V') {
                    jogo = new JogoDaVelha();
                }
                else if (modelo == 'L') {
                    jogo = new Liga4();
                }
                else if (modelo == 'C') {
                    cout << "Escolha o modo de jogo (1 = FACIL, 2 = MEDIO, 3 = DIFICIL): ";
                    int choice, linhas, colunas,numBombs;
                    cin >> choice;

                    switch (choice) 
                    {
                        case 1: //FÁCIL
                            linhas = 5;
                            colunas = 5;
                            numBombs = (linhas * colunas) * 10 / 100;
                            break;
                        
                        case 2: //MÉDIO
                            linhas = 10;
                            colunas = 10;
                            numBombs = (linhas * colunas) * 20 / 100;
                            break;
                        
                        case 3: //DIFÍCIL
                            linhas = 15;
                            colunas = 15;
                            numBombs = (linhas * colunas) * 30 / 100;
                            break;
        
        default:
            cout << "Modo inválido. Usando FACIL como padrão.\n";
            linhas = 5;
            colunas = 5;
            numBombs = (linhas * colunas) * 10 / 100;
            break;
    }
                    jogo = new CampoMinado(linhas, colunas, numBombs);
                }

                Partida* partida = new Partida (jogador1, jogador2, jogo);

                partida->iniciarPartida(modelo);
                sistema.saveSistema();
                pause();

                delete partida, jogo;
            }
        }

        else if (comando=="FS"){
            cout<< "Finalizando sistema..."<< endl;
            break;
        }

        else {
            cout<< "Comando inexistente"<< endl;
            pause();
            continue;
        }


    }
    sistema.saveSistema();
    cout << "Sistema finalizado com sucesso!" << endl;
}


/// @brief Menu de comandos básicos do sistema
void Menu() {
    clear();
    cout << "============================================================SISTEMA DE JOGOS============================================================" << endl;
    cout << "COMANDOS:" << endl;
    cout << "\tCJ - CADASTRAR JOGADOR" << endl;
    cout << "\t\tInsira um <apelido> e um <nome> para cadastrar o jogador ao sistema" << endl << endl;

    cout << "\tRJ - REMOVER JOGADOR"  << endl;
    cout << "\t\tInsira o <apelido> do jogador a ser removido" << endl << endl;

    cout << "\tLJ - LISTAR JOGADORES" << endl;
    cout << "\t\tExibe uma lista dos jogadores cadastrados no sistema e suas estatisticas" << endl << endl;

    cout << "\tEP - EXECUTAR PARTIDA" << endl;
    cout << "\t\tInsira o jogo a ser jogado (R)eversi, (L)iga4, Jogo da (V)elha ou (C)ampo Minado e os apelidos dos dois jogadores" << endl << endl;

    cout << "\tFS - FINALIZAR SISTEMA" << endl;
    cout << "\t\tEncerra a execucao do programa" << endl << endl;

    cout << "=========================================================================================================================================" << endl;
}

/// @brief Converte uma string para caixa alta
/// @param str 
void toUpper(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

/// @brief Pausa a tela do terminal esperando confirmação
void pause() {
    cout << endl << "Pressione qualquer [ENTER] para continuar..."<< std::flush;
    cin.get();
}

/// @brief Limpa o terminal
void clear() {
    #ifdef _WIN32
        system("cls");
    #else   
        system("clear");
    #endif
}