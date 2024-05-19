#include "../headers/dijkstra.hpp"
#include "../headers/queue.hpp"
#include <vector>
#include <tuple>
#include <float.h>



std::tuple<std::vector<int>, std::vector<double>> dijkstra::dijkstra(const Graph& g, Queue& q){
    /* 1. Definimos dos arreglos de tamaño |V |, distancias y previos. */
    std::vector<int> previos(g.edges.size(), -1);
    std::vector<double> distancias(g.edges.size(), DBL_MAX);

    /* 3. Definimos la distancia del nodo raíz como 0, su nodo previo como −1, 
        y agregamos el par (distancia = 0, nodo = raíz) a Q */
    distancias[0] = 0;
    previos[0] = -1;
    q.push(0, 0);

    /*4. Por cada nodo v distinto de la raíz en el grafo:
        • Definimos distancias[v] como infinita y previos[v] como indefinido.
        • Agregamos el par (distancia = ∞, nodo = v) a Q. */
    for(int v = 1; v < g.edges.size(); v++){
        distancias[v] = DBL_MAX;
        previos[v] = -1;
        q.push(v, DBL_MAX);
    }

    /* 5. Se espera que la creación de Q se resuelva por medio de un Heapify, que transforme un array
        con las distancias en una cola en tiempo lineal (O(n)).*/
    /** hacer push y listo :v ??*/
    

    /* 6. Mientras Q no se encuentre vacío, repetimos: */
    while(!q.empty()){
        /* a) Obtenemos el par (d, v) con menor distancia en Q y lo eliminamos. */
        auto [v, d] = q.extractMin();

        /* b) Por cada vecino u del nodo v: */
        for(auto [u, w] : g.edges[v]){
            /* i. Si la distancia guardada para u (distancias[u]) es mayor a la distancia guardada para
            v (distancias[v]) más el peso de la arista (u, v), actualizamos el valor de la distancia
            de u, guardamos v como el nodo previo de u y actualizamos la distancia del par que
            representa al nodo u en Q utilizando decreaseKey. */
            if(distancias[u] > distancias[v] + w){
                distancias[u] = distancias[v] + w;
                previos[u] = v;
                q.decreaseKey(u, distancias[u]);
            }
        } 
    }


    /* 7. Retornamos el arreglo de previos y distancias.  */
    return std::make_tuple(std::move(previos), std::move(distancias));
}