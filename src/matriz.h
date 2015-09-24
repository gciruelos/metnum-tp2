#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>
#include <iostream>
#include <utility> // std::pair
#include <map>
#include <sstream>
#include <algorithm>

typedef unsigned int uint;


bool fst_comp(const std::pair<uint,uint>& a, const std::pair<uint,uint>& b) {
      return a.first < b.first;
}


template <typename T>
void mostrar_vector(std::vector<T> v, std::ostream& o){
    o << "{";
    for(uint i = 0; i < v.size(); i++){
        if(i > 0) o << ", "; 
        o << v[i];
    }
    o << "}";
}

uint first_node = 1;


class Matriz {

public:

    Matriz(std::ifstream& in){
        uint tamano = 0;
        uint from, to;
        std::string line;
        uint nodes, edges;

        char numeral; std::string dummy;

        std::getline(in, line); // titulo
        std::getline(in, line); // fuente
        std::getline(in, line); // nodos y links

        std::istringstream iss(line);
        iss >> numeral >> dummy >> nodes >> dummy >> edges; // leo nodos y edges
        std::getline(in, line); // mas info
        
        // son las filas de la matriz,  v[i] te da una lista 
        // de pares <columna, valor>
        std::vector<std::vector<std::pair<uint, int> > > Ptrans_lil(nodes, 
                std::vector<std::pair<uint,int> > ());

        for(uint i = 0; i < nodes; i++){
            out_degrees.push_back(0);
            in_degrees.push_back(0);
        }
        
        for(uint i = 0; i < edges; i++){
             in >> from >> to;
             // los nodos se numeran desde first_node...
             from-=first_node; to-=first_node;    
             Ptrans_lil[to].push_back(std::make_pair(from, 1));
             out_degrees[from]++;
             in_degrees[to]++;
        }
       
        // http://netlib.org/linalg/html_templates/node91.html   CRS
        // https://de.wikipedia.org/wiki/Compressed_Row_Storage  esta en aleman
        // pero tiene lindos dibujitos
        // itero sobre las filas, voy a ir completando [val], col_ind y row_ptr
        row_ptr.push_back(0);
        for(uint i = 0; i < Ptrans_lil.size(); i++){
            std::vector<std::pair<uint, int> > fila_i = Ptrans_lil[i];
            std::sort(fila_i.begin(), fila_i.end(), fst_comp);
            for(uint j = 0; j < fila_i.size(); j++){
                col_ind.push_back((fila_i[j]).first);
            }
            row_ptr.push_back(row_ptr[i] + fila_i.size());
        }
    }



    std::vector<double> multiplicar(std::vector<double> x) const{
        std::vector<double> y(x.size(), 0);
      
        //mostrar_vector(x, std::cerr); std::cerr << std::endl;
        //mostrar_vector(y, std::cerr); std::cerr << std::endl;
        
        // elementos non zero
        uint nnz = row_ptr[row_ptr.size()-1];
        uint fila_actual = 0;
        uint accum = 0;
        for(uint i = 0; i < nnz; i++){ 
            if(i == row_ptr[fila_actual+1]){ //termine esta fila 
                fila_actual++;
                accum = 0;
            }
            // y_k = \sum_i P^t_ki * x_i    , P^t_ki = 1/deg(i)
            y[fila_actual] += x[col_ind[i]] / out_degrees[col_ind[i]]; 
        }
        return y;
    }


    void mostrar() const{
        std::cerr << "col_ind = ";
        mostrar_vector(col_ind, std::cerr);
        std::cerr << std::endl;

        std::cerr << "row_ptr = ";
        mostrar_vector(row_ptr, std::cerr);
        std::cerr << std::endl;

        std::cerr << "out_degrees = ";
        mostrar_vector(out_degrees, std::cerr);
        std::cerr << std::endl;
    }

    std::vector<uint> get_in_degrees() const{
        return in_degrees;
    }

    uint get_nodes() const{
        return in_degrees.size(); // medio cabeza
    }


private:
    std::vector<uint> out_degrees;
    std::vector<uint> in_degrees;
    std::vector<uint> val;  //no lo vamos a usar
    std::vector<uint> col_ind;
    std::vector<uint> row_ptr;
};

#endif // MATRIZ_H
