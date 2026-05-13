#include <stdio.h>

int main() {

    // Declaração do tabuleiro 10x10
    int tabuleiro[10][10];

    int i, j;

    // Inicializa todas as posições com 0 (água)
    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIO HORIZONTAL

    int linhaHorizontal = 1;
    int colunaHorizontal = 2;

    // Verifica se cabe no tabuleiro
    if(colunaHorizontal + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaHorizontal][colunaHorizontal + i] == 0) {

                tabuleiro[linhaHorizontal][colunaHorizontal + i] = 3;
            }
        }
    }

    // NAVIO VERTICAL

    int linhaVertical = 5;
    int colunaVertical = 7;

    // Verifica se cabe no tabuleiro
    if(linhaVertical + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaVertical + i][colunaVertical] == 0) {

                tabuleiro[linhaVertical + i][colunaVertical] = 3;
            }
        }
    }

    // NAVIO DIAGONAL PRINCIPAL

    int linhaDiagonal1 = 0;
    int colunaDiagonal1 = 0;

    // Verifica limites do tabuleiro
    if(linhaDiagonal1 + 3 <= 10 &&
       colunaDiagonal1 + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaDiagonal1 + i]
                         [colunaDiagonal1 + i] == 0) {

                tabuleiro[linhaDiagonal1 + i]
                          [colunaDiagonal1 + i] = 3;
            }
        }
    }

    // NAVIO DIAGONAL SECUNDÁRIA

    int linhaDiagonal2 = 2;
    int colunaDiagonal2 = 9;

    // Verifica limites do tabuleiro
    if(linhaDiagonal2 + 3 <= 10 &&
       colunaDiagonal2 - 2 >= 0) {

        for(i = 0; i < 3; i++) {

            // Verifica sobreposição
            if(tabuleiro[linhaDiagonal2 + i]
                         [colunaDiagonal2 - i] == 0) {

                tabuleiro[linhaDiagonal2 + i]
                          [colunaDiagonal2 - i] = 3;
            }
        }
    }

    // EXIBE O TABULEIRO

    printf("TABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    return 0;
}