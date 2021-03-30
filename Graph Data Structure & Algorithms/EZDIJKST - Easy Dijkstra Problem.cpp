// By Vishwam Shriram Mundada
// https://www.spoj.com/problems/EZDIJKST/
// Straightforward implementation of DIJKSTRA

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dijkstra(int source, int dist[], int vis[], vector<pair<int, int> > v[])
{
    priority_queue<pair<int, int> , vector<pair<int, int> > , greater<pair<int, int> > > pq;
    
    pq.push({0, source});
    dist[source] = 0;
    
    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        
        if(vis[p.second])
            continue;
        
        vis[p.second] = 1;
        
        for(int i = 0; i < v[p.second].size(); ++i)
        {
            pair<int, int> child = v[p.second][i];
            
            if(vis[child.first])
            {
                continue;
            }
            
            if(child.second + p.first < dist[child.first])
            {
                dist[child.first] = child.second + p.first;
                pq.push({dist[child.first], child.first});
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
        int n = 0, e = 0, a, b, wt;
        cin >> n >> e;
        vector<pair<int, int> > v[n+1];
        for(int i = 0; i < e; ++i)
        {
            cin >> a >> b >> wt;
            v[a].push_back({b, wt});
        }
        int source = 0, dest = 0;
        cin >> source >> dest;
        
        int dist[n+1];
        for(int i = 0; i <= n; ++i)
        	dist[i] = INT_MAX;
        
        int vis[n+1];
        for(int i = 0; i <= n; ++i)
        	vis[i] = 0;
        
        dijkstra(source, dist, vis, v);
        
        if(dist[dest] == INT_MAX)
            cout << "NO" << endl;
        else
            cout << dist[dest] << endl;
    }
}
