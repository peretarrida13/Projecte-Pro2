//ACATTATCATGC 3
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> unio(vector<string>& v, vector<string>& u){
    vector<string> res;
    for(int i = 0; i < v.size(); ++i) res.push_back(v[i]);
    for(int i = 0; i < u.size(); ++i) res.push_back(u[i]);
    sort(res.begin(), res.end());
    return res;
}

vector<string> interseccio(vector<string>&v, vector<string>& u){
    vector<string> res; 
    for(int i = 0; i < v.size(); ++i){
        int j = 0; 
        bool trobat = false;
        while(not trobat and j < u.size()){
            if(v[i] == u[j]){
                res.push_back(v[i]);
                trobat = true;
            }
            else ++j;
        }
    }
    sort(res.begin(), res.end()); 
    return res;
}

vector<string> kmer(string s, int k){
    vector<string> res;
    for(int i = 0; i < s.length() - k + 1; ++i){
        string s1;
        for(int j = 0; j < k; ++j){
            s1.push_back(s[i + j]);
        }
        res.push_back(s1);        
    }
    sort(res.begin(), res.end());
    return res;
}

double distancia(string s, string c, int k){
    vector<string> v; 
    v = kmer(s, k);
    vector<string> u; 
    u = kmer(c, k);
    vector<string> un;
    un = unio(v, u);
    vector<string> in; 
    in = interseccio(v, u);
    double m1 = un.size(); 
    double m2 = in.size();
    double div = m2 / m1;
    double res = (1 - div) * 100;
    return res;
}

int main(){
    string s, c;
    int k; 
    cin >> s >> c >> k;
    cout << distancia(s, c, k) << endl;
}

