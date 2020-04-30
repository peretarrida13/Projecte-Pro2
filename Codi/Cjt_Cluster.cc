#include "Cjt_Cluster.hh"

void Cjt_Cluster::inicialitza_clustrers(Cjt_Especies& e){
    for(map<string, Especie>::iterator it = especies.begin(); it != especies.end(); ++it){
        string id = it -> first;
        Cluster clust(id);
        c.insert(make_pair(id, clust));
    }
}

void Cjt_Cluster::ejecuta_paso_wpgma(){
    
}

Cluster Cjt_Cluster::consultar_cluster(string id) const{

}

void Cjt_Cluster::imprime_arbol_filogenetio(){

}
