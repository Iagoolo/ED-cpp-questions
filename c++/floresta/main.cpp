/**** Este programa tem como objetivo resolver o problema do fogo em uma floresta.
-> A floresta é representada por uma matriz de caracteres.
-> O fogo começa em uma posição inicial e se espalha nas 4 direções cardeais.
-> Queime as árvores representadas por '#' e mantenha os espaços vazios '.' intactos.
****/

#include <iostream>
#include <string>
#include <vector>
#include "fogo.hpp" // Inclui a função de espalhar fogo

using namespace std;

// Função para exibir a matriz no terminal
void show_mat(vector<string> mat);

// Função para ler a matriz fornecida pelo usuário
void read_mat(vector<string> &mat, int nl);

// Função principal
int main() {
    int nl = 0, nc = 0, lfire = 0, cfire = 0;

    cout << "Digite a quantidade de linhas e colunas e por onde o fogo se inicia" << endl;
    // Lê a quantidade de linhas, colunas e a posição inicial do fogo
    cin >> nl >> nc >> lfire >> cfire;
    vector<string> mat; // Matriz que representa a floresta
    read_mat(mat, nl);
    // Chama a função que espalha o fogo na matriz
    tocar_fogo(mat, lfire, cfire);

    // Exibe o estado final da floresta após o fogo
    show_mat(mat);

}
// Mostra o conteúdo da matriz linha por linha
void show_mat(vector<string> mat) {
    for (int l = 0; l < (int) mat.size(); l++) {
        cout << mat[l] << "\n"; // Imprime cada linha da matriz
    }
}
// Lê a matriz da entrada padrão
void read_mat(vector<string> &mat, int nl) {
    for (int l = 0; l < nl; l++) {
        string linha; // Variável para armazenar a linha atual
        cin >> linha; // Lê uma linha da matriz
        mat.push_back(linha); // Adiciona a linha ao vetor da matriz
    }
}
