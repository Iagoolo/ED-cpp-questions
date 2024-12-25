#include <iostream>

class Box {
    private:
        // Atributos privados: largura, altura e comprimento
        double largura {1.0};
        double altura {1.0};
        double comprimento {1.0};

    public:
        // Construtor para inicializar a caixa com valores fornecidos
        Box(double l, double a, double c) {
            std::cout << "Caixa criada" << std::endl;
            comprimento = c;
            largura = l;
            altura = a;
        }

        // Método que calcula o volume da caixa
        double volume() {
            return largura * comprimento * altura;
        }

        // Getter para obter a altura
        double getaltura() {
            return altura;
        }

        // Setter para adicionar um valor à altura
        void setaddaltura(int valor) {
            altura += valor;
        }
};
