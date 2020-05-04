#include "Especie.hh"
using namespace std;

Especie::Especie(){
    //INICIALITZEM L'ESPECIE I LI POSEM EL GEN = "0"
    gen = "0";
}

Especie::Especie(string& g, int& k){
    //INICIALITZEM LA ESPECIE AMB EL GEN DONAT I A PARTIR D'AQUEST I LA K TROBEM EL KMER D'AQUELLA ESPECIE
    gen = g; 
    map<string, int> res;
    for(int i = 0; i < g.length() - k + 1; ++i){
        //RECORREM ELS CARACTERS DEL GEN FINS QUE PUGUEM AGAFAR EL ULTIM KMER
        string s1;
        for(int j = 0; j < k; ++j){
            //AGAFEM ELSE K CARACTERS I ELS GUARDEM A LA STRING
            s1.push_back(g[i + j]);
        }
        map<string, int> ::iterator it = res.find(s1); //BUSQUEM QUE LA STRING NO ESTIGUI JA EN EL MAP
        if(it == res.end()){ //EN CAS QUE NO ESXISTEIXI L'AFEGIM EN EL MAP
            res.emplace(s1, 1);
        }
        else{
            //EN CAS DE QUE EXISTEIXI LI SUMEM 1 A LA SEGONA COMPONENT
            it -> second = it -> second + 1;
        }        
    }
    //FINALMENT TRASPASSEM EL MAP AL KMER
    kmer = res;
}

Especie::~Especie(){
    //DESPTRUCTORA
}

map<string, int> Especie::obtener_kmer() const{
    //RETORNA EL KMER DE L'ESPECIE
    return kmer;
}

string Especie::obtener_gen() const{
    //RETORNA EL GEN DE L'ESPECIE
    return gen;
}
