// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/NR2/

#include <iostream>
#include <math.h>
using namespace std;
 
long long nob = 64;
 
long long binaryToDecimal(int a[])
{
    long long ans=0;
    for(int i=0;i<nob;++i)
    {
        ans += (1LL<<i)*a[i];
    }
    return ans;
}
 
int main()
{
    long long n=0,a=0;
    cin>>n;
    int zero[nob]={0};
    int one[nob]={0};
    int ansInBits[nob]={0};
    for(long long i=0;i<n;++i)
    {
        cin>>a;
        for(int j=0;j<nob;++j)
        {
            if(((1) & (a>>j)) != 0)
            {
                // making sure if there is 1 or not at jth position
                one[j]=1;
            }
            else
            {
                // making sure if there is 0 or not at jth position
                zero[j]=1;
            }
        }
    }
    for(int j=0;j<nob;++j)
        if(one[j]==1 && zero[j]==1)
            ansInBits[j]=1;  // if there is atleast one 1 and atleast one 0, their xor will have atleast one 1 and if we have atleast one 1 their OR will be 1
 
    long long ans = binaryToDecimal(ansInBits);
    cout<<ans;
    return 0;
} 
