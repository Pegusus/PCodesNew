#include <bits/stdc++.h>

using namespace std;
int* lpsarray(string p)
{
    int len = p.length();
    int* lps = new int[len];

    lps[0] = 0;
    int i = 1;
    int j = 0;
    while(i<len)
    {
        if(p[i]==p[j]){
            lps[i] = j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0){
                j = lps[j-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
bool isMatching(string str,string pattern)
{
    int* lps = lpsarray(pattern);
    int lenstr = str.length();
    int lenpattern  = pattern.length();

    int i = 0;
    int j = 0;

    while(i<lenstr && j<lenpattern)
    {
        if(str[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0){
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j==lenpattern)return true;

    return false;
}
int position(string str, string pattern)
{
    int* lps = lpsarray(pattern);
    int lenstr = str.length();
    int lenpattern  = pattern.length();

    int i = 0;
    int j = 0;

    while(i<lenstr && j<lenpattern)
    {
        if(str[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0){
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(j==lenpattern)return (i - lenpattern);

    return -1;
}
int main()
{
    string str;
    string pattern;
    cin>>str>>pattern;

    cout<<isMatching(str,pattern)<<endl;
    cout<<position(str,pattern);


    return 0;
}
