# Tarea2Log2025
Diseño y Análisis de Algoritmos Tarea 2

Este proyecto implementa y evalúa experimentalmente cuatro variantes del algoritmo de Kruskal para encontrar el árbol cobertor mínimo (MST) de grafos completos generados aleatoriamente. El estudio compara el rendimiento entre diferentes estructuras de datos (arreglo ordenado vs heap) y optimizaciones (con y sin path compression en Union-Find).

Archivos de código:
- arista.h: Define la estructura Arista con operadores de comparación para ordenamiento y uso en heaps.
- kruskal.h: Declaraciones de las funciones principales del algoritmo de Kruskal.
- unionFind.cpp: Implementación de la estructura Union-Find con operaciones estándar y optimizadas (path compression).
- random.cpp: Funciones para generar nodos aleatorios y construir estructuras de aristas (arreglo ordenado y heap).
- kruskal.cpp: Implementaciones de las cuatro variantes del algoritmo de Kruskal.
- main.cpp: Programa principal que ejecuta los experimentos y genera los resultados.

Resultados
- resultados_kruskal.csv: Archivo con los tiempos de ejecución medidos para cada variante del algoritmo con diferentes tamaños de entrada (2^5 a 2^12 nodos). Este archivo contiene los datos experimentales utilizados para generar los gráficos y análisis presentados en el informe del proyecto.

Librerías usadas (librería estándar C++)
- vector: Contenedores dinámicos para nodos y aristas.
- algorithm: Función sort() para ordenamiento de aristas.
- queue: Cola de prioridad (priority_queue) para implementación de heap.
- random: Generador de números aleatorios para coordenadas de nodos.
- chrono: Medición precisa de tiempos de ejecución.
- iostream: Entrada y salida estándar.
- fstream: Escritura del archivo CSV con resultados.
- utility: Tipo pair para coordenadas de nodos.
- cmath, ctime, cstdlib: Funciones matemáticas y de sistema.

Compilación y ejecución

- Compilador: g++ (GNU Compiler Collection) versión 9.0 o superior.
- Sistema: compatible con Windows (WSL).

Para compilar ejecutar este comando en la raiz dell repositorio

´´´
g++ -o main main.cpp
´´´

Para ejecutar los experimentos

´´´
./main
´´´

Notas
- El programa ejecuta automáticamente todos los experimentos (tamaños de 2^5 a 2^12 nodos, 5 repeticiones cada uno).
- El tiempo de ejecución total puede (o no) ser de varios minutos, especialmente para los casos más grandes.
- Los resultados se guardan automáticamente en resultados_kruskal.csv.
- El progreso se muestra en consola durante la ejecución.

Para pruebas rápidas se puede modificar el archico main.cpp (línea del bucle for(int exp=5; exp <= 12; exp++)) ajustando los límites del exponente.