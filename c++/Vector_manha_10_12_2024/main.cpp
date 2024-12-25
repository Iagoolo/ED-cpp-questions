#include <iostream>
#include "Vector.hpp"
using namespace std;

// Funcao que recebe um vector e o imprime na tela
void print(const Vector& vec) {
    for(int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Main Function
int main() {
    Vector meu_vector; // Cria vector vazio

    for(int i = 1; i <= 20; ++i) {
        meu_vector.push_back(i); // insere numeros no vector
    }
    
    Vector vector2(meu_vector); // cria uma copia do vector anterior
    
    print(meu_vector);
    print(vector2);

    vector2[3] = 99999;

    print(meu_vector);
    print(vector2);

    while(!meu_vector.empty()) { // esvazia meu_vector
        meu_vector.pop_back();
    }

    cout << "size do meu_vector = " << meu_vector.size() << endl;
    cout << "size do vector2 = " << vector2.size() << endl;
    cout << "capacity do meu_vector = " << meu_vector.capacity() << endl;
    cout << "capacity do vector2 = " << vector2.capacity() << endl;
   
    return 0;
}