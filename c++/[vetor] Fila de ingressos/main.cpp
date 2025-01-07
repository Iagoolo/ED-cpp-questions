#include <iostream>
#include <vector>

using namespace std;

void imprimir(const vector<int>& fila) {
    for (size_t i = 0; i < fila.size(); ++i) {
        cout << fila[i] << " ";
    }
    cout << endl;
}

// Função para verificar se uma pessoa desceu
bool pessoaDesceu(const vector<int>& descer, int pessoa) {
    for (int p : descer) {
        if (p == pessoa) {
            return true;
        }
    }
    return false;
}

void new_fila(vector<int>& fila, const vector<int>& descer) {
    vector<int> newFila;

    for (int pessoa : fila) {
        if (!pessoaDesceu(descer, pessoa)) {  // Se a pessoa não desceu, ela permanece na fila
            newFila.push_back(pessoa);
        }
    }

    fila = newFila;  // Atualiza a fila com a nova lista
}

void leitura(vector<int>& vetor) {
    for (int& pessoa : vetor) {
        cin >> pessoa;
    }
}

int main() {
    int f_quant;  // Quantidade de pessoas inicialmente na fila
    cin >> f_quant;

    vector<int> fila(f_quant);  // Vetor fila com a quantidade de pessoas
    leitura(fila);

    int d_quant;  // Quantidade de pessoas que desceram
    cin >> d_quant;

    vector<int> descer(d_quant);  // Vetor de pessoas que desceram do ônibus
    leitura(descer);

    new_fila(fila, descer);
    imprimir(fila);

    return 0;
}
