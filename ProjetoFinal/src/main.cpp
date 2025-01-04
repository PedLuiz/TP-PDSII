#include "../include/Liga4.hpp"
#include "../include/JogoDaVelha.hpp"
#include "../include/Reversi.hpp"
#include "../include/Sistema.hpp"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

void processarEntrada(string& entrada, string& comando, string& nome, string apelido[], char& ordem, char& jogo);

int main(){
    
    while(true) {
        
        string entrada, comando, nome, apelido[2];
        char ordem, jogo;
        Sistema sistema;

        getline(cin, entrada);

        processarEntrada(entrada, comando, nome, apelido, ordem, jogo);

        if(comando == "CJ"){
            if(apelido[0].empty() || nome.empty()){
                cout << "Nome ou apelido inválidos." << endl;
                continue;
            }
            else
                sistema.cadastrarJogador(apelido[0], nome);
        }

        else if(comando == "RJ"){
            if(apelido[0].empty())
                cout << "Apelido inválido." << endl;
            else{
                sistema.removerJogador(apelido[0]);
                cout << "Jogador " << apelido[0] << " removido com sucesso" << endl;
            }
        }

        else if(comando == "LJ"){
            if(ordem == 'A' || ordem == 'N')
                sistema.printSistema(ordem);
            else  cout << "Parametro de ordenação inválido." << endl;
        }

        else if(comando == "EP"){
            /* Jogo* jogo;
            Liga4 liga4;
            Reversi reversi;
            JogoDaVelha velha;
            ???*/
        }

        else if(comando == "FS") break;

        else cout << "Comando Inválido!" << endl;

    }
}

void processarEntrada(string& entrada, string& comando, string& nome, string apelido[], char& ordem, char& jogo){
    istringstream iss(entrada);
    iss >> comando;
    
    if(comando == "CJ"){
        iss >> apelido[0];
        getline(iss, nome);
        nome = nome.substr(1);
    }

    else if(comando == "RJ"){
        iss >> apelido[0];
    }

    else if(comando == "LJ"){
        iss >> ordem;
    }

    else if(comando == "EP"){
        iss >> jogo;
        iss >> apelido[0];
        iss >> apelido[1];
    }
}