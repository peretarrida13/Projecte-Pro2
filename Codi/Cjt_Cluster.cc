#include "Cjt_Cluster.hh"

void Cjt_Cluster::actualitza_taula(const string& id1, const string& id2, bool eliminar){
    //Mirem si em d'eliminar o afegir elements a la taula
    //Eliminar l'especie de les columnes.
    if(eliminar){
        //Eliminar l'especie de les columnes.
        for(map<string, map<string, double> >::iterator iter = taula_distancies.begin(); iter != taula_distancies.end(); ++iter){
            map<string, double>::iterator it = (iter -> second).find(id1);
            (iter -> second).erase(id1);
        }
        //Busquem l'especie dins del conjunt per eliminar-la despres
        map<string, map<string, double> >::iterator it2 = taula_distancies.find(id1);
        taula_distancies.erase(it2);

        for(map<string, map<string, double> >::iterator iter = taula_distancies.begin(); iter != taula_distancies.end(); ++iter){
            map<string, double>::iterator it3 = (iter -> second).find(id2);
            (iter -> second).erase(id2);
        }

        map<string, map<string, double> >::iterator it4 = taula_distancies.find(id2);
        taula_distancies.erase(it4);

        
    }else{
        map<string, double> aux;
        string id_res = id1 + id2;
        for(map<string, map<string, double> >::iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it){
            map<string, double>::iterator it1 = (it -> second).find(id1);
            map<string, double>::iterator it2 = (it -> second).find(id2);
            double dist1 = it1 -> second;
            double dist2 = it2 -> second;
            double res = ((dist1 + dist2) / 2);
            aux.insert(make_pair(it -> first, res));
            (it->second).insert(make_pair(id_res, res));
        }
        taula_distancies.insert(make_pair(id_res, aux));
    }
}

Cjt_Cluster::Cjt_Cluster(){}

void Cjt_Cluster::inicialitza_clustrers(Cjt_Especies& e){
    taula_distancies.clear();
    c.clear();
    taula_distancies = e.taula_dist();
    map<string, Especie> aux = e.cjt();
    for(map<string, Especie>::iterator it = aux.begin(); it != aux.end(); ++it){
        string id = it -> first;
        Cluster cl(id);
        c.insert(make_pair(id, cl));
    }

}

void Cjt_Cluster::ejecuta_paso_wpgma(){
    //ACTUALITZAR LA TAULA DE DISTANCIES
    string m1, m2;
    double min = 101;
    for(map<string, map<string, double> >::iterator it = taula_distancies.begin(); it != taula_distancies.end(); ++it){
        for(map<string, double>::iterator it1 = (it -> second).begin(); it1 != (it -> second).end(); ++it1){
            if(it -> first != it1 ->first){
                if(min >= it1 -> second){
                    min = it1 -> second;
                    m1 = it -> first;
                    m2 = it1 -> first;
                }
            }
        }
    }
    actualitza_taula(m2, m1, false);
    actualitza_taula(m1, m2, true);
    
    //ACTUALITZAR EL CONJUNT DE CLUSTERS AMB EL NOU CLUSTER FUSIONAT
    //Eliminem el primer cluster
    string id_res = m2 + m1;
    map<string, Cluster>::iterator it = c.find(m1);
    BinTree<pair<string, double> > dret = it -> second.get_tree();
    c.erase(it);
    //Eliminem el segon cluster
    map<string, Cluster>::iterator iter = c.find(m2);
    BinTree<pair<string, double> > esq = iter -> second.get_tree();
    c.erase(iter);

    //Crear nou cluster amb la unio de les dos strings i la meitat de la distancia
    Cluster aux(make_pair(id_res, double(min / 2)), dret, esq);
    c.insert(make_pair(id_res, aux));
   
}

Cluster Cjt_Cluster::consultar_cluster(string id){
    map<string, Cluster>::iterator it = c.find(id);
    return it -> second;
}

void Cjt_Cluster::imprime_arbol_filogenetico(){
 //EXACUTA EL L'ALGORITME FINS QUE C <= 1
    if(c.size() > 1){

        while(c.size() > 1){
            ejecuta_paso_wpgma();
        }    

        map<string, Cluster>::iterator it = c.begin(); 
        BinTree<pair<string, double> > aux = (it -> second).get_tree();
        (it -> second).imprimeix_cluster(aux);
    }
    else{
        map<string, Cluster>::iterator it = c.begin(); 
        BinTree<pair<string, double> > aux = (it -> second).get_tree();
        (it -> second).imprimeix_cluster(aux);
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
    map<string, Cluster>::iterator it = c.find(id);
    if(it != c.end()) return true;
    else return false;
}

int Cjt_Cluster::mida_cjt(){
    return c.size();
}