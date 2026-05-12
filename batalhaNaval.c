#include <stdio.h>

int main() {

    // Matriz do tabuleiro 10x10
    int tabuleiro[10][10];

    // Vetores dos navios
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais
    int linhaHorizontal = 2;
    int colunaHorizontal = 1;

    int linhaVertical = 5;
    int colunaVertical = 7;

    int i, j;

    // Inicializa o tabuleiro com água
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Validação do navio horizontal
    if(colunaHorizontal + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {
                tabuleiro[linhaHorizontal][colunaHorizontal + i] =
                navioHorizontal[i];
            }
        }
    }

    // Validação do navio vertical
    if(linhaVertical + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaVertical + i][colunaVertical] == 0) {
                tabuleiro[linhaVertical + i][colunaVertical] =
                navioVertical[i];
            }
        }
    }

    // Exibe o tabuleiro
    printf("TABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}