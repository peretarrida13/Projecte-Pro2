#include "Cluster.hh"
using namespace std;

Cluster::Cluster(){}

Cluster::Cluster(string& e){
    //Constructora que ens serveix per crear un clúster només amb el identificador i sense distància. 
    BinTree<pair<string, double> > aux(make_pair(e, -1));
    clust = aux;
}

Cluster::Cluster(pair<string, double> p, Cluster dret, Cluster esq){
    //Constructora per crear un clúster més complet.
    BinTree<pair<string, double> > res(p, dret.clust, esq.clust);
    clust = res;
}

Cluster::~Cluster(){}
 
void Cluster::imprimeix_arbre(const BinTree<pair<string, double> >& c) const{
    // Comprovem que el conjunt no estigui buit 
    if(not c.empty()){
        if(not c.right().empty() and not c.left().empty()){
            //imprimim el node i després imprimim recursivament la resta del arbre
            cout << "[(" << c.value().first << ", " << c.value().second << ") ";
            
            imprimeix_arbre(c.right());
            imprimeix_arbre(c.left());
            cout << "]";
        }else{
            cout << '[' << c.value().first << ']';
        }
    }
}

void Cluster::imprimeix_cluster(const Cluster& c){
    BinTree<pair<string, double> > aux = c.clust;
    imprimeix_arbre(aux);
}


 