#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 10005
#define inf 1e9
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

struct Node
{
    ll at,cost,dis;
    Node(ll _at,ll _cost,ll _dis)
    {
        at=_at;
        cost=_cost;
        dis=_dis;
    }
};

bool operator < (Node A,Node B)
{
    return A.cost > B.cost;
}

struct Edge
{
    ll v,w,ty;
};

vector<Edge>adj[MX];
priority_queue<Node>PQ;
ll dist[MX][15];
ll n,m,k,d;

void dijkstra(ll s)
{
    for(ll i=0;i<=n;i++)
    {
        for(ll j=0;j<=10;j++)
        dist[i][j]=inf;
    }
    dist[s][0]=0;
    PQ.push(Node(s,0,0));
    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();

        for(ll i=0;i<adj[u.at].size();i++)
        {
            Edge e=adj[u.at][i];
            if(dist[e.v][u.dis+e.ty]>u.cost+e.w)
            {
                dist[e.v][u.dis+e.ty]=u.cost+e.w;
                PQ.push(Node(e.v,dist[e.v][u.dis+e.ty],u.dis+e.ty));
            }
        }
    }
}
int main()
{
    ll test,t=1;
    sc1(test);
    while(test--)
    {
        sc3(n,m,k);
        sc1(d);
        for(ll i=0;i<=n;i++)
        {
            adj[i].clear();
        }
        for(ll i=1;i<=m;i++)
        {
            ll u,v,w;
            sc3(u,v,w);
            adj[u].pb({v,w,0});
        }
        for(ll i=1;i<=k;i++)
        {
            ll u,v,w;
            sc3(u,v,w);
            adj[u].pb({v,w,1});
        }
        dijkstra(0);
        ll ans=inf;
        for(ll i=0;i<=d;i++)
        {
            ans=min(ans,dist[n-1][i]);
        }
        printf("Case %lld: ",t++);
        if(ans==inf)
            printf("Impossible\n");
        else
            printf("%lld\n",ans);
    }
    return 0;
}

