#include<bits/stdc++.h>
using namespace std;
void buildtree(int* arr, int start, int end, int treeNode,int* tree) {
	if (start == end) {
		tree[treeNode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildtree(arr, start, mid, treeNode * 2, tree);
	buildtree(arr, mid + 1, end, (treeNode * 2) + 1, tree);
	tree[treeNode] = min(tree[treeNode * 2],tree[(treeNode * 2) + 1]);
	return;
}

void update(int* arr, int* tree, int index, int value, int start, int end, int treeNode) {
	if (start == end)
	{
		arr[index] = value;
		tree[treeNode] = value;
		return;
	}
	int mid = (start + end) / 2;
	if (index <= mid)
		update(arr, tree, index, value, start, mid, treeNode * 2);
	else
		update(arr, tree, index, value, mid + 1, end, (treeNode * 2) + 1);
	tree[treeNode] = min(tree[treeNode * 2],tree[treeNode * 2 + 1]);
	return;
}
int query(int* tree, int start, int end, int left, int right, int treeNode) {
	if (start > right || end < left)
		return 0; // range is completely outside
	if (start >=left && end <=right)
		return tree[treeNode]; //range is completely inside
	// range is partially inside and partially outside
	int mid = (start + end) / 2;
	int a = INT_MAX, b = INT_MAX;
	if (mid >= left)
		a = query(tree, start, mid, left, right, (treeNode * 2));
	if(mid<right)
		b= query(tree, mid+1, end, left, right, (treeNode * 2)+1);
	return min(a,b);

}
int main() {
    int n,q;
    cin>>n>>q;
    int*arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //segement tree array
    int*tree=new int[4*n];
    buildtree(arr,0,n-1,1,tree);
    for(int i=0;i<q;i++){
        char type;
        int l,r;
        cin>>type>>l>>r;
        if(type=='q')
            cout<<query(tree,0,n-1,l-1,r-1,1)<<endl;
        else if(type=='u')
            update(arr,tree,l-1,r,0,n-1,1);// here l is index and r is value
    }
    delete[]arr;
    delete[]tree;
}
