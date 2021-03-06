// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/DIEHARD/
// Easy

/*
The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live in any of the three places - fire, water and 
air. After every unit time, you have to change your place of living. For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.

Input:

The first line consists of an integer t, the number of test cases. For each test case there will be two positive integers representing the 
initial health H and initial armor A.

Output:
For each test case find the maximum time you can survive.

Note: You can choose any of the 3 places during your first move.

Input Constraints:
1 <= t <= 10
1 <= H, A <= 1000

Example:
Sample Input:
3
2 10
4 4
20 8

Sample Output:
1
1
5
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	while(t--)
	{
	    int h, a;
	    cin >> h >> a;
	    int ans = 0;
	    while(h > 0 && a > 0)
	    {
	        h += 3;
	        a += 2;
	        ans++;
	        if(a > 10)
	        {
	            h -= 5;
	            a -= 10;
	        }
	        else
	        {
	            h -= 20;
	            a += 5;
	        }
	        ans++;
	    }
	    cout << ans-1 << endl;
	}
	return 0;
}
