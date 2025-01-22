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
    jogo = Liga4(); // Reinicia o jogo
    jogo.fazerJogada({1, 1}); // 'X'
    jogo.fazerJogada({1, 2}); // 'O'
    jogo.fazerJogada({1, 3}); // 'X'
    jogo.fazerJogada({1, 4}); // 'O'
    jogo.fazerJogada({1, 5}); // 'X'
    CHECK(jogo.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 4: Jogada diagonal descendente vencedora
    jogo = Liga4(); // Reinicia o jogo
    jogo.fazerJogada({1, 1}); // 'X'
    jogo.fazerJogada({2, 2}); // 'O'
    jogo.fazerJogada({2, 1}); // 'X'
    jogo.fazerJogada({3, 3}); // 'O'
    jogo.fazerJogada({3, 1}); // 'X'
    jogo.fazerJogada({3, 2}); // 'O'
    jogo.fazerJogada({4, 4}); // 'O'
    jogo.fazerJogada({4, 1}); // 'X'
    jogo.fazerJogada({4, 2}); // 'O'
    jogo.fazerJogada({5, 5}); // 'O'
    jogo.fazerJogada({5, 1}); // 'X'
    jogo.fazerJogada({5, 2}); // 'O'
    jogo.fazerJogada({6, 6}); // 'X'
    CHECK(jogo.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 5: Jogada diagonal ascendente vencedora
    jogo = Liga4(); // Reinicia o jogo
    jogo.fazerJogada({4, 4}); // 'X'
    jogo.fazerJogada({3, 5}); // 'O'
    jogo.fazerJogada({3, 3}); // 'X'
    jogo.fazerJogada({2, 6}); // 'O'
    jogo.fazerJogada({2, 2}); // 'X'
    jogo.fazerJogada({1, 7}); // 'O'
    jogo.fazerJogada({1, 1}); // 'X'
    CHECK(jogo.getVencedor() == 'X'); // Espera-se 'X' como vencedor

    // Teste 6: Tabuleiro cheio sem vencedor (empate)
    jogo = Liga4(); // Reinicia o jogo
    jogo.fazerJogada({1, 1}); // 'X'
    jogo.fazerJogada({2, 1}); // 'O'
    jogo.fazerJogada({3, 1}); // 'X'
    jogo.fazerJogada({4, 1}); // 'O'
    jogo.fazerJogada({5, 1}); // 'X'
    jogo.fazerJogada({6, 1}); // 'O'
    jogo.fazerJogada({7, 1}); // 'X'
    jogo.fazerJogada({1, 2}); // 'O'
    jogo.fazerJogada({2, 2}); // 'X'
    jogo.fazerJogada({3, 2}); // 'O'
    jogo.fazerJogada({4, 2}); // 'X'
    jogo.fazerJogada({5, 2}); // 'O'
    jogo.fazerJogada({6, 2}); // 'X'
    jogo.fazerJogada({7, 2}); // 'O'
    jogo.fazerJogada({1, 3}); // 'X'
    jogo.fazerJogada({2, 3}); // 'O'
    jogo.fazerJogada({3, 3}); // 'X'
    jogo.fazerJogada({4, 3}); // 'O'
    jogo.fazerJogada({5, 3}); // 'X'
    jogo.fazerJogada({6, 3}); // 'O'
    jogo.fazerJogada({7, 3}); // 'X'
    jogo.fazerJogada({1, 4}); // 'O'
    jogo.fazerJogada({2, 4}); // 'X'
    jogo.fazerJogada({3, 4}); // 'O'
    jogo.fazerJogada({4, 4}); // 'X'
    jogo.fazerJogada({5, 4}); // 'O'
    jogo.fazerJogada({6, 4}); // 'X'
    jogo.fazerJogada({7, 4}); // 'O'
    jogo.fazerJogada({1, 5}); // 'X'
    jogo.fazerJogada({2, 5}); // 'O'
    jogo.fazerJogada({3, 5}); // 'X'
    jogo.fazerJogada({4, 5}); // 'O'
    jogo.fazerJogada({5, 5}); // 'X'
    jogo.fazerJogada({6, 5}); // 'O'
    jogo.fazerJogada({7, 5}); // 'X'
    jogo.fazerJogada({1, 6}); // 'O'
    jogo.fazerJogada({2, 6}); // 'X'
    jogo.fazerJogada({3, 6}); // 'O'
    jogo.fazerJogada({4, 6}); // 'X'
    jogo.fazerJogada({5, 6}); // 'O'
    jogo.fazerJogada({6, 6}); // 'X'
    jogo.fazerJogada({7, 6}); // 'O'
    CHECK(jogo.getVencedor() == ' '); // Empate esperado
}
