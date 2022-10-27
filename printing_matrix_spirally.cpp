#include <iostream>
using namespace std;

/*printing matrix spirally*/



void spiralPrint(int **arr, int nrows, int mcols)
{
    int i=0,j=0,l=0;
    int count=nrows*mcols;
    while(count>0){
        while(j<mcols){
            cout<<arr[i][j]<<" ";
            j++;
            count--;
        }
        if(count==0)
            break;
        
        j--;
        int k=i;
        i++;
        while(i<nrows){
            cout<<arr[i][j]<<" ";
            i++;
            count--;
        }
        if(count==0)
            break;
        
        i--;
        j--;
        while(j>=l){
            cout<<arr[i][j]<<" ";
            j--;
            count--;
        }
        if(count==0)
            break;
        
        j++;
        i--;
        while(i>k){
            cout<<arr[i][j]<<" ";
            i--;
            count--;
        }
        
        j++;
        i++;
        mcols--;
        nrows--;
        l++;
        
        
    }
}

int main()
{


        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    
}
