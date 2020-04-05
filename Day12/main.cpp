//Recursive Solution

#include <bits/stdc++.h>

using namespace std;
bool checkSum(int* a,int n,int sum)
{
    if(sum == 0) return true;
    if(n == 0) return false;

    bool ans = checkSum(a,n-1,sum-a[n-1])||checkSum(a,n-1,sum);
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int* a = new int[n];

    for(int i = 0;i<n;i++)
        cin>>a[i];
    int sum;
    cin>>sum;
    cout<<checkSum(a,n,sum);
    return 0;
}

//Iterative Dp solution
#include <bits/stdc++.h>

using namespace std;
bool checkSum(int* a,int n,int sum)
{
    bool** dp = new bool*[n+1];
    for(int i = 0;i<=n;i++)
        dp[i] = new bool[sum+1];

    for(int i = 0;i<=n;i++)
        dp[i][0] = true;

    for(int i = 1;i<=sum;i++)
        dp[0][i] = false;

    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=sum;j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j-a[i-1]>=0)
                dp[i][j] = dp[i-1][j]||dp[i-1][j-a[i-1]];
        }
    int ans = dp[n][sum];

    return ans;
}
int main()
{
    int n;
    cin>>n;
    int* a = new int[n];

    for(int i = 0;i<n;i++)
        cin>>a[i];
    int sum;
    cin>>sum;
    if(checkSum(a,n,sum)==1) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
