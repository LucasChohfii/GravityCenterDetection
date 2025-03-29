#include <stdio.h>

// Função que lê a matriz do usuário
void lerMatriz(int linhas, int colunas, float matriz[100][100]) {
    printf("Digite os valores da matriz (%dx%d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }
}

// Função que encontra centro de gravidade
void encontrarCentroGravidade(int linhas, int colunas, float matriz[100][100]) {
    float somatotal = 0;
    //arrays que armazenam as somas das linhas e colunas
    float somalinhas[100] = {0};
    float somalcolunas[100] = {0};
    //calcula as somas das linhas e colunas
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            somatotal += matriz[i][j];
            somalinhas[j] += matriz[i][j];
            somalcolunas[j] += matriz[i][j];
        }
    }
    //encontrar centro de gravidade
    float CentroGravidadeLinha = 0;
    float CentroGravidadeColuna = 0;
    for (int i = 0; i < linhas; i++) {
        CentroGravidadeLinha += somalinhas[i] * i;
    }
    CentroGravidadeLinha /= somatotal;

    for (int j = 0; j < colunas; j++) {
        CentroGravidadeColuna += somalcolunas[j] * j;
    }
    CentroGravidadeColuna /= somatotal;

    //mostra centro de gravidade
    int linhaCentro = (int)CentroGravidadeLinha;
    int colunaCentro = (int)CentroGravidadeColuna;
    printf("Centro de Gravidade: Linha = %d (indice %d), Coluna = %d (indice %d)\n", linhaCentro + 1, linhaCentro, colunaCentro + 1, colunaCentro);

    //calcula a diferenca das linhas e colunas
    float diflinha = 0;
    float difcoluna = 0;
    for (int i = 0; i < linhas; i++) {
        float dif = somalinhas[i] - somalinhas[linhaCentro];
        diflinha += (dif < 0) ? -dif : dif; //valor abosluto usando "se-entao-senao"
    }
    for (int j = 0; j < colunas; j++) {
        float dif = somalcolunas[j] - somalcolunas[j];
        difcoluna += (dif < 0) ? -dif : dif; //valor absoluto usando "se-entao-senao"
    }
    //mostra as diferencas
    printf("Diferenca entre as somas das linhas = %.1f\n", diflinha);
    printf("Diferenca entre as somas das colunas = %.1f\n", difcoluna);
}
int main() {
    int linhas, colunas;
    float matriz[100][100];

    // Solicita ao usuário o tamanho da matriz
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    // Verifica se a matriz tem um tamanho válido
    if (linhas < 3 || colunas < 3 || linhas > 100 || colunas > 100) {
        printf("Numero de linhas invalido! Utilize no mínimo 3x3 e no maximo 100x100.\n");
        return 1;
    }
    // Chama a função para ler os elementos da matriz
    lerMatriz(linhas, colunas, matriz);
    // Chama a funcao que encontra o centro de gravidade e as diferencas.
    encontrarCentroGravidade(linhas, colunas, matriz);

    return 0;
}
