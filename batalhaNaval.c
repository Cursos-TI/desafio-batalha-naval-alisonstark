#include <stdio.h>
#include <stdlib.h>



// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// #############################
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

// #############################

// Por padrao, os navios sao posicionados horizontalmnente da esquerda para a direita
// ou verticalmente de cima para baixo, dependendo da orientacao escolhida pelo usuario.
// TODO Permitir posicionamento diagonal dos navios

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

// Criar uma funcao pra zerar o tabuleiro e liberar a memoria alocada
void liberar_tabuleiro(unsigned short** tabuleiro, unsigned short tamanho_tabuleiro){
    for (unsigned short i = 0; i < tamanho_tabuleiro; i++) {
        free(tabuleiro[i]);
    }
    free(tabuleiro);
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
                
                // Se o numero for 3, pintar de azul; se for 4, pintar de ciano; se for 5, pintar de verde
                if (tabuleiro[i-1][j-1] == 3) {
                    printf("\033[0;34m%hu\033[0m  ", tabuleiro[i-1][j-1]);
                } else if (tabuleiro[i-1][j-1] == 4) {
                    printf("\033[0;36m%hu\033[0m  ", tabuleiro[i-1][j-1]);
                } else if (tabuleiro[i-1][j-1] == 5) {
                    printf("\033[0;32m%hu\033[0m  ", tabuleiro[i-1][j-1]);
                } else {
                    printf("%hu  ", tabuleiro[i-1][j-1]);
                }
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

    unsigned short tamanho_tabuleiro;  

    // Criar banner de boas-vindas
    printf("########################################################\n");
    printf("########## Bem-vindo(a) ao jogo Batalha Naval ##########\n");
    printf("########################################################\n");

    printf("Escolha o tamanho do tabuleiro (minimo 5 e maximo 10): ");
    scanf("%hu", &tamanho_tabuleiro);
    while(tamanho_tabuleiro < 5 || tamanho_tabuleiro > 10){
        printf("Tamanho invalido! Escolha um tamanho entre 5 e 10: ");
        scanf("%hu", &tamanho_tabuleiro);
    }

    printf("\nTamanho do tabuleiro definido: %hu x %hu\n\n", tamanho_tabuleiro, tamanho_tabuleiro);
    printf("Escolha o nivel de dificuldade:\n");
    printf("(1) - Novato:       1 navio tamanho 3\n");
    printf("(2) - Aventureiro:  1 navio tamanho 3 e 1 navio tamanho 4\n");
    printf("(3) - Mestre:       1 navio tamanho 3, 1 navio tamanho 4 e 1 navio tamanho 5\n\n");

    // Salvar opção do usuário
    unsigned short nivel_dificuldade;
    printf("Digite o numero correspondente ao nivel desejado: ");
    scanf("%hu", &nivel_dificuldade);
    while(nivel_dificuldade < 1 || nivel_dificuldade > 3){
        printf("Nivel invalido! Escolha um nivel entre 1 e 3: ");
        scanf("%hu", &nivel_dificuldade);
    }

    // Inicializar tabuleiro
    unsigned short** tabuleiro;
    unsigned short** tabuleiro_inicializado = inicializar_tabuleiro(tabuleiro, tamanho_tabuleiro);
    char letras[tamanho_tabuleiro];                                                     
    unsigned short numeros[tamanho_tabuleiro];

    // Coordenadas
    char coord_letra;
    unsigned short coord_num;
    char orientacao;

    
    // Posicionar navios de acordo com o nível de dificuldade
    switch(nivel_dificuldade){
        case 1:
            printf("Escolha as coordenadas do navio tamanho 3: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);
            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);

            unsigned short navio[3] = {3, 3, 3};
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio, coord_letra, coord_num, orientacao);
            printf("########## Configuracao final ########## \n");
            printf("########################################\n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);
            
            break;
        
        case 2:
            printf("Escolha as coordenadas do navio tamanho 3: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);

            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);
            unsigned short navio1[3] = {3, 3, 3};
            unsigned short navio2[4] = {4, 4, 4, 4};
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio1, coord_letra, coord_num, orientacao);
            printf("Escolha as coordenadas do navio tamanho 3: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);

            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio2, coord_letra, coord_num, orientacao);

            printf("########## Configuracao final ########## \n");
            printf("########################################\n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);
            
            break;

        case 3:
             // Implementar similarmente ao case 2, mas com um navio adicional de tamanho 5
            printf("Escolha as coordenadas do navio tamanho 3: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);

            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);
            unsigned short navio3[3] = {3, 3, 3};
            unsigned short navio4[4] = {4, 4, 4, 4};
            unsigned short navio5[5] = {5, 5, 5, 5, 5};
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio3, coord_letra, coord_num, orientacao);
            printf("Escolha as coordenadas do navio tamanho 4: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);

            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio4, coord_letra, coord_num, orientacao);
            printf("Escolha as coordenadas do navio tamanho 5: \n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);

            printf("Digite a letra para escolher a coluna de partida: ");
            scanf(" %c", &coord_letra);
            printf("Digite o numero para escolher a linha de partida: ");
            scanf("%hu", &coord_num);
            printf("\n");
            printf("Escolha a orientacao do navio (h para horizontal, v para vertical): ");
            scanf(" %c", &orientacao);
            posicionar_navio(tabuleiro_inicializado, tamanho_tabuleiro, navio5, coord_letra, coord_num, orientacao);
            printf("########## Configuracao final ########## \n");
            printf("########################################\n");
            printar_tabuleiro(letras, numeros, tabuleiro_inicializado, tamanho_tabuleiro);
            
            break;

        default:
            printf("Nivel de dificuldade invalido!\n"); // Redundante, mas tudo bem
            break;

    }
    
    liberar_tabuleiro(tabuleiro_inicializado, tamanho_tabuleiro);
    return 0;
}
