#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "random.cpp"
#include "unionFind.cpp"
using namespace std;

/*
estructura para representar aristas, x es el nodo de salida, y el de llegada
y peso la distancia euclidiana al cuadrado
*/
typedef struct {
    int x;
    int y;
    double peso;

    //sobrecarga de < para orden ascendente en sort
    bool operator<(const Arista& otra) const{
        return peso < otra.peso;
    }

    //sobrecarga de > para cola de prioridad con greater
    bool operator>(const Arista& otra) const{
        return peso > otra.peso;
    }

}Arista;


vector<Arista> MST_arreglo(vector<Arista> aristas_ordenadas, UnionFind nodos, bool optimizacion){}