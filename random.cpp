#include <vector>
#include <random>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "kruskal.h"
using namespace std;

/*
funcion que genera el arreglo de pares ordenados que representa 
cada nodo, creando cada par con random()
int -> vector[pair[double, double]]
*/
vector<pair<double, double>> generarNodos(int n){
    vector<pair<double, double>> nodos;
    nodos.reserve(n); //guardamos espacio para n nodos

    mt19937 generador(time(0)); //semilla
    uniform_real_distribution<double> distribucion(0.0, 1.0);

    for( int i=0; i<n; i++){
        nodos.emplace_back(
            distribucion(generador), //generacion de double en las posiciones x e y
            distribucion(generador)
        );       
    }
    return nodos;
}

/*
funcion que toma el arreglo de nodos generado aleatoriamente y calcula
todas las aristas posibles para luego devolver un arreglo ordenado de menor a 
mayor según peso
[vector[pair[double, double]] int] -> vector[Arista]
*/
vector<Arista> generarArregloAristas(const vector<pair<double, double>>& nodos){
    vector<Arista> aristas;
    int n = nodos.size();
    aristas.reserve((n*(n-1))/2);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double dx = nodos[i].first - nodos[j].first;
            double dy = nodos[i].second - nodos[j].second;
            double peso = dx*dx + dy*dy;

            aristas.push_back({i,j,peso});
        }
    }
    sort(aristas.begin(), aristas.end()); //se ordena con el override el operador
    return aristas;
}

/*
funcion que toma el arreglo de nodos generado aleatoriamente y calcula
todas las aristas posibles para luego devolver una cola de prioridad de menor a 
mayor según peso
[vector[pair[double, double]] int] -> priority_queue(Arista)
*/
priority_queue<Arista, vector<Arista>, greater<Arista>> 
generarColaAristas(const vector<pair<double,double>>& nodos){

    priority_queue<Arista, vector<Arista>, greater<Arista>> heap;
    int n = nodos.size();
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double dx = nodos[i].first - nodos[j].first;
            double dy = nodos[i].second - nodos[j].second;
            double peso = dx*dx + dy*dy;
            heap.push({i,j,peso});
        }
    }

    return heap;    
}