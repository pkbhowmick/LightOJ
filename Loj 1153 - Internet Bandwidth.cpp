///Loj 1153 - Internet Bandwidth
///FordFulkerson algorithm
#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll g[105][105];
ll rg[105][105];

ll parent[105];
ll n;
bool bfs(ll s,ll t)
{
    bool vis[n+1];
    memset(vis,0,sizeof vis);
    queue<ll>q;
    q.push(s);
    vis[s]=true;
    parent[s]=-1;

    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll v=1;v<=n;v++)
        {
            if(vis[v]==false&&rg[u][v]>0)
            {
                q.push(v);
                parent[v]=u;
                vis[v]=true;
            }
        }
    }
    return (vis[t]==true);
}
ll fordFulkarson(ll s,ll t)
{
    ll max_flow=0;
    while(bfs(s,t))
    {
        ll path_flow=INT_MAX;
        for(ll v=t;v!=s;v=parent[v])
        {
            ll u=parent[v];
            path_flow=min(path_flow,rg[u][v]);
        }
        for(ll v=t;v!=s;v=parent[v])
        {
            ll u=parent[v];
            rg[u][v]-=path_flow;
            rg[v][u]-=path_flow;
        }
        max_flow+=path_flow;
    }
    return max_flow;
}
int main()
{
    ll test;
    ll tt=1;
    sc1(test);
    while(test--)
    {
        sc1(n);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=1;j<=n;j++)
            {
                g[i][j]=0;
                rg[i][j]=0;
            }
        }
        ll s,t,c;
        sc3(s,t,c);
        for(ll i=1;i<=c;i++)
        {
            ll u,v,cost;
            sc3(u,v,cost);
            g[u][v]+=cost;
            g[v][u]+=cost;
            rg[u][v]+=cost;
            rg[v][u]+=cost;
        }
        ll ans=fordFulkarson(s,t);
        printf("Case %lld: %lld\n",tt++,ans);
    }
    return 0;
}
