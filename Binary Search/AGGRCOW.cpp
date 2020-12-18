// By Vishwam Mundada

#include <iostream>
#include <algorithm>
using namespace std;
 
bool canCowsPlaced(int a[], int n, int c, int mid)
{
    int cowsPlaced=1;
    int place = a[0];
    for(int i=1;i<n;++i)
    {
        if(a[i]-place >= mid)
        {
            cowsPlaced++;
            place=a[i];
        }
        if(cowsPlaced >= c)
            return true;
    }
    if(cowsPlaced>=c)
        return true;
    return false;
}
 
int BinarySearch(int a[], int n, int c, int max)
{
    int l=0, r=max, mid=0;
    while(r-l > 1)
    {
        mid = (l+r)/2;
        bool temp = canCowsPlaced(a,n,c,mid);
        if(temp == true)
        {
            l=mid;
        }
        else
        {
            r=mid-1;
        }
    }
    if(canCowsPlaced(a,n,c,r))
        return r;
    return l;
}
 
int main()
{
    int n=0, c=0, t=0, max=0;
    cin>>t;
    while(t--)
    {
        max=0;
        cin>>n>>c;
        int a[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            if(a[i]>max)
                max=a[i];
        }
        sort(a,a+n);
        cout<<BinarySearch(a,n,c,max)<<endl;
    }
    return 0;
}
