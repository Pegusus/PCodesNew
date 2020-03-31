#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}
int lcshelper(char* s1,char* s2,int m,int n,int** dp)
{
    if(m==0||n==0)
        return 0;
    if(dp[m][n]>-1)return dp[m][n];

    if(s1[0]==s2[0])
    {return (1 + lcshelper(s1+1,s2+1,m-1,n-1,dp));}
    else
    {
        int option1 = lcshelper(s1,s2+1,m,n-1,dp);
        int option2 = lcshelper(s1+1,s2,m-1,n,dp);

        int ans = max(option1,option2);

        dp[m][n] = ans;

        return ans;
    }

}
int lcs(string s1, string s2){

    int m=0,n=0;
    for(int i = 0;s1[i]!='\0';i++)
        m++;
     for(int i = 0;s2[i]!='\0';i++)
        n++;

    char* ns1 = new char[m+1];
    char* ns2 = new char[n+1];

     strcpy(ns1, s1.c_str());
     strcpy(ns2, s2.c_str());

    int** dp = new int*[m+1];

    for(int i = 0;i<n;i++)
        dp[i] = new int[n+1];

    for(int i = 0;i<m+1;i++)
        for(int j = 0;j<n+1;j++)
            dp[i][j] = -1;

    return lcshelper(ns1,ns2,m,n,dp);
}


int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << lcs(s1,s2) << endl;
    return 0;
}


