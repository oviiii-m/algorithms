#include<iostream>
using namespace std;
int linearSearch(int* arr,int n,int x){
  for(int i=0;i<n;i++){
    if(arr[i]==x)
      // we'll return the index i if we found the x in that array
      return i;
  }
  // we'll return -1 if are unable to find the x in the given array
  return -1;
}
int main(){
 int num;
  cin>>num;
  int* arr=new int[num];
  //taking num values of inputs in array
  for(int i=0;i<num;i++){
        cin>>arr[i];
  }

  int x;
  cin>>x;
  //this will return index of element x
  cout<<linearSearch(arr,num,x);
}
