#include "Cluster.hh"
using namespace std;

Cluster::Cluster(Especie& e){
    pair a; 
    a.fist() = e.obtener_gen();
}

Cluster::Cluster(Cluster esquerra, Cluster dret){
    cluster.left() = esquerra;
    cluster.right() = dret;
}

Cluster::~Cluster(){}

void Cluster::imprimeix_cluster(){
    if(not a.empty()){
        cout << a.value() << endl;
        imprimeix_cluster(a.right());
        imprimeix_cluster(a.left());
    }
}