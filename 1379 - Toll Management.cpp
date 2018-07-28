#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
ll n,m,src,des,p;
struct Node
{
    ll at,cost;
    Node(ll _at,ll _cost)
    {
        at=_at;
        cost=_cost;
    }
};

bool operator <(Node A,Node B)
{
    return A.cost>B.cost;
}
struct Edge
{
    ll v,w;
};
vector<Edge>adj[10005];
priority_queue<Node>PQ;
ll dist[10005];
void dijkstra(ll s)
{
    for(ll i=1; i<=n; i++)
        dist[i]=10000000000;

    dist[s]=0;
    PQ.push(Node(s,0));
    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();
        if(u.cost!=dist[u.at])
            continue;

        for(ll i=0; i<adj[u.at].size(); i++)
        {
            Edge e=adj[u.at][i];
            if(dist[e.v]>u.cost+e.w)
            {
                dist[e.v]=u.cost+e.w;
                PQ.push(Node(e.v,dist[e.v]));
            }
        }
    }
}
vector<Edge>rev[10005];
ll dist2[10005];
void dijkstra2(ll s)
{
    for(ll i=1; i<=n; i++)
        dist2[i]=10000000000;

    dist2[s]=0;
    PQ.push(Node(s,0));
    while(!PQ.empty())
    {
        Node u=PQ.top();
        PQ.pop();
        if(u.cost!=dist2[u.at])
            continue;

        for(ll i=0; i<rev[u.at].size(); i++)
        {
            Edge e=rev[u.at][i];
            if(dist2[e.v]>u.cost+e.w)
            {
                dist2[e.v]=u.cost+e.w;
                PQ.push(Node(e.v,dist2[e.v]));
            }
        }
    }
}
void reset(ll k)
{
    for(ll i=1; i<=k; i++)
    {
        adj[i].clear();
        rev[i].clear();
    }
}
int main()
{
    ll test;
    sc1(test);
    ll tt=1;
    while(test--)
    {
        sc3(n,m,src);
        sc2(des,p);
        reset(n);
        for(ll i=1; i<=m; i++)
        {
            ll u,v,c;
            sc3(u,v,c);
            Edge e;
            e.v=v;
            e.w=c;
            adj[u].pb(e);
            e.v=u;
            e.w=c;
            rev[v].pb(e);
        }
        dijkstra(src);
        dijkstra2(des);
        ll ans=-1;
        for(ll i=1; i<=n; i++)
        {
            ll sz=adj[i].size();
            for(ll j=0; j<sz; j++)
            {
                Edge e=adj[i][j];
                ll now=dist[i]+dist2[e.v]+e.w;
                if(now<=p)
                {
                    ans=max(ans,e.w);
                }
            }
        }
        printf("Case %lld: %lld\n",tt++,ans);
    }
    return 0;
}
