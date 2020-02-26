#include <iostream> 
#include <cmath>
using namespace std;

void putToMatrix(float * arr, int rows, int cols)
{
    int i;
    int j;
    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
            cin >> *(arr + i*cols +j);
    }
}

void printMatrix(float * arr, int rows, int cols)
{
    int i;
    int j;
    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols-1;j++)
            cout << *(arr+i*cols + j) << " ";
        cout << *(arr+i*cols + j);
        cout << "\n";
    }
}

int max_pivot(float *mat, int rows, int cols, int col){
    int i;
    int res = -1;
    float max = -1000000;
    float elem;
    for(i=0; i<rows;i++)
    {
        elem = abs(*(mat + i*cols + col));
        if (elem > max)
        {
            max = elem;
            res = i;
        }
    }
    return res;
}


void permutation(float *mat, int cols, int row1, int res)
{
    int i;
    int j;
    float arr[1][cols];
    for (j=0; j<cols;++j)
    {
        arr[1][j] = *(mat + row1*cols + j);
        *(mat + row1*cols + j) = *(mat + res*cols + j);
        *(mat + res*cols + j) = arr[1][j];
    }
}

void elemenation(float *mat, int rows, int cols, int col)
{
    int i;
    int j;
    float alpha;
    for (i = col; i < rows-1; ++i)
    {
        alpha = (*(mat + (i+1)*cols + col))/(*(mat + col*cols + col));
        for (j = 0;j < cols; j++)
        {
            cout << "";
            *(mat + (i+1)*cols + j) -= alpha*(*(mat + col*cols + j));
            *(mat + (i+1)*cols + j) = round(*(mat + (i+1)*cols + j) * 100.0) / 100.0;
        }
    }
}

void gauss_elem(float *mat, int rows, int cols){
    int i;
    int res;
    for (i = 0; i<cols-1; ++i)
    {
        res = max_pivot(mat, rows, cols, i);
        if (i!=res)
        {
            cout << "step #" << i+1 << ": " << "permutation" << endl;
            permutation(mat, cols, i, res);
            printMatrix(mat, rows, cols);
        }
        cout << "step #" << i+1 << ": " << "elimination" << endl;
        elemenation(mat, rows, cols, i);
        printMatrix(mat, rows, cols);
    }
}

float det_upp(float *mat, int rows)
{
    float res = 1;
    int i;
    int cols = rows;
    for (i=0;i<cols;++i)
        res *= *(mat + i*cols + i);
    return res;
}

int main(int argc, char const *argv[])
{
    int rows;
    int cols;
    float res;

    cin >> rows;
    cols = rows;
    float a[rows][cols];
    putToMatrix(*a, rows, cols);
    gauss_elem(*a, rows, cols);
    res = det_upp(*a, rows);
    cout << "result:" << endl;
    cout << res << endl;
    return 0;
}