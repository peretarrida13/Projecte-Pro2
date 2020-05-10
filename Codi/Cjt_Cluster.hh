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
	/**
	 * @brief Diccionari on guardem els clústers a partir del indentificador
	*/ 
    map<string, Cluster> c;

	/**
	 * @brief Taula per emmagatzemmar la distàncies entre clústers.
	*/
	map<string, map<string, double> > taula_distancies;

	/** @brief Modificadora que ens permet actualitzar la matriu dist 
 	* donat el identificador elimina les files i les columnes donades
 	* \pre <em> Cert.</em>
 	* \post Si l'espècie no existeix, s'afageix a la matriu i s'actualitza les distàncies entre les espècies, en cas contrari, s'elimina de la matriu.
	*/
	void actualitza_taula(const string& id1, const string& id2, bool eliminar);
	
public: 
	/**
	@brief Constructora per defecte;
	**/
	Cjt_Cluster();

/**
	@brief Inclialitza es clústers
	Inicialitza els clústers partint d'un conjunt d'espècies no buit.
	\pre Conjunt d'espècies no està buit
	\post S'han imprés els clústers restants i la taula de distàncies entre clústers, els identificadors indexen les files o les comlumnes. 
	*/
    void inicialitza_clustrers(Cjt_Especies& e);
    
    /**
	@brief Exacuta un pas WPGMA
	Exacuta un pas de l'algorisme WPGMA
	\pre Conjunt de clústers amb mida més gran o igual que 1.
	\post S'ha exacutat un pas del algorisme WPGMA i s'ha imprés al taula de distàncies.
	*/
    void ejecuta_paso_wpgma();
	
	/**
	 * @brief Consultar un clúster del conjunt
	 * \pre El clúster de l'identificador existeix dins del conjunt.
	 * \post Retorna el clúster corresponent a l'identificador donat.
	*/
	Cluster consultar_cluster(string id);
	
	/**
	 * @brief Imprimeix l'arbre filogenetic a partir del conjunt d'espècies actual.
	 * \post <em>Cert</em>
	 * \post S'ha descartat el conjunt de cluústers anterior i s'ha exacutat tot l'algorisme WPGMA, s'imprimeixen l'estructura arbolescent del clúster amb els seus
	 * respectius identificadors i la distància entre les fulles. Error si el conjunt de clusters es buit.
	*/
	void imprime_arbol_filogenetico();

	/**
	 * @brief Imprimeix taula de distàncies.
	 * \post <em>Cert</em>
	 * \post S'ha imprés la taula amb els identificadors corresponents.
	*/
	void imprimir_taula_distancias();

	/**
	 * @brief Busca Cluster.
	 * \post Conjunt de clústers no buits.
	 * \post Retorna si el exiteix el clúster dins del conjunt de clústers.
	*/
	bool busca_cluster(const string& id);

	/**
	 * @brief Retorna la mida del conjunt de clusters
	 * \post <em>Cert</em>
	 * \post Retorna la mida del conjunt de clústers
	*/
	int mida_cjt();

};

#endif 