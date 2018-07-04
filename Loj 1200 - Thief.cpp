#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll n,w;
ll pr[105],we[105];
ll dp[105][10005];

ll solve(ll pos,ll baki)
{
    if(pos>n||baki==0)
    {
        return 0;
    }
    if(dp[pos][baki]!=-1)return dp[pos][baki];
    ll ret1=0,ret2=0;
    if(we[pos]<=baki)
        ret1=pr[pos]+max(solve(pos,baki-we[pos]),solve(pos+1,baki-we[pos]));
    ret2=solve(pos+1,baki);
    return dp[pos][baki]=max(ret1,ret2);
}
int main()
{
    ll t=1,test;
    sc1(test);
    while(test--)
    {
        memset(dp,-1,sizeof dp);
        sc2(n,w);
        ll tot=0;
        for(ll i=1;i<=n;i++)
        {
            ll v;
            sc3(pr[i],v,we[i]);
            tot+=v*we[i];
        }
        if(tot>w)
        {
            printf("Case %lld: Impossible\n",t++);
            continue;
        }
        ll ans=solve(1,w-tot);
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
