// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/CCHESS/
// Easy

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x[] = {-2, -1, 1, 2, -2, -1, 1, 2};
int y[] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isValid(int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int bfs(int a, int b, int c, int d)
{
    int vis[8][8];
    
    for(int i = 0; i < 8; ++i)
        for(int j = 0; j < 8; ++j)
            vis[i][j] = -1;
    
    queue<pair<pair<int, int>, int> > q;
    q.push({ {a, b}, 0});
    vis[a][b] = 0;
    
    while(!q.empty())
    {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        
        // cout << p.first.first << " " << p.first.second << " " << p.second << endl;
        
        for(int i = 0; i < 8; ++i)
        {
            int m = p.first.first + x[i];
            int n = p.first.second + y[i];
            int cost = p.second + p.first.first * m + p.first.second * n;
            
            if(isValid(m, n))
            {
                if(vis[m][n] != -1 && cost < vis[m][n])
                {
                    vis[m][n] = cost;
                    q.push({{m, n}, vis[m][n]});
                }
                else if(vis[m][n] == -1)
                {
                    vis[m][n] = cost;
                    q.push({{m, n}, vis[m][n]});
                }
            }
        }
    }
    return vis[c][d];
}

int main()
{
    int a, b, c, d;
    while(cin >> a >> b >> c >> d)
        cout << bfs(a, b, c, d) << endl;
}
