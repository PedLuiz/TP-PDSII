#ifndef SISTEMA_H
#define SISTEMA_H

/**
 * @file Sistema.hpp
 * @brief Declaração da classe Sistema.
 * 
 * Este arquivo define a classe Sistema, que gerencia o sistema de jogadores,
 * incluindo o cadastro, remoção, e armazenamento das estatísticas dos jogadores.
 * Ele também lida com a leitura e gravação de dados no arquivo "jogadores.txt".
 * 
 */

#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <fstream>

/**
 * @class Sistema
 * @brief Classe responsável pelo gerenciamento de jogadores e suas informações no sistema.
 * 
 * A classe Sistema permite o cadastro, remoção, e listagem de jogadores. Além disso,
 * ela gerencia a persistência de dados em um arquivo e a exibição de informações
 * sobre os jogadores cadastrados.
 */
class Sistema {
private:
    /// @brief Vetor contendo todos os jogadores cadastrados no sistema.
    std::vector<Jogador> vetor_jogadores;

    /// @brief Arquivo usado para armazenar os dados dos jogadores.
    std::fstream arq_jogadores;

    int num_jogadores_cadastrados;

public:
    /// @brief Construtor. 
    Sistema();

    /**
     * @brief Destrutor da classe Sistema.
     * 
     * Fecha o arquivo de jogadores, garantindo que os dados sejam corretamente
     * salvos quando o sistema for destruído.
     */
    ~Sistema();

    /**
     * @brief Carrega o sistema de jogadores a partir de um arquivo.
     * 
     * Lê os dados dos jogadores cadastrados e inicializa o vetor de jogadores.
     */
    void loadSistema();

    /**
     * @brief Salva os dados dos jogadores no arquivo.
     * 
     * Grava as informações atuais dos jogadores cadastrados no arquivo para
     * persistência de dados.
     */
    void saveSistema();

    int getNumJogadores();

    /**
     * @brief Cadastra um novo jogador no sistema.
     * 
     * Adiciona um novo jogador ao sistema, com o nome e apelido fornecidos.
     * 
     * @param nome Nome do jogador a ser registrado.
     * @param apelido Apelido único do jogador, de uma palavra.
     */
    void cadastrarJogador(std::string nome, std::string apelido);

    /**
     * @brief Exibe o sistema de jogadores de acordo com o ordenação fornecido.
     * 
     * A exibição pode ser controlada pelo parâmetro, que determina 
     * a ordem de exibição dos jogadores.
     * 
     * @param parametro Parâmetro que controla a ordem de exibição dos jogadores.
     */
    void printSistema(char parametro);

    /**
     * @brief Exibe a classificação (leaderboard) dos jogadores.
     * 
     * Mostra a classificação dos jogadores com base no número de vitórias por jogo.
     */
    void printLeaderBoard();

    /// @brief Remove um jogador do sistema com base no apelido.
    /// @param apelido 
    void removerJogador(std::string apelido);

    /// @brief Verifica se um jogador está registrado no sistema.
    /// @param apelido Apelido do jogador a ser verificado.
    /// @return `true` se o jogador estiver registrado, `false` caso contrário.
    bool jogadorRegistrado(std::string apelido);

    /**
     * @brief Obtém um ponteiro para o jogador registrado com o apelido fornecido.
     * 
     * Retorna um ponteiro para o jogador identificado pelo apelido. Se o jogador
     * não existir, retorna um ponteiro nulo.
     * 
     * @param apelido Apelido do jogador a ser retornado.
     * @return Ponteiro para o jogador, ou `nullptr` se não encontrado.
     */
    Jogador* getJogador(std::string apelido);
};

#endif 
