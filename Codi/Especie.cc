#include "Especie.hh"
using namespace std;

Especie::Especie(){
    //al crear l'especie si no tenim gen li assignem el valor 0
    gen = "0";
}

Especie::Especie(string& g, int& k){
    //inicialitzem el gen amb el parametre donat.
    gen = g; 

    //Recorrem el gen caracter a caracter per poder agafar els k caracters.
    for(int i = 0; i < g.length() - k + 1; ++i){
        //Creem una string per emmagatzamar els kmers i mes tard poder-los afegir al map. 
        string s1;

        //Agafem els k caracters partint del ièssim caràcter del gen.
        for(int j = 0; j < k; ++j){
            s1.push_back(g[i + j]);
        }

        //Busquem si aquesta string esta dins del map per saber si l'hem d'afegir en el map o incrementar la seva segona component.
        map<string, int> ::iterator it = kmer.find(s1); 
        if(it == kmer.end()){
            kmer.insert(make_pair(s1, 1));
        }
        else{
            it -> second = it -> second + 1;
        }        
    }
}

Especie::~Especie(){
    //Destructora per defecte.
}


string Especie::obtener_gen() const{
    //Retorna el gen de l'espècie.
    return gen;
}

double Especie::distancia(const Especie& a, const Especie& b){
    int in = 0;
    int un = 0;
    //Fem servir els kmers en dos maps per tal de calcular la distància.
    map<string, int> p = b.kmer;
    map<string, int> s = a.kmer;

    //Afegim els kmers de s a l'itersecció o a la unió
    //en funció de si el kmer existeix a p.
    for(map<string, int>::iterator it = s.begin(); it != s.end(); ++it){
        map<string, int>::iterator it2 = p.find(it->first);
        if(it2 != p.end()){
            if(it->second >= it2->second){
                un += it->second;
                in += it2->second;
            } else{
                un += it2->second;
                in += it->second;
            }
            p.erase(it2->first);
        } else un += it->second;
    }

    //Afegim els kmer de p a la unió.
    for(map<string, int>::iterator it = p.begin(); it != p.end(); ++it) un += it->second;

    //Apliquem la formula per calcular la distància.
    double res = (1.0-(double(in)/double(un)))*100.0;
    return res;
}