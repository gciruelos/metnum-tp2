#ifndef MATRIZ_DEPORTES_H
#define MATRIZ_DEPORTES_H

#include <vector>
#include <iostream>
#include <utility> // std::pair
#include <map>
#include <sstream>
#include <algorithm>

typedef unsigned int uint;

class MatrizDep {

public:

    MatrizDep(std::ifstream& in, double c){ 
        uint fecha, equipo1, goles1, equipo2, goles2; 
        uint nodes, edges;


        char numeral; std::string dummy;
        
        in >> nodes >> edges; // leo nodos y edges 
        
        std::vector<std::vector<double> >  h;

        // armo la matriz
        for(uint i = 0; i<nodes; i++){
            h.push_back(std::vector<double>(nodes, 0));
            m.push_back(std::vector<double>(nodes, 0));
        }


        for(uint i = 0; i < edges; i++){
             in >> fecha >> equipo1 >> goles1 >> equipo2 >> goles2;
             // los nodos se numeran desde 1...
             equipo1--; equipo2--;
             if(goles1 > goles2){
                 h[equipo2][equipo1] += goles1-goles2;
             } else if (goles1 < goles2){
                 h[equipo1][equipo2] += goles2-goles1;
             } else {
                 // ver que hacemos con el empate, por ahora nada
             }
        }

        // normalizo segun lo que dice GeM 
        std::vector<double> goles;
        for(int i = 0; i<nodes; i++){
            double accum = 0;
            for(int j = 0; j<nodes; j++){
                accum+=h[i][j];
            }
            goles.push_back(accum);
        }
        mostrar_vector(goles, std::cerr);
        std::cerr << std::endl;

        double eps = 0.00001; //si un numero es menor que esto, lo considero 0
        for(int i = 0; i<nodes; i++){
            for(int j = 0; j<nodes; j++){
                if(goles[i]<eps){
                    h[i][j] = 1.0/nodes;
                } else {
                    // ver paper para esta cuenta
                    h[i][j] = c * h[i][j] / goles[i]  +  (1-c) / nodes;
                }
            } 
        }
        // m es h transpuesta
        for(int i = 0; i<nodes; i++){
            for(int j = 0; j<nodes; j++){
                m[i][j] = h[j][i];
            } 
        }


        /*
        for(int i = 0; i<nodes; i++){
            mostrar_vector(m[i], std::cerr);
            std::cerr << std::endl;
        }*/

        std::cerr << "listo" << std::endl;
    }

    uint get_nodes(){
        return m.size();
    }

    std::vector<double> multiplicar(std::vector<double> x){
        std::vector<double> y;

        for(uint i = 0; i<m.size(); i++){
            double accum = 0;
            for(uint j = 0; j<m[i].size(); j++){
                accum += x[j] *((double) m[i][j]);
            }
            y.push_back(accum);
        }
        return y;
    }



    

private:
    std::vector<std::vector<double> >  m;
};

#endif // MATRIZ_DEPORTES_H
