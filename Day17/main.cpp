#include<bits/stdc++.h>
using namespace std;

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
int querry(int* tree,int si,int ei,int treenode,int l,int r){
    if(si>r || ei < l)
        return INT_MAX;
    if(si>=l&&ei<=r)
        return tree[treenode];
    int mid = si + (ei-si)/2;
    int ans1 = querry(tree,si,mid,2*treenode+1,l,r);
    int ans2 = querry(tree,mid+1,ei,2*treenode+2,l,r);
    return min(ans1,ans2);
}
int main() {

    int n,q;
    cin>>n>>q;
    int* arr = new int[n];
    for(int i =0 ;i<n;i++)
        cin>>arr[i];

    int* tree = new int[4*n];
    buildTree(arr,tree,0,n-1,0);

    while(q--){
        char ch;int a,b;
        cin>>ch;
        cin>>a>>b;
        if(ch=='q')
        {
            cout<<querry(tree,0,n-1,0,a-1,b-1)<<endl;
        }
        else
             updateTree(arr,tree,0,n-1,0,a-1,b);

    }
	return 0;
}
