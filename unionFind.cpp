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

        /*
        funcion que implementa la optimización de find poniendo conectando el nodo
        de interes a su raiz directamente, su input es el indice del nodo
        y su output es el indice de la raiz y nuevo padre
        int -> int */
        int find_opt(int x){
            if(padre[x] != x){
                padre[x] = find_opt(padre[x]);
            } 
            return padre[x];
        }
    
        /*
        funcion para unir dos grupos de nodos, toma las raices de x e y, compara
        sus alturas en el arreglo alturas (rank) para saber que arbol se une al otro
        [int int] -> void
        */
        void unir(int x, int y){
            int raiz_x = find(x);
            int raiz_y = find(y);

            if (raiz_x == raiz_y){
                return;
            }

            if(altura[raiz_x] < altura[raiz_y]){
                padre[raiz_x] = raiz_y;
            } else{
                padre[raiz_y] = raiz_x;
                if(altura[raiz_y] == altura[raiz_x]){
                    altura[raiz_x] += 1;
                }
            }
        }

        /*
        funcion de union que usa find_opt(x) para encontrar raices, resto de la logica es 
        analogo a find(x)
        [int int] -> void
        */
        void unir_opt(int x, int y){
            int raiz_x = find_opt(x);
            int raiz_y = find_opt(y);

            if (raiz_x == raiz_y){
                return;
            }

            if(altura[raiz_x] < altura[raiz_y]){
                padre[raiz_x] = raiz_y;
            } else{
                padre[raiz_y] = raiz_x;
                if(altura[raiz_y] == altura[raiz_x]){
                    altura[raiz_x] += 1;
                }
            }
        }
};