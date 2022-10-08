#include <iostream>
using namespace std;

void helper(int input[], int si, int mid, int ei)
{
    int *temp = new int[ei-si+1];
    int i=si, j=mid+1, k=0;
    while(i <= mid && j <= ei){
        if(input[i] < input[j]){
            temp[k++] = input[i++];
        }
        else{
            temp[k++] = input[j++];
        }
    }
    while(i <= mid){
        temp[k++] = input[i++];
    }
    while(j <= ei){
        temp[k++] = input[j++];
    }
    k = 0;
    for(int i=si; i<=ei; i++){
        input[i] = temp[k++];
    }
    return;
}

void merge(int input[], int si, int ei)
{
    if(si >= ei){
        return;
    }
    int mid = (si+ei)/2;
    merge(input, si, mid);
    merge(input, mid+1, ei);
    helper(input, si, mid, ei);
}

void mergeSort(int input[], int size){
	merge(input, 0, size-1);        
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
