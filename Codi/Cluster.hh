/** @file Cluster.hh
 * @brief Especificació de la classe Clúster
*/

#ifndef CLUSTER_HH
#define CLUSTER_HH

#include "Especie.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

using namespace std;

/** @class Clúster
 * @brief Respresenta les opcions i característiques d'un cluster d'espècies.
*/
class Cluster{
	
private:
/** 
 * @brief Classe gestionada per mitjà d'un BinTree
 * Esta format pel pair que conté una string que actua com identificador del clúster i un double que representa la distància a la que estan les espècies de les seves branques
 */
	BinTree<pair<string, double> > clust;

public:
	Cluster();
/**
 * @brief Constructora.
 * \pre <em>Cert</em>
 * \post El resultat un clúster sense nodes i fills creada a partir d'una espècie.
 */

	Cluster(string& e);

/** @brief Constructora a partir de dos clusters.
 * \pre <em>Cert<em>
 * \post El resultat una fusió dels dos clusters en un.
*/
	Cluster(pair<string, double> p,  Cluster dret, Cluster esq);

/** @brief Constructora a partir de dos BinTree.
 * \pre <em>Cert<em>
 * \post El resultat una fusió dels dos arbres en un.
*/
	Cluster(pair<string, double> p, BinTree<pair<string, double> > dret, BinTree<pair<string, double> > esq);

/** @brief Destructora*/
 	~Cluster();

/** @brief Imprimeix arbre
 * Funció d'immersió per ajudar a imprimir el arbre
 * \pre Arbre no buit.
 * \post S'ha imprès el arbre.
*/ 
	void imprimeix_arbre(const BinTree<pair<string, double> >& c) const;
	
/** @brief Imprimeix clúster
 * Funció recursiva que ens permet imprimir el cluster
 * \pre Clúster no buit.
 * \post S'ha imprès el clúster.
*/ 
	void imprimeix_cluster(const Cluster& c);
};

#endif 