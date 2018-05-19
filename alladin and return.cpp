///LOJ - Aladdin and the Return Journey

#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 60005
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll cost[MX/2];
vector<ll>ed[MX/2];
ll dis[MX/2];
ll fin[MX/2];
ll cost2[MX];
ll seg[4*MX];
ll tim;
ll par[MX/2];
ll P[MX/2][50];
ll L[MX/2];

void build(ll n,ll l,ll r)
{
    if(l==r)
    {
        seg[n]=cost2[l];
        return;
    }
    ll mid=(l+r)/2;
    build(n*2,l,mid);
    build(n*2+1,mid+1,r);
    seg[n]=seg[2*n]+seg[2*n+1];
}

void update(ll n,ll l,ll r,ll pos,ll val)
{
    if(l==r)
    {
        seg[n]=val;
        return;
    }
    ll mid=(l+r)/2;
    if(pos<=mid)
        update(2*n,l,mid,pos,val);
    else
        update(2*n+1,mid+1,r,pos,val);

    seg[n]=seg[2*n]+seg[2*n+1];
}

ll query(ll n,ll L,ll R,ll l,ll r)
{
    if(L>r||R<l)return 0;
    if(L>=l&&R<=r)return seg[n];
    ll mid=(L+R)/2;
    ll x=query(n*2,L,mid,l,r);
    ll y=query(n*2+1,mid+1,R,l,r);
    return x+y;
}

void dfs(ll u,ll p)
{
    par[u]=p;
    L[u]=L[p]+1;
    dis[u]=++tim;
    cost2[dis[u]]=cost[u];
    for(ll i=0; i<ed[u].size(); i++)
    {
        ll v=ed[u][i];
        if(v==par[u])
            continue;

        //cout<<"call "<<v<<endl;
        dfs(v,u);
    }
    fin[u]=++tim;
    cost2[fin[u]]=-cost[u];
}

ll lca_query(ll N, ll p, ll q)
{
    ll tmp, log, i;

    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    log=1;
    while(1)
    {
        ll next=log+1;
        if((1<<next)>L[p])
            break;
        log++;

    }

    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];

    return par[p];
}

void lca_init(ll N)
{
    memset (P,-1,sizeof(P));
    ll i,j;
    for (i = 0; i < N; i++)
        P[i][0] = par[i];

    for (j = 1; (1 << j) < N; j++)
        for (i = 0; i < N; i++)
            if (P[i][j - 1] != -1)
                P[i][j] = P[P[i][j - 1]][j - 1];
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n;
        sc1(n);
        for(ll i=0; i<n; i++)
            sc1(cost[i]);

        for(ll i=0;i<n;i++)
            ed[i].clear();
        for(ll i=1; i<n; i++)
        {
            ll u,v;
            sc2(u,v);
            ed[u].pb(v);
            ed[v].pb(u);
        }
        tim=0;
        dfs(0,-1);
        build(1,1,2*n);
        lca_init(n);

        printf("Case %lld:\n",t++);
        ll q;
        sc1(q);

        while(q--)
        {
            ll ty,x,y;
            sc3(ty,x,y);
            if(ty)
            {
                update(1,1,2*n,dis[x],y);
                update(1,1,2*n,fin[x],-y);
                cost[x]=y;
            }
            else
            {
                ll lca=lca_query(n,x,y);
                ll ad1=query(1,1,2*n,dis[lca],dis[x]);
                ll ad2=query(1,1,2*n,dis[lca],dis[y]);
                ll now=ad1+ad2-cost[lca];
                printf("%lld\n",now);
            }

        }
    }
    return 0;
}
