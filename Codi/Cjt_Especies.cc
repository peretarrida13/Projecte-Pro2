#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies(){
    //Constructora per defecte
}

Cjt_Especies::~Cjt_Especies(){
    //Destructora per defecte
}

void Cjt_Especies::crea_especie(string& id, string& gen, int& k){
    Especie e(gen, k);
    //Donats el gen i la k introduit per l'usari creem una especie per insertar-la juntament amb l'identificador dins del map
    especies.insert(make_pair(id, e));
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        double dist = Especie::distancia(it -> second, e);
        taula_dist.afageix_especie(id, it -> first, dist);
    }
}

Especie Cjt_Especies::consultar_especie(string id) const{
    //Busquem dins del conjunt l'identificador per retornar l'especie.
    map<string, Especie>::const_iterator it = especies.find(id);
    return it -> second;
}


void Cjt_Especies::eliminar_especie(string& id){
    //Busquem l'especie dins del map per eliminar-la.
    map<string, Especie>::iterator it = especies.find(id);
    if(it != especies.end()){
        //Guardem l'especie i actualitzem la taula de distancies per eliminar la fila i la columna corresponent a l'especie eliminada
        Especie e = it -> second;
        especies.erase(it);
        taula_dist.elimina_especie(id);
    }
}


bool Cjt_Especies::existe_especie(string& id){
    //Busquem l'especie amb dit identificador per dir si l'especie esta dins del conjunt o no.
    map<string, Especie>::iterator it = especies.find(id);
    
    if(it != especies.end()) return true;
    else return false; //
}

void Cjt_Especies::lee_cjt_especies(int k){
    //Buidem el conjunt d'especies i la taula de distancies per poder-les rescriure.
    especies.clear();
    taula_dist.buida_taula();
    string id, gen; 
    int n; 
    //Llegim el valor de n per saber quantes especies em de llegir.
    cin >> n;
    //Llegim el identificador i el gen per crear una especie i afeegir-la al map.
    for(int i = 0; i < n; ++i){
        cin >> id >> gen;
        Especie e(gen, k);
        especies.insert(make_pair(id, e));
        for(map<string, Especie>::iterator it1 = especies.begin(); it1 != especies.end(); ++it1){
            double dist = Especie::distancia(e, it1 -> second);
            taula_dist.afageix_especie(id, it1 -> first, dist);
        }
    }
}

bool Cjt_Especies::esta_buit(){
    return especies.empty();
}

void Cjt_Especies::imprime_cjt_especies() const{
    //Recorrem el conjunt per imprimir el conjunt d'epecies
    for(map<string, Especie>::const_iterator it = especies.begin(); it != especies.end(); ++it){
        Especie e = it -> second;

        cout << it -> first << ' ' << e.obtener_gen() << endl;
    }
}

void Cjt_Especies::inici(){
    it_esp = especies.begin();
}

bool Cjt_Especies::final(){
    if(it_esp == especies.end()) return true;
    else return false;
}

void Cjt_Especies::incrementar(){
    if(it_esp != especies.end()) ++it_esp;
}

string Cjt_Especies::obtenir_primer(){
    return it_esp -> first;
}

Especie Cjt_Especies::obtenir_segon(){
    return it_esp -> second;
}

void Cjt_Especies::imprimir_taula_distancies() const{
    taula_dist.imprimir_taula_distancies();
}

Taula_distancies Cjt_Especies::obtenir_taula(){
    return taula_dist;
}