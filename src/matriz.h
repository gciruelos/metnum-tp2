/*
 * P_2 = c P_1 + (1-c) E
 *     = c P + c D + (1-c) E
 *
 * col_j(P_2) = col_j(c P) + col_j(c D) + col_j((1-c) E)
 *
 *                   /
 *                  /                0                c/n                 (1-c)/n
 *                 /                 0                c/n                 (1-c)/n
 *                /                  .                 .                     .
 *    si n_j = 0 /      col_j(c P) = .   col_j(c D) =  .    col_j((1-c) E) = .
 *               \                   .                 .                     .
 *                \                  0                c/n                 (1-c)/n
 *                 \                 0                c/n                 (1-c)/n
 *                  \
 *                   \
 *                     
 *                     entonces queda    col_j(P_2) = (1/n, ..., 1/n)
 *                                      
 *                                      o sea, (P_2)_ij = 1/n
 *
 *
 *
 *                  /
 *                 /          c w_1j/n_j        c (1-w_1j)/n              (1-c)/n
 *                /           c w_2j/n_j        c (1-w_2j)/n              (1-c)/n
 *               /               .                   .                       .
 *   si n_j > 0 /   col_j(c P) = .     col_j(c D) =  .      col_j((1-c) E) = .
 *              \                .                   .                       .
 *               \               .                   .                    (1-c)/n
 *                \              .                   .                    (1-c)/n
 *                 \
 *                  \
 *                     
 *                                                /     1/n               si w_ij = 0
 *         entonces   col_j(P_2)_i  = (P_2)_ij = / 
 *                                               \
 *                                                \     c/n_j + (1-c)/n   si w_ij = 1
 *
 *
 *     Entonces, se puede almacenar facil por columnas o como diccionario, 
 *     si se tiene w_ij y n_j.
 *
 *     Lo que se puede hacer es guardar W en un diccionario, y despues ir iterandola y
 *     si una entrada esta definida, poner   c/n_j + (1-c)/n
 *
 *
 *     Luego, cuando te piden un valor, te fijas si está definido en el diccionario.
 *         
 *          si no esta definido, devolves    1/n
 *          si esta definido, devolves      M(i,j)
 *
 *
 *     Y listo,
 *      ahora queda solo implementarlo, pero es MUY facil
 *    
 *
 */




