#ifndef MATRIZ_DEPORTES_H
#define MATRIZ_DEPORTES_H

#include <vector>
#include <iostream>
#include <utility> // std::pair
#include <map>
#include <sstream>
#include <algorithm>

typedef unsigned int uint;

uint first_node = 1;


class MatrizDep {

public:

    MatrizDep(std::ifstream& in){ 
        uint fecha, equipo1, goles1, equipo2, goles2; 
        uint nodes, edges;

        char numeral; std::string dummy;
        
        in >> nodes >> edges; // leo nodos y edges 
        
        // armo la matriz
        for(uint i = 0; i<nodes; i++)
            m.push_back(std::vector<uint>(nodes, 0));

        for(uint i = 0; i < edges; i++){
             in >> fecha >> equipo1 >> goles1 >> equpo2 >> goles2;
             // los nodos se numeran desde first_node...
             equipo1-=first_node; equipo2-=first_node;    
        }
    

private:
    std::vector<std::vector<uint> >  m;
};

#endif // MATRIZ_DEPORTES_H
