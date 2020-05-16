/** @file main.cc
 * @brief Implementació de la classe principal.
*/

#include "Cjt_Cluster.hh"

using namespace std;

int main(){
    int k;
    Cjt_Especies esp;
    Cjt_Cluster c;
    string op, id, id2, gen; 

    cin >> k;

    while(cin >> op and op != "fin"){
        if(op =="crea_especie"){
            cin >> id >> gen; 
            cout << "# crea_especie " << id << ' ' << gen << endl;
            if(esp.existe_especie(id)) cout << "ERROR: La especie " << id << " ya existe." << endl;   
            else esp.crea_especie(id, gen, k);
        }
        else if(op == "obtener_gen"){
            cin >> id;
            cout << "# obtener_gen " << id << endl;
            if(not esp.existe_especie(id)) cout << "ERROR: La especie " << id << " no existe." << endl;
            else{
                cout << esp.consultar_especie(id).obtener_gen() << endl;
            }
        }
        else if(op == "distancia"){
            cin >> id >> id2;
            cout << "# distancia " << id << ' ' << id2 << endl;
            if(esp.existe_especie(id) and esp.existe_especie(id2)){
                double dist1 = esp.distancia(esp.consultar_especie(id), esp.consultar_especie(id2));
                cout << dist1 << endl;
            }
            else if(not esp.existe_especie(id) and esp.existe_especie(id2)) cout << "ERROR: La especie " << id << " no existe." << endl;
            else if(not esp.existe_especie(id2) and esp.existe_especie(id)) cout << "ERROR: La especie " << id2 << " no existe." << endl;
            else cout << "ERROR: La especie " << id << " y la especie " << id2 << " no existen." << endl;
        }
        else if(op == "elimina_especie"){
            cin >> id;
            cout << "# elimina_especie " << id << endl;
            if(esp.existe_especie(id)) esp.eliminar_especie(id);
            else cout << "ERROR: La especie " << id << " no existe." << endl;
        }
        else if(op == "existe_especie"){
            cin >> id;
            cout << "# existe_especie " << id << endl;            
            if(esp.existe_especie(id)) cout << "SI" << endl;
            else cout << "NO" << endl;
        }
        else if(op == "lee_cjt_especies"){
            cout << "# lee_cjt_especies" << endl;
            esp.lee_cjt_especies(k);
        }
        else if(op == "imprime_cjt_especies"){
            cout << "# imprime_cjt_especies" << endl;
            esp.imprime_cjt_especies();
        }
        else if(op == "tabla_distancias"){
            cout << "# tabla_distancias" << endl;
            esp.imprimir_tabla_distancias();
        }
       else if(op == "inicializa_clusters"){
            cout << "# inicializa_clusters" << endl;
            if(not esp.esta_buit()){
                c.inicialitza_clustrers(esp);
                c.imprimir_taula_distancias();
            }
        }
        else if(op == "ejecuta_paso_wpgma"){
            cout << "# ejecuta_paso_wpgma" << endl;
            if(c.mida_cjt() > 1){
                c.ejecuta_paso_wpgma();
                c.imprimir_taula_distancias();
            }
            else cout << "ERROR: num_clusters <= 1" << endl;
        }
        else if(op == "imprime_cluster"){
            cin >> id;
            cout << "# imprime_cluster " << id << endl;
            if(c.busca_cluster(id)){
                c.consultar_cluster(id).imprimeix_cluster(c.consultar_cluster(id).clust);
                cout << endl;
            }
            else cout << "ERROR: El cluster " << id << " no existe." << endl;
        }
        else if(op == "imprime_arbol_filogenetico"){
            cout << "# imprime_arbol_filogenetico" << endl;
            c.inicialitza_clustrers(esp);
            if(c.mida_cjt() != 0){
                c.imprime_arbol_filogenetico();
                cout << endl;
            }else{
                cout << "ERROR: El conjunto de clusters es vacio." << endl;
            }
        }
        cout << endl;
    }
}