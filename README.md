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
O jogador insere as coordenadas da jogada válida no formato (<linha> <coluna>).
    - Uma jogada é considerada válida quando cerca entre peças aliadas, em alguma das 8 direções, alguma peça adversária.
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

### Extras Implementados

Visualização de Jogadas Possíveis:
O tabuleiro exibe todas as posições válidas onde o jogador pode jogar, facilitando a tomada de decisão.

Contagem de Peças:
Um método adicional conta e exibe o número de peças de cada jogador.

## Campo Minado

### Visão Geral

Este projeto é uma implementação do jogo Campo Minado em C++, onde o objetivo é localizar todas as células sem bombas, 
evitando que o jogador clique em uma célula com bomba. O jogo é desenvolvido para ser jogado no terminal, com funcionalidades 
para posicionamento de bombas, revelação de células, sinalização de células suspeitas e controle de turnos. Ele também oferece 
validação de jogadas e atualização do estado do jogo conforme o progresso.

### Estrutura do Programa

O programa é dividido em dois arquivos principais:

CampoMinado.hpp: Contém a declaração da classe CampoMinado, que herda da classe Jogo. Define os métodos necessários para manipulação 
do jogo, como posicionar bombas, fazer jogadas, verificar se o jogo terminou, entre outros.

CampoMinado.cpp: Contém a implementação da classe CampoMinado, incluindo as funções que controlam o andamento do jogo, como a colocação 
das bombas, verificação de jogadas válidas, troca de turno, revelação de células e controle do estado final do jogo.

### Funcionamento

O jogo segue a seguinte sequência de ações:

O jogo inicia com a escolha do nível de dificuldade(fácil, médio, difícil).
O tabuleiro sendo configurado com bombas e células vazias segundo nível de dificuldade selecionado.
A cada turno, o jogador escolhe uma célula para revelar ou sinalizar.
O tabuleiro é atualizado após cada jogada, mostrando as células reveladas e sinalizadas.
O número de jogadas restantes diminui a cada movimento válido.
O jogo termina quando um jogador revela uma bomba ou quando todas as células sem bomba são reveladas.
O vencedor é determinado quando um jogador não perde ao revelar uma bomba ou se o jogo atinge um empate.

### Dificuldades Encontradas

Lógica de posicionamento e contagem de bombas adjacentes: Garantir que as bombas fossem distribuídas de maneira aleatória 
sem repetição e contar corretamente o número de bombas adjacentes a cada célula foi um desafio.

Validação de jogadas: A validação de jogadas (verificando se a coordenada já foi revelada ou se está fora do tabuleiro) 
exigiu um código robusto para garantir uma boa experiência ao usuário.

Controle de turnos e detecção de vencedor: A implementação de regras de turnos e detecção de vencedor ao encontrar uma bomba 
foi complicada devido à necessidade de controlar o estado do jogo com base nas jogadas feitas por ambos os jogadores.

### Métodos Implementados

colocarBombas: Coloca aleatoriamente as bombas no tabuleiro.
contarBombasAdjacentes: Conta o número de bombas nas células adjacentes a uma célula específica.
colocarSinalizador: Coloca ou remove um sinalizador ('F') em uma célula.
fazerJogada: Realiza a jogada de um jogador, revelando a célula selecionada ou marcando-a com um sinalizador.
isJogadaValida: Verifica se a jogada é válida (se a célula está dentro do tabuleiro e ainda não foi revelada).
printTabuleiro: Imprime o tabuleiro visível (com células já reveladas e sinalizadas).
revelarTabuleiro: Revela todo o tabuleiro, mostrando as bombas e os números nas células.
getVencedor: Retorna o vencedor da partida (baseado em quem perdeu ao clicar em uma bomba).
isEstadoFinal: Verifica se o jogo terminou (se todas as jogadas possíveis foram feitas ou se um jogador perdeu).
setTurno: Alterna o turno entre os jogadores.

## Liga 4

### Visão Geral

Este projeto é uma implementação do clássico jogo Liga 4 em C++, desenvolvido para ser jogado no terminal. 
O objetivo do jogo é conectar quatro peças consecutivas em uma linha, coluna ou diagonal antes do oponente. 
Ele oferece funcionalidades como verificação de vencedor, controle de turnos, validação de jogadas e exibição 
do tabuleiro.

### Estrutura do Programa

O programa é dividido em dois arquivos principais:

Liga4.hpp: Declara a classe Liga4, que herda de Jogo, e define os métodos necessários para implementar a lógica do jogo.

Liga4.cpp: Implementa a classe Liga4, com foco nas regras do jogo, manipulação do tabuleiro e interações do jogador.

### Funcionamento

O jogo segue a seguinte sequência de ações:

Inicialização do tabuleiro vazio e configuração do turno inicial.
Cada jogador, no seu turno, escolhe uma coluna para inserir sua peça ('X' ou 'O').
A peça cai na posição mais baixa disponível na coluna escolhida.
O programa verifica se há um vencedor ou se o jogo atingiu o estado final (tabuleiro cheio ou vitória).
Caso não haja um estado final, o turno é alternado e o próximo jogador realiza sua jogada.

### Dificuldades Encontradas

Verificação de Vitória: Implementar a lógica para verificar combinações horizontais, verticais e diagonais de peças 
foi desafiador devido à necessidade de percorrer todas as posições possíveis do tabuleiro.

### Métodos Implementados

Liga4(): Construtor que inicializa o jogo com um tabuleiro 6x7 vazio e define as condições iniciais.
getVencedor(): Verifica todas as linhas, colunas e diagonais do tabuleiro para determinar se algum jogador venceu.
isEstadoFinal(): Retorna true se o jogo atingiu um estado final, seja por vitória de um jogador ou por o tabuleiro estar cheio.
getTurno(): Retorna o jogador atual ('X' ou 'O').
setTurno(): Alterna o turno entre os jogadores. Caso ocorra um erro inesperado, exibe uma mensagem.
fazerJogada(): Realiza a jogada colocando a peça do jogador atual na coluna escolhida, se válida.
isJogadaValida(): Verifica se a jogada é válida (coluna entre 1 e 7 e ainda não preenchida).
printTabuleiro(): Imprime o estado atual do tabuleiro, mostrando as peças inseridas e os espaços vazios.
~Liga4(): Destrutor para limpar qualquer recurso utilizado pelo jogo.



## Jogo da Velha

### Visão Geral

Uma implementação do clássico Jogo da Velha em C++. Nele, dois jogadores competem entre qual será o primeiro a completar uma linha, coluna ou diagonal de um tabuleiro 3x3 com suas respectivas peças, alternadamente. O programa constrói a experiência realizando alternância de turnos, validação e execução de jogadas por meio do terminal e verificação de estados do tabuleiro.

### Estrutura do Programa

O Jogo da Velha é uma classe derivada da classe abstrata "Jogo", definida nos arquivos Jogo.hpp e Jogo.cpp, que contém atributos e métodos comuns aos jogos implementados.
A própria classe "JogoDaVelha", por outro lado, definida em JogoDaVelha.hpp e JogoDaVelha.cpp, possui um atributo a mais que a classe mãe - um caractere "turno", correspondente à peça do jogador da vez -, além de sobrescrever métodos virtuais e definir novos, responsáveis por:
Determinar o vencedor e o estado final do jogo, alternar o turno entre jogadores, validar e fazer jogadas e imprimir o tabuleiro.

### Funcionamento

Ao se iniciar uma partida do Jogo da Velha, o construtor da classe gera o tabuleiro vazio e inicializa o atributo "turno" com a peça 'X', por convenção.
Em seguida, em um loop, recebe entradas dos usuários com as posições do tabuleiro sobre as quais são feitas as jogadas, avalia se a jogada é válida (i. e. não é uma casa ocupada ou uma posição fora do tabuleiro) e, por fim, realiza a jogada alterando o espaço correspondente no tabuleiro e alternando o turno. O programa sai do loop quando o tabuleiro está em seu estado final, isto é, quando um dos jogadores completou uma linha, coluna ou diagonal (vitória), ou quando não houverem mais jogadas possíveis (empate).

### Dificuldades Encontradas

Uma parte desafiadora dessa parte do projeto foi a programação defensiva, uma vez que houve momentos em que incoerências nas entradas do usuário faziam com que o programa fornecesse outputs incorretos (por exemplo, antes de ser tratada a "case sesitivity", alguns métodos não eram executados quando o usuário fornecia a entrada em letra minúscula).

### Métodos Implementados

JogoDaVelha(): Construtor. Instancia um objeto "Jogo" com um tabuleiro 3x3 e define o primeiro turno como 'X', por convenção.

getVencedor(): Itera sobre colunas, linhas e diagonais. Caso uma das entradas em uma das direções do tabuleiro seja diferente da entrada anterior, não há vencedor e o método retorna ' '. Caso contrário, ou seja, todas as peças na direção são iguais, o método retorna a peça.

isEstadoFinal(): Avalia, primeiramente, se há um vencedor. Se sim, o jogo chegou ao seu estado final e a função retorna true. Caso contrário, a função checa o tabuleiro em busca de casas não ocupadas. Caso existam, retorna false.

alternaTurno(): Existem dois jogadores. Quando o turno tem valor 'X', altera para 'O'. Caso contrário, altera para 'X'.

getTurno(): Retorna o turno atual.

isJogadaValida(): Recebe um par de inteiros na forma de uma coordenada do tabuleiro. Se for uma coordenada dentro do tabuleiro (i. e. com valores entre 1 e 3) e essa não estiver ocupada, a jogada é válida e é retornado true. Caso contrário, é imprimida uma mensagem de erro e retorna false.

fazerJogada(): Confere se a jogada é valida por meio do método anterior. Caso positivo, altera a posição no tabuleiro com a peça correspondente ao jogador da vez.

printTabuleiro(): Imprime o tabuleiro resultante da jogada.