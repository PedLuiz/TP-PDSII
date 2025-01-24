#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Reversi.hpp"


TEST_CASE("Testando estaNoTabuleiro") {
    Reversi jogo;

    CHECK(jogo.estaNoTabuleiro({0, 0}) == true);
    CHECK(jogo.estaNoTabuleiro({7, 7}) == true);
    CHECK(jogo.estaNoTabuleiro({-1, 0}) == false);
    CHECK(jogo.estaNoTabuleiro({8, 8}) == false);
}

TEST_CASE("Testar getPecasConvertidas") {
    Reversi jogo;
    SUBCASE("Jogada valida - conversao horizontal para direita") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({3, 5});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 4)); // Converte a peça em (3,4)
    }

    SUBCASE("Jogada valida - conversao horizontal para esquerda") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({4, 2});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 3)); // Converte a peça em (4,4)
    }

    SUBCASE("Jogada valida - conversao vertical para cima") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 4});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(3, 4)); // Converte a peça em (3,3)
    }

    SUBCASE("Jogada valida - conversao vertical para baixo") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({5, 3});
        CHECK(convertidas.size() == 1);
        CHECK(convertidas[0] == make_pair(4, 3)); // Converte a peça em (4,4)
        jogo.fazerJogada({5, 3}); // X joga em (4,5)
    }

    SUBCASE("Jogada valida - conversoes multiplas") {
        jogo.fazerJogada({4,2});
        jogo.fazerJogada({5,4});
        jogo.fazerJogada({2,5});
        jogo.fazerJogada({4,1});
        jogo.fazerJogada({5,2});

        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 4});
        CHECK(convertidas.size() == 2);
        CHECK(convertidas[0] == make_pair(3, 4));
        CHECK(convertidas[1] == make_pair(3, 3));
    }

    SUBCASE("Jogada valida - conversoes multiplas") {
        jogo.fazerJogada({2,4});
        jogo.fazerJogada({2,5});
        jogo.fazerJogada({3,5});
        jogo.fazerJogada({2,3});
        jogo.fazerJogada({3,2});
        jogo.fazerJogada({4,2});
        jogo.fazerJogada({1,6});
        jogo.fazerJogada({4,6});
        jogo.fazerJogada({2,2});
        jogo.fazerJogada({2,1});
        jogo.fazerJogada({1,2});
        jogo.fazerJogada({3,6});

        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({2, 6});
        CHECK(convertidas.size() == 5);
        CHECK(convertidas[0] == make_pair(3, 6));
        CHECK(convertidas[1] == make_pair(2, 2));
        CHECK(convertidas[2] == make_pair(2, 3));
        CHECK(convertidas[3] == make_pair(2, 4));
        CHECK(convertidas[4] == make_pair(2, 5));
    }

    SUBCASE("Jogada invalida - fora do tabuleiro") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({-1, -1});
        CHECK(convertidas.empty());

        convertidas = jogo.getPecasConvertidas({8, 8});
        CHECK(convertidas.empty());
    }

    SUBCASE("Jogada invalida - posicao ocupada") {
        vector<pair<int, int>> convertidas = jogo.getPecasConvertidas({3, 3});
        CHECK(convertidas.empty());
    }
}

TEST_CASE("Testar fazerJogada") {
    Reversi jogo;

    SUBCASE("Jogada valida - deve alterar tabuleiro corretamente") {
        CHECK(jogo.isJogadaValida({2, 4}));
        jogo.fazerJogada({2, 4});
        CHECK(jogo.getTabuleiroPossivel()[2][4] == 'X'); // Jogador X
        CHECK(jogo.getTabuleiroPossivel()[3][4] == 'X'); // Peça convertida
    }

    SUBCASE("Jogada invalida - nao deve alterar tabuleiro") {
        jogo.fazerJogada({0, 0});
        CHECK(jogo.getTabuleiroPossivel()[0][0] != 'X');
        CHECK(jogo.getTabuleiroPossivel()[0][0] != 'O');
    }

    SUBCASE("Troca de turno apos jogada valida") {
        CHECK(jogo.getTurno() == 'X');
        jogo.fazerJogada({2, 4});
        CHECK(jogo.getTurno() == 'O'); // Deve ser 'O' após a jogada de 'X'
    }
}

TEST_CASE("Testar isJogadaValida") {
    Reversi jogo;

    SUBCASE("Jogada valida - dentro do tabuleiro e com conversao") {
        CHECK(jogo.isJogadaValida({2, 4}) == true);
        CHECK(jogo.isJogadaValida({3, 5}) == true);
    }

    SUBCASE("Jogada invalida - fora do tabuleiro") {
        CHECK(jogo.isJogadaValida({-1, 3}) == false);
        CHECK(jogo.isJogadaValida({8, 8}) == false);
    }

    SUBCASE("Jogada invalida - posicao ja ocupada") {
        CHECK(jogo.isJogadaValida({3, 3}) == false);
        CHECK(jogo.isJogadaValida({4, 4}) == false);
    }

    SUBCASE("Jogada invalida - sem pecas para converter") {
        CHECK(jogo.isJogadaValida({0, 0}) == false);
    }
}
