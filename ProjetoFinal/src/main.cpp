#include "../include/Liga4.hpp"
#include "../include/JogoDaVelha.hpp"
#include "../include/Reversi.hpp"
#include "../include/Sistema.hpp"

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){

    Sistema sistema;

    while(true) {
        
        string entrada, comando, nome, apelido1, apelido2;
        char ordem, jogo;
        getline(cin, entrada);

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
