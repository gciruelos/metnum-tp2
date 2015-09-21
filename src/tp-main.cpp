#include <iostream>
#include <fstream>
#include <vector>
#include <string>



void imprimir_vector(std::vector<double> v){
    std::cout << "[";
    for(int i = 0; i<v.size(); i++){
        std::cout << v[i];
        if(i!=v.size()-1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}


int mi_atoi(char * a){
  if(a[0] == '0') return 0;
  else if(a[0] == '1') return 1;
  else if(a[0] == '2') return 2;
  else if(a[0] == '3') return 3;
  else return -1;
}
 


int main(int argc, char * argv[]){
  /* argv[0] es el nombre del programa
   * argv[1] es el nombre de archivo donde estan los paremetros
   * argv[2] es el archivo de output
   */



    int alg, tipo_de_instancia;
    double c, tolerancia;
    std::string red_f;


    // abrimos el archivo de parametro y cargamos todo
    std::ifstream input_file(argv[1]);
    input_file >> alg >> c  >> tipo_de_instancia >> red_f >> tolerancia;
    input_file.close();


    // abrimos el archivo de la red y lo cargamos
    std::ifstream red_file(red_f);
    red_file.close();
    

    // ACA YA ESTA TODO LISTO PARA SER USADO

  
    std::ofstream f_soluciones(argv[2], std::ofstream::out);

 
    return 0;
}

