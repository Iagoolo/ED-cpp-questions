#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Matriz.h"
using namespace std;


/**
 * Essa funcao recebe como argumento referencias para duas matrizes A e B.
 * Se A e B tiverem as mesma dimensoes (numero de linhas igual e numero de colunas igual),
 * entao a soma eh feita e eh armazenada numa nova matriz C e depois essa matriz C eh impressa na tela. 
 * Lembre das aulas de matematica que a soma de uma matriz A com uma matriz B so eh possivel 
 * se o numero de linhas e de colunas de A for igual ao numero de linhas e de colunas de B, respectivamente.
 * Se for possivel fazer a soma, entao a nova matriz C contendo o resultado da soma deve ser impressa. 
 * Caso contrario, a string "nao foi possivel somar" deve ser impressa no terminal.
 */
void soma(Matriz& A, Matriz& B) {
	
	if(A.linhas() != B.linhas() || A.colunas() != B.colunas()){
		cout << "nao foi possivel somar" << endl;
		return;
	} 
	
	Matriz C(A.linhas(), A.colunas());

	for (int i = 0; i < C.linhas(); i++){
		for (int j = 0; j < C.colunas(); j++){
			C.setValor((A.getValor(i, j) + B.getValor(i, j)), i, j);
		}
	}

	C.print();
}
/**
 * Essa funcao recebe como argumento referencias para duas matrizes A e B.
 * Lembre das aulas de matematica que a multiplicacao de uma matriz A por uma matriz B so eh possivel 
 * se o numero de colunas de A for igual ao numero de linhas de B. 
 * Se for possivel fazer a multiplicacao, uma nova matriz C eh criada contendo o resultado 
 * da multiplicacao e deve ser impressa no terminal.
 * Caso contrario, a string "nao foi possivel multiplicar" deve ser impressa no terminal. 
 */
void multiplica(Matriz& A, Matriz& B) {
	
	if (A.colunas() != B.linhas()){
		cout << "nao foi possivel multiplicar" << endl;
		return;
	}

	Matriz C (A.linhas(), B.colunas());

	for (int i = 0; i < C.linhas(); i++) { 
		for (int j = 0; j < C.colunas(); j++) { 
			int valor = 0; 
			for (int k = 0; k < A.colunas(); k++) {
				valor += A.getValor(i, k) * B.getValor(k, j); 
			} 
		C.setValor(valor, i, j); 
		}
	}

	C.print();
}


/**
 * Funcao principal
 */
int main(){

	vector<Matriz*> matrizes; // Vector de ponteiros para matrizes
	
	while(true) {
		string line;
		string comando;
		
		getline(cin, line);
		stringstream ss { line };
		
		ss >> comando;

		if(comando == "exit") {
			for(int i = 0; i < matrizes.size(); ++i) {
				delete matrizes[i];
			}
			return 0;
		}
		// creatematrix [l] [c]
		else if(comando == "creatematrix") {
			int l, c;
			ss >> l;
			ss >> c;
            Matriz *m = new Matriz(l, c);
            for(int i = 0; i < l; ++i) {
                for(int j = 0; j < c; ++j) {
                    int val = 0;
                    cin >> val;
                    cin.ignore();
                    m->setValor(val, i, j);
                }
            }
			matrizes.push_back( m );
		}
		// printmatrix [k]
		else if(comando == "printmatrix") {
			int k;
			ss >> k;
			matrizes[k]->print();
		}
		// nlinhas [k]
		else if(comando == "nlinhas") {
			int k;
			ss >> k;
			cout << "linhas: " << (matrizes[k])->linhas() << endl;
		}
        // ncolunas [k]
		else if(comando == "ncolunas") {
			int k;
			ss >> k;
			cout << "colunas: " << matrizes[k]->colunas() << endl;
		}
        // getvalor [i] [j] [k]
		else if(comando == "getvalor") {
			int i, j, k;
			ss >> i >> j >> k;
			cout << "valor: " << matrizes[k]->getValor(i,j) << endl;
		}
		// sum [p] [q] 
		else if(comando == "sum") {
            int p, q;
			ss >> p >> q;
			soma(*(matrizes[p]), *(matrizes[q]));
		}
        // multiply [p] [q] 
		else if(comando == "multiply") {
            int p, q;
			ss >> p >> q;
			multiplica(*(matrizes[p]), *(matrizes[q]));
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}