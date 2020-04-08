#include <iostream>
#include "Cjt_Especies.hh"
using namespace std;

class Cluster{
    //ABANS DEL .CC I PULIR DETALLS CAL LLEGIR I ENTENDRE QUE ES UN PUTO CLUSTER;

private:
    
public:
    void inicialitza_clustrers(Cjt_Especies& e);
    //PRE: Conjunt d'especies no buit;
    //POST: imprimeix els clusters restants i la taula de distancies entre clusters
    //identificadors marquen les files i les columnes;
    void ejecuta_paso_wpgma(Cjt_Especies& e );//Mirar amb més clardat que es el cluster i com funciona; 
    //PRE:cert; 
    //POST: fusiona els dos clusters de menor distancia i imprimeix la taula de distancies entre clusters resultats;
    //es fan servir els identificadors dels clusters per indexar la taula;
    void imprime_cluster(string identificador);
    //PRE: Existeix el cluster amb identificador; 
    //POST: Imprimeix l'estructura arbolescent  del cluster amb l'identificador donat;
    void imprime_arbol_filogenetico();
    //imprimeix el arbre filogenetic per el conjunt d'especies, agrupa les especies resultants d'aplicar l'algoritme WPGMA.
    //es descarta el conjunt de clusters previ i es reinicia amb el conjunt d'especies en el estat en el que esta en el moment
    //anper a continuació aplicar l'algoritme;
};