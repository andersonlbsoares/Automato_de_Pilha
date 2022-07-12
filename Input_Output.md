Entrada

    quantidade de estados - N

    Quantidade de símbolos do alfabeto de entrada
    símbolos do alfabeto de entrada

    Quantidade de símbolos do alfabeto da pilha
    símbolos do alfabeto da pilha

    número do estado inicial (entre 0 e N-1)

    símbolo inicial da pilha


    Quantidade de estados finais
    estados finais

    Quantidade de transições
    Lista de transições, cada uma contendo
        número do estado de partida, número do estado de chegada, símbolo de entrada, símbolo do topo da pilha e string a ser escrita na pilha
        
    uma string

Saída

    Uma árvore de Descrições Instantâneas (DI) seguida da palavra "aceita" ou "rejeita".
    
    Cada DI contém o estado atual, o que resta ler da entrada e o conteúdo da pilha.


Exemplo:

Entrada:

3
2
0 1
3
0 1 Z
0
Z
1
2
12
0 0 0 Z 0Z
0 0 1 Z 1Z
0 0 0 0 00
0 0 0 1 01
0 0 1 0 10
0 0 1 1 11
0 1 e Z Z
0 1 e 0 0
0 1 e 1 1
1 1 0 0 e
1 1 1 1 e
1 2 e Z Z
1111

Saída:

(0,1111,Z;(0,111,1Z;(0,11,11Z;(0,1,111Z;(0,e,1111Z;(1,e,1111Z));(1,1,111Z;(1,e,11Z)));(1,11,11Z;(1,1,1Z;(1,e,Z;(2;e;Z)))));(1,111,1Z;(1,11,Z;(2;11;Z))));(1;1111;Z;(2;1111;Z)))
