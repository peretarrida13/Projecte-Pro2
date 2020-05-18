#include "Taula_distancies.hh"


Taula_distancies::Taula_distancies(){}

Taula_distancies::~Taula_distancies(){}

void Taula_distancies::elimina_especie(const string& id){
    for(map<string, map<string, double> >::iterator it1 = taula_dist.begin(); it1 != taula_dist.end(); ++it1){
        map<string, double>::iterator iter = (it1 -> second).find(id);
        it1 -> second.erase(iter);
    }
    //Busquem l'especie dins del conjunt per eliminar-la despres
    map<string, map<string, double> >::iterator it = taula_dist.find(id);
    taula_dist.erase(it); 
}

void Taula_distancies::afageix_especie(const string& id1, const string& id2, const double& d){
    map<string, map<string, double> >::iterator it = taula_dist.find(id1);
    if(it != taula_dist.end()) it -> second.insert(make_pair(id2, d));
    else{
        map<string, double> aux;
        aux.insert(make_pair(id2, d));
        taula_dist.insert(make_pair(id1, aux));
    }
    map<string, map<string, double> >::iterator it1 = taula_dist.find(id2);
    if(it1 != taula_dist.end()) it1 -> second.insert(make_pair(id1, d));
}


void Taula_distancies::imprimir_taula_distancies() const{
    for(map<string, map<string, double> >::const_iterator fila = taula_dist.begin(); fila != taula_dist.end(); ++fila){
        cout << fila -> first << ":";
        for(map<string, double>::const_iterator columna = (fila -> second).begin(); columna != (fila -> second).end(); ++columna){
            if(fila -> first < columna -> first) cout << ' ' << columna -> first << " (" << columna -> second << ')';
        } 
        cout << endl;
    }
}

void Taula_distancies::distancia_minima(double& min, string& m1, string& m2){
    for(map<string, map<string, double> >::iterator it = taula_dist.begin(); it != taula_dist.end(); ++it){
        for(map<string, double>::iterator it1 = (it -> second).begin(); it1 != (it -> second).end(); ++it1){
            if(it -> first != it1 ->first){
                if(min > it1 -> second){
                    min = it1 -> second;
                    m1 = it -> first;
                    m2 = it1 -> first;
                }
            }
        }
    }
}

void Taula_distancies::actualitza_taula_cluster(const string& id1, const string& id2){
    map<string, double> aux;
    string id_res = id1 + id2;
    //Calculem les distancies per anar-les afegint la columna a la taula i anem calculant la nova fila amb la cadena resultant
    for(map<string, map<string, double> >::iterator it = taula_dist.begin(); it != taula_dist.end(); ++it){
        map<string, double>::iterator it1 = (it -> second).find(id1);
        map<string, double>::iterator it2 = (it -> second).find(id2);           
        if(it1 != (it -> second).end() and it2 != (it -> second).end()) {  
            double res = ((it1 -> second + it2 -> second) / 2);
            it -> second.insert(make_pair(id_res, res));
            aux.insert(make_pair(it ->first, res));
        }
    }
    //Afegim la nova fila a la taula de distàncies
    taula_dist.insert(make_pair(id_res, aux));

    //Eliminem les dos espècies implicades en l'algorisme wpgma 
    //Primer eliminem columna per columna la primera espècie.
    for(map<string, map<string, double> >::iterator iter = taula_dist.begin(); iter != taula_dist.end(); ++iter){
        map<string, double>::iterator it = (iter -> second).find(id1);
        if(it != iter -> second.end())(iter -> second).erase(id1);
    }
    //Eliminem la fila corresponent a la primera espècie.
    map<string, map<string, double> >::iterator it2 = taula_dist.find(id1);
    if(it2 != taula_dist.end())taula_dist.erase(it2);
    //Eliminem columna per columna la segona espècie.
    for(map<string, map<string, double> >::iterator iter = taula_dist.begin(); iter != taula_dist.end(); ++iter){
        map<string, double>::iterator it3 = (iter -> second).find(id2);
        if(it3 != iter -> second.end())(iter -> second).erase(id2);
    }
    //Eliminem la fila corresponent a la segona espècie
    map<string, map<string, double> >::iterator it4 = taula_dist.find(id2);
    if(it4 != taula_dist.end()) taula_dist.erase(it4);
}

void Taula_distancies::buida_taula(){
    taula_dist.clear();
}