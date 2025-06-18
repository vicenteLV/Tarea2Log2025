#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "unionFind.cpp"
#include "kruskal.h"  
#include "random.cpp"
#include "kruskal.cpp"

using namespace std;
using namespace chrono;

int main(){
    //crear csv
    ofstream archivo("resultados_kruskal.csv");
    archivo << "exponente,pasada,tiempo_gen_nodos,tiempo_gen_arreglo,tiempo_gen_heap,";
    archivo << "tiempo_var1,tiempovar2,tiempo_var3,tiempo_var4\n";
    
    cout << "Iniciando experimentos...\n" << endl;

    for(int exp=5; exp <= 12; exp++){
        int n = 1<<exp; //2^exp
        cout<<"### Experimento con 2^"<<exp<<" = "<<n<<" nodos ###"<<endl;

        for(int pasada=1; pasada<=5; pasada++){
            cout<<"Pasada "<<pasada<<" de 5"<<endl;

            //generacion de nodos
            auto inicio = high_resolution_clock::now();
            vector<pair<double,double>> nodos = generarNodos(n);
            auto fin = high_resolution_clock::now();
            double tiempo_gen_nodos = duration<double,milli>(fin-inicio).count();

            //generacion arreglo ordenado (sort)
            inicio = high_resolution_clock::now();
            vector<Arista> aristas_ordenadas = generarArregloAristas(nodos);
            fin = high_resolution_clock::now();
            double tiempo_gen_arreglo = duration<double,milli>(fin-inicio).count();

            //generacion heap (con implementación de C++)
            inicio = high_resolution_clock::now();
            priority_queue<Arista,vector<Arista>,greater<Arista>> heap_aristas = generarColaAristas(nodos);
            fin = high_resolution_clock::now();
            double tiempo_gen_heap = duration<double,milli>(fin-inicio).count();

            //APLICACION DE ALGORITMO KRUSKAL

            //variacion 1: Con optimización y arreglo ordenado
            UnionFind uf1(n);
            inicio = high_resolution_clock::now();
            vector<Arista> mst1 = MST_arreglo(aristas_ordenadas,uf1,true);
            fin = high_resolution_clock::now();
            double tiempo_var1 = duration<double,milli>(fin-inicio).count();

            //variacion 2: Con optimizacion y cola de prioridad
            UnionFind uf2(n);
            inicio = high_resolution_clock::now();
            vector<Arista> mst2 = MST_heap(heap_aristas,uf2,true);
            fin = high_resolution_clock::now();
            double tiempo_var2 = duration<double,milli>(fin-inicio).count();

            //variacion 3: Sin optimizacion y con arreglo ordenado
            UnionFind uf3(n);
            inicio = high_resolution_clock::now();
            vector<Arista> mst3 = MST_arreglo(aristas_ordenadas,uf3,false);
            fin = high_resolution_clock::now();
            double tiempo_var3 = duration<double,milli>(fin-inicio).count();

            //variacion 4: Sin optimización y con cola de prioridad
            UnionFind uf4(n);
            inicio = high_resolution_clock::now();
            vector<Arista> mst4 = MST_heap(heap_aristas,uf4,false);
            fin = high_resolution_clock::now();
            double tiempo_var4 = duration<double,milli>(fin-inicio).count();

            //resultados al csv
            archivo<<exp<<","<<pasada<<","<<tiempo_gen_nodos<<",";
            archivo<<tiempo_gen_arreglo<<","<<tiempo_gen_heap<<",";
            archivo<<tiempo_var1<<","<<tiempo_var2<<","<<tiempo_var3<<",";
            archivo<<tiempo_var4<<"\n";

            cout<<"Tiempos(ms) en pasada "<<pasada<<":\nVar1= "<<tiempo_var1<<"\n"<<"Var2= "<<tiempo_var2<<"\n"
            <<"Var3= "<<tiempo_var3<<"\n"<<"Var4= "<<tiempo_var4<<"\n"<<endl;
        }
        cout<<endl;
    }
    archivo.close();
    cout <<"Experimentos listos, resultados en resultados_kruskal.csv"<<endl;

    return 0;
}