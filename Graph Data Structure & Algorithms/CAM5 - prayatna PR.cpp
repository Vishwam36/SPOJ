// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/CAM5/
// Very easy, basic

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void bfs(int source, vector<int> v[], int visited[])
{
    queue<int> q;
    
    q.push(source);
    visited[source] = 1;
    
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        
        for(int i = 0; i < v[curr].size(); ++i)
        {
            int child = v[curr][i];
            if(visited[child] == 0)
            {
                visited[child] = 1;
                q.push(child);
            }
        }
    }
}

int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        int n = 0, e = 0, x = 0, y = 0, ans = 0;
        cin >> n;
        cin >> e;
        vector<int> v[n];
        int visited[n] = {0};
        for(int i = 0; i < e; ++i)
        {
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        
        for(int i = 0; i < n; ++i)
        {
            if(visited[i] == 0)
            {
                bfs(i, v, visited);
                ++ans;
            }
        }
        cout << ans << endl;
    }
}
