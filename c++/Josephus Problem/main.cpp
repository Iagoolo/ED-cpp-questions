#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& vetor, int v_size, int posv) {
    cout << "[ ";
    for (int i = 0; i < v_size; i++) {
        if (i == posv) {
            cout << vetor[i] << "> ";
        } else {
            cout << vetor[i] << " ";
        }
    }
    cout << "]" << endl;
}

// Essa função irá fazer com que o elemento que deverá ser derrotado
// seja apagado do vetor através de trocas sucessivas até ele 
// alcançar a última posição e com a diminuição do tamanho do vetor
void matar(vector<int>& vetor, int v_size, int posv) {
    
    // Imprime primeiramente o vetor, para imprimir o vetor original antes da mudança
    imprimir(vetor, v_size, posv);

    // Caso base: vetor com apenas um elemento
    if (v_size == 1) {
        return;
    }

    // Ajuste da posição inicial (verifica se está dentro do vetor)
    int i = posv;
    if (posv == v_size - 1) { // Último elemento
        posv = -1;
        i = 0;
    } else {
        i = posv + 1;
    }

    // Move o elemento atual para o final
    for (; i < v_size - 1; i++) {
        swap(vetor[i], vetor[i + 1]);
    }

    // Reduz o tamanho do vetor
    --v_size;

    // Atualiza a posição para o próximo elemento
    if (posv + 1 == v_size) {
        posv = 0;
    } else {
        ++posv;
    }


    // Chamada recursiva para a retirada dos outros elementos
    matar(vetor, v_size, posv);
}

int main() {

    int v_size;
    cin >> v_size; // Quantidade de elementos

    vector<int> vetor(v_size);
    for (int i = 0; i < v_size; ++i) {
        vetor[i] = i + 1;
    }

    int pos; // Posição na fila
    cin >> pos;

    int posv = pos - 1; // Posição no vetor (como o vetor começa a partir de 0, diminuímos uma posição)

    matar(vetor, v_size, posv);

    return 0;
}
