/** @file Cjt_Especies.hh
 * @brief Especificació de la classe Cjt_Especies.
*/
#ifndef CJT_ESPECIES_HH
#define CJT_ESPECIES_HH

#include "Taula_distancies.hh"

#ifndef NO_DIAGRAM
#include <map>
#endif

/** @class Cjt_Especies
 * @brief Respesenta les opcions i característiques del conjunt d'espècies.
*/
class Cjt_Especies{

private:
/** @brief Diccionari on guardem les espècies classificant-les per els identificadors. */
	map<string, Especie> especies;
/** @brief Taula la qual emmagatzema la distància entre espècies.*/
	Taula_distancies taula_dist;
/** @brief Iterador que recorre el map especies.*/
	map<string, Especie>::iterator it_esp = especies.begin();

public:

/** @brief <b>Constructora.</b>
 * \pre <em>Cert.</em>
 * \post El resultat és  un conjunt d'Especies buit.
*/
	Cjt_Especies();

/** @brief <b>Destructura.</b> */
	~Cjt_Especies();

/**
	@brief <b>Crea espècie.</b>
	Crea una espècie i l'emmagatzema al map.
	
	\pre No existeix cap espècie amb l'identificador donat.
	\post Un nou objecte del tipus espècie s'ha afegit al conjunt d'espècies.
	*/
	void crea_especie(string& id, string& gen, int& k);

	/**
	@brief <b>Consultar l'espècie d'un conjunt.</b>
	Consultora d'un conjunt d'espècies, retorna una especie.
	\pre Existeix l'espècie dins del conjunt. 
	\post Retorna l'objecte especie amb l'identificador donat.
	*/
	Especie consultar_especie(string id) const;
	
	
	/**
	@brief <b>Elimina espècie.</b>
	Busca l'espècie i l'elimina de la taula i del map.
	\pre Existeix l'espècie amb l'identificador donat.
	\post S'ha eliminat l'espècie amb l'identificador id del conjunt d'espècies.
	*/	
	void eliminar_especie(string& id);
	
	/**
	@brief <b>Existeix espècie.</b>
	Busca una espècies dins del conjunt amb l'identificador donat. 
	\pre Identificador vàlid.
	\post Retorna si l'espècie que pertany a l'identificador pertany al conjunt o no.
	*/
	bool existe_especie(string& id);
	
	/**
	@brief <b>Llegir Un Conjunt d'espècies.</b>
	Llegeix i l'espècie i la guarda en el map i en la taula.
	\pre <em>Cert.</em>
	\post S'ha llegit i afegit totes les espècies al conjunt i s'ha emplenat la taula.
	*/
	void lee_cjt_especies(int k);

	/** @brief <b>Conjunt buit.</b>
	 * 
	 * \pre <em>Cert.</em>
	 * \post Retorna si el conjunt està buit o no.
	*/
	bool esta_buit();
	
	/**
	@brief <b>Imprimeix un Conjunt d'espècies.</b>
	Imprimeix un conjunt d'espècies primer l'identificador i després el gen.
	\pre Conjunt d'espècies no buit.
	\post S'han imprés totes les espècies.
	*/
	void imprime_cjt_especies() const;

	/** @brief <b>Iterador Inici.</b>
	 * \pre Copnjunt no buit.
	 * \post Iterador apunta al principi del map.
	*/
	void inici();

	/** @brief <b>Interador final.</b>
	 * \pre <em>Cert.</em>
	 * \post Retorna si l'iterador apunta o no al final de especies.
	*/
	bool final();
	
	/** @brief <b>Incrementa iterador.</b>
	 * \pre Iterador <b>no</b> apunta al final del map.
	 * \post L'iterador apunta el següent element del map.
	*/
	void incrementar();
	
	/** @brief <b>Obtenir primer element.</b>
	 * \pre Iterador no apunta al final del map.
	 * \post Retorna el primer element del map al qual apunta l'iterador.
	*/
	string obtenir_primer();
	
	/** @brief <b>Obtenir segon element.</b>
	 * \pre Iterador <b>no</b> apunta al final del map.
	 * \post retorna el segon element del map al qual apunta l'iterador.
	*/
	Especie obtenir_segon();

	/**
	@brief <b>Obtenir Taula</b>
	\pre <em>Cert.</em>
	\post Retorna la taula de distàncies del conjunt.
	*/
	Taula_distancies obtenir_taula();
};

#endif