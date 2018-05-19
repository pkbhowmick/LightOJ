#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

vector<ll>V;
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
        V.clear();
        ll n,m;
        sc2(n,m);
        for(ll i=1;i<=m;i++)
        {
            ll v;
            sc1(v);
            V.pb(v);
        }
        ll mx=pow(2,m);
        ll tot=0;
        //cout<<mx<<endl;
        for(ll i=1;i<mx;i++)
        {
            vector<ll>now;
            ll lcm=1;
            for(ll j=0;j<m;j++)
            {
                if(check(i,j))
                {
                    now.pb(V[j]);
                }
            }
            ll sz=now.size();
            for(ll j=0;j<sz;j++)
            {
                ll gc=__gcd(lcm,now[j]);
                lcm=(lcm*now[j])/gc;
            }
            ll add=n/lcm;
            if(sz%2)
                tot+=add;
            else
                tot-=add;
        }
        ll ans=n-tot;
        printf("Case %lld: %lld\n",t++,ans);
    }

    return 0;
}
