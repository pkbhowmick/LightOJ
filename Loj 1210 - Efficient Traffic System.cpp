#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 20005
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

vector<ll>adj[MX];
vector<ll>rev[MX];
ll vis[MX],dag[MX],scc,in[MX],out[MX];
stack<ll>S;

void dfs1(ll s)
{
    vis[s]=1;
    for(ll i=0; i<adj[s].size(); i++)
    {
        ll u=adj[s][i];
        if(vis[u]==0)
            dfs1(u);
    }
    S.push(s);
}

void dfs2(ll u)
{
    vis[u]=1;
    for(ll i=0; i<rev[u].size(); i++)
    {
        ll v=rev[u][i];
        if(vis[v]==0)
            dfs2(v);
    }
    dag[u]=scc;
}

int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n,m;
        sc2(n,m);
        for(ll i=1; i<=n; i++)
        {
            while(!S.empty())
                S.pop();
            adj[i].clear();
            rev[i].clear();
            vis[i]=0;
        }
        for(ll i=1; i<=m; i++)
        {
            ll u,v;
            sc2(u,v);
            adj[u].pb(v);
            rev[v].pb(u);
        }
        for(ll i=1; i<=n; i++)
        {
            if(vis[i]==0)
            dfs1(i);
        }
        scc=0;
        memset(vis,0,sizeof vis);
        while(!S.empty())
        {
            ll u=S.top();
            //cout<<u<<endl;
            S.pop();
            if(vis[u]==0)
            {
                scc++;
                dfs2(u);

            }
        }
        if(scc==1)
        {
            printf("Case %lld: 0\n",t++);
            continue;
        }
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<adj[i].size();j++)
            {
                ll u=adj[i][j];
                if(dag[i]!=dag[u])
                {
                    in[dag[u]]++;
                    out[dag[i]]++;
                    //cout<<i<<" "<<u<<endl;
                }
            }
        }
        //cout<<scc<<endl;
        //cout<<scc<<endl;
        ll c1=0,c2=0;
        for(ll i=1;i<=scc;i++)
        {
            if(in[i]==0)c1++;
            if(out[i]==0)c2++;
        }
        ll ans=max(c1,c2);
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
