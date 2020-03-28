int max(int a, int b)
{
    if(a>b)return a;
    else return b;
}
int getMax(int* A,int n,int* dp)
{
    dp[0] = A[0];
    dp[1] = max(A[1],A[0]);

    for(int i =2;i<n;i++)
    {
        dp[i] = max(A[i] + dp[i-2],dp[i-1]);
    }
    return dp[n-1];
}
int getMaxMoney(int arr[], int n){

    int* dp = new int[n+1];
    for(int i =0 ;i<n+1;i++)dp[i] = 0;
    int N = n;
    return getMax(arr,N,dp);

}
