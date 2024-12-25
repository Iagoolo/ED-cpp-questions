/**** Este programa tem como objetivo resolver o problema da Torre de Hanoi 
com três pinos de forma automática. ****/
#include <iostream>

using namespace std;

// Função recursiva responsável por resolver a Torre de Hanoi.
// Move os discos de um pino inicial para um pino final, usando um pino intermediário.
void hanoi(int quant, char ini, char med, char final){
    // Caso base: se houver apenas um disco, move-o diretamente para o pino final.
    if (quant == 1){
        cout << ini << " -> " << final << endl;
        return;
    } 
    // Passo recursivo:
    // 1. Move os discos superiores para o pino intermediário.
    hanoi(quant - 1, ini, final, med);
    // 2. Move o maior disco diretamente para o pino final.
    cout << ini << " -> " << final << endl;     
    // 3. Move os discos do pino intermediário para o pino final.
    hanoi(quant - 1, med, ini, final);  
}

int main(){
    int quant;
    // Solicita ao usuário o número de discos.
    cout << "Digite o número de anilhas: ";
    cin >> quant;

    // Chama a função Hanoi para resolver o problema.
    hanoi(quant, 'A', 'B', 'C');

    return 0;
}
