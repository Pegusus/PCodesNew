#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int helper(char* a1,char* a2,int m,int n,int** dp)
{
  if(m<=0||n<=0)return max(m,n);
    if(dp[m][n]!=-1)return dp[m][n];
    if(a1[0]==a2[0])return (1 + helper(a1+1,a2+1,m-1,n-1,dp));
    else {

    int ans = min(helper(a1,a2+1,m,n-1,dp),min( helper(a1+1,a2,m-1,n,dp), helper(a1+1,a2+1,m-1,n-1,dp))) + 1;
    dp[m][n] = ans;

    return ans;}
}
int editDistance(string s1, string s2){

    int m =0,n=0;
    // m = strlen(s1);
    // n = strlen(s2);

    for(int i = 0;s1[i]!='\0';i++)
        m++;
    for(int i = 0;s2[i]!='\0';i++)
        n++;

    char* ch_arr1 = new char[m];
    char* ch_arr2 = new char[n];

    for(int i = 0;i<m;i++)
        ch_arr1[i] = s1[i];
    for(int i = 0;i<n;i++)
        ch_arr2[i] = s2[i];

    int** dp = new int*[m+1];
    for(int i = 0;i<m+1;i++)
        dp[i] = new int[n];

    for(int i = 0;i<m;i++)
        for(int j = 0;j<n;j++)
            dp[i][j] = -1;

    for(int i = 0;i<m+1;i++)
        dp[i][0] = i;

    for(int i = 1;i<n+1;i++)
        dp[0][i] = i;

    return helper(ch_arr1,ch_arr2,m,n,dp);

}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}


