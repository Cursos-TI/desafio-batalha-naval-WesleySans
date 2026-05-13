#include <stdio.h>

int main() {

    int tabuleiro[10][10];

    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    int i, j;

    // Inicializa tabuleiro com água
    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // NAVIOS

    // Navio horizontal
    for(i = 0; i < 3; i++) {
        tabuleiro[1][2 + i] = 3;
    }

    // Navio vertical
    for(i = 0; i < 3; i++) {
        tabuleiro[5 + i][7] = 3;
    }

    // Navio diagonal principal
    for(i = 0; i < 3; i++) {
        tabuleiro[2 + i][2 + i] = 3;
    }

    // Navio diagonal secundária
    for(i = 0; i < 3; i++) {
        tabuleiro[2 + i][8 - i] = 3;
    }

    // HABILIDADE CONE

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            if(j >= 2 - i && j <= 2 + i) {
                cone[i][j] = 1;
            }
            else {
                cone[i][j] = 0;
            }
        }
    }

    // HABILIDADE CRUZ

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            if(i == 2 || j == 2) {
                cruz[i][j] = 1;
            }
            else {
                cruz[i][j] = 0;
            }
        }
    }

    // HABILIDADE OCTAEDRO

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            if((i + j >= 2) &&
               (i + j <= 6) &&
               (i - j <= 2) &&
               (j - i <= 2)) {

                octaedro[i][j] = 1;
            }
            else {
                octaedro[i][j] = 0;
            }
        }
    }

    // POSIÇÕES DAS HABILIDADES

    int origemConeLinha = 1;
    int origemConeColuna = 5;

    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    int origemOctaedroLinha = 7;
    int origemOctaedroColuna = 7;

    // APLICA CONE NO TABULEIRO

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            int linhaTabuleiro = origemConeLinha + i;
            int colunaTabuleiro = origemConeColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(cone[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // APLICA CRUZ NO TABULEIRO

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            int linhaTabuleiro = origemCruzLinha + i - 2;
            int colunaTabuleiro = origemCruzColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(cruz[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // APLICA OCTAEDRO NO TABULEIRO

    for(i = 0; i < 5; i++) {

        for(j = 0; j < 5; j++) {

            int linhaTabuleiro = origemOctaedroLinha + i - 2;
            int colunaTabuleiro = origemOctaedroColuna + j - 2;

            if(linhaTabuleiro >= 0 &&
               linhaTabuleiro < 10 &&
               colunaTabuleiro >= 0 &&
               colunaTabuleiro < 10) {

                if(octaedro[i][j] == 1 &&
                   tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0) {

                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
                }
            }
        }
    }

    // EXIBE TABULEIRO

    printf("TABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < 10; i++) {

        for(j = 0; j < 10; j++) {

            if(tabuleiro[i][j] == 0) {
                printf("0 ");
            }
            else if(tabuleiro[i][j] == 3) {
                printf("3 ");
            }
            else if(tabuleiro[i][j] == 5) {
                printf("5 ");
            }
        }

        printf("\n");
    }

    return 0;
}