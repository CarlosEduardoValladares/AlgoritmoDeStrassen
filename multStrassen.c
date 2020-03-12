#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printMatrix(int size, int*matrix){

  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++){
      printf("%d ", *((matrix+i*size)+j));
    }
    printf("\n");
  }

}

int *multStrassen(int size, int *matrix){

  

  return matrix;

}

int main(int argc, char* argv[]){

    int input;
    int size;
    for(int i = 0; i < argc; i++){

        if( strcmp(argv[i], "-n") == 0){

            char *ptr;
            if (strtol(argv[i+1], &ptr, 10) <= 0){

                printf("Erro: O formato esperado é: -n <número positivo>\n");
                return 0;

            } else {

                input = strtol(argv[i+1], &ptr, 10);
                printf("Valor: %d\n", input);

                int exp = floor((log(input)/log(2))+1);
                /* como não existe uma função log na base 2,
                uso a propriedade: log(x)/log(2) é log(x) na base 2 */

                size = pow(2, exp);
                if(size%input == 0){
                    size = pow(2, exp-1);
                    // Quando o tamanho é potência de 2, não é preciso aumentar a matriz

                }

                printf("O cálculo será feito em uma matriz %d x %d\n", size, size);
                /* Toda essa conta é feita porque o algoritmo só
                funciona para matrizes que tenham tamanhos que
                sejam potência de 2 */

            }
        }

    }

    int matriz[size][size];

    for(int i = 0; i < size; i++){
      for(int j = 0; j < size; j++){
        if(j < input && i < input){
          matriz[i][j] = 1;
        } else {
          matriz[i][j] = 0;

        }
      }
    }

    printMatrix(size, (int *)matriz);

    return 0;
}
