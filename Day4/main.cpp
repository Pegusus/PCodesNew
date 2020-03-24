#include <bits/stdc++.h>
using namespace std;
int a[71];
long countways(int n,int* a)
{
    if(n==0)return 1;
    if(n==1)return 1;
    if(n==2)return 2;
    if(a[n]!=0)return a[n];
    long count = countways(n-1,a)+countways(n-2,a)+countways(n-3,a);
    a[n] = count;
    return count;
}
long staircase(int n){

    for(int i = 0; i<71 ; i++)
        a[i]=0;
    int x = n;
    return countways(x,a);
}
int main(){

  int n;
  cin >> n ;
  cout << staircase(n) << endl;
}

