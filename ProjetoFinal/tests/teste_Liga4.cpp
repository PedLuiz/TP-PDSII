#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Liga4.hpp"

TEST_CASE("Testando a função getVencedor") 
{
    Liga4 jogo;

    // Teste 1: Verificar se o tabuleiro está vazio (sem vencedor)
    CHECK(jogo.getVencedor() == ' ');

    // Teste 2: Jogada horizontal vencedora
    jogo.fazerJogada({1, 1}); // 'X'
    jogo.fazerJogada({2, 1}); // 'O'
    jogo.fazerJogada({1, 2}); // 'X'
    jogo.fazerJogada({2, 2}); // 'O'
    jogo.fazerJogada({1, 3}); // 'X'
    jogo.fazerJogada({2, 3}); // 'O'
    jogo.fazerJogada({1, 4}); // 'X'
    CHECK(jogo.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 3: Jogada vertical vencedora
    Liga4 jogo2;
    jogo2.fazerJogada({1, 1}); // 'X'
    jogo2.fazerJogada({1, 2}); // 'O'
    jogo2.fazerJogada({1, 3}); // 'X'
    jogo2.fazerJogada({1, 4}); // 'O'
    jogo2.fazerJogada({1, 5}); // 'X'
    CHECK(jogo2.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 4: Jogada diagonal descendente vencedora
    Liga4 jogo3;
    jogo3.fazerJogada({1, 1}); // 'X'
    jogo3.fazerJogada({2, 2}); // 'O'
    jogo3.fazerJogada({2, 1}); // 'X'
    jogo3.fazerJogada({3, 3}); // 'O'
    jogo3.fazerJogada({3, 1}); // 'X'
    jogo3.fazerJogada({3, 2}); // 'O'
    jogo3.fazerJogada({4, 4}); // 'O'
    jogo3.fazerJogada({4, 1}); // 'X'
    jogo3.fazerJogada({4, 2}); // 'O'
    jogo3.fazerJogada({5, 5}); // 'O'
    jogo3.fazerJogada({5, 1}); // 'X'
    jogo3.fazerJogada({5, 2}); // 'O'
    jogo3.fazerJogada({6, 6}); // 'X'
    CHECK(jogo3.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 5: Jogada diagonal ascendente vencedora
    Liga4 jogo4;
    jogo4.fazerJogada({4, 4}); // 'X'
    jogo4.fazerJogada({3, 5}); // 'O'
    jogo4.fazerJogada({3, 3}); // 'X'
    jogo4.fazerJogada({2, 6}); // 'O'
    jogo4.fazerJogada({2, 2}); // 'X'
    jogo4.fazerJogada({1, 7}); // 'O'
    jogo4.fazerJogada({1, 1}); // 'X'
    CHECK(jogo4.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 6: Tabuleiro cheio sem vencedor (empate)
    Liga4 jogo5;
    jogo5.fazerJogada({1, 1}); // 'X'
    jogo5.fazerJogada({2, 1}); // 'O'
    jogo5.fazerJogada({3, 1}); // 'X'
    jogo5.fazerJogada({4, 1}); // 'O'
    jogo5.fazerJogada({5, 1}); // 'X'
    jogo5.fazerJogada({6, 1}); // 'O'
    jogo5.fazerJogada({7, 1}); // 'X'
    jogo5.fazerJogada({1, 2}); // 'O'
    jogo5.fazerJogada({2, 2}); // 'X'
    jogo5.fazerJogada({3, 2}); // 'O'
    jogo5.fazerJogada({4, 2}); // 'X'
    jogo5.fazerJogada({5, 2}); // 'O'
    jogo5.fazerJogada({6, 2}); // 'X'
    jogo5.fazerJogada({7, 2}); // 'O'
    jogo5.fazerJogada({1, 3}); // 'X'
    jogo5.fazerJogada({2, 3}); // 'O'
    jogo5.fazerJogada({3, 3}); // 'X'
    jogo5.fazerJogada({4, 3}); // 'O'
    jogo5.fazerJogada({5, 3}); // 'X'
    jogo5.fazerJogada({6, 3}); // 'O'
    jogo5.fazerJogada({7, 3}); // 'X'
    jogo5.fazerJogada({1, 4}); // 'O'
    jogo5.fazerJogada({2, 4}); // 'X'
    jogo5.fazerJogada({3, 4}); // 'O'
    jogo5.fazerJogada({4, 4}); // 'X'
    jogo5.fazerJogada({5, 4}); // 'O'
    jogo5.fazerJogada({6, 4}); // 'X'
    jogo5.fazerJogada({7, 4}); // 'O'
    jogo5.fazerJogada({1, 5}); // 'X'
    jogo5.fazerJogada({2, 5}); // 'O'
    jogo5.fazerJogada({3, 5}); // 'X'
    jogo5.fazerJogada({4, 5}); // 'O'
    jogo5.fazerJogada({5, 5}); // 'X'
    jogo5.fazerJogada({6, 5}); // 'O'
    jogo5.fazerJogada({7, 5}); // 'X'
    jogo5.fazerJogada({1, 6}); // 'O'
    jogo5.fazerJogada({2, 6}); // 'X'
    jogo5.fazerJogada({3, 6}); // 'O'
    jogo5.fazerJogada({4, 6}); // 'X'
    jogo5.fazerJogada({5, 6}); // 'O'
    jogo5.fazerJogada({6, 6}); // 'X'
    jogo5.fazerJogada({7, 6}); // 'O'
    CHECK(jogo5.getVencedor() == ' '); // Empate esperado
}
