#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies(){
    //Constructora per defecte.
}

Cjt_Especies::~Cjt_Especies(){
    //Destructora per defecte.
}

void Cjt_Especies::crea_especie(string& id, string& gen, int& k){
    //Donats gen i la k creem una especie per afegir-la al map juntament amb l'identificador.    
    Especie e(gen, k);
    especies.insert(make_pair(id, e));

    //Recorrem el conjunt per calcular la distància i afergir l'espècie a la taula de distàncies.
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        double dist = Especie::distancia(it -> second, e);
        taula_dist.afageix_especie(id, it -> first, dist);
    }
}

Especie Cjt_Especies::consultar_especie(string id) const{
    //Busquem l'identificador dins del conjunt per retornar l'espècie.
    map<string, Especie>::const_iterator it = especies.find(id);
    return it -> second;
}


void Cjt_Especies::eliminar_especie(string& id){
    //Busquem l'espècie dins del map per eliminar-la.
    map<string, Especie>::iterator it = especies.find(id);
    if(it != especies.end()){
        //Eliminem l'especie i actualitzem la taula de distàncies.
        especies.erase(it);
        taula_dist.elimina_especie(id);
    }
}


bool Cjt_Especies::existe_especie(string& id){
    //Busquem l'espècie dins del conjunt per retornar si l'especie existeix o no.
    map<string, Especie>::iterator it = especies.find(id);
    
    if(it != especies.end()) return true;
    else return false; //
}

void Cjt_Especies::lee_cjt_especies(int k){
    //Buidem el conjunt d'espècies i la taula de distàncies per poder-les reescriure.
    especies.clear();
    taula_dist.buida_taula();

    string id, gen; 
    int n; 
    //Llegim el valor de n per saber quantes especies em de llegir.
    cin >> n;
    
    for(int i = 0; i < n; ++i){
        //Llegim el identificador i el gen per crear una especie i afeegir-la al map.
        cin >> id >> gen;
        Especie e(gen, k);
        especies.insert(make_pair(id, e));
        //A mesura que afegim les espècies dins del map anem creant la taula de distàncies.
        for(map<string, Especie>::iterator it1 = especies.begin(); it1 != especies.end(); ++it1){
            double dist = Especie::distancia(e, it1 -> second);
            taula_dist.afageix_especie(id, it1 -> first, dist);
        }
    }
}

bool Cjt_Especies::esta_buit(){
    //Retorna un boolea per veure si el conjunt està buit o no.
    return especies.empty();
}

void Cjt_Especies::imprime_cjt_especies() const{
    //Recorrem el map per imprimir les espècies.
    for(map<string, Especie>::const_iterator it = especies.begin(); it != especies.end(); ++it){
        Especie e = it -> second;
        cout << it -> first << ' ' << e.obtener_gen() << endl;
    }
}

void Cjt_Especies::inici(){
    //L'iterador torna a apuntar al inici.
    it_esp = especies.begin();
}

bool Cjt_Especies::final(){
    //Mirem si em acabat de recorre el map o no.
    if(it_esp == especies.end()) return true;
    else return false;
}

void Cjt_Especies::incrementar(){
    //Incrementa el valor de l'iterador per apuntar el segon element.
    if(it_esp != especies.end()) ++it_esp;
}

string Cjt_Especies::obtenir_primer(){
    //Retorna el primer element al qual apunta el iterador.
    return it_esp -> first;
}

Especie Cjt_Especies::obtenir_segon(){
    //Retorna el segon element al qual apunta el iterador.
    return it_esp -> second;
}


Taula_distancies Cjt_Especies::obtenir_taula(){
    //Retorna la taula de distàncies del conjunt.
    return taula_dist;
}