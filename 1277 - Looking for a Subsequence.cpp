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
ll I[100005];
ll L[100005];
ll arr[100005];
ll LIS(ll n)
{
    I[0]=-INT_MAX;
    for(ll i=1;i<=n;i++)
    {
        I[i]=INT_MAX;
    }
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
        if(lo>len)
            len=lo;
    }
    return len;
}
int main()
{
    ll test;
    sc1(test);
    ll t=1;
    while(test--)
    {
        ll n,q;
        sc2(n,q);
        for(ll i=n;i>=1;i--)
        {
            sc1(arr[i]);
            arr[i]=-arr[i];
        }
        ll mx=LIS(n);
        printf("Case %lld:\n",t++);
        while(q--)
        {
            ll v;
            sc1(v);
            ll k=v;
            ll tem=k;
            bool ok=true;
            if(v>mx)
            {
                printf("Impossible\n");
                continue;
            }
            for(ll i=n;i>=1;i--)
            {
                if(L[i]>v&&k==tem)
                {
                    ok=false;
                    v=L[i];
                    printf("%lld",-arr[i]);
                    v--;
                    k--;
                    if(k!=0)
                        printf(" ");
                    else
                        break;
                }
                else if(L[i]<v&&k<=L[i])
                {
                    v=L[i];
                    printf("%lld",-arr[i]);
                    v--;
                    k--;
                    if(k!=0)
                        printf(" ");
                    else
                        break;
                }
                else if(L[i]==v)
                {
                    printf("%lld",-arr[i]);
                    v--;
                    k--;
                    if(k!=0)
                        printf(" ");
                    else
                        break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
