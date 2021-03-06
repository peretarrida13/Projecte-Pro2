/** @file Especie.hh
 * @brief Especificació de la classe Espècie.
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#include <string>
#endif

using namespace std;

/** @class Espècie
 * @brief Representació d'una espècie i el seu conjunt d'opcions i característiques.
*/

class Especie{

private: 
/** @brief Cadena de gens d'una espècie.*/
    string gen;
	/** @brief Map encarregat de guarda els kmers i les seves repeticions un cop s'inicialitza l'espècie a partir del gen.*/
	map<string, int> kmer;
public:

    /**
	@brief <b>Constructora.</b>
	\pre <em>Cert.</em>
	\post El resultat es una espècie amb el gen = "0".
	*/
    Especie();
    
    /**
	@brief <b>Constructora.</b>
	\pre <em>Cert.</em>
	\post El resultat és una espècie ab els paràmetres implicits indicats a la crida del mètode, i amb la k calculem el kmer.
	*/
    Especie(string& gen, int& k);
    
	/** @brief <b>Destructora.</b> */
	~Especie();
    
    /**
	@brief <b>Consultora del gen d'una Espècie.</b>
	
	\pre <em>Cert.</em>
	\post Retorna la cadena de gens associada a l'espècie.
	*/
    string obtener_gen() const;

	/**
	@brief <b>Distància entre 2 espècies.</b>
	Donades 2 especies retorna la distància entre elles.
	\pre Existeixen els dos paràmetres d'entrada.
	\post Retorna la distància entre les dos espècies amb dits identificadors.
	*/
	static double distancia(const Especie& a, const Especie& b); 
    
};

#endif