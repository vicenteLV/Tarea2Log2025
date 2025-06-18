#ifndef KRUSKAL_H
#define KRUSKAL_H

#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <queue>
#include "arista.h"

class UnionFind;

using namespace std;

vector<Arista> MST_arreglo(vector<Arista> aristas_ordenadas, UnionFind& nodos, bool optimizacion);

vector<Arista> MST_heap(priority_queue<Arista,vector<Arista>,greater<Arista>> heap,
    UnionFind& nodos, bool optimizacion);


#endif