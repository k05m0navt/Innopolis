#include <iostream> 
#include <cmath>
#include<iomanip>
using namespace std;

void putToMatrix(float * arr, int rows, int cols)
{
    int i;
    int j;

    for (i=0;i<rows;i++)
    {
        for(j=0;j<cols/2;j++)
            cin >> *(arr + i*cols +j);
    }

    for (i=0;i<rows;i++)
    {
        for(j=cols/2;j<cols;j++)
        {
            if (i + cols/2 == j)
                *(arr + i*cols +j) = 1;
            else
                *(arr + i*cols +j) = 0;
        }
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

int max_pivot(float *mat, int rows, int cols, int col)
{
    int i;
    int res = -1;
    float max = -1000000;
    float elem;

    cols = cols/2;
    for(i=col; i<rows;i++)
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

void elemenation(float *mat, int rows, int cols, int k, int i)
{
    int j;
    float alpha;
    alpha = (*(mat + (k+1)*cols + i))/(*(mat + i*cols + i));
    for (j = 0;j < cols; ++j)
    {
        cout << "";
        *(mat + (k+1)*cols + j) -= alpha*(*(mat + i*cols + j));
        *(mat + (k+1)*cols + j) = round(*(mat + (k+1)*cols + j) * 100.0) / 100.0;
    }
    printMatrix(mat, rows, 2*cols);
}

void gauss_elem(float *mat, int rows, int cols)
{
    int i;
    int j;
    int k;
    int count_test;
    int res;
    float alpha;

    cols = cols/2;
    count_test = 0; 
    for (i = 0; i<cols-1; ++i)
    {
        res = max_pivot(mat, rows, cols, i);
        if (i!=res)
        {
            cout << "step #" << count_test+1 << ": " << "permutation" << endl;
            permutation(mat, 2*cols, i, res);
            printMatrix(mat, rows, 2*cols);
        }
        for (k = i; k < rows-1; k++)
        {
            cout << "step #" << count_test+1 << ": " << "elimination" << endl;
            elemenation(mat, rows, cols, k, i);
            count_test++;
            cout << "";
        }
    }
}

void jord_elem(float *mat, int rows, int cols)
{
    int i;
    int j;
    int k;
    int count_test;
    int res;
    float alpha;

    cols = cols/2;
    count_test = 0;
    for (i = cols - 1; i > 0; --i)
    {
        res = max_pivot(mat, rows, cols, i);
        if (i!=res)
        {
            cout << "step #" << count_test+1 << ": " << "permutation" << endl;
            permutation(mat, cols, i, res);
            printMatrix(mat, rows, cols);
        }
        for (k = i; k > 0; k++)
        {
            cout << "step #" << count_test+1 << ": " << "elimination" << endl;
            elemenation(mat, rows, cols, k, i);
            count_test++;
            cout << "";
        }
    }
}

int main(int argc, char const *argv[])
{
    cout << fixed;
    cout << setprecision(2);
    int rows;
    int cols;
    float res;

    cin >> rows;
    cols = rows;
    float a[rows][2*cols];
    putToMatrix(*a, rows, 2*cols);
    cout << "step #0: Augmented Matrix" << endl;
    printMatrix(*a, rows, 2*cols);
    gauss_elem(*a, rows, 2*cols);
    return 0;
}    