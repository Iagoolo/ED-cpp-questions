#include <iostream>
#include "Box.h" // Inclui a classe Box

using namespace std;

int main() {
    // Array para armazenar largura, altura e comprimento
    int vetor[3];

    // Solicita ao usuário as medidas da caixa
    cout << "Digite as medidas da caixa" << endl;
    cout << "Largura - Altura - Comprimento: ";
    cin >> vetor[0]; // Largura
    cin >> vetor[1]; // Altura
    cin >> vetor[2]; // Comprimento

    // Criação de um objeto da classe Box
    Box caixa(vetor[0], vetor[1], vetor[2]);

    // Exibe o volume da caixa
    cout << "Volume: " << caixa.volume() << endl;

    return 0;
}
