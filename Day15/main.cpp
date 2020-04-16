
#include <bits/stdc++.h>

using namespace std;

int lps(string s)
{
    int len = s.length();
    int max = 1;

    for(int i = 0;i<len;i++)
    {
        int l = i;
        int r = i;

        while(l!=0 && r!=len && s[l]==s[r]){
            int curr_len = r-l+1;
            if(max<curr_len)max = curr_len;
            l--;
            r++;
        }

         l = i;
         r = i+1;

        while(l!=0 && r!=len && s[l]==s[r]){
            int curr_len = r-l+1;
            if(max<curr_len)max = curr_len;
            l--;
            r++;
        }
    }

    return max;

}
int main()
{
   string s;
   cin>>s;
   cout<<lps(s);
    return 0;
}
