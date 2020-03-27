#include <iostream>
#include <stdlib.h>
#include "Matrix.h"
using namespace std;

Matrix::Matrix(){
    matrix = alloc(0, 0);
}

Matrix::Matrix(int rows, int cols){
    matrix = alloc(rows, cols);
}

Matrix::~Matrix(){
    dealloc();
}

void Matrix::dealloc(){

}

int ** Matrix::alloc(int rows, int cols){
    x = rows;
    y  = cols;

    int ** new_matrix = new int *[rows];
    for (int row = 0; row<rows; row++){
        new_matrix[row] = new int[cols];
    }
    return new_matrix;
}
// void putToMatrix(int * arr, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols;j++){
//             cin >> *(arr + i*cols +j);
//         }
//     }
// }

// void assignOne2Another(int *a, int *b, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols;j++){
//             *(a + i*cols +j) = *(b + i*cols +j);
//         }
//     }
// }

// void printMatrix(int * arr, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols-1;j++){
//             cout << *(arr+i*cols + j) << " ";
//         }
//         cout << *(arr+i*cols + j);
//         cout << "\n";
//     }
// }

// void sumMatrix(int *d, int *a, int *b, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols;j++){
//             *(d + i*cols +j) = *(a + i*cols +j) + *(b + i*cols +j);
//         }
//     }
// }

// void subMatrix(int *e, int *b, int *a, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols;j++){
//             *(e + i*cols +j) = *(b + i*cols +j) - *(a + i*cols +j);
//         }
//     }
// }

// void mulMatrix(int *f, int *c, int *a, int rows, int cols, int cols_c){
//     int i;
//     int j;
//     int k;
//     for (i=0;i<rows;i++){
//         for (j=0;j<cols;j++){
//             *(f + i*cols +j) = 0;
//             for (k=0; k<cols_c;k++){
//                 *(f + i*cols +j) += *(c + i*cols_c +k) * *(a + k*cols + j);
//             }
//         }
//     }
// }

// void transpMatrix(int *g, int *a, int rows, int cols){
//     int i;
//     int j;
//     for (i=0;i<rows;i++){
//         for(j=0;j<cols;j++){
//            *(g + j*rows +i) = *(a + i*cols +j);
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    Matrix m1;
    cin >> m1;
    cout << m1;

    return 0;
}