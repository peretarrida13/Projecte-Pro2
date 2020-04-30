#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies(){}

void Cjt_Especies::crea_especie(string& id, string& gen, int& k){
    Especie e(gen, k);
    especies.insert(make_pair(id, e));
}

Especie Cjt_Especies::consultar_especie(string id){
    map<string, Especie>::iterator it = especies.find(id);
    return it -> second;
}

double Cjt_Especies::distancia(const Especie& a, const Especie& b){
    vector<string> primer = a.obtener_kmer(); 
    vector<string> segon = b.obtener_kmer();

    //calcul del vector unio; 
    vector<string> unio;
    for(int i = 0; i < primer.size(); ++i) unio.push_back(primer[0]); 
    for(int i = 0; i < segon.size(); ++i) unio.push_back(segon[0]);
    double res1 = unio.size();

    //calcul del vector interseccio
    vector<string> interseccio;
    for(int i = 0; i < primer.size(); ++i){
        for(int j = 0; j < segon.size(); ++j){
            if(primer[i] == segon[j]){
                interseccio.push_back(primer[i]);
            }
        }
    }
    double res2 = interseccio.size();

    //calcul final de la distància
    double res = (1- (res1/res2)) * 100;
    return res;
}

void Cjt_Especies::eliminar_especie(string& id){
    if(existe_especie(id)){
        especies.erase(id);
    }
}


bool Cjt_Especies::existe_especie(string& id){
    map<string, Especie>::iterator it = especies.find(id);
    if(it != especies.end()){
        return true;
    }
    else return false;
}

void Cjt_Especies::lee_cjt_especies(int k){
    string id, gen; 
    while(cin >> id >> gen){
        Especie e(gen, k);
        especies.insert(make_pair(id, e));
    }
}

bool Cjt_Especies::esta_buit(){
    return especies.empty();
}

void Cjt_Especies::imprime_cjt_especies(){
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        Especie e = it -> second;
        cout << it -> first << ' ' << e.obtener_gen() << endl;
    }
}

void Cjt_Especies::imprimir_tabla_distancias()const{

}
