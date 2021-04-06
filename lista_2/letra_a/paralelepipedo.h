
class Paralelepipedo {

    public:
        Paralelepipedo (int []);
        void setDim(int []);
        int getVolume();
    private:
        int dimxyz [3] = {1};
        int computeVolume();
};