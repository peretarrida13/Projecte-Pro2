/** @file Taula Distancies.hh
 * @brief Especificació de la classe Taula de distàncies.
*/

#ifndef TAULA_DISTANCIAS_HH
#define TAULA_DISTANCIAS_HH

#include"Especie.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Espècie
 * @brief Representació d'una espècie i el seu conjunt d'opcions i característiques.
*/

class Taula_distancies{

private: 
    map<string, map<string, double> > taula_dist;
public:
    /**
	@brief Constructora
	*/
    Taula_distancies();

    /** @brief Destructora **/
    ~Taula_distancies();

    /**
	@brief <b>Elimina espècie.</b>
	\pre L'espècie existeix a l'espècie.
	\post La taula ja no conté l'espècie.
	*/
    void elimina_especie(const string& id);

    /**
	@brief <b>Afageix espècie.</b>
	\pre L'espècie encara no existeix dins de la taula de distàncies.
	\post S'han afegit la fila i la columna corresponent.
	*/
    void afageix_especie(const string& id1, const string& id2, const double& d);

    /**
	@brief <b>Distància mínima.</b>
	\pre <em>Cert.</em>.
	\post S'ha obtingut les dos espècies amb distància mínima i el valor d'aquesta distància.
	*/
    void distancia_minima(double& min, string& m1, string& m2);

    /**
	@brief <b>Actualitza Taula.</b>
	
	\pre Els identificadors pertanyen a la taula.
	\post S'han eliminat les files i columnes amb els identificadors donats i s'ha afegit la nova.
	*/
    void actualitza_taula_cluster(const string& id1, const string& id2);
    /**
	@brief <b>Imprimir Taula.</b>

	\pre <em>Cert.</em>
	\post S'imprimeix la distància entre cada parell d'espècies del conjunt.
	*/
    void imprimir_taula_distancies() const;

    /**
	@brief <b>Buida Taula.</b>
	
	\pre <em>Cert.</em>
	\post La taula ja no conté cap element.
	*/
    void buida_taula();
};

#endif