#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

ll arr[32];

bool check(ll n,ll i)
{
    return n&(1<<i);
}

int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n,w;
        sc2(n,w);
        for(ll i=0;i<n;i++)
        {
            sc1(arr[i]);
        }
        ll lo=15;
        if(n<=15)
            lo=n;

        ll mx=pow(2,lo);
        vector<ll>V;
        ll an=0;
        for(ll i=0;i<mx;i++)
        {
            ll sum=0;
            for(ll j=0;j<lo;j++)
            {
                if(check(i,j))
                    sum+=arr[j];
            }
            V.pb(sum);
            if(sum<=w)
                an++;
        }
        sort(V.begin(),V.end());
        vector<ll>V2;
        lo=(n-15);
        if(lo>0)
        mx=pow(2,lo);
        for(ll i=0;i<mx&&lo>0;i++)
        {
            ll sum=0;
            for(ll j=0;j<lo;j++)
            {
                if(check(i,j))
                    sum+=arr[15+j];
            }
            V2.pb(sum);
        }
        ll sz=V.size();
        ll sz2=V2.size();
        ll ans=0;
        for(ll i=0;i<sz2;i++)
        {
            ll now=V2[i];
            if(now<=w)
            {
                ans++;
                ll need=w-now;
                if(need>0)
                {
                    ll id=upper_bound(V.begin(),V.end(),need)-V.begin();
                    ans+=(id-1);
                }
            }
        }
        if(n<=15)
            ans=an;
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
