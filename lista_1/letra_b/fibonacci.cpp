class Fibonacci {

    public:
        
        void setFibonacci(int valor){
            indice = valor;
            computeFibonacci();
        }

        int getFibonnaci(){
            return resultado;
        }

    private:
        int indice;
        int resultado = 0;
        int numAnteriorGrau1 = 1;
        int numAnteriorGrau2 = 1;

        void computeFibonacci(){

            for(int contador = 2; contador < indice; contador++){
                resultado = numAnteriorGrau1 + numAnteriorGrau2;
                numAnteriorGrau2 = numAnteriorGrau1;
                numAnteriorGrau1 = resultado;
            }

            
        }
};