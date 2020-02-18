#include <iostream>
using namespace std;

void putToMatrix(int * arr, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            cin >> *(arr + i*cols +j);
        }
    }
}

void assignOne2Another(int *a, int *b, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            *(a + i*cols +j) = *(b + i*cols +j);
        }
    }
}

void printMatrix(int * arr, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols-1;j++){
            cout << *(arr+i*cols + j) << " ";
        }
        cout << *(arr+i*cols + j);
        cout << "\n";
    }
}

void sumMatrix(int *d, int *a, int *b, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            *(d + i*cols +j) = *(a + i*cols +j) + *(b + i*cols +j);
        }
    }
}

void subMatrix(int *e, int *b, int *a, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            *(e + i*cols +j) = *(b + i*cols +j) - *(a + i*cols +j);
        }
    }
}

void mulMatrix(int *f, int *c, int *a, int rows, int cols, int cols_c){
    int i;
    int j;
    int k;
    for (i=0;i<rows;i++){
        for (j=0;j<cols;j++){
            *(f + i*cols +j) = 0;
            for (k=0; k<cols_c;k++){
                *(f + i*cols +j) += *(c + i*cols_c +k) * *(a + k*cols + j);
            }
        }
    }
}

void transpMatrix(int *g, int *a, int rows, int cols){
    int i;
    int j;
    for (i=0;i<rows;i++){
        for(j=0;j<cols;j++){
           *(g + j*rows +i) = *(a + i*cols +j);
        }
    }
}

int main(int argc, char const *argv[])
{
    int rows;
    int cols;
    int cols_c;

    cin >> rows;
    cin >> cols;
    int a[rows][cols];
    putToMatrix(*a, rows, cols);

    cin >> rows;
    cin >> cols;
    int b[rows][cols];
    putToMatrix(*b, rows, cols);

    cin >> rows;
    cin >> cols_c;
    int c[rows][cols_c];
    putToMatrix(*c, rows, cols_c);

    int d[rows][cols];
    sumMatrix(*d, *a, *b, rows, cols);

    int e[rows][cols];
    subMatrix(*e, *b, *a, rows, cols);

    int f[rows][cols];
    mulMatrix(*f, *c, *a, rows, cols, cols_c);

    int g[cols][rows];
    transpMatrix(*g, *a, rows, cols);

    printMatrix(*d, rows, cols);
    printMatrix(*e, rows, cols);
    printMatrix(*f, rows, cols);
    printMatrix(*g, cols, rows);

    return 0;
}