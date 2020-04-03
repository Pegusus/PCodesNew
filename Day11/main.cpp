#include<iostream>
using namespace std;
int k(int* wt, int* val, int n, int w,int** dp)
{
    if(n==0||w==0)return 0;
     if(dp[n][w]!=-1)return dp[n][w];

    if(wt[n-1]<=w)
    {
        int ans = max(val[n-1]+k(wt,val,n-1,w-wt[n-1],dp),k(wt,val,n-1,w,dp));
        dp[n][w] = ans;
        return ans;
    }
    if(wt[n-1]>w)
    {
        int ans = k(wt,val,n-1,w,dp);
        dp[n][w] = ans;
        return ans;
    }

}
int knapsack(int* weights, int* values, int n, int maxWeight){

    int N = n;
    int w = maxWeight;
    int** dp = new int*[N+1];
    for(int i = 0;i<n+1;i++)
        dp[i] = new int[w+1];

    for(int i = 0;i<n+1;i++)
        for(int j = 0;j<w+1;j++)
            dp[i][j] = -1;

    return k(weights,values,N,w,dp);
}


int main(){

  int n;
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}


