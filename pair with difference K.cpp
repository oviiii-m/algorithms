#include <bits/stdc++.h>

using namespace std;

bool binary(int a[],int k,int low,int high)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(a[mid]<k) 
            low=mid+1;
        else if(a[mid]>k) 
            high=mid-1;
        else return true;
    }
    return false;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,f=0;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<n;i++)
       {
            int s=a[i]+k;
         if(binary(a,s,0,n-1)) 
         { 
             f=1;break;
         }
        }
        if(f==0) 
            cout<<"false\n";
        else
            cout<<"true\n";

    }
    return 0;

}