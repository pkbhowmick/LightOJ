#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;

bool prime[1000006];

ll mob[1000006];
void seive()
{
    for(ll i=2; i<=1000000; i++)
    {
        if(!prime[i])
        {
            for(ll j=i; j<=1000000; j+=i){
                prime[j]=true;
                if(j%(i*i)==0)mob[j]=0;
                mob[j]*=(-1);
            }
        }
    }
}

int main()
{
    for(ll i=1;i<=1000000;i++)
        mob[i]=1;
    seive();
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n,m;
        sc2(n,m);
        if(n>m)swap(n,m);
        ll tot=n*m;
        for(ll i=2;i<=n;i++)
        {
            //cout<<mob[i]<<endl;
            if(mob[i]==1)
                tot+=((n/i)*(m/i));
            else if(mob[i]==-1)
                tot-=((n/i)*(m/i));

        }
        if(n>0)
            tot++;
        if(m>0)
            tot++;

        printf("Case %lld: %lld\n",t++,tot);
    }
    return 0;
}
