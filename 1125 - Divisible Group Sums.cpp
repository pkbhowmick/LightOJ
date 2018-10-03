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
ll arr[205];
ll dp[205][25][15];
ll d;
ll n;
ll solve(ll pos,ll sum,ll need)
{
    sum=sum%d;
    sum+=d;
    sum=sum%d;
    if(need==0)
    {
        if(sum==0)return 1;
        else return 0;
    }
    if(pos>n)
        return 0;
    if(dp[pos][sum][need]!=-1)return dp[pos][sum][need];
    ll ret1=0,ret2=0;
    ret1=solve(pos+1,sum+arr[pos],need-1);
    ret2=solve(pos+1,sum,need);
    return dp[pos][sum][need]=ret1+ret2;
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {

        ll q;
        sc2(n,q);
        for(ll i=1; i<=n; i++)
        {
            sc1(arr[i]);
        }
        printf("Case %lld:\n",t++);
        while(q--)
        {
            memset(dp,-1,sizeof dp);
            ll m;
            sc2(d,m);
            ll ans=solve(1,0,m);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
