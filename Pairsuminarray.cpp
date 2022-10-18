#include <iostream>
#include <algorithm>
int pairSum(int *arr, int n, int num)
{
    int count=0;
    sort(arr, arr+n);
    int i=0, j=n-1;
    while(i < j){
        if(arr[i] + arr[j] == num)
        {
             if(arr[i] == arr[j])
             {
                 count += (j-i+1)*(j-i)/2;
                 return count;
                 
             }
        
            int countI=0, countJ=0, l=i, k=j;
            while(arr[i] == arr[l]){
                l++;
                countI++;
            }
            while(arr[j] == arr[k]){
                k--;
                countJ++;
            }
            count += countI*countJ;
           i = l, j = k;            
        }
        else if(arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;	
}


using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;

		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cin >> x;

		cout << pairSum(input, size, x) << endl;

		delete[] input;
	}
	
	return 0;
}
