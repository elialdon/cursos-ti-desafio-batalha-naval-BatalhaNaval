#include <stdio.h>
#include <stdio.h>

#define TAMANHO 10
#define NAVIO 3
#define HABILIDADE 1
#define VAZIO 0

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // --- POSICIONAMENTO DE NAVIOS (Nível Aventureiro) ---
    
    // Navio Horizontal (Linha 1, Colunas 2 a 4)
    for(int j = 2; j <= 4; j++) tabuleiro[1][j] = NAVIO;

    // Navio Vertical (Linhas 5 a 7, Coluna 1)
    for(int i = 5; i <= 7; i++) tabuleiro[i][1] = NAVIO;

    // Navio Diagonal 1 (Caindo: (2,7), (3,8), (4,9))
    for(int i = 0; i < 3; i++) tabuleiro[2+i][7+i] = NAVIO;

    // Navio Diagonal 2 (Subindo: (7,2), (8,1))
    for(int i = 0; i < 2; i++) tabuleiro[7+i][2-i] = NAVIO;

    printf("### Tabuleiro com Navios ###\n");
    exibirTabuleiro(tabuleiro);

    // --- HABILIDADES ESPECIAIS (Nível Mestre) ---

    // 1. Habilidade em CONE (Inicia em 0,4)
    int cone[TAMANHO][TAMANHO] = {0};
    int centroX = 0, centroY = 4;
    for (int i = 0; i < 3; i++) { // Altura do cone
        for (int j = centroY - i; j <= centroY + i; j++) {
            if (i >= 0 && i < TAMANHO && j >= 0 && j < TAMANHO)
                cone[i][j] = HABILIDADE;
        }
    }
    printf("### Habilidade: Cone ###\n");
    exibirTabuleiro(cone);

    // 2. Habilidade em CRUZ (Centro em 5,5)
    int cruz[TAMANHO][TAMANHO] = {0};
    int cX = 5, cY = 5;
    for (int k = 0; k < 5; k++) {
        cruz[cX][cY-2+k] = HABILIDADE; // Horizontal
        cruz[cX-2+k][cY] = HABILIDADE; // Vertical
    }
    printf("### Habilidade: Cruz ###\n");
    exibirTabuleiro(cruz);

    // 3. Habilidade em OCTAEDRO (Losango - Centro em 8,5)
    int octa[TAMANHO][TAMANHO] = {0};
    int oX = 8, oY = 5;
    for (int i = -2; i <= 2; i++) {
        for (int j = -2; j <= 2; j++) {
            // A lógica do octaedro/losango é baseada na distância de Manhattan: |dx| + |dy| <= raio
            if ((i < 0 ? -i : i) + (j < 0 ? -j : j) <= 2) {
                if (oX+i >= 0 && oX+i < TAMANHO && oY+j >= 0 && oY+j < TAMANHO)
                    octa[oX+i][oY+j] = HABILIDADE;
            }
        }
    }
    printf("### Habilidade: Octaedro ###\n");
    exibirTabuleiro(octa);

    return 0;
}