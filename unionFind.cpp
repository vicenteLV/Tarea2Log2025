#include <vector>
#include <iostream>

class UnionFind{
    private:
        std::vector<int> padre; //nodo padre del nodo 'i'
        std::vector<int> altura; //altura del arbol en 'i' para union

    public:
        /*
        Constructor: inicializa padre y altura
        define a cada indice como su propio padre inicialmente
        */
        UnionFind(int n) {
            padre.resize(n);
            altura.resize(n, 0);
            for (int i=0; i<n; i++){
                padre[i]=i;
            }
        }

        /*
        funcion find sin optimización
        toma un entero que representa un nodo y devuelve 
        el indice del padre asociado a tal nodo en el arreglo padres
        int -> int
        */
        int find(int x){
            if (padre[x] != x){
                return find(padre[x]);
            }
            else{
                return x;
            }
        }

        int find_opt(int x){
            
        }

        void unir(int x, int y){

        }
};