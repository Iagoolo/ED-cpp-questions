#include "fogo.hpp"

// Função que espalha o fogo a partir de uma posição inicial
void tocar_fogo(std::vector<std::string> &mat, int l, int c) {
    int nl = mat.size();    // Número de linhas da matriz
    int nc = mat[0].size(); // Número de colunas da matriz

    // Verifica se a posição está fora dos limites da matriz
    if (l < 0 || l >= nl || c < 0 || c >= nc) {
        return;
    }

    // Se a posição atual não contém uma árvore, o fogo não se espalha
    if (mat[l][c] != '#') {
        return;
    }

    // Marca a posição atual como queimada
    mat[l][c] = 'o';

    // Chama a função recursivamente nas 4 direções cardeais
    tocar_fogo(mat, l + 1, c); // Sul
    tocar_fogo(mat, l - 1, c); // Norte
    tocar_fogo(mat, l, c + 1); // Leste
    tocar_fogo(mat, l, c - 1); // Oeste
}
