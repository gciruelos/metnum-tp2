#include "matriz.h"
#include "matriz_deportes.h"
#include <unistd.h>


bool fst_comp_dec(const std::pair<double, std::string>& a, const std::pair<double,std::string>& b) {
      return a.first > b.first;
}

// la distancia basada en norma 1
double dist_1(std::vector<double> v, std::vector<double> w){
    double dist = 0;
    for(uint i = 0; i<v.size(); i++) 
        dist += fabs(v[i] - w[i]);
    return dist;
}

double norma_1(std::vector<double> v){
    double suma = 0;
    for(uint i = 0; i<v.size(); i++)
        suma += fabs(v[i]);
    return suma;
}


std::vector<double> pagerank(Matriz p_trans, double c, double tolerancia){
    // uso el algoritmo 1 de kamvar et al.
    uint nodes = p_trans.get_nodes();
    std::vector<double> x(nodes, 1./nodes), y, v(nodes, 1./nodes);
    double w;

    uint k = 0;

    std::vector<double> iters;
     
    while(1){
        std::cerr << "iteracion "<< k++ << std::endl;        
        //mostrar_vector(x, std::cout);
        //std::cerr << std::endl; 
        y = p_trans.multiplicar(x);
        for(uint i = 0; i<y.size(); i++)
            y[i] *= c;
    
        w = norma_1(x) - norma_1(y);
 
        for(uint i = 0; i<y.size(); i++)
            y[i] += w*v[i];

        // si la distancia entre Ax y x es menor a tolerancia, terminamos
        // si no, seguimos
        iters.push_back(dist_1(x,y)); 
        
        if(dist_1(x,y) < tolerancia){
            mostrar_vector(iters, std::cout);
            std::cout << std::endl;
            return y;
        }
        else
            x = y;
    }
}


std::vector<uint> indeg(Matriz p_trans){
    return p_trans.get_in_degrees();
}

std::vector<double> metodopot(MatrizDep p, double tolerancia){
    uint nodes = p.get_nodes();
    std::vector<double> x(nodes, 1./nodes), y;
    double n1;
    while(1){
        //std::cerr << "iteracion "<< k++ << std::endl;        
        y = p.multiplicar(x);

        n1 = norma_1(y);
        for(int i = 0; i<y.size(); i++)
            y[i] /= n1;

        // si la distancia entre Ax y x es menor a tolerancia, terminamos
        // si no, seguimos 
        if(dist_1(x,y) < tolerancia)
            return y;
        else
            x = y;
    }
    return y;
}

template <typename T>
void solucion(std::vector<T> v, std::ofstream& solus_file){
    
    for(uint i = 0; i<v.size(); i++)
        solus_file << v[i] << std::endl;
}

void resolver(int tipo_de_instancia,
              int alg, 
              double c, 
              double tolerancia, 
              std::ifstream& red_file,
              std::ofstream& solus_file){

    

    if(red_file.good()){
        std::cerr << "ok!" << std::endl;
    }
    
    if(tipo_de_instancia == 0){ // PAGINAS WEB
        Matriz p_trans(red_file);
        red_file.close();
        if(alg == 0) // PageRank
            solucion(pagerank(p_trans, c, tolerancia), solus_file);
        else // in-deg
            solucion(indeg(p_trans), solus_file);
    } else { // LIGAS DEPORTIVAS
        MatrizDep h_trans(red_file, c);
        red_file.close();
		std::vector<double> res;
        if(alg == 0){ // GeM
            res = metodopot(h_trans, tolerancia);
            solucion(res, solus_file);
			} else {
			res = h_trans.rank_comun();
            solucion(res, solus_file);
			}
    }

    solus_file.close();

}
