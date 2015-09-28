#include "matriz.h"
#include "matriz_deportes.h"
#include <unistd.h>



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


double dist_2(std::vector<double> v, std::vector<double> w){
    double dist = 0;
    for(uint i = 0; i<v.size(); i++) 
        dist += pow(v[i] - w[i], 2);
    return sqrt(dist);
}

double norma_2(std::vector<double> v){
    double suma = 0;
    for(uint i = 0; i<v.size(); i++)
        suma += v[i]*v[i];
    return sqrt(suma);
}

std::vector<double> pagerank(Matriz p_trans, double c, double tolerancia){
    // uso el algoritmo 1 de kamvar et al.
    uint nodes = p_trans.get_nodes();
    std::vector<double> x(nodes, 1./nodes), y, v(nodes, 1./nodes);
    double w;

    uint k = 0;
     
    while(1){
        //std::cerr << "iteracion "<< k++ << std::endl;        
        mostrar_vector(x, std::cout);
        std::cerr << std::endl;
        usleep(100000);
        y = p_trans.multiplicar(x);
        for(uint i = 0; i<y.size(); i++)
            y[i] *= c;
    
        w = norma_1(x) - norma_1(y);
 
        for(uint i = 0; i<y.size(); i++)
            y[i] += w*v[i];

        // si la distancia entre Ax y x es menor a tolerancia, terminamos
        // si no, seguimos
        std::cerr << dist_1(x,y) <<std::endl;
        if(dist_1(x,y) < tolerancia)
            return y;
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
    double n2;
    while(1){
        //std::cerr << "iteracion "<< k++ << std::endl;        
        y = p.multiplicar(x);

        n2 = norma_1(y);
        for(int i = 0; i<y.size(); i++)
            y[i] /= n2;

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
    //std::cerr << "solucion! ";
    //mostrar_vector(v, std::cerr);
    //std::cerr << std::endl;
    
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
        p_trans.mostrar();
        red_file.close();
        if(alg == 0) // PageRank
            solucion(pagerank(p_trans, c, tolerancia), solus_file);
        else // in-deg
            solucion(indeg(p_trans), solus_file);
    } else { // LIGAS DEPORTIVAS
        MatrizDep h_trans(red_file, c);
        red_file.close();
        if(alg == 0) // GeM
            solucion(metodopot(h_trans, tolerancia), solus_file);
        else // to be decided
            ;
    }

    solus_file.close();

}
