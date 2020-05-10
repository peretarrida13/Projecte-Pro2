#include "Cluster.hh"
using namespace std;

Cluster::Cluster(string& e){
    //Constructora que ens serveix per crear un clúster només amb el identificador i sense distància. 
    BinTree<pair<string, double> > aux(make_pair(e, -1));
    clust = aux;
}

Cluster::Cluster(pair<string, double> p, BinTree< pair<string, double> > dret, BinTree< pair<string, double> > esq){
    //Constructora per crear un clúster més complet.
    BinTree<pair<string, double> > res(p, dret, esq);
    clust = res;
}

Cluster::~Cluster(){}
 
void Cluster::imprimeix_cluster(const BinTree<pair<string, double> >& c){
    // Comprovem que el conjunt no estigui buit 
    if(not c.empty()){
        if(c.value().second != -1){
            //imprimim el node i després imprimim recursivament la resta del arbre
            cout << "[(" << c.value().first << ", " << c.value().second << ") ";
            imprimeix_cluster(c.right());
            imprimeix_cluster(c.left());
            cout << "]";
        }else{
            cout << '[' << c.value().first << ']';
        }
    }
}

BinTree<pair<string, double> > Cluster::get_tree(){
    //Retorna el arbre binari
    return clust;
}


 