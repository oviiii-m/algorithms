#include<iostream>
using namespace std;
int linear_search(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        return i;
    }
    return -1;
}
int main()
{
    cout<<"enter the number of elements in array ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter the numbers ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter the the number you want to search ";
    int key ;
    cin>>key;
    cout<<"the element is at position "<<linear_search(arr,n,key);
}