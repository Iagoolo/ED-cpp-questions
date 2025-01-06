#include <iostream>
#include <vector>

//Recebe o vetor de inteiros resultados e o seu tamanho e os imprime sem modificá-los
void imprimir (const std::vector<int>& resultados, const size_t r_size){

    // Imprimir os resultados
    for (size_t i = 0; i < r_size; ++i) {
        std::cout << resultados[i];
        if (i != r_size - 1) {
            std::cout << " ";
        } else {
            std::cout << "\n";
        }
    }
}

//compara se as strings são iguais sem modificá-las
void compara(const std::vector<std::string>& consultas, const size_t c_size, const std::vector<std::string>& busca,
             const size_t b_size, std::vector<int>& resultados, const size_t r_size) {
                
    // Para cada palavra da lista de busca
    for (size_t i = 0; i < b_size; ++i) {
        // Contador de ocorrências para busca[i]
        for (size_t j = 0; j < c_size; ++j) {
            if (busca[i] == consultas[j]) {
                resultados[i]++;  // Caso sejam iguais, o resultado da busca que está sendo feita aumenta 
            }
        }
    }
}

void leitura(std::vector<std::string>& palavras, size_t p_size) {
    
    for (size_t i {0}; i < p_size; ++i){
        std::cin >> palavras[i];
    }   
}

int main() {

    size_t c_size; // Tamanho do vetor de consultas
    std::cin >> c_size; // Leitura do tamanho do vetor de string
    std::cin.ignore(); // Limpar o buffer de entrada

    std::vector<std::string> consultas(c_size); // Inicialização do vetor de string consulta
    leitura(consultas, c_size); // Leitura de consultas

    size_t b_size; // Tamanho do vetor de busca
    std::cin >> b_size; // Leitura do tamanho do vetor de busca
    std::cin.ignore(); // Limpar o buffer de entrada

    std::vector<std::string> busca(b_size); // Inicialização do vetor de string busca
    leitura(busca, b_size); // Leitura de buscas
    
    //Tamanho do vetor que mostrará resultados 
    //Tamanho do vetor resultados será igual ao de busca
    size_t r_size = b_size; 
    std::vector<int> resultados(r_size, 0); // Inicializa o vetor de resultados com zeros

    compara(consultas, c_size, busca, b_size, resultados, r_size); // Faz a comparação entre consultas e busca
    imprimir(resultados, r_size);//Imprime os resultados

    return 0;
}