#include "Cluster.hh"
using namespace std;

Cluster::Cluster(){
    //Constructora per defecte.
}

Cluster::Cluster(string& e){
    //Constructora 
    //crear un clúster només amb el identificador i amb distància negativa. 
    BinTree<pair<string, double> > aux(make_pair(e, -1));
    clust = aux;
}

Cluster::Cluster(pair<string, double> p, Cluster dret, Cluster esq){
    //Constructora a partir de 2 clústers.
    BinTree<pair<string, double> > res(p, dret.clust, esq.clust);
    clust = res;
}

Cluster::~Cluster(){}
 
void Cluster::imprimeix_arbre(const BinTree<pair<string, double> >& c) const{
    //Comprovem que el conjunt no estigui buit.
    if(not c.empty()){
        if(not c.right().empty() and not c.left().empty()){
            //imprimim el node arrel, la resta de l'arbre l'imprimim recursivament.
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
    //Imprimim el clúster.
    BinTree<pair<string, double> > aux = c.clust;
    imprimeix_arbre(aux);
}


 