/** @file Especie.hh
 * @brief Especificació de la classe Espècie.
*/

#ifndef ESPECIE_HH
#define ESPECIE_HH

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif

using namespace std;

/** @class Espècie
 * @brief Representació d'una espècie i el seu conjunt d'opcions i característiques.
*/

class Especie{

private: 
/** @brief Identificador de cada espècie.*/
	string id;
/** @brief Cadena de gens d'una espècie. */
    string gen;
/** @brief Vector que guarda els kmers un cop s'inicialitza l'espècie amb els seus gens */
	vector<string> kmer;

/** @brief Passa de la string gen a un vector kmer
 * \pre L'espècie té un gen vàld
 * \post S'han afegit al kmer les diferents strings resultants de dividir el gen en k parts.
*/
public:
    /**
	@brief Constructora
	\pre <em>Cert</em>
	\post El resultat es una espècie amb el gen = "0";
	*/
    Especie();
    
    /**
	@brief Constructora
	\pre <em>Cert</em>
	\post El resultat és una espècie ab els paràmetres implicits indicats a la crida del mètode, i amb la k calculem el kmer.
	*/
    Especie(string& gen, int& k);
    
/** @brief Destructora */
	~Especie();


/**
	@brief Consultora del vector kmer.
	
	\pre <em>Cert</em> 
	\post Retorna un vector amb tots els seus integrans.
	*/
    vector<string> obtener_kmer() const;
    
    /**
	@brief Consultora del gen d'una Espècie;
	
	\pre <em>Cert</em>
	\post Retorna la cadena de gens associada a l'espècie.
	*/
    string obtener_gen() const;
    
};

#endif