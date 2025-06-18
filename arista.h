#ifndef ARISTA_H
#define ARISTA_H

/*
estructura para representar aristas, x es el nodo de salida, y el de llegada
y peso la distancia euclidiana al cuadrado
*/
struct Arista{
    int i;
    int j;
    double peso;

    //sobrecarga de < para orden ascendente en sort
    bool operator<(const Arista& otra) const{
        return peso < otra.peso;
    }

    //sobrecarga de > para cola de prioridad con greater
    bool operator>(const Arista& otra) const{
        return peso > otra.peso;
    }

};

#endif