#include <stdio.h>

# define LIN 3
# define COL 3

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    unsigned short tabuleiro[11][10];

    // Inicializar tabuleiro
    // Letreiro do topo
    char letras[10] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J'};
    printf(" ");
    for (unsigned short i = 0; i < 11; i++){
        printf("  %c", letras[i]);
    }
    
    // Durante a construção do tabuleiro, certificar-se de acrescentar a numeração 1-10 na minha coluna (j=0)
    // Durante as manipulações, certificar-se de que na posição tabuleiro[i][0] temos as numerações 1-10
    // O tabuleiro de fato começa em tabuleiro[i][j>=1]
    printf("\n");
    for (unsigned short i = 0; i < 11; i++) {
        for (unsigned short j = 0; j < 10; j++){
            if (j == 0) {
                tabuleiro[i][j] = i+1; 
            } else { 
                tabuleiro[i][j] = 0;
            }
        }
    }

    // Printar tabuleiro
    for (unsigned short i = 0; i < 10; i++) {
        for (unsigned short j = 0; j < 10; j++){
            if (tabuleiro[i][j] == 10){
                printf("%hu ", tabuleiro[i][j]);    
            } else {
                printf("%hu  ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }

    // Declarar navios
    // TODO Usuário pode escolher o posicionamento do navio (horizontal, vertical ou diagonal) 
    // Lhe são oferecido 3 navios com número variado de casas (3, 4 e 5)
    
    // Navio de 3 casas
    unsigned short navio_horizontal[3] = {3, 3, 3};
    unsigned short navio_vertical[3] = {3, 3, 3};

    // Posicionar navio
    // Usuário digita a coordenada (x,y) inicial e a partir dela o navio é posicionado para a direita ou para cima 
    // TODO Usuário pode escolher se posiciona para a direta ou esquerda (horizontal) ou para cima ou baixo (vertical)
    // void posicionar_navio(unsigned short tabuleiro[LIN][COL], unsigned short navio[], unsigned short coord_i, unsigned short coord_j){
        
    // }



    


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
