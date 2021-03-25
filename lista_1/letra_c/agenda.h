#include <iostream>
#include <string>


using namespace std;


class Agenda {
    public:
        void setNames ();
        void getNames ();
    private:
        string names[3];
        string checkName(string);
};