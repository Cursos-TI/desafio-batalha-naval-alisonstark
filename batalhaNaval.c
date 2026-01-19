#include <stdio.h>
#include <stdlib.h>


// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Definir funcao para inicializar o tabuleiro
unsigned short** inicializar_tabuleiro(unsigned short** tabuleiro, unsigned short tamanho_tabuleiro){
    // Inicializar matriz do tabuleiro com zeros (usar malloc para alocar dinamicamente)
    // Se eu usar calloc, ja inicializa com 0s, preenchendo os argumentos de calloc apropriadamente
    tabuleiro = (unsigned short**) malloc(tamanho_tabuleiro * sizeof(unsigned short*));
    for (unsigned short i = 0; i < tamanho_tabuleiro; i++) {
        tabuleiro[i] = (unsigned short*) calloc(tamanho_tabuleiro, sizeof(unsigned short));
    }
    return tabuleiro;
}

// Definir função para imprimir o tabuleiro
// Transformar em uma funcao para printar o tabuleiro
void printar_tabuleiro(char letras[], unsigned short numeros[], unsigned short** tabuleiro, unsigned short tamanho_tabuleiro){

    
    printf("\n");
    // Inicializar vetor de letras de acordo com o tamanho do tabuleiro, considerando que o vetor de letras esta vazio
    for (unsigned short j = 0; j < tamanho_tabuleiro; j++) {
        letras[j] = 'A' + j;
    }

    // Inicializar vetor de numeros de acordo com o tamanho do tabuleiro, considerando que o vetor de numeros esta vazio
    for (unsigned short i = 0; i < tamanho_tabuleiro; i++) {
        numeros[i] = i + 1;
    }

    printf(" ");
    for (unsigned short i = 0; i <= tamanho_tabuleiro; i++) {
        for (unsigned short j = 0; j <= tamanho_tabuleiro; j++) {

            if (i == 0 && j == 0) {
                printf("   ");
            }
            else if (i == 0) {
                printf("%c  ", letras[j-1]);
            }
            else if (j == 0) {
                printf("%hu  ", numeros[i-1]);
            }
            else {
                if(j == 1 && i <= 9){
                    printf(" ");
                }
                printf("%hu  ", tabuleiro[i-1][j-1]);
            }
        }
        // Indo da linha 0 para a linha 1, pule 2 linhas
        if (i == 0) {
            printf("\n\n");
        } else {
            printf("\n");
        }
    }
    printf("\n");
}

// Posicionar navio
// Considere orientacao 'h' para horizontal e 'v' para vertical
void posicionar_navio(unsigned short** tabuleiro, unsigned short tamanho_tabuleiro, unsigned short navio[3], unsigned short coord_letra, unsigned short coord_num, char orientacao){
    
    // Traduzir coordenadas em termos de (i,j)
    unsigned short coord_i = coord_num - 1; // linha
    // Transformar a letra em número
    unsigned short coord_j = coord_letra - 'A'; // coluna
    
    if (orientacao == 'h') {
        for (unsigned short k = 0; k < 3; k++) {
            // Checar se a posicao nao esta ocupada e se esta dentro dos limites do tabuleiro
            if(tabuleiro[coord_i][coord_j + k] != 0 && (coord_j + k) < tamanho_tabuleiro){
                printf("Erro: Posicao ja ocupada no tabuleiro ou limite do tabuleiro ultrapassado!\n");
                return;
            }
            tabuleiro[coord_i][coord_j + k] = navio[k];
        }
    } else if (orientacao == 'v') {
        for (unsigned short k = 0; k < 3; k++) {
            if(tabuleiro[coord_i + k][coord_j] != 0 && (coord_i + k) < tamanho_tabuleiro){
                printf("Erro: Posicao ja ocupada no tabuleiro ou limite do tabuleiro ultrapassado!\n");
                return;
            }
            tabuleiro[coord_i + k][coord_j] = navio[k];
        }
    }   
}

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    // Durante a construção do tabuleiro, certificar-se de acrescentar a numeração 1-10 na minha coluna (j=0)
    // Durante as manipulações, certificar-se de que na posição tabuleiro[i][0] temos as numerações 1-10
    // O tabuleiro de fato começa em tabuleiro[i][j>=1]

    // TODO Deixar o processo mais dinamico solicitando entrada do usuário para o posicionamento e orientacao dos navios e definiçao do tamanho do tabuleiro
    // Navios podem ter tamanho variável (mínimo 2 e máximo 5)
    // Tabuleiro pode ter tamanho variável (mínimo 5x5 e máximo 10x10)

    unsigned short** tabuleiro;
    unsigned short tamanho_tabuleiro = 10;                                  // Implementar tamanhos de tabuleiro definidos pelo usuário (mínimo 5x5 e máximo 10x10)
    char letras[10];                                                        // Automatizar a geração das letras conforme o tamanho do tabuleiro
    unsigned short numeros[10];

    unsigned short** tabuleiro_inicializado = inicializar_tabuleiro(tabuleiro, tamanho_tabuleiro);

    // Navios de exemplo posicionados
    posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, (unsigned short[3]){3, 3, 3}, 'B', 2, 'h'); // Posicionar navio horizontalmente em B2
    posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, (unsigned short[3]){3, 3, 3}, 'E', 5, 'v'); // Posicionar navio verticalmente em E5

    printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);
    
    // Navio de 3 casas
    unsigned short navio_horizontal[3] = {3, 3, 3};
    unsigned short navio_vertical[3] = {3, 3, 3};

    



    


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
