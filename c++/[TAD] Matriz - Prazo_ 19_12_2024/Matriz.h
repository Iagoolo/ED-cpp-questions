#ifndef MATRIZ_H
#define MATRIZ_H

class Matriz {
private:
    int lin;    // numero de linhas da matriz
    int col;    // numero de colunas da matriz
    int **mat;  // ponteiro para matriz de inteiros (deve ser alocada dinamicamente)
    
public:
    // Construtor: aloca matriz com m linhas e n colunas
    Matriz(int m, int n);

    // Destrutor: libera memoria alocada
    ~Matriz(); 

    // Retorna o numero de linhas da matriz
    int linhas();

    // Retorna o numero de colunas da matriz
    int colunas();  

    // Retorna o valor contido na celula [i][j] da matriz
    int getValor(int i, int j); 

    // Atribui o valor v a celula [i][j] da matriz
    void setValor(int v, int i, int j); 

    // Imprimir a matriz 
    void print();

    // Com a linha abaixo, eu estou dizendo para o C++ nao criar
    // o construtor de copia default. Ou seja, nao quero que seja possivel
    // instanciar uma matriz passando outra matriz como argumento pelo construtor
    Matriz(const Matriz& m) = delete;  
    // tambem nao quero que seja possivel atribuir uma matriz a outra
    Matriz& operator=(const Matriz& m) = delete;
};

#endif