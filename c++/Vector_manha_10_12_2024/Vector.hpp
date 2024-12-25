#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

// Classe que implementa uma lista linear de inteiros
class Vector {
private:
    int m_capacity; // tamanho maximo do array
    int m_size;     // numero de elementos na lista
    int *m_array;   // ponteiro para o array de int

public:
    // Construtor de cópia
    Vector(const Vector& vec);

    // Construtor default
    Vector();

    // Destrutor
    ~Vector();

    // Solicita que a capacidade do vetor seja n.
    // Se n for maior que a capacidade atual do vetor, a
    // funcao faz com que a lista aumente sua capacidade
    // realocando os elementos para o novo vetor . Em todos
    // os outros casos , a chamada da funcao nao causa uma
    // realocacao e a capacidade do vetor nao eh afetada.
    void reserve(int n); // O(n)

    // Recebe um inteiro como argumento e o adiciona
    // logo apos o ultimo elemento da lista .
    void push_back(const int & value); // tempo medio O(1)

    // Retorna uma referencia para o elemento na posicao k .
    // A funcao verifica automaticamente se k esta dentro dos
    // limites de elementos validos no vetor, lancando uma
    // excecao 'out_of_range' se nao estiver.
    int& at(int k); // O(1)
    const int& at(int k) const; // O(1) versao const da funcao at

    // Retorna quantos elementos existem na lista
    int size() const;

    // Retorna se a lista esta vazia
    bool empty() const;

    // Retorna a capacidade total da lista
    int capacity() const;

    // sobrecarga do operador []
    // Recebe um indice k e retorna o elemento na posicao k
    // Se k for invalido, mesmo assim a funcao acessa a posicao (cuidado!!!)
    int& operator[] (int k);
    const int& operator[] (int k) const; // versao const do operador[]

    // Remove o último elemento da lista
    void pop_back();
};

#endif