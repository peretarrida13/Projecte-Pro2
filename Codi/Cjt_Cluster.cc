#include "Cjt_Cluster.hh"


Cjt_Cluster::Cjt_Cluster(){}

void Cjt_Cluster::inicialitza_clustrers(Cjt_Especies& e){
    //Borrem totes les restes dins la taula de distàncies i dins del conjunt de clusters
    c.clear();
    taula_distancies.buida_taula();
    taula_distancies = e.obtenir_taula();
    //Anem especie per especie i la convertim en clúster per afegir-la al map
    e.inici();
    while(not e.final()){
        string id = e.obtenir_primer();
        Cluster cl(id);
        c.insert(make_pair(id, cl));
        e.incrementar();
    }
}

void Cjt_Cluster::ejecuta_paso_wpgma(){
    string m1, m2;
    double min = 101;
    //Recorrem la taula per mirar quines son les dos especies amb menys distancies entre si
    taula_distancies.distancia_minima(min, m1, m2);
    //donat les dos espècies amb menys distància actualitzem la taula i el conjunt de clusters
    taula_distancies.actualitza_taula_cluster(m1, m2);
    //Actualitzem el conjunt de clúster donats les dos espècies amb menys distància
    string res = m1 + m2;
    map<string, Cluster>::iterator it = c.find(m1);
    Cluster esq = it -> second;
    c.erase(it);
    map<string, Cluster>::iterator it1 = c.find(m2);
    Cluster dret = it1 -> second;
    c.erase(it1);

    Cluster aux(make_pair(res, double(min / 2)), dret, esq);
    c.insert(make_pair(res, aux));
}

Cluster Cjt_Cluster::consultar_cluster(string id) const{
    //Retornem el cluster donat el identificador
    map<string, Cluster>::const_iterator it = c.find(id);
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
        (it -> second).imprimeix_cluster((it -> second));
    }
}

Taula_distancies Cjt_Cluster::obtenir_taula() const{
    //Recorrem la taula per imprimir tots els components de la taula
    return taula_distancies;
}

bool Cjt_Cluster::busca_cluster(const string& id){
    //Busquem el cluster dins del conjunt per retornar si existeix o no dins del conjunt
    map<string, Cluster>::const_iterator it = c.find(id);
    if(it != c.end()) return true;
    else return false;
}

int Cjt_Cluster::mida_cjt() const{
    return c.size();
}