#include <iostream>
#include <algorithm>
using namespace std;
int tripletSum(int *arr, int n, int num)
{
    int ans = 0;
 int check;
 sort(arr,arr+n);
	//Write your code here
 int k = 0;
 for(k=0; k<n-2; k++)
 {
     check = num - arr[k];
     
 
 int i = k+1; 
 int j = n-1;
 while(i<j)
 {
     if(arr[i] + arr[j] < check)
     {
         i++;
     }
     else if (arr[i] + arr[j] > check)
     {
         j--;
     }
     else
     {
         if(arr[i] == arr[j])
         {
             ans += (j-i)*(j-i+1)/2;
             break;
         }
         int cnt1 = 1;
         while(arr[i] == arr[i+1])
         {
             i++;
             cnt1++;
         }
         i++;
         int cnt2 = 1;
         while(arr[j] == arr[j-1])
         {
             j--;
             cnt2++;
         }
         j--;
        ans += cnt1*cnt2; 
     }
 }
 }
 return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
