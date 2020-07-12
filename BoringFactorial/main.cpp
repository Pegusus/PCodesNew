#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,d;
void extendedEuclid(ll a,ll b){
    if(b==0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(b,a%b);
        ll temp = x;
        x = y;
        y = temp - (a/b)*y;
    }
}
ll mulinv(ll n,ll m){
    extendedEuclid(n,m);
    return ((x%m)+m)%m;
}
ll solve(ll N,ll P){
    if(N>=P)
        return 0;
    ll ans = 1;
    for(ll i = N+1 ;i < P;i++){
        ans = (( (ans%P) * (mulinv(i,P)%P) ) +P )%P;
    }
    ans = ans*(-1);
    if(ans<0)
        return (ans+P)%P;
    return ans;
}
int main()
{
    ll t;
    cin>>t;
    while(t--){
        ll N,P;
        cin>>N>>P;
        cout<<solve(N,P)<<endl;
    }
    return 0;
}
