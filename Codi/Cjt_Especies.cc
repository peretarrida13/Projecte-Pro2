#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies(){
    //CONSTRUCTORA QUE CREA UN MAP BUIT;
}

Cjt_Especies::~Cjt_Especies(){
    //DESTRUCTORA
}

void Cjt_Especies::crea_especie(string& id, string& gen, int& k){
    //CREEM LA ESPECIE DONATS ELS PARAMETRES
    Especie e(gen, k);
    //INSERTEM LA ESPECIE EN EL CONJUNT
    especies.insert(make_pair(id, e));
}

Especie Cjt_Especies::consultar_especie(string id){
    //BUSQUEM EL IDENTIFICADOR DINS DEL MAP
    map<string, Especie>::iterator it = especies.find(id);
    //RETORNA LA SEGONA COMPONENT DEL MAP --> L'ESPECIE
    return it -> second;
}

double Cjt_Especies::distancia(const Especie& a, const Especie& b){
    //DECLARACIO DE #UNIO I #INTERSECCIO
    int in = 0;
    int un = 0;
    //DOS MAPS QUE EMMAGATZEMEN ELS KMERS DE L'ESPECIE A I B.
    map<string, int> p = b.obtener_kmer();
    map<string, int> s = a.obtener_kmer();

    //RECORREM COPIEM P I BORREM ELS QUE ES COMPARTEIXIN CONJUNTS AMB S
    for(map<string, int>::iterator it = s.begin(); it != s.end(); ++it){
        map<string, int>::iterator it2 = p.find(it->first);
        if(it2 != p.end()){
            if(it->second >= it2->second){
                un += it->second;
                in += it2->second;
            }
            else{
                un += it2->second;
                in += it->second;
            }
            p.erase(it2->first);
        }
        //SI L'ELEMENT DE S NO ESTA DINS DE P SUMEM NOMES A LA UNIO 
        else un += it->second;
    }
    
    for(map<string, int>::iterator it = p.begin(); it != p.end(); ++it) un += it->second;
    //PER ULTIM APLIQUEM LA FORMULA
    double res = (1.0-(double(in)/double(un)))*100.0;
    return res;
}

void Cjt_Especies::eliminar_especie(string& id){
    //PRIMER MIREM SI LA ESPECIA EXISTEIX
    if(existe_especie(id)){
        //EN CAS QUE EXISTEIXI BORREM LA ESPECIE AMB L'IDENTIFICADOR DONAT
        especies.erase(id);
    }
}


bool Cjt_Especies::existe_especie(string& id){
    //BUSQUEM DINS DEL MAP L'ESPECIE I ASSIGNEM EL ITERADOR
    map<string, Especie>::iterator it = especies.find(id);
    //DI L'ITERADOR ES DIFERENT AL FINAL DEL MAP
    if(it != especies.end()){
        //RETORNEM TRUE
        return true;
    }
    //ALTRAMENT RETORNEM FALSE
    else return false;
}

void Cjt_Especies::lee_cjt_especies(int k){
    //BORREM QUALSEVOL ELEMENT DEL CONJUNT PER SI DE CAS EL CONJUNT ESTA B
    especies.clear();
    //CREEM LES VARRIABLES NECESSARIES
    string id, gen; 
    int n; 
    //NUMERO D'ESPECIES DEL CONJUNT
    cin >> n;
     
    for(int i = 0; i < n; ++i){
        //LLEGIM L'IDENTIFICADOR I EL GEN
        cin >> id >> gen;
        //CREEM L'ESPECIE
        Especie e(gen, k);
        //INSERTEM L'IDENTIFICADOR I L'ESPECIE DINS DEL CONJUNT
        especies.insert(make_pair(id, e));
    } 

    map<string, map<string, double> >::iterator taula = dist.begin();
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        string id = it -> first;
        for(map<string, Especie>::iterator it2 = especies.begin(); it2 != especies.end(); ++it2){
            double d = distancia(it -> second, it2 -> second);
            dist.emplace(id, taula -> second.emplace( (it2 -> first), d));
        }
        ++taula;
    }
}

bool Cjt_Especies::esta_buit(){
    //RETORNA SI EL CONJUNT ESTA BUIT O NO
    return especies.empty();
}

void Cjt_Especies::imprime_cjt_especies(){
    //RECORRE EL CONJUNT I IMPRIMEIX EL IDENTIFICADOR I EL GEN DE TOTES LES ESPECIES DEL CONJUNT
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        Especie e = it -> second;
        cout << it -> first << ' ' << e.obtener_gen() << endl;
    }
}

void Cjt_Especies::imprimir_tabla_distancias(){
    //RECORRE EL MAP
    for(map<string, map<string, double> >::iterator fila = dist.begin(); fila != dist.end(); ++fila){
        cout << fila -> first << ":";
        for(map<string, double>::iterator columna = (fila -> second).begin(); columna != (fila -> second).end(); ++columna){
            cout << ' ' << columna -> first << " (" << columna -> second << ')';
        } 
        cout << endl;
    }
}