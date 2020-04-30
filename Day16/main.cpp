#include <bits/stdc++.h>

using namespace std;
void buildSegmentTree(int* arr,int* tree,int si,int ei,int treenode){
    if(si == ei){
        tree[treenode] = arr[si];
        return;
    }
    int mid = si + (ei-si)/2;
    buildSegmentTree(arr,tree,si,mid,2*treenode+1);
    buildSegmentTree(arr,tree,mid+1,ei,2*treenode+2);

    tree[treenode] = tree[2*treenode+1] + tree[2*treenode+2];
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

    tree[treenode] = tree[2*treenode+1] + tree[2*treenode+2];
}
int querry(int* tree,int si,int ei,int treenode,int l,int r){
    if(ei<l || si>r)
        return 0;
    if(si>=l&&ei<=r)
        return tree[treenode];
    int mid = si + (ei-si)/2;

    int ans1 = querry(tree,si,mid,2*treenode+1,l,r);
    int ans2 = querry(tree,mid+1,ei,2*treenode+2,l,r);

    return ans1+ans2;
}
int main()
{
    int arr[] = {1,3,5,7,9,6,2};

    int n = sizeof(arr)/sizeof(arr[0]);
    int* tree = new int[4*n];
    for(int i = 0;i<4*n;i++)
        tree[i] = INT_MIN;
    buildSegmentTree(arr,tree,0,n-1,0);
    for(int i = 0;i<4*n;i++)
    {
        if(tree[i]!=INT_MIN)
            cout<<i<<"-"<<tree[i]<<" ";
    }
    updateTree(arr,tree,0,n-1,0,1,3);
    cout<<endl;
    for(int i = 0;i<4*n;i++)
    {
        if(tree[i]!=INT_MIN)
            cout<<i<<"-"<<tree[i]<<" ";
    }
    cout<<endl;
    cout<<querry(tree,0,n-1,0,1,3);
    return 0;
}
