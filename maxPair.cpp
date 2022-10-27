#include<bits/stdc++.h>
using namespace std;
struct node{
    int max;
    int smax;
};
void buildtree(int* arr,node* tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].max=arr[start];
        tree[treeNode].smax=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    buildtree(arr,tree,start,mid,treeNode*2);
    buildtree(arr,tree,mid+1,end,(treeNode*2+1));
    node left=tree[treeNode*2];
    node right=tree[treeNode*2+1];
    tree[treeNode].max=max(left.max,right.max);
    tree[treeNode].smax=min(max(left.max,right.smax),max(right.max,left.smax));
    return;
}

void update(int* arr,node* tree,int start,int end,int treeNode,int index,int value){
    if(start==end){
        arr[index]=value;
        tree[treeNode].max=arr[start];
        tree[treeNode].smax=INT_MIN;
        return;
    }
    int mid=(start+end)/2;
    if(index<=mid)
        update(arr,tree,start,mid,treeNode*2,index,value);
    else
        update(arr,tree,mid+1,end,treeNode*2+1,index,value);
    node left=tree[treeNode*2];
    node right=tree[treeNode*2+1];
    tree[treeNode].max=max(left.max,right.max);
    tree[treeNode].smax=min(max(left.max,right.smax),max(right.max,left.smax));
    return;  
}
node query(node* tree,int start,int end,int treeNode,int left,int right){
    if (start > right || end < left)// range is completely outside
    {
        node ans;
        ans.max=INT_MIN;
        ans.smax=INT_MIN;
        return ans;
    } 
	if (start >=left && end <=right)
		return tree[treeNode];//range is completely inside
	// range is partially inside and partially outside
	int mid = (start + end) / 2;
    node l,r;
    l.max=INT_MIN,l.smax=INT_MIN,r.max=INT_MIN,r.smax=INT_MIN;
    if(mid>=left)
        l=query(tree,start,mid,treeNode*2,left,right);
    if(mid<right)
        r=query(tree,mid+1,end,treeNode*2+1,left,right);
    node ans;
    ans.max=max(l.max,r.max);
    ans.smax=min(max(l.max,r.smax),max(r.max,l.smax));
    return ans;
}
int main() {
    int n;
    cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    node* tree=new node[3*n];
    buildtree(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        char type;
        int l,r;
        cin>>type>>l>>r;
        if(type=='Q'){
            node ans=query(tree,0,n-1,1,l-1,r-1);
            cout<<ans.max+ans.smax<<endl;
        }
        else if(type=='U'){
            update(arr,tree,0,n-1,1,l-1,r);
        }
    }
    delete[]arr;
    delete[]tree;
}
