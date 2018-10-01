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

ll arr[100005];
ll brr[100005];

ll I[100005];
ll L[100005];
ll I2[100005];
ll L2[100005];
ll n;
void LIS1()
{
    ll len=0;
    for(ll i=1;i<=n;i++)
    {
        ll lo=0;
        ll hi=len;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            if(I[mid]<arr[i])
                lo=mid+1;
            else
                hi=mid-1;
        }
        I[lo]=arr[i];
        L[i]=lo;
        if(len<lo)
            len=lo;
    }
}
void LIS2()
{
    ll len=0;
    for(ll i=1;i<=n;i++)
    {
        ll lo=0;
        ll hi=len;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            if(I2[mid]<brr[i])
                lo=mid+1;
            else
                hi=mid-1;
        }
        I2[lo]=brr[i];
        L2[i]=lo;
        if(len<lo)
            len=lo;
    }
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        sc1(n);
        I[0]=-INT_MAX;
        I2[0]=-INT_MAX;
        for(ll i=1,j=n;i<=n;i++,j--)
        {
            sc1(arr[i]);
            brr[j]=arr[i];
            I[i]=INT_MAX;
            I2[i]=INT_MAX;
        }
        LIS1();
        LIS2();
        ll ans=0;
        for(ll i=1,j=n;i<=n;i++,j--)
        {
            ll now=min(L[i],L2[j]);
            //cout<<L[i]<<" "<<L2[j]<<endl;
            //cout<<"id "<<i<<" "<<now<<endl;
            now=now*2-1;
            ans=max(ans,now);
        }
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
