/**** Este programa tem como objetivo resolver o problema da Torre de Hanoi 
com quatro pinos de forma automática. ****/
#include <iostream>
using namespace std;

// Função recursiva que resolve o problema da Torre de Hanói com quatro pinos.
void hanoi(int quant, char init, char aux1, char aux2, char fim) {

    // Caso base: Se não houver discos, termina a execução.
    if (quant == 0) {
        return;
    }

    // Caso base: Se houver apenas um disco, move diretamente para o pino final.
    if (quant == 1) {
        cout << init << " -> " << fim << endl;
        return;
    }

    // Dividir os discos em dois subconjuntos:
    // 1. Mover o subconjunto superior para o pino auxiliar 1.
    hanoi(quant / 2, init, fim, aux2, aux1);

    // 2. Mover o subconjunto restante para o pino final.
    hanoi(quant - quant / 2, init, aux2, aux1, fim);

    // 3. Mover o subconjunto superior do pino auxiliar 1 para o pino final.
    hanoi(quant / 2, aux1, init, aux2, fim);
}

int main() {
    int quant;
    // Lê a quantidade de discos do usuário.
    cout << "Digite o número de anilhas: ";
    cin >> quant;

    // Chama a função hanoi para resolver o problema.
    hanoi(quant, 'A', 'B', 'C', 'D');

    return 0;
}
