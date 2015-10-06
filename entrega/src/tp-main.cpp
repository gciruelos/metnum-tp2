#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "problema.h"




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
    std::ifstream red_file(red_f.c_str(), std::ifstream::in);
    
    // ACA YA ESTA TODO LISTO PARA SER USADO
    std::ofstream solus_file(argv[2], std::ofstream::out);

    resolver(tipo_de_instancia, alg, c, tolerancia, red_file, solus_file);

  
 

 
    return 0;
}

