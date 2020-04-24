/** @file main.cc
 * @brief Implementació de la classe principal.
*/

#include "Cjt_Cluster.hh"

using namespace std;

int main(){
    
    cout.setf(ios::fixed);
    cout.precision(4);

    int k;
    Cjt_Cluster clust;
    Cjt_Especies esp;
    string op, id, id2, gen; 

    cin >> k;

    while(cin >> op and op != "fin"){
        if(op =="crea_especie"){
            cin >> id >> gen; 
            if(esp.existe_especie(id)) cout << "Error: Ja existeix l'espècie amb aquest identificador" << endl;   
            else esp.crea_especie(id, gen);
        }
        else if(op == "obtener_gen"){
            cin >> id;
            if(not esp.existe_especie(id)) cout << "Error: L'espècie no existeix en el conjunt" << endl;
            else{
                cout << esp.consultar_especie(id).obtener_gen() << endl;
            }
        }
        else if(op == "distancia"){
            cin >> id >> id2;
            if(esp.existe_especie(id) and esp.existe_especie(id2)){
                cout << esp.distancia(esp.consultar_especie(id), esp.consultar_especie(id2)) << endl;
            }
            else cout << "Error: Una de les especies no existeix en el conjunt" << endl;
        }
        else if(op == "elimina_especie"){
            cin >> id;
            if(esp.existe_especie(id)) esp.eliminar_especie(id);
            else cout << "Error: L'espècie que vols eliminar no existeix en el conjunt" << endl;
        }
        else if(op == "existe_especie"){
            cin >> id;
            if(esp.existe_especie(id)) cout << "L'espècie existeix en el conjunt" << endl;
            else cout << "L'espècie no existeix en el conjunt" << endl;
        }
        else if(op == "lee_cjt_especies"){
            esp.lee_cjt_especies();
        }
        else if(op == "imprime_cjt_especies"){
            esp.imprime_cjt_especies();
        }
        else if(op == "tabla_distancias"){
            esp.imprimir_tabla_distancias();
        }
        else if(op == "inicialitza_clusters"){
            if(esp.esta_buit()) cout << endl;
            else clust.inicialitza_clustrers(esp);
        }
        else if(op == "ejecuta_paso_wpgma"){
            clust.ejecuta_paso_wpgma();
        }
        else if(op == "imprime_cluster"){
            cin >> id;
            clust.consultar_cluster(id).imprimeix_cluster();
        }
        else if(op == "imprime_arbol_filogenetio"){
            clust.imprime_arbol_filogenetio();
        }
    }
}