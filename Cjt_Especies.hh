#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef vector<vector<double> > Matriu;
class Cjt_Especies{
	/*Com les especies són 2 strings, identificador i gen, podem fer servir un
	map i amb string als 2 components, a més ens estalbiem grans cerques dins
	de vector o llistes*/
private:
	map <string, string> Cjt_Especies;
	Matriu taula_distancies();

public:
	void crea_especie(string& identificador, string& gen);
	//PRE: No existeix cap especie amb el mateix identificador;
	//POST: S'ha creat una especie i s'ha agregat al conjunt;
	void obtener_gen(string& identificador);
	//PRE: Existeix l'especie si no missatge d'error;
	//POST: Retorna el gen assossiat a l'identificador;e
	double distancia(string& id1, string& id2, int k); //COMPROVAR ESTÀ PER VEURE
	//COM ES FA;
	//PRE:2 identificadors existents;
	//POST: s'imprimeix la distancia entre els 2 identificadors;
	void eliminar_especie(string& id);
	//PRE: existeix una especies amb id en el conjunt d'especies; 
	//POST: s'ha eliminat l'especie amb identificador id del conjunt d'especies
	bool existe_especie(string& id);
	//PRE: cert;
	//POST: retornem si existeix o no l'especie;
	void lee_cjt_especies();
	//PRE: No existeix una especie amb aquest identificador
	//POST: S'han afegit al conjunt les especies;
	void imprime_cjt_especies();
	//PRE: conjunt no buit;
	//POST: s0ha imprés el conjunt;
	void tabla_distancias();
	//PRE: 
	//POST: s'imprimeix la distancia entre cada parell d'especies del conjunt;
	
	//FUNCIONS AFEGIDES PER CALCULAR LA DISTANCIA CORRECTAMENT:
	vector<string> unio(vector<string>& v, vector<string>& u);
	//PRE: 2 vectors no buits; 
	//POST: 1 vector amb les components dels dos vectors;
	vector<string> interseccio(vector<string>& v, vector<string>& u);
	//PRE: 2 vectors no buits amb elements amb comú; 
	//POST: Un sol vector amb els elements comuns de u i v;
	vector<string> kmer(string s, int k);
	//PRE: String no buida; 
	//POST: vector que conté la string dividida en k parts;

};