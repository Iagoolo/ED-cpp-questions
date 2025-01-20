// NAO MEXA NESTE ARQUIVO, ELE JA ESTA PRONTO PARA SER USADO PELO MOODLE
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "ForwardList.h"
using namespace std;

int main() 
{
	vector<ForwardList> listas; // um vector de listas
	
	while(true) {
		string comando, token;
		getline(cin, comando);
		stringstream ss{ comando };
        ss >> token;

        cout << "$" << ss.str() << endl;

		// exit
		if(token == "exit") {
			listas.clear();
			break;
		}
		// create
		else if(token == "create") {
			listas.push_back(ForwardList());
		}
		// size l
		else if(token == "size") {
			int l;
            ss >> l;
			cout << "size list " << l << ": " << listas[l].size() << std::endl;
		}
        // addFront l a1 ... an 
		else if(token == "addFront") {
			int l;
            ss >> l;
            int value;
            while(ss >> value) {
                listas[l].push_front(value);
            }
		}
		// insertafter l k v
		else if(token == "insertafter") {
			int l;
            ss >> l;
			int k;
            ss >> k;
			int v;
			ss >> v;
			for(auto it = listas[l].begin(); it != listas[l].end(); ++it) {
				if(*it == k) {
            		listas[l].insert_after(it, v);
					break;
				}
			}	
		}
		// eraseafter l k
		else if(token == "eraseafter") {
			int l;
            ss >> l;
			int k;
            ss >> k;
			int v;
			ss >> v;
			for(auto it = listas[l].begin(); it != listas[l].end(); ++it) {
				if(*it == k) {
            		listas[l].erase_after(it);
					break;
				}
			}	
		}
        // show 
		else if(token == "show") {
            for(unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": " << listas[i] << endl;
            }	
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}