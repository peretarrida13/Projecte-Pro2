#include "Cjt_Especies.hh"
using namespace std;

Cjt_Especies::Cjt_Especies(){
    //Constructora per defecte
}

Cjt_Especies::~Cjt_Especies(){
    //Destructora per defecte
}

void Cjt_Especies::actualitza_dist(const Especie& e, const string& id, bool eliminar){
    //Mirem si em d'eliminar o afegir elements a la taula
    if(eliminar){
        //Eliminar l'especie de les columnes.
        for(map<string, map<string, double> >::iterator it1 = dist.begin(); it1 != dist.end(); ++it1){
            map<string, double>::iterator iter = (it1 -> second).find(id);
            it1 -> second.erase(iter);
        }
        //Busquem l'especie dins del conjunt per eliminar-la despres
        map<string, map<string, double> >::iterator it = dist.find(id);
        dist.erase(it); 
        
    }else{
        //Creem un map aiuxiliar que sera equivalent a la nova fila afegida amb la nova especie.
        map<string, double> aux; 
        
        for(map<string, Especie>::iterator it1 = especies.begin(); it1 != especies.end(); ++it1){
            aux.insert(make_pair(it1 -> first, Especie::distancia(it1 -> second, e)));
        }
        dist.insert(make_pair(id, aux)); 
        
        //Calculem la distancia entre la nova especie i la resta i l'afegim a com una nova columna.
        map<string, map<string, double> >::iterator tau = dist.begin();

        for(map<string, Especie>::iterator it1 = especies.begin(); it1 != especies.end(); ++it1){
            (tau -> second).insert(make_pair(id, Especie::distancia(it1 -> second, e)));
            ++tau;
        }
    }
}

void Cjt_Especies::crea_especie(string& id, string& gen, int& k){
    //Donats el gen i la k introduit per l'usari creem una especie per insertar-la juntament amb l'identificador dins del map.
    Especie e(gen, k);
    especies.insert(make_pair(id, e));
    
    //Hem d'actualitzar la taula de distancies per afegir la nova especie.
    actualitza_dist(e, id, false);
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
               
        actualitza_dist(e, id, true);
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
    dist.clear();
    
    string id, gen; 
    int n; 
    //Llegim el valor de n per saber quantes especies em de llegir.
    cin >> n;
    //Llegim el identificador i el gen per crear una especie i afeegir-la al map.
    for(int i = 0; i < n; ++i){
        cin >> id >> gen;
        Especie e(gen, k);
        
        especies.insert(make_pair(id, e));
    } 

    //Recorrem el map d'especies per omplir la taula de distancies amb les corresponents distancies entre especies.
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        map<string,double> aux;
        for(map<string, Especie>::iterator it2 = especies.begin(); it2 != especies.end(); ++it2){            
            aux.insert(make_pair(it2 -> first, Especie::distancia(it -> second, it2 -> second)));
        }
        dist.insert(make_pair(it -> first, aux));
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

void Cjt_Especies::imprimir_tabla_distancias() const{
    //Recorrem la taula per imprimir tots els components de la taula
    for(map<string, map<string, double> >::const_iterator fila = dist.begin(); fila != dist.end(); ++fila){
        cout << fila -> first << ":";

        for(map<string, double>::const_iterator columna = (fila -> second).begin(); columna != (fila -> second).end(); ++columna){
            if(fila -> first < columna -> first) cout << ' ' << columna -> first << " (" << columna -> second << ')';
        } 
        cout << endl;
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

map<string, map<string, double> > Cjt_Especies::taula(){
    return dist;
}