#include "matriz.h"


// la distancia basada en norma 1
double dist_1(std::vector<double> v, std::vector<double> w){
    double dist = 0;
    for(uint i = 0; i<v.size(); i++) 
        dist += fabs(v[i] - w[i]);
}

double norma_1(std::vector<double> v){
    double suma = 0;
    for(uint i = 0; i<v.size(); i++)
        suma += fabs(v[i]);
    return suma;
}


std::vector<double> pagerank(Matriz m, double c, double tolerancia){
    // uso el algoritmo 1 de kamvar et al.
    uint nodes = m.get_nodes();
    std::vector<double> x(nodes, 1./nodes), y, v(nodes, 1./nodes);
    double w; 
    

 
    while(1){
        y = m.multiplicar(x);
        for(uint i = 0; i<y.size(); i++)
            y[i] *= c;
    
        w = norma_1(x) - norma_1(y);
   
    
        for(uint i = 0; i<y.size(); i++)
            y[i] += w*v[i];

        // si la distancia entre Ax y x es menor a tolerancia, terminamos
        // si no, seguimos
        if(dist_1(x,y) < tolerancia)
            return y;
        else
            x = y;
    }
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

    

    //if(red_file.good()){
    //    std::cerr << "ok!" << std::endl;
   // }
    
    if(tipo_de_instancia == 0){ // PAGINAS WEB
        Matriz m(red_file);
        m.mostrar();
        red_file.close();
        if(alg == 0) // PageRank
            solucion(pagerank(m, c, tolerancia), solus_file);
        else 
            ;// in-deg
    }

    solus_file.close();

}
