#include <stdio.h>

int main() {

    // Tabuleiro 10x10
    int tabuleiro[10][10];

    int i, j;

    // Inicializa o tabuleiro com água
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIO HORIZONTAL

    int linhaH = 1;
    int colunaH = 2;

    if(colunaH + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            if(tabuleiro[linhaH][colunaH + i] == 0) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // NAVIO VERTICAL

    int linhaV = 5;
    int colunaV = 7;

    if(linhaV + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            if(tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // NAVIO DIAGONAL PRINCIPAL

    int linhaDP = 0;
    int colunaDP = 0;

    if(linhaDP + 3 <= 10 && colunaDP + 3 <= 10) {

        for(i = 0; i < 3; i++) {

            if(tabuleiro[linhaDP + i][colunaDP + i] == 0) {
                tabuleiro[linhaDP + i][colunaDP + i] = 3;
            }
        }
    }

    // NAVIO DIAGONAL SECUNDÁRIA

    int linhaDS = 2;
    int colunaDS = 9;

    if(linhaDS + 3 <= 10 && colunaDS - 2 >= 0) {

        for(i = 0; i < 3; i++) {

            if(tabuleiro[linhaDS + i][colunaDS - i] == 0) {
                tabuleiro[linhaDS + i][colunaDS - i] = 3;
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