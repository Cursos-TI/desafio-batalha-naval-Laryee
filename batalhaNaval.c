#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // -------------------------------
    // Declaração e inicialização do tabuleiro com água (0)
    // -------------------------------
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa todo o tabuleiro com água (valor 0)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // -------------------------------
    // Declaração dos navios (não necessário armazenar, mas conforme enunciado)
    // -------------------------------
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // -------------------------------
    // Coordenadas iniciais dos navios (definidas diretamente no código)
    // -------------------------------
    int linhaHorizontal = 2;
    int colunaHorizontal = 4;

    int linhaVertical = 5;
    int colunaVertical = 7;

    // -------------------------------
    // Validação para garantir que os navios não saiam do tabuleiro
    // -------------------------------
    if (colunaHorizontal + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal fora dos limites!\n");
        return 1;
    }

    if (linhaVertical + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical fora dos limites!\n");
        return 1;
    }

    // -------------------------------
    // Posicionando o navio horizontal
    // -------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Validação extra: evitar sobreposição
        if (tabuleiro[linhaHorizontal][colunaHorizontal + i] != AGUA) {
            printf("Erro: Sobreposição detectada no navio horizontal!\n");
            return 1;
        }
        tabuleiro[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    // -------------------------------
    // Posicionando o navio vertical
    // -------------------------------
    for (int i = 0; i < TAM_NAVIO; i++) {
        // Validação extra: evitar sobreposição
        if (tabuleiro[linhaVertical + i][colunaVertical] != AGUA) {
            printf("Erro: Sobreposição detectada no navio vertical!\n");
            return 1;
        }
        tabuleiro[linhaVertical + i][colunaVertical] = NAVIO;
    }

    // -------------------------------
    // Exibindo o tabuleiro
    // -------------------------------
    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
