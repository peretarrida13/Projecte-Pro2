/** @file Cjt_Especies.hh
 * @brief Especificació de la classe Cjt_Especies.
*/
#ifndef CJT_ESPECIES_HH
#define CJT_ESPECIES_HH

#include "Especie.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Especies
 * @brief Respesenta les opcions i característiques del conjunt d'espècies.
*/
class Cjt_Especies{

private:
/** @brief Diccionari on guardem les espècies a partir d'un identificador. */
	map<string, Especie> especies;
/** @brief Matriu de doubles que representen les distàncies entre espècies donats dos identificadors. */
	map<string, map<string, double> > dist;

/** @brief Modificadora que ens permet actualitzar la matriu dist 
 * donats una espècie i un boolea que ens indica si em d'eliminar o afegir columnes i files.
 * \pre <em> Cert.</em>
 * \post Si l'espècie no existeix, s'afageix a la matriu i s'actualitza les distàncies entre les espècies, en cas contrari, s'elimina de la matriu.
*/
	void actualitza_dist(const Especie& e, const string& id, bool eliminar);

public:
/** @brief  Creadora
 * \pre <em>Cert</em>
 * \post El resultat és  un conjunt d'Especies buit.
*/
	Cjt_Especies();

/** @brief Destructura */
	~Cjt_Especies();

/**
	@brief Crear espècie
	Es crea un objecte espècie amb l'identificador i els gens donats.
	Un cop creada l'espècie l'afegeix al conjunt d'espècies.
	
	\pre No existeix cap espècie amb l'identificador donat.
	\post Un nou objecte del tipus espècie s'ha afegit al conjunt d'espècies.
	*/
	void crea_especie(string& identificador, string& gen, int& k);

	/**
	@brief Consultar l'espècie d'un conjunt
	Consultora d'un conjunt d'espècies per veure l'espècie pertanyent al conjunt amb l'identificador donat.
	\pre Existeix l'espècie dins del conjunt. 
	\post Retorna l'objecte especie amb l'identifjicador donat.
	*/
	Especie consultar_especie(string id);
	
	/**
	@brief Distància entre 2 espècies
	Donats dos identificadors i de dos espècies diferents i un enter k, es retorna la distància entre
	les dos espècies. Si alguna de les dos espècies no existeix, la funcio retorna Error.
	\pre Existeixen els dos paràmetres d'entrada;
	\post Retorna la distància entre les dos espècies amb dits identificadors.
	*/
	double distancia(const Especie& a, const Especie& b); 
	
	/**
	@brief Elimina espècie
	Es dona un identificador, es busca l'espècie amb l'identificador dins del conjunt, i
	s'elimina.
	\pre Existeix l'espècie amb l'identificador donat.
	\post S'ha eliminat l'espècie amb l'identificador id del conjunt d'espècies.
	*/	
	void eliminar_especie(string& id);
	
	/**
	@brief Existeix espècie
	Busca una espècies dins del conjunt amb l'identificador donat. Retorna true si l'ha trobada
	i false en cas contrari.
	\pre Identificador vàlid.
	\post Retorna si l'espècie que pertany a l'identificador pertany al conjunt o no.
	*/
	bool existe_especie(string& id);
	
	/**
	@brief Llegir Un Conjunt d'espècies
	Llegeix un conjunt d'espècies i guarda els valors llegits en una llista d'espècies.
	\pre <em>Cert</em>
	\post S'ha llegit i afegit totes les espècies al conjunt.
	*/
	void lee_cjt_especies(int k);

	/** @brief Conjunt buit
	 * 
	 * \pre <em>Cert</em>
	 * \post retorna true si el conjunt està buit i false si el conjunt té Espècies.
	*/
	bool esta_buit();
	
	/**
	@brief Imprimeix un Conjunt d'espècies
	Imprimeix un conjunt d'espècies amb el identificador i amb el gen corresponents.
	\pre Conjunt d'espècies no buit.
	\post S'han imprés totes les espècies del conjunt amb els seus respectius identificadors i gens.
	*/
	void imprime_cjt_especies();
	
	/**
	@brief <b>Taula de distàncies</b>
	Donat un conjunt d'espècies imprimeix una matriu amb les distàncies entre espècies del conjunt.
	\pre Conjunt no buit.
	\post S'imprimeix la distància entre cada parell d'espècies del conjunt.
	*/
	void imprimir_tabla_distancias();

	/**
	@brief <b>Taula de distàncies</b>
	Retorna la taula de distancies de un conjunt d'especies
	\pre Conjunt no buit.
	\post S'ha retornat la distància entre cada parell d'espècies del conjunt.
	*/
	map<string, map<string, double> > taula_dist();

	/**
	@brief <b> Map Especies </b>
	Retorna el map del conjunt d'especies.
	\pre Existeix el conjunt d'espècies.
	\post Retorna un map que conté el conjunt d'espècies sense la taula de distàncies.
	*/
	map<string, Especie> cjt();
};

#endif