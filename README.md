# TP-PDSII
Repositório dedicado ao Projeto Final da disciplina de "PDS II"

## Reversi 
### Visão Geral
Este projeto é uma implementação do jogo Reversi em C++. Ele utiliza classes e herança para modelar o jogo de maneira modular, possibilitando a extensão para outros tipos de jogos tabuleiros. O foco principal é criar uma experiência jogável diretamente no terminal, com validação de jogadas, alternância de turnos, e visualização de jogadas possíveis.

### Estrutura do Programa
O programa é dividido em três arquivos principais:

Jogo.hpp e Jogo.cpp:
Define a classe base Jogo, que encapsula as funcionalidades gerais para jogos de tabuleiro:
Representação genérica do tabuleiro, uma matriz de caracteres.
Métodos virtuais para determinar vencedores, turno e estado do jogo.

Implementação padrão para exibir o tabuleiro.
Reversi.hpp e Reversi.cpp:
Contém a implementação específica do jogo Reversi, com métodos adicionais para:
Validar jogadas e verificar se estão dentro das regras do jogo.
Identificar as peças a serem convertidas ao realizar uma jogada.
Contabilizar as peças de cada jogador.
Exibir as jogadas possíveis no tabuleiro.

### Funcionamento
O jogo começa com o tabuleiro inicializado com as quatro peças centrais configuradas.
A cada rodada:
O jogador é informado sobre o turno atual.
O tabuleiro mostra as jogadas possíveis (representadas por +).
O jogador insere as coordenadas da jogada no formato (<linha> <coluna>).
Após validação da jogada, o tabuleiro é atualizado, e as peças adversárias são convertidas.
O jogo continua até nenhum jogador possuir jogadas válidas disponíveis
O programa declara o vencedor baseado no número de peças no tabuleiro.

### Dificuldades Encontradas

Uma das principais dificuldades foi de implementar a lógica identificação e conversão das peças em todas as direções lidando ao mesmo tempo com os limites do tabuleiro, além de outras regras espécificas do outro como o sistema de passagem de turnos

Reaproveitamento do código base:
Projetar uma arquitetura genérica para o tabuleiro exigiu planejar métodos abstratos, tornando o sistema adaptável para outros jogos.

Interação com o usuário:
A implementação de uma interface de texto intuitiva foi essencial para uma boa experiência de uso.

Validação de jogadas: 
Implementar uma verificação robusta e eficiente.

Extras Implementados

Visualização de Jogadas Possíveis:
O tabuleiro exibe todas as posições válidas onde o jogador pode jogar, facilitando a tomada de decisão.

Contagem de Peças:
Um método adicional conta e exibe o número de peças de cada jogador.

