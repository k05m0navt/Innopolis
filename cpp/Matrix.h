#include <iostream>
using namespace std;

class Matrix{
    public:
        int **matrix;
        Matrix();

        Matrix(int x, int y);

        ~Matrix();

        int ** setSize(int x, int y);

        int * getMatrix();

        int ** alloc(int x, int y);

        friend istream & operator >> (istream &in, Matrix& m){
            int i;
            int j;
            for (i=0;i<x;i++)
                for(j=0;j<y;j++)
                    in >> *(m.matrix + i*y +j);
            return in;
        } 

        friend ostream & operator << (ostream &out, Matrix& m){
            for (i=0;i<x;i++){
                for(j=0;j<y-1;j++){
                    out << *(m.matrix+i*y + j) << " ";
                }
                out << *(m.matrix+i*y + j);
                out << "\n";
            }

            return out;
        }

        Matrix& operator =(Matrix& m){
            Matrix data;
            data.matrix = m.matrix;
            return data;
        }

        void dealloc();
    private:
        int x;
        int y;
};