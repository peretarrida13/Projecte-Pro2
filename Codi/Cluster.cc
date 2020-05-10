#include "Cluster.hh"
using namespace std;

Cluster::Cluster(string& e){
    BinTree<pair<string, double> > aux(make_pair(e, -1));
    clust = aux;
}

Cluster::Cluster(pair<string, double> p, BinTree< pair<string, double> > dret, BinTree< pair<string, double> > esq){
    BinTree<pair<string, double> > res(p, dret, esq);
    clust = res;
}

Cluster::~Cluster(){}
 
void Cluster::imprimeix_cluster(const BinTree<pair<string, double> >& c){
    //IMPRIMIR RECUR SIVASMENT, COMENCEM PER EL VALOR DEL NODE ARREL I ANEM FENT;
    if(not c.empty()){
        if(c.value().second != -1){
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
    return clust;
}

BinTree<pair<string, double> > Cluster::get_right(){
    return clust.right();
}

BinTree<pair<string, double> > Cluster::get_left(){
    return clust.left();
}

