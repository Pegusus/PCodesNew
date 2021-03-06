#include<bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}
void buildTree(int* arr,int* tree,int si,int ei,int treenode){
    if(si==ei){
        tree[treenode] = arr[si];
        return;
    }
    int mid = si + (ei-si)/2;
    buildTree(arr,tree,si,mid,2*treenode+1);
    buildTree(arr,tree,mid+1,ei,2*treenode+2);

    tree[treenode] = min(tree[2*treenode+1],tree[2*treenode+2]);
}
void updateTree(int* arr,int* tree,int si,int ei,int treenode,int idx,int val)
{
    if(si==ei){
        arr[idx] = val;
        tree[treenode] = val;
        return;
    }
    int mid = si + (ei-si)/2;

    if(idx<=mid)
        updateTree(arr,tree,si,mid,2*treenode+1,idx,val);
    else
        updateTree(arr,tree,mid+1,ei,2*treenode+2,idx,val);

    tree[treenode] = min(tree[2*treenode+1] , tree[2*treenode+2]);
}
int main() {

	// Write your code here
    int arr[] = {1,5,2,4,3};
    int n = 5;

    int* tree = new int[4*n];
    for(int i = 0;i<4*n;i++)
        tree[i]=INT_MIN;
    buildTree(arr,tree,0,n-1,0);

    for(int i = 0;i<4*n;i++)
        if(tree[i]!=INT_MIN)
            cout<<i<<"-"<<tree[i]<<" ";
    cout<<endl;
    updateTree(arr,tree,0,n-1,1,2,0);
    for(int i = 0;i<4*n;i++)
        if(tree[i]!=INT_MIN)
            cout<<i<<"-"<<tree[i]<<" ";
}
