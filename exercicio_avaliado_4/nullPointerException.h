#include <exception>

using namespace std;

class NullPointerException: public exception {

    public:
        virtual const char *what() const throw (){
            return "Ponteiro nulo.";
        }
};
