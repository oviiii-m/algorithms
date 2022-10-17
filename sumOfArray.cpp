#include<iostream>
using namespace std;

int sum(int input[], int n) 
{int sum=0;
   for(int i=0;i<n;i++){
       sum+=input[i];
   }
    return sum;
}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    cout << sum(input, n) << endl;
}


