#include <bits/stdc++.h>
using namespace std;
int min(int a,int b)
{
    if(a<b)return a;
    else return b;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        int a[r][c];
        for(int i = 0;i<r;i++)
            for(int j = 0;j<c;j++)
                cin>>a[i][j];

         int m = r,n=c;
     int hp[m+1][n+1];
    for(int i = 0;i<m+1;i++)
        for(int j = 0;j<n+1;j++)
            hp[i][j] = INT_MAX;
    hp[m][n-1]=1;
    hp[m-1][n]=1;

    for(int i = m-1;i>=0;i--)
        for(int j = n-1;j>=0;j--)
        {
            int need = min(hp[i+1][j],hp[i][j+1])-a[i][j];
            if(need<=0) hp[i][j]=1;
            else
                hp[i][j]=need;
        }
        cout<<hp[0][0]<<endl;

    }
    return 0;
}
