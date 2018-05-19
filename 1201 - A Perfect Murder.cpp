#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,m;
vector<int>ed[1005];

int dp[1005][5];

int par[1005];

int call(int u,int kill)
{
    if(ed[u].size()==0)
        return 1;
    if(dp[u][kill]!=-1)
        return dp[u][kill];

    int sum=0;
    for(int i=0; i<ed[u].size(); i++)
    {
        int v=ed[u][i];
        if(v!=par[u])
        {
            par[v]=u;

            if(kill==0)
            {
                sum+=max(call(v,1),call(v,0));
            }
            else
            {
                sum+=call(v,0);
            }
        }
    }
    return dp[u][kill]=sum+kill;
}

int main()
{
    int test,t=1;
    scanf("%d",&test);

    while(test--)
    {
        memset(dp,-1,sizeof dp);
        memset(par,-1,sizeof par);
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            ed[i].clear();
        for(int i=1; i<=m; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            ed[u].pb(v);
            ed[v].pb(u);
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(par[i]==-1)
                ans+=max(call(i,1),call(i,0));
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
