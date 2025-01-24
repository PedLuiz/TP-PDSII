#ifndef CAMPOMINADO_HPP
#define CAMPOMINADO_HPP

/**
 * @file CampoMinado.hpp
 * @brief Declaração da classe Campo Minado.
 * 
 * Este arquivo define a classe derivada CampoMinado, implementando a lógica e regras específicas do jogo. A classe gerencia o estado do jogo, determinação aleatória do estado inicial, validação e efeitos de cada jogada
 */

#include "Jogo.hpp"
#include <utility>

using namespace std;

/**
 * @class CampoMinado
 * @brief Classe que implmenta a lógica do Campo Minado
 * 
 * A classe `Campo Minado`, herdeira da classe base Jogo, implementa os métodos virtuais puros da classe pai
 * e estende sua funcionalidade com regras adicionais.
 * Ela lida com a colocação inicial das bombas, efeito de revelação de bombas adjacentes por jogada e controle do tabuleiro, além de contar com um seletor dificuldade
 * que controla o tamanho do campo
 */
class CampoMinado : public Jogo {
private:
    int linhas;
    int colunas;
    char turno_atual;
    char perdedor;
    int numBombas;
    bool jogoAtivo;
    int count_jogadas;
    int jogadasRestantes;
    
    /// @brief Tabuleiro que contem as posições das bombas, invisível para os jogadores.
    vector<vector<char>> tabuleiro_oculto;

    /// @brief Tabuleiro acessível para os jogadores onde o jogo acontece
    vector<vector<char>> tabuleiro_visivel;

    /**
     * @brief Coloca as bombas aleatoriamente no tabuleiro.
     * 
     * Este método distribui as bombas de forma aleatória no tabuleiro baseando-se
     * número de bombas especifico da dificuldade.
     */
    void colocarBombas();

    /**
     * @brief Conta o número de bombas adjacentes a uma célula.
     * 
     * Este método verifica as células ao redor da célula fornecida e retorna o número 
     * de bombas adjacentes.
     * 
     * @param linha A linha da célula a ser verificada.
     * @param coluna A coluna da célula a ser verificada.
     * @return O número de bombas adjacentes à célula.
     */
    int contarBombasAdjacentes(int linha, int coluna) const;

    /**
     * @brief Atualiza o tabuleiro visível, mostrando os elementos descobertos.
     * 
     * Este método é chamado sempre que o estado do jogo é alterado quando 
     * uma jogada é feita.
     */
    void atualizarTabuleiro();

public:
    /**
     * @brief Construtor da classe CampoMinado.
     * 
     * Inicializa o tabuleiro de acordo com o número de linhas, colunas e bombas fornecidos baseados na dificuldade escolhida
     * 
     * @param linhas Número de linhas do tabuleiro.
     * @param colunas Número de colunas do tabuleiro.
     * @param numBombas Número total de bombas no tabuleiro.
     */
    CampoMinado(int linhas, int colunas, int numBombas);

    char getVencedor() override;

    /// @brief Realiza a troca de turnos entre os jogadores
    void setTurno();

    char getTurno();
    bool isEstadoFinal() override;
    void fazerJogada(pair<int, int> jogada) override;
    bool isJogadaValida(pair<int, int> jogada) override;

    /**
     * @brief Coloca um sinalizador em uma célula do tabuleiro.
     * 
     * Este método permite ao jogador marcar uma célula como suspeita (sinalizar) sem 
     * revelá-la com o indicador `F`. Isso pode ser útil para tentar descobrir onde estão as bombas.
     * 
     * @param jogada Um par (linha, coluna) representando a célula a ser sinalizada.
     */
    void colocarSinalizador(pair<int, int>);
    void printTabuleiro() override;

    /**
     * @brief Revela completamente o tabuleiro.
     * 
     * Este método revela todas as células do tabuleiro revelando as bombas escondidas.
     */
    void revelarTabuleiro();

    /// @brief Destrutor 
    ~CampoMinado();
};

#endif
