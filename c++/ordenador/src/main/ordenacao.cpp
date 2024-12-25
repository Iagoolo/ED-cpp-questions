/**** Este programa tem como objetivo ordenar um conjunto de valores dados pelo
usuário de forma automática, usando um algoritmo de ordenação chamado bubble sort ****/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Função que implementa o algoritmo Bubble Sort para ordenar o vetor
void ordenacao(vector<int>& array) {
    while (true) {
        bool trocou = false; // Verifica se houve troca nesta iteração

        // Percorre o vetor para comparar elementos adjacentes
        for (size_t i = 0; i < array.size() - 1; ++i) {
            if (array[i] > array[i + 1]) { 
                // Troca os elementos fora de ordem
                int aux = array[i];
                array[i] = array[i + 1];
                array[i + 1] = aux;
                trocou = true; // Marca que houve uma troca
            }
        }

        // Se nenhuma troca foi feita, o vetor já está ordenado
        if (!trocou) {
            break; // Sai do loop
        }
    }
}

int main() {
    vector<int> array;   // Vetor para armazenar os números
    string valores;      // String para capturar a entrada

    cout << "Digite os valores a serem ordenados" << endl;
    getline(cin, valores); // Lê a linha completa de números fornecida pelo usuário
    stringstream ss(valores);
    int n;

    // Converte os valores da string para inteiros e os adiciona ao vetor
    while (ss >> n) {
        array.push_back(n);
    }

    // Chama a função de ordenação
    ordenacao(array);

    // Imprime os números ordenados
    for (auto &v : array)
        cout << v << endl;

    return 0;
}
