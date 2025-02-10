#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char vencedor(queue<char>& times, vector<int>& resultados){
    
   while(times.size() != 1){

    char time1 = times.front();
    times.pop();
    char time2 = times.front();
    times.pop();

    int gols1 = resultados.front();
    resultados.erase(resultados.begin());
    int gols2 = resultados.front();
    resultados.erase(resultados.begin());

    if (gols1 > gols2){
        times.push(time1);
    }
    else if (gols2 > gols1){
        times.push(time2);
    }
   }

    return times.front();
}

void adicionar(queue<char>& times){

    for (int i = 'A'; i <= 'P'; i++){
        times.push(i);
    }
}

int main(){

    queue<char> times;
    adicionar(times);

    vector<int> resultados(30);
    for (int i = 0; i < 30; i++){
        cin >> resultados[i];
    }

    cout << vencedor(times, resultados) << endl;

    return 0;
}