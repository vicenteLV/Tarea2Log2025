#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "kruskal.h"
#include "unionFind.cpp"
#include "random.cpp"
using namespace std;

/*
funcion que recibe aristas ordenadas por sort en un arreglo, una instancia
de UnionFind que ayuda a trackear nodos y un valor booleano que indica si se usarán 
funciones find optimizadas o no, retorna un vector de aristas que conforman el MST
[vector<Arista> UnionFind bool] -> vector<Arista>
*/
vector<Arista> MST_arreglo(vector<Arista> aristas_ordenadas, UnionFind nodos, bool optimizacion){
    int n = nodos.padre.size();
    vector<Arista> T;

    int k = 0;
    while(T.size()<((n*(n-1))/2) && k<arista_ordenadas.size()){
        aristas_ordenadas[k]

    }
    
    
}