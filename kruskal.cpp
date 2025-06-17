#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>

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

