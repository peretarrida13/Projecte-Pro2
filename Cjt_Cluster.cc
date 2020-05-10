#include "Cjt_Cluster.hh"

void Cjt_Cluster::actualitza_taula(const string& id1, const string& id2){
    
    map<string, double> aux;
    string id_res = id1 + id2;
    //Calculem les distancies per anar-les afegint la columna a la taula i anem calculant la nova fila amb la cadena resultant
    for(map<string, map<string, double> >::iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it){
        map<string, double>::const_iterator it1 = (it -> second).find(id1);
        map<string, double>::const_iterator it2 = (it -> second).find(id2);           
        if(it1 != (it -> second).end() and it2 != (it -> second).end()) {  
            double d = it1 -> second;
            double d1 = it2 -> second;
            double res = ((d + d1) / 2);
            it -> second.insert(make_pair(id_res, res));
            aux.insert(make_pair(it ->first, res));
        }
    }
    //Afegim la nova fila a la taula de distàncies
    taula_distancies.insert(make_pair(id_res, aux));
      
    //Eliminem les dos espècies implicades en l'algorisme wpgma 
    //Primer eliminem columna per columna la primera espècie.
    for(map<string, map<string, double> >::iterator iter = taula_distancies.begin(); iter != taula_distancies.end(); ++iter){
        map<string, double>::iterator it = (iter -> second).find(id1);
        (iter -> second).erase(id1);
    }
    //Eliminem la fila corresponent a la primera espècie.
    map<string, map<string, double> >::iterator it2 = taula_distancies.find(id1);
    taula_distancies.erase(it2);
    //Eliminem columna per columna la segona espècie.
    for(map<string, map<string, double> >::iterator iter = taula_distancies.begin(); iter != taula_distancies.end(); ++iter){
        map<string, double>::iterator it3 = (iter -> second).find(id2);
        (iter -> second).erase(id2);
    }
    //Eliminem la fila corresponent a la segona espècie
    map<string, map<string, double> >::iterator it4 = taula_distancies.find(id2);
    taula_distancies.erase(it4);
}

Cjt_Cluster::Cjt_Cluster(){}

void Cjt_Cluster::inicialitza_clustrers(Cjt_Especies& e){
    //Borrem totes les restes dins la taula de distàncies i dins del conjunt de clusters
    taula_distancies.clear();
    c.clear();
    //Igualem la taula de distancies del conjunt d'especies a la del conjunt de clusters ja que el principi és igual
    taula_distancies = e.taula_dist();
    //Anem especie per especie i la convertim en clúster per afegir-la al map
    map<string, Especie> aux = e.cjt();
    for(map<string, Especie>::iterator it = aux.begin(); it != aux.end(); ++it){
        string id = it -> first;
        Cluster cl(id);
        c.insert(make_pair(id, cl));
    }
}

void Cjt_Cluster::ejecuta_paso_wpgma(){
    
    string m1, m2;
    double min = 101;
    //Recorrem la taula per mirar quines son les dos especies amb menys distancies entre si
    for(map<string, map<string, double> >::iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it){
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
    //donat les dos espècies amb menys distància actualitzem la taula i el conjunt de clusters
    actualitza_taula(m1, m2);

    //Actualitzem el conjunt de clúster donats les dos espècies amb menys distància
    string id_res = m1 + m2;
    map<string, Cluster>::iterator it = c.find(m2);
    BinTree<pair<string, double> > dret = it -> second.get_tree();
    c.erase(it);
   
    map<string, Cluster>::iterator iter = c.find(m1);
    BinTree<pair<string, double> > esq = iter -> second.get_tree();
    c.erase(iter);
    
    Cluster aux(make_pair(id_res, double(min / 2)), dret, esq);
    c.insert(make_pair(id_res, aux));
}

Cluster Cjt_Cluster::consultar_cluster(string id){
    //Retornem el cluster donat el identificador
    map<string, Cluster>::iterator it = c.find(id);
    return it -> second;
}

void Cjt_Cluster::imprime_arbol_filogenetico(){
    //comprovem que el conjunt no estigui buit.
    if(not c.empty()){
        //fem el bucle per exacutar el algorisme fins que el conjunt de cluster nomes contingui un cluster, el resultant, i  l'escrivim.
        while(c.size() > 1){
            ejecuta_paso_wpgma();
        }      
        map<string, Cluster>::iterator it = c.begin(); 
        (it -> second).imprimeix_cluster((it -> second).get_tree());
    }
}

void Cjt_Cluster::imprimir_taula_distancias(){
    //Recorrem la taula per imprimir tots els components de la taula
    for(map<string, map<string, double> >::iterator fila = taula_distancies.begin(); fila != taula_distancies.end(); ++fila){
        cout << fila -> first << ":";

        for(map<string, double>::iterator columna = (fila -> second).begin(); columna != (fila -> second).end(); ++columna){
            if(fila -> first < columna -> first) cout << ' ' << columna -> first << " (" << columna -> second << ')';
        } 
        cout << endl;
    }
}

bool Cjt_Cluster::busca_cluster(const string& id){
    //Busquem el cluster dins del conjunt per retornar si existeix o no dins del conjunt
    map<string, Cluster>::iterator it = c.find(id);
    if(it != c.end()) return true;
    else return false;
}

int Cjt_Cluster::mida_cjt(){
    return c.size();
}