#include <iostream>
#include <vector>
using namespace std;

void right_rotation(vector<int>& vet, int nrot){

    nrot %= vet.size();

    for (int j {1}; j <= nrot; ++j){
        for (size_t i = vet.size() - 1; i > 0; --i){
            int aux = vet[i];
            vet[i] = vet[i - 1];
            vet[i - 1] = aux;
        }
    }
}

//Imprimir o vetor rotacionado
void show(vector<int> &vet) {
    cout << "[ ";
    for(int value : vet)
        cout << value << " ";
    cout << "]\n";
}

int main(){

    //Tamanho do vetor e número de rotações
    int size, nrot;
    cin >> size >> nrot; 

    //vetor com os elemntos
    vector<int> vet(size);

    for(int i = 0; i < size; i++)
        cin >> vet[i];
    
    right_rotation(vet, nrot);
    show(vet);
}