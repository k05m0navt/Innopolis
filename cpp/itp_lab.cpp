#include <iostream>
#include <stdlib.h> 
using namespace std;

void putToMatrix(float * arr, int rows, int cols){
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

void printMatrix(float * arr, int rows, int cols){
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


int max_pivot(float *mat, int rows, int cols, int col){
    int i;
    int res = -1;
    float max = -1000000;
    float elem;
    for(i=0; i<rows;i++){
        elem = abs(*(mat + i*cols + col));
        if (elem > max){
            max = elem;
            res = i;
        }
    }
    return res;
}

void pivoting(float *mat, int cols, int row1, int res){
    int i;
    int j;
    int arr[1][cols];
    for (j=0; j<cols;j++){
        arr[1][j] = *(mat + row1*cols + j);
        *(mat + row1*cols + j) = *(mat + res*cols + j);
        *(mat + res*cols + j) = arr[1][j];
    }
}

void elemenation(float *mat, int rows, int cols, int col){
    int i;
    int j;
    float alpha;
    for (i = col; i < rows-1; ++i){
        alpha = (*(mat + (i+1)*cols + col))/(*(mat + col*cols + col));
        for (j = 0;j < cols; j++){
            *(mat + (i+1)*cols + j) -= alpha*(*(mat + col*cols + j));
        }
    }
}

void gauss_elem(float *mat, int rows, int cols){
    int i;
    int res;
    for (i = 0; i<cols-1; ++i){
        res = max_pivot(mat, rows, cols, i);
        cout << "step #" << i+1 << ": " << "permutation" << endl;
        pivoting(mat, cols, i, res);
        printMatrix(mat, rows, cols);
        
        cout << "step #" << i+1 << ": " << "elimination" << endl;
        elemenation(mat, rows, cols, i);
        printMatrix(mat, rows, cols);
    }
}

int main(int argc, char const *argv[])
{
    int rows;
    int cols;
    int cols_c;
    int res;

    cin >> rows;
    cols = rows;
    float a[rows][cols];
    putToMatrix(*a, rows, cols);
    gauss_elem(*a, rows, cols);
    return 0;
}
