#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void limpa_palavras(string p, map<string, int> &palavras){

    int i;
    string aux = "";
    bool flag = false;

    for(i = 0; i < p.size(); i++){
        if(p[i] >= 'a' && p[i] <= 'z') {
            flag = true;
            aux += p[i];
        } else if(p[i] >= 'A' && p[i] <= 'Z'){
            flag = true;
            aux += p[i] + 32;
        } else if(flag == true){
            palavras[aux] = 1;
            aux = "";
            flag = false;
        }
    }
    if(aux != ""){
        palavras[aux] = 1;
    }
}

int main(){

    map<string, int> dicionario;
    string aux;
    vector<string> linhas;

    // Leitura arquivo

    while(!cin.eof()) {
        cin >> aux;
        linhas.push_back(aux);
    }

    // Limpa palavras e taca no dicionario

    for(auto v: linhas){
        limpa_palavras(v, dicionario);
    }

    linhas.clear();

    // Imprime na tela

    for(auto v: dicionario){
        cout << v.first << endl;
    }

    return 0;
}
