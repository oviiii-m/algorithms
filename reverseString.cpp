#include<iostream>
using namespace std;

int main(){
  string str;
  cin>>str;
  int s=0,e=s.size()-1;
  while(s<e){
    swap(str[s],str[e]);
    s++;
    e--;
  }
  cout<<"reversed string"<<" "<<str<<endl;
}
