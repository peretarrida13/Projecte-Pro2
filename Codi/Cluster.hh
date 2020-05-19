/** @file Cluster.hh
 * @brief Especificació de la classe Clúster
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#endif

using namespace std;

/** @class Clúster
 * @brief Respresenta les opcions i característiques d'un cluster d'espècies.
*/
class Cluster{
	
private:
/** @brief BinTree que gestiona la classe la strring es l'identificador i el double la distancia.*/
	BinTree<pair<string, double> > clust;

public:
	Cluster();
/**
 * @brief <b>Constructora.</b>
 * \pre <em>Cert.</em>
 * \post El resultat un clúster nomes amb el node arrel.
 */

	Cluster(string& e);

/** @brief <b>Constructora</b> a partir de dos clusters.
 * \pre <em>Cert.<em>
 * \post El resultat una fusió dels dos clusters en un.
*/
	Cluster(pair<string, double> p,  Cluster dret, Cluster esq);

/** @brief <b>Destructora.</b>*/
 	~Cluster();

/** @brief <b>Imprimeix arbre</b>
 * Funció d'immersió i recursiva.
 * \pre Arbre no buit.
 * \post S'ha imprès el arbre.
*/ 
	void imprimeix_arbre(const BinTree<pair<string, double> >& c) const;
	
/** @brief <b>Imprimeix clúster.</b>
 * Funció que crida la funció d'immersió.
 * \pre Clúster no buit.
 * \post S'ha imprès el clúster.
*/ 
	void imprimeix_cluster(const Cluster& c);
};

#endif 