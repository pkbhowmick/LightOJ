#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
ll n,arr[1005];

ll dp1[1005];
ll dp2[1005];
ll solve1(ll pos)
{
    if(pos>n-1)
    {
        return 0;
    }
    if(dp1[pos]!=-1)return dp1[pos];
    ll ret1=0,ret2=0;
    ret1=arr[pos]+solve1(pos+2);
    ret2=solve1(pos+1);

    return dp1[pos]=max(ret1,ret2);
}
ll solve2(ll pos)
{
    if(pos>n)
    {
        return 0;
    }
    if(dp2[pos]!=-1)return dp2[pos];
    ll ret1=0,ret2=0;
    ret1=arr[pos]+solve2(pos+2);
    ret2=solve2(pos+1);

    return dp2[pos]=max(ret1,ret2);
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        sc1(n);
        for(ll i=1;i<=n;i++)
        {
            sc1(arr[i]);
        }
        ll ans=max(solve1(1),solve2(2));
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
