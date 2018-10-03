#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll arr[1005];
ll brr[1005];
ll ab[1005];
ll ba[1005];
ll dp[1005][3];
ll n;
ll solve(ll pos,ll lvl)
{
    if(pos==n)
    {
        if(lvl)
            return brr[n];
        else
            return arr[n];
    }
    if(dp[pos][lvl]!=-1)return dp[pos][lvl];
    ll ret1=0,ret2=0;
    if(lvl==0)
    {
        ret1=arr[pos]+solve(pos+1,0);
        ret2=arr[pos]+ab[pos+1]+solve(pos+1,1);
    }
    else
    {
        ret1=brr[pos]+solve(pos+1,1);
        ret2=brr[pos]+ba[pos+1]+solve(pos+1,0);
    }
    return dp[pos][lvl]=min(ret1,ret2);
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        memset(dp,-1,sizeof dp);
        sc1(n);
        for(ll i=1; i<=n; i++)
        {
            sc1(arr[i]);
        }
        for(ll i=1; i<=n; i++)
        {
            sc1(brr[i]);
        }
        for(ll i=2;i<=n;i++)
            sc1(ab[i]);
        for(ll i=2;i<=n;i++)
            sc1(ba[i]);
        ll ans=min(solve(1,0),solve(1,1));
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
