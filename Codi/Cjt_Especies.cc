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
            double d = distancia(it1 -> second, e);
            aux.insert(make_pair(it1 -> first, d));
        }
        dist.insert(make_pair(id, aux)); 
        
        //Calculem la distancia entre la nova especie i la resta i l'afegim a com una nova columna.
        map<string, map<string, double> >::iterator tau = dist.begin();

        for(map<string, Especie>::iterator it1 = especies.begin(); it1 != especies.end(); ++it1){
            double d = distancia(it1 -> second, e);
            (tau -> second).insert(make_pair(id,d));
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

Especie Cjt_Especies::consultar_especie(string id){
    //Busquem dins del conjunt l'identificador per retornar l'especie.
    map<string, Especie>::iterator it = especies.find(id);
    return it -> second;
}

double Cjt_Especies::distancia(const Especie& a, const Especie& b){
    int in = 0;
    int un = 0;
    //inicialitzem els kmers en dos maps per tal de calcular la distancia
    map<string, int> p = b.obtener_kmer();
    map<string, int> s = a.obtener_kmer();

    //Copiem p i borrem els kmers que comparteix amb s durant el recorregut
    for(map<string, int>::iterator it = s.begin(); it != s.end(); ++it){
        map<string, int>::iterator it2 = p.find(it->first);
        if(it2 != p.end()){
            if(it->second >= it2->second){
                un += it->second;
                in += it2->second;
            } else{
                un += it2->second;
                in += it->second;
            }
            p.erase(it2->first);
        } else un += it->second; //Si el kmer de s no es troba en p només sumem a unió 
    }
    
    for(map<string, int>::iterator it = p.begin(); it != p.end(); ++it) un += it->second;

    double res = (1.0-(double(in)/double(un)))*100.0;
    return res;
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
        string id = it -> first;
        map<string,double> aux;
        for(map<string, Especie>::iterator it2 = especies.begin(); it2 != especies.end(); ++it2){
            double d = distancia(it -> second, it2 -> second);
            
            aux.insert(make_pair(it2 -> first, d));
        }
        dist.insert(make_pair(id,aux));
    }
}

bool Cjt_Especies::esta_buit(){
    return especies.empty();
}

void Cjt_Especies::imprime_cjt_especies(){
    //Recorrem el conjunt per imprimir el conjunt d'epecies
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        Especie e = it -> second;

        cout << it -> first << ' ' << e.obtener_gen() << endl;
    }
}

void Cjt_Especies::imprimir_tabla_distancias(){
    //Recorrem la taula per imprimir tots els components de la taula
    for(map<string, map<string, double> >::iterator fila = dist.begin(); fila != dist.end(); ++fila){
        cout << fila -> first << ":";

        for(map<string, double>::iterator columna = (fila -> second).begin(); columna != (fila -> second).end(); ++columna){
            if(fila -> first < columna -> first) cout << ' ' << columna -> first << " (" << columna -> second << ')';
        } 

        cout << endl;
    }
}

map<string, map<string, double> > Cjt_Especies::taula_dist(){
    return dist;
}

map<string, Especie> Cjt_Especies::cjt(){
    return especies;
}

