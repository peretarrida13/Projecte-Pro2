#include "Cjt_Cluster.hh"


Cjt_Cluster::Cjt_Cluster(){}

void Cjt_Cluster::inicialitza_clustrers(Cjt_Especies& e){
    //Borrem totes les restes dins la taula de distàncies i dins del conjunt de clústers.
    c.clear();
    taula_distancies.buida_taula();
    taula_distancies = e.obtenir_taula();

    //Recorrem el conjunt d'espècies mitjançant el iterador i completem el conjunt de clústers.
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

    //Busquem les dos espècies amb menys distància entre elles i actualitzem la taula de distàncies.
    taula_distancies.distancia_minima(min, m1, m2);
    taula_distancies.actualitza_taula_cluster(m1, m2);

    //Actualitzem el conjunt de clúster amb les espècies amb menys distància entre si.
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
    //Retornem el clúster que pertany al identificador.
    map<string, Cluster>::const_iterator it = c.find(id);
    return it -> second;
}

void Cjt_Cluster::imprime_arbol_filogenetico(){
    //comprovem que el conjunt no estigui buit.
    if(not c.empty()){
        //Exacutem fins el final l'algorisme WPGMA.
        while(c.size() > 1){
            ejecuta_paso_wpgma();
        }      
        //Imprimim el clúster resultant.
        map<string, Cluster>::iterator it = c.begin(); 
        (it -> second).imprimeix_cluster((it -> second));
    }
}

Taula_distancies Cjt_Cluster::obtenir_taula() const{
    //Obtenim la taula de distàncies.
    return taula_distancies;
}

bool Cjt_Cluster::busca_cluster(const string& id){
    //Booleà que ens indica si existix o no el clúster dins del conjunt.
    map<string, Cluster>::const_iterator it = c.find(id);
    if(it != c.end()) return true;
    else return false;
}

int Cjt_Cluster::mida_cjt() const{
    //Retorna la mida del conjunt.
    return c.size();
}