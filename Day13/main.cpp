#include <bits/stdc++.h>
using namespace std;
int A[1000][1000],dp[1000][1000],nr,nc,gmin = INT_MAX;
int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}
int minFare(int row,int col)
{
    if(row==nr) return 0;

    if(dp[row][col]!=-1)return dp[row][col];
    int ans;
    if(col==0&&nc!=1)
    {
        int option2 = A[row][col] + minFare(row+1,col);
        int option3 = A[row][col] + minFare(row+1,col+1);
        ans = min(option2,option3);

    }
    if(col==0&&nc==1)
    {
        int option2 = A[row][col] + minFare(row+1,col);
        ans = option2;

    }
    if(col!=0&&col==nc-1)
    {
        int option1 = A[row][col] + minFare(row+1,col-1);
        int option2 = A[row][col] + minFare(row+1,col);
        ans = min(option1,option2);
    }
    if(col>0&&col<nc-1)
    {
        int option1 = A[row][col] + minFare(row+1,col-1);
        int option2 = A[row][col] + minFare(row+1,col);
        int option3 = A[row][col] + minFare(row+1,col+1);
        ans = min(option3,min(option1,option2));
    }

   dp[row][col] = ans;
    return ans;
}
int main()
{
    int n,m;
    cin>>n>>m;
    nr = n;nc = m;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            dp[i][j] = -1;
	for(int i = 0;i<m;i++)
        dp[n][i] = 0;

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>A[i][j];

    for(int j = 0;j<m;j++)
    {
        int mini = minFare(0,j);
        if(mini<gmin) gmin = mini;
    }
    cout<<gmin<<endl;
    return 0;
}
