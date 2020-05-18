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

    void elimina_especie(const string& id);

    void afageix_especie(const string& id1, const string& id2, const double& d);

    void distancia_minima(double& min, string& m1, string& m2);

    void actualitza_taula_cluster(const string& id1, const string& id2);
    /**
	@brief <b>Taula de distàncies</b>
	Donat un conjunt d'espècies imprimeix una matriu amb les distàncies entre espècies del conjunt.
	\pre Conjunt no buit.
	\post S'imprimeix la distància entre cada parell d'espècies del conjunt.
	*/
    void imprimir_taula_distancies() const;

    void buida_taula();
};

#endif