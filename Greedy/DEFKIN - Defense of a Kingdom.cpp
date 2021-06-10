// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/DEFKIN/
// Easy

/*


Theodore implements a new strategy game “Defense of a Kingdom”. On each level a player defends the Kingdom that is represented by a rectangular grid of cells. 
The player builds crossbow towers in some cells of the grid. The tower defends all the cells in the same row and the same column. 
No two towers share a row or a column.

The penalty of the position is the number of cells in the largest undefended rectangle. For example, the position shown on the picture has penalty 12.

This position has a penalty of 12.

Help Theodore write a program that calculates the penalty of the given position.
Input

The first line of the input file contains the number of test cases.

Each test case consists of a line with three integer numbers: w — width of the grid, h — height of the grid and 
n — number of crossbow towers (1 ≤ w, h ≤ 40 000; 0 ≤ n ≤ min(w, h)).

Each of the following n lines contains two integer numbers xi and yi — the coordinates of the cell occupied by a tower (1 ≤ xi ≤ w; 1 ≤ yi ≤ h).
Output

For each test case, output a single integer number — the number of cells in the largest rectangle that is not defended by the towers.
Example

Input:
1
15 8 3
3 8
11 2
8 6

Output:
12
*/

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int w, h, n;
        cin >> w >> h >> n;
        vector<int> x, y;
        x.push_back(0); // assume at 0 there is defence to cover corners
        y.push_back(0);
        for(int i = 0; i < n; ++i)
        {
            int a, b;
            cin >> a >> b;
            x.push_back(a);
            y.push_back(b);
        }
        x.push_back(w+1); // assume defence at the end to cover corners
        y.push_back(h+1);
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        int max_diff_w = 0, max_diff_h = 0;
        
        for(int i = 1; i < x.size(); ++i)
            max_diff_w = max(max_diff_w, x[i]-x[i-1]-1);
        
        for(int i = 1; i < y.size(); ++i)
            max_diff_h = max(max_diff_h, y[i]-y[i-1]-1);
        
        cout << max_diff_h * max_diff_w << endl;
    }
	return 0;
}
