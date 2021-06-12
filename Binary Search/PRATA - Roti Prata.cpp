// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/PRATA/
// Decent

/*
IEEE is having its AGM next week and the president wants to serve cheese prata after the meeting. The subcommittee members are asked to go to food connection 
and get P(P<=1000) pratas packed for the function. The stall has L cooks(L<=50) and each cook has a rank R(1<=R<=8). A cook with a rank R can cook 1 prata in 
the first R minutes 1 more prata in the next 2R minutes, 1 more prata in 3R minutes and so on(he can only cook a complete prata) ( For example if a cook is 
ranked 2.. he will cook one prata in 2 minutes one more prata in the next 4 mins an one more in the next 6 minutes hence in total 12 minutes he cooks 3 pratas 
in 13 minutes also he can cook only 3 pratas as he does not have enough time for the 4th prata). The webmaster wants to know the minimum time to get the order 
done. Please write a program to help him out.

Input
The first line tells the number of test cases. Each test case consist of 2 lines. In the first line of the test case we have P the number of prata ordered. 
In the next line the first integer denotes the number of cooks L and L integers follow in the same line each denoting the rank of a cook.
Output

Print an integer which tells the number of minutes needed to get the order done.

Example

Input:
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
Output:
12
36
1
*/

// Binary search on time

#include <bits/stdc++.h>
using namespace std;

bool can(int t, int cook[], int n, int p)
{
    int paratas = 0;
    for(int i = 0; i < n; ++i)
    {
        int temp = (int)sqrt((2*t)/cook[i]); // temp has paratas cooked bt cook[i]
        while(temp*(temp+1) > (2*t)/cook[i])
        {
            --temp;
        }
        paratas += temp;
    }
    if(paratas >= p)
        return true;
    return false;
}

int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int l = 0, p = 0;
        cin >> p;
        cin >> l;
        int cook[l];
        for(int i = 0; i < l; ++i)
            cin >> cook[i];
        
        int low = 0, high = 1e9;
        while(high-low > 1)
        {
            int mid = (low+high)/2;
            if(can(mid, cook, l, p))
                high = mid;
            else
                low = mid+1;
        }
        if(can(low, cook, l, p))
            cout << low << endl;
        else
            cout << high << endl;
    }
	return 0;
}
