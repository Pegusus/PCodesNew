#include <bits/stdc++.h>

using namespace std;
void buildTree(int* arr,int* tree,int start,int end,int treenode){
    if(start==end){
        tree[treenode] = arr[start];
        return;
    }
    int mid = start + (end-start)/2;
    buildTree(arr,tree,start,mid,2*treenode);
    buildTree(arr,tree,mid+1,end,2*treenode+1);

    tree[treenode] = tree[2*treenode] + tree[2*treenode + 1];
}
void updateTree(int* arr,int* tree,int start,int end,int treenode,int idx,int value){
    if(start==end)
    {
        arr[idx] =  value;
        tree[treenode] = value;
        return;
    }
    int mid = start + (end-start)/2;

    if(idx<mid)
        updateTree(arr,tree,start,mid,2*treenode,idx,value);
    else
        updateTree(arr,tree,mid+1,end,2*treenode+1,idx,value);

    tree[treenode] = tree[2*treenode] + tree[2*treenode+1];
}
int querry(int* tree,int start,int end,int treenode,int left,int right){
    //completely outside
    if(end<left || start>right)
        return 0;
    //completely inside
    if(start>=left && end<=right)
        return tree[treenode];
    //partially
    int mid = start + (end-start)/2;
    int ans1 = querry(tree,start,mid,2*treenode,left,right);
    int ans2 = querry(tree,mid+1,end,2*treenode+1,left,right);

    return ans1+ans2;
}
void display(int* arr)
{
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<"array: ";
    for(int i = 0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[] = {1,2,5,6,7,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    int* tree = new int[4*n];
    for(int i = 0;i<4*n;i++)
        tree[i] = INT_MIN;

    buildTree(arr,tree,0,5,1);

    for(int i = 1;i<4*n;i++)
        if(tree[i]!=INT_MIN)
        cout<<tree[i]<<" ";
    cout<<endl;
    updateTree(arr,tree,0,5,1,0,2);
    display(arr);
    cout<<endl;
    for(int i = 1;i<4*n;i++)
        if(tree[i]!=INT_MIN)
        cout<<tree[i]<<" ";
    cout<<endl;
    int ans = querry(tree,0,5,1,2,4);
    cout<<ans;
    return 0;
}
