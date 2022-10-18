#include <iostream>
using namespace std;
void reverse(int input[],int si,int ei)
{
    int i=si, j=ei;
    while(i <= j){
        int temp = input[i];
        input[i] = input[j];
        input[j] = temp;
        i++;
        j--;
    }  
    
}

void rotate(int *input, int d, int n)
{
    int start=0, end=n-1;
    reverse(input,start, end);
    reverse(input,start, end-d);
    reverse(input,end-d+1,end);
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
