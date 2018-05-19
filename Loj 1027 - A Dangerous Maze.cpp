#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n;
        sc1(n);
        ll neg=0;
        ll tot=0;
        for(ll i=1;i<=n;i++)
        {
            ll v;
            sc1(v);
            if(v<0)
            {
                neg++;
                v=-v;
            }
            tot+=v;
        }
        printf("Case %lld: ",t++);
        if(neg==n)
        {
            printf("inf\n");
            continue;
        }
        ll now=n-neg;
        ll gc=__gcd(tot,now);
        now=now/gc;
        tot=tot/gc;
        printf("%lld/%lld\n",tot,now);
    }
    return 0;
}
