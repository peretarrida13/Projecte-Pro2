/**
 * @file Cjt_Cluster.hh
 * @brief Especificació de la classe Cjt_Cluster
*/
#ifndef CJT_CLUSTER_HH
#define CJT_CLUSTER_HH

#include "Cluster.hh" 
#include "Cjt_Especies.hh"

#ifndef NO_DIAGRAM
#include <map> 
#endif
 
/**
 * @class Conjunt de Clúster
 * @brief Representació del conjunt de clústers i de les seves opcions i característiques.
*/
class Cjt_Cluster{

private: 
	/** @brief Diccionari on guardem els clústers ordenats per mitjà de l'indentificador.*/ 
    map<string, Cluster> c;

	/** @brief Taula per emmagatzemmar la distàncies entre clústers.*/
	Taula_distancies taula_distancies;
	
public: 
	/**	@brief <b>Constructora.</b>*/
	Cjt_Cluster();

	/**
	@brief <b>Inclialitza es clústers.</b>
	Inicialitza els clústers partint d'un conjunt d'espècies.
	\pre Conjunt d'espècies no està buit.
	\post S'han inicialitza el map i la taula, i s'ha imprés la taula de distàncies entre clústers. 
	*/
    void inicialitza_clustrers(Cjt_Especies& e);
    
    /**
	@brief <b>Exacuta un pas WPGMA.</b> 
	\pre Conjunt de clústers amb mida més gran que 1.
	\post S'ha exacutat un pas del algorisme WPGMA i s'ha imprés al taula de distàncies.
	*/
    void ejecuta_paso_wpgma();
	
	/**
	 * @brief <b>Consultar un clúster del conjunt.</b>
	 * \pre El clúster de l'identificador existeix dins del conjunt.
	 * \post Retorna el clúster corresponent a l'identificador donat.
	*/
	Cluster consultar_cluster(string id) const;
	
	/**
	 * @brief <b>Imprimeix l'arbre filogenetic a partir del conjunt d'espècies actual.</b>
	 * \post <em>Cert.</em>
	 * \post S'ha exacutat tot l'algorisme WPGMA, s'imprimeixen l'estructura arbolescent resultant.
	*/
	void imprime_arbol_filogenetico();

	/**
	 * @brief <b>Obtenir taula de distàncies.</b>
	 * \post <em>Cert.</em>
	 * \post S'ha retornat la taula de distàncies entre clusters.
	*/
	Taula_distancies obtenir_taula() const;

	/**
	 * @brief <b>Existeix Cluster.</b>
	 * \post Conjunt de clústers no buits.
	 * \post Retorna si existeix o no el cluster dins del conjunt.
	*/
	bool busca_cluster(const string& id);

	/**
	 * @brief <b>Mida del Conjunt.</b>
	 * \post <em>Cert.</em>
	 * \post Retorna la mida del conjunt de clústers.
	*/
	int mida_cjt() const;

};

#endif 