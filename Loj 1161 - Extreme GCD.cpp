#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll cnt[10005];
ll ans[10005];
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        memset(cnt,0,sizeof cnt);
        ll n;
        sc1(n);
        for(ll i=1;i<=n;i++)
        {
            ll v;
            sc1(v);
            cnt[v]++;
        }
        for(ll i=10000;i>0;i--)
        {
            ll now=cnt[i];
            for(ll j=i+i;j<=10000;j+=i)
                now+=cnt[j];
            now=(now)*(now-1)*(now-2)*(now-3);
            now=now/24;
            for(ll j=i+i;j<=10000;j+=i)
                now=now-ans[j];

            ans[i]=now;
        }
        printf("Case %lld: %lld\n",t++,ans[1]);
    }
    return 0;
}
