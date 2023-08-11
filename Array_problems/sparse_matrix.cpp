#include <iostream>
#include <conio.h>
 
using namespace std;
int main()
{
    cout<<"Enter the dimensions of the matrix: ";
    int m, n;
    cin>>m>>n;
    double mat[m][n];
    int zeros = 0;
    cout<<"Enter the elements of the matrix: ";
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
            if(mat[i][j] == 0)
            {
                zeros++;
            }
        }
    }
    cout << "Matrix:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
 
    if(zeros > (m*n)/2)
    {
        cout<<"The matrix is a sparse matrix";
    }
    else
    {
        cout<<"The matrix is not a sparse matrix";
    }
 
}