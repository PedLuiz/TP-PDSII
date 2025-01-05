#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi() : isTurnoX(true), Jogo(8, 8) {
    // Construtor e inicialização da posição inicial do jogo
    tabuleiro[3][3] = 'X';
    tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = 'O';
    tabuleiro[4][3] = 'O';
}

vector<pair<int,int>> Reversi::getPossiveisJogadas() {
    // Retorna um vetor de todas as jogadas válidas possíveis no estado atual do tabuleiro
    vector<pair <int, int>> jogadas_possiveis;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (isJogadaValida({i, j})) 
                jogadas_possiveis.push_back({i, j});
        }
    }  

    return jogadas_possiveis;
}

vector<pair<int, int>> Reversi::getPecasConvertidas(pair<int,int> jogada) {
    // Retorna uma lista de pecas adversarias que serao convertidas ao fazer determinada jogada;
    int x_start = jogada.first;
    int y_start = jogada.second;

    if (!estaNoTabuleiro(jogada)) {
        return {};
    }

    char jogador = getTurno(); 

    char adversario;
    if (jogador == 'X') {
        adversario = 'O';
    } else {
        adversario = 'X';
    }

    // valores a serem somados para ir para uma das 8 direções apartir de uma entrada da matriz
    // começando na pela direita e caminhando no sentido horário (L SE S SO O NO N NE) 
    vector<pair<int, int>> directions = {
        {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    
    vector<pair<int, int>> pecas_convertidas;

    for (const auto& direcao : directions) {
        int next_x = direcao.first; 
        int next_y = direcao.second; 

        int x = jogada.first;
        int y = jogada.second;

        x += next_x;
        y += next_y;

        if (!estaNoTabuleiro({x, y})) 
            continue;

        while (tabuleiro[x][y] == adversario) {
            x += next_x;
            y += next_y;

            if (!estaNoTabuleiro({x, y})) 
                break;
        }
        
        if (!estaNoTabuleiro({x, y})) 
                break;

        if (tabuleiro[x][y] == jogador) {
            // Encontramos a outra peca do mesmo tipo, agora fazemos o caminho inverso e adicionando as
            //  coordenadas ao vetor de pecas convertidas
            while (true) {
                x -= next_x;
                y -= next_y;
                if ((x == x_start) && (y == y_start)) {
                    break;
                }
                pecas_convertidas.push_back({x, y});
            }
        }

    }
    
    return pecas_convertidas;
}


bool Reversi::isEstadoFinal() {
    // Retorna verdadeiro se o jogo acabou (nenhum jogador possui movimentos disponíveis) 
    // checando se o jogador atual possui jogadas disponíveis

    bool jogador_atual_possui_jogadas = !getPossiveisJogadas().empty();

    trocaTurno(); // temporariamente troca o turno para checar a possibilidade do próximo jogador
    bool outro_jogador_possui_jogadas = !getPossiveisJogadas().empty();
    trocaTurno();

    if ((!jogador_atual_possui_jogadas) && (!outro_jogador_possui_jogadas)) {
        // Nenhum dos jogadores possui jogadas disponíveis, jogo acabou
        return true;
    }

    return false;
}

char Reversi::getTurno() {
    // Retorna qual jogador tem o turno atual

    if (isTurnoX) 
        return 'X';
    else
        return 'O';
}

void Reversi::trocaTurno() {
    // Troca o turno entre os jogadores

    isTurnoX = !isTurnoX;
}

void Reversi::fazerJogada(pair<int, int> jogada) { 
    // Após a validação, realiza a jogada (x, y), fazendo as alterações do tabuleiro de forma condizente
    // e trocando o turno posteriormente

    int x = jogada.first;
    int y = jogada.second;

    if (isJogadaValida(jogada)) {
        char jogador = getTurno();
        tabuleiro[x][y] = jogador;

        vector<pair<int, int>> pecas_convertidas = getPecasConvertidas(jogada);
        for (const auto& peca : pecas_convertidas) {
            int peca_x = peca.first;
            int peca_y = peca.second;

            tabuleiro[peca_x][peca_y] = jogador;
        }

        trocaTurno();

    } else {
        cout << "ERRO: jogada invalida" << endl;
    }
}

bool Reversi::isJogadaValida(pair<int,int> jogada) {
    // retorna verdadeiro se para o estado atual do tabuleiro a jogada (x, y) é válida

    int curr_x = jogada.first;
    int curr_y = jogada.second;

    if ((tabuleiro[curr_x][curr_y] != ' ') || (!estaNoTabuleiro(jogada))) {
        return false;
    }

    vector<pair<int, int>> pecas_convertidas = getPecasConvertidas(jogada);

    if (pecas_convertidas.size() == 0) 
        return false; 

    return true;
}

vector<int> Reversi::countPieces() const {
    // Conta a quantidade de peças de cada jogador
    // resultado = {countX, countO}

    int countX = 0;
    int countO = 0;
    vector<int> resultado;

    for (const auto &linha : tabuleiro) { 
        for (const char &pos : linha) { 
            if (pos == 'X') {
                countX++;
            } else if (pos == 'O') {
                countO++;
            }
        }
    }
    resultado.push_back(countX);
    resultado.push_back(countO);

    return resultado;
}

bool Reversi::estaNoTabuleiro(pair<int, int> jogada) {
    // Verifica se uma jogada (x, y) está dentro dos limites do tabuleiro

    int x = jogada.first;  
    int y = jogada.second; 

    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        return true; 
    } else {
        return false; 
    }
}

char Reversi::getVencedor() {
    // Compara o vetor resultado = {countX, countO}  

    vector<int> resultado = countPieces();

    if (resultado[0] > resultado[1]){
        return 'X';
    }

    else if (resultado[0] < resultado[1]){
        return 'O';
    }

    else{
        return ' ';
    } 
}

vector<vector<char>> Reversi::getTabuleiroPossivel(){
    // Marca no tabuleiro com '+' as coordenadas das possíveis jogadas
    vector<vector<char>> tabuleiro_possivel = tabuleiro;

    vector<pair<int, int>> jogadas_possiveis = getPossiveisJogadas();

    for (const auto& jogada : jogadas_possiveis) {
        int x = jogada.first;
        int y = jogada.second;
        tabuleiro_possivel[x][y] = '+';
    }

    return tabuleiro_possivel;
}

void Reversi::printTabuleiroPossivel() {
    // Printa o tabuleiro com as jogadas possiveis do turno atual formatado
    vector<vector<char>> tabuleiro_possivel=getTabuleiroPossivel();

    cout << "    ";

    for (int i=0; i<8; i++){
        cout << i+1 << "   ";
    }
    cout << endl;

    for (int i = 0; i < M; i++) {
        cout<< i+1 << " ";
        for (int j = 0; j < N; j++) {
            cout<<  "| " << tabuleiro_possivel[i][j]  << " ";
        }
        cout << "|" << endl << endl;
    }
};

int main () {
    Reversi* test = new Reversi(); 

    int x, y; 

    int rodada = 1;
    while (true) {
        cout << endl << "Rodada " << rodada << ", vez do jogador " << test->getTurno() << ":" <<  endl << endl;

        test->printTabuleiroPossivel(); 

        cin >> x >> y;
        x--; y--;
        if ((x < 0) || (y < 0))  {
            break;
        }

        while (!(test->isJogadaValida({x, y}))) {
            cin >> x >> y;
            x--, y--; 
        }

        test->fazerJogada({x, y});

        rodada++;
    }

        return 0;
}
