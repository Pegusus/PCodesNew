// Creater - Aniruddha Guin
// Dynamic Programming - 1
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    string s;
    int n,i,x;
    long long int poss[5001];

    while(1)
    {
        cin>>s;
        if(s=="0")break;

        n = s.size();
        for(int i = 0;i<5000;i++)poss[i]=0;
        poss[0] = 1;

        for(int i = 1;i<n;i++)
        {
            x = (s[i-1]-'0')*10+(s[i]-'0');
            if(s[i]!='0')               //copy the same possibilities as the digit will be just
                poss[i] = poss[i-1];
                                        //attached to the previous when the digit cannot be combined
            if(x>=10&&x<=26&&i>1)       //if the i th element can combine with the i-1 th element
                poss[i]+=poss[i-2];

            else if(x>=10&&x<=26)
                poss[i]++;
            poss[i] = poss[i]%mod;
        }
        cout<<poss[n-1]<<endl;
    }
    return 0;
}
