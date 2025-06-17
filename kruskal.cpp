#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>

/*
estructura para representar aristas, x es el nodo de salida, y el de llegada
y peso la distancia euclidiana al cuadrado
*/
typedef struct {
    int x;
    int y;
    double peso;
}Arista;

/*
funcion que genera el arreglo de pares ordenados que representa 
cada nodo, creando cada par con random()
int -> vector[pair[double, double]]
*/
std::vector<std::pair<double, double>> generarNodos(int n){
    std::vector<std::pair<double, double>> nodos;
    nodos.reserve(n); //guardamos espacio para n nodos
    std::srand(std::time(0));

    for( int i=0; i<n; i++){
        nodos[i] = {
            static_cast<double>(std::rand()) / RAND_MAX,
            static_cast<double>(std::rand()) / RAND_MAX
        };        
    }
    return nodos;
}

/*
funcion de comparacion para sort en la generacion de aristas
[Arista Arista] -> bool*/
bool comparacionPesos(const Arista& a, const Arista& b){
    return a.peso < b.peso;
}

/*
funcion que toma el arreglo de nodos generado aleatoriamente y calcula
todas las aristas posibles para luego devolver un arreglo ordenado de menor a 
mayor según peso
[vector[pair[double, double]] int] -> vector[Arista]
*/
std::vector<Arista> generarArregloAristas(std::vector<std::pair<double, double>> nodos, int n){
    std::vector<Arista> aristas;
    aristas.reserve((n*(n-1))/2);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            double dx = nodos[i].first - nodos[j].first;
            double dy = nodos[i].second - nodos[j].second;
            double peso = dx*dx + dy*dy;

            aristas.push_back({i,j,peso});
        }
    }
    std::sort(aristas.begin(), aristas.end(), comparacionPesos);
    return aristas;
}

/*
funcion que toma el arreglo de nodos generado aleatoriamente y calcula
todas las aristas posibles para luego devolver una cola de prioridad de menor a 
mayor según peso
[vector[pair[double, double]] int] -> priority_queue(Arista)
*/
std::priority_queue<Arista, std::vector<Arista>, std::greater<Arista>> 
generarColaAristas(const std::vector<std::pair<double,double>>& nodos, 
    int n){

    std::priority_queue<Arista, std::vector<Arista>, std::greater<Arista>> heap;
    
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