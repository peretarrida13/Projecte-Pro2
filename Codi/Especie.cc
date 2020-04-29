#include "Especie.hh"
using namespace std;

Especie::Especie(){
    gen = "0";
}

Especie::Especie(string& g, int& k){
    gen = g; 
    vector<string> res;
    for(int i = 0; i < g.length() - k + 1; ++i){
        string s1;
        for(int j = 0; j < k; ++j){
            s1.push_back(g[i + j]);
        }
        res.push_back(s1);        
    }
    sort(res.begin(), res.end());
    kmer = res;
}

Especie::~Especie(){}

vector<string> Especie::obtener_kmer() const{
    return kmer;
}

string Especie::obtener_gen() const{
    return gen;
}
