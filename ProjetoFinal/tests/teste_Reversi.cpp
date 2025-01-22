#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Reversi.hpp"

TEST_CASE("Testando fazerJogada") {
    Reversi jogo;

    SUBCASE("Executando movimento válido") {
        jogo.fazerJogada({2, 3});
        CHECK(jogo.isJogadaValida({2, 3}) == false); 
        CHECK(jogo.getTurno() == 'O');
    }

    SUBCASE("Executando movimento inválido") {
        jogo.fazerJogada({0, 0});
        CHECK(jogo.isJogadaValida({0, 0}) == false);
        CHECK(jogo.getTurno() == 'X'); 
    }
}

TEST_CASE("Testando estaNoTabuleiro") {
    Reversi jogo;

    CHECK(jogo.estaNoTabuleiro({0, 0}) == true);
    CHECK(jogo.estaNoTabuleiro({7, 7}) == true);
    CHECK(jogo.estaNoTabuleiro({-1, 0}) == false);
    CHECK(jogo.estaNoTabuleiro({8, 8}) == false);
}