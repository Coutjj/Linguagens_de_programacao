/*
  
  *  Universidade Federal do Rio de Janeiro
  *  Escola Politecnica
  *  Departamento de Eletronica e de Computacao
  *  EEL770 - Linguagens de Programação - Turma 2020/2
  *  Prof: Miguel Elias Mitre Campista
  *  Autor: Juan Coutinho Lima

*/


int fibonacciIndice(int indice){

    int result = 0;
    int numAnteriorGrau1 = 1;
    int numAnteriorGrau2 = 1;

    if (indice == 0){
        return result;
    } 
    
    result = 1;

    for (int contador = 2; contador < indice; contador++){
        result = numAnteriorGrau1 + numAnteriorGrau2;
        numAnteriorGrau2 = numAnteriorGrau1;
        numAnteriorGrau1 = result;
    }

    return result;
}


int fibonacciRecursivo(int indice){

    if (indice == 0){
        return 0;
    }
    else if (indice == 1) {
        return 1;
    }

    return fibonacciRecursivo(indice - 1) + fibonacciRecursivo(indice - 2);
}