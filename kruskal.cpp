#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "unionFind.cpp"
#include "random.cpp"
using namespace std;

/*
funcion que recibe aristas ordenadas por sort en un arreglo, una instancia
de UnionFind que ayuda a trackear nodos y un valor booleano que indica si se usarán 
funciones find optimizadas o no, retorna un vector de aristas que conforman el MST
[vector<Arista> UnionFind bool] -> vector<Arista>
*/
vector<Arista> MST_arreglo(vector<Arista> aristas_ordenadas, UnionFind& nodos,
    bool optimizacion){
    
    int n = nodos.getPadreSize();
    vector<Arista> T;
    T.reserve(n-1); //el MST tiene n-1 aristas

    int k = 0;
    while(T.size()<n-1 && k<aristas_ordenadas.size()){
        if(T.size()==(n-1)/4 || T.size()==2*((n-1)/4) || T.size()==3*((n-1)/4)){
            int avance = (T.size()/(n-1)) * 100;
            cout << avance << " de avance en esta secuencia..." << endl;
        }

        Arista menor_actual = aristas_ordenadas[k];
        int nodo_i = menor_actual.i;
        int nodo_j = menor_actual.j;

        int raiz_i, raiz_j;

        //operacion find depende de la optimizacion que se le haya dado o no
        if(optimizacion){
            raiz_i = nodos.find_opt(nodo_i);
            raiz_j = nodos.find_opt(nodo_j);
        } else{
            raiz_i = nodos.find(nodo_i);
            raiz_j = nodos.find(nodo_j);
        }

        if(raiz_i != raiz_j){
            T.push_back(menor_actual);
            
            if(optimizacion){
                nodos.unir_opt(nodo_i, nodo_j);
            }else{
                nodos.unir(nodo_i,nodo_j);
            }
        }
        k++;
    }
    return T;    
}

/*
funcion que recibe cola de prioridad para heap, instancia de UnionFind, y valor
booleano que indica si corresponde la optimizacion de las operaciones de find y unir
[priority_queue UnionFind bool] -> vector<Arista>*/
vector<Arista> MST_heap(priority_queue<Arista,vector<Arista>,greater<Arista>> heap,
    UnionFind& nodos, bool optimizacion){
    
    int n = nodos.getPadreSize();
    vector<Arista> T;
    T.reserve(n-1);

    while(T.size()<(n-1) && !heap.empty()){
        if(T.size()==(n-1)/4 || T.size()==2*((n-1)/4) || T.size()==3*((n-1)/4)){
            int avance = (T.size()/(n-1)) * 100;
            cout << avance << " de avance en esta secuencia..." << endl;
        }

        Arista menor_actual = heap.top();
        heap.pop();

        int nodo_i = menor_actual.i;
        int nodo_j = menor_actual.j;
        int raiz_i, raiz_j;

        if(optimizacion){
            raiz_i = nodos.find_opt(nodo_i);
            raiz_j = nodos.find_opt(nodo_j);
        }else{
            raiz_i = nodos.find(nodo_i);
            raiz_j = nodos.find(nodo_j);
        }

        if(raiz_i != raiz_j){
            T.push_back(menor_actual);

            if(optimizacion){
                nodos.unir_opt(nodo_i, nodo_j);
            } else{
                nodos.unir(nodo_i, nodo_j);
            }
        }
    }
    return T;
}