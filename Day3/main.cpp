#include<iostream>
using namespace std;
int a[1000][10];
int count(int value,int* denominations,int numDenominations,int a[1000][10])
{
    if(value==0)return 1;
    if(numDenominations==0)return 0;
    if(value<0)return 0;
    if(a[value][numDenominations]>0)return a[value][numDenominations];

    int first = count(value-denominations[0],denominations,numDenominations,a);
    int second = count(value,denominations+1,numDenominations-1,a);
    a[value][numDenominations] = first+second;
    return first+second;
}
int countWaysToMakeChange(int denominations[], int numDenominations, int value){

    int x = value,y = numDenominations;

    for(int i = 0;i<x+1;i++)
        for(int j = 0;j<y+1;j++)
            a[i][j] = -1;
    return count(x,denominations,y,a);

}
int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << countWaysToMakeChange(denominations, numDenominations, value);

}


