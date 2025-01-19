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
        // createWith l
		else if(token == "createWith") {
			int l;
            ss >> l;
			listas.push_back(ForwardList(listas[l]));
		}
		// pushback x l
		else if(token == "pushback") {
			int x, l;
            ss >> x >> l;
			listas[l].push_back(x);
		}
        // pushfront x l
		else if(token == "pushfront") {
			int x, l;
            ss >> x >> l;
			listas[l].push_front(x);
		}
        // popfront l
		else if(token == "popfront") {
			int l;
            ss >> l;
			listas[l].pop_front();
		}
        // popback l
		else if(token == "popback") {
			int l;
            ss >> l;
			listas[l].pop_back();
		}
        // front l
		else if(token == "front") {
			int l;
            ss >> l;
			cout << "front: " << listas[l].front() << endl;
		}
        // back l
		else if(token == "back") {
			int l;
            ss >> l;
            cout << "back: " << listas[l].back() << endl;
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