#include <bits/stdc++.h>
#define pb push_back
#define sc1(n) scanf("%lld",&n)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define MX 100000
using namespace std;

typedef long long int ll;
typedef unsigned long long ul;
ll n,k,w;
struct point
{
    ll x,y;
};
vector<point>V;
bool operator < (point a,point b)
{
    return a.y<b.y;
}
ll dp[105][105];
ll Find(ll pos)
{
    ll lo=pos;
    ll hi=n-1;
    ll mid;
    ll ans=0;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(V[mid].y<=V[pos].y+w){
            lo=mid+1;
            ans=max(ans,mid-pos+1);
        }
        else
            hi=mid-1;
    }
    return ans;
}
ll solve(ll pos,ll mov)
{
    //cout<<"call "<<pos<<" "<<mov<<endl;
    if(pos>=n||mov==0)
    {
        return 0;
    }
    if(dp[pos][mov]!=-1)
        return dp[pos][mov];
    ll ret1=0,ret2=0;
    if(mov>0)
    {
        ll get=Find(pos);
        //cout<<pos<<" "<<get<<endl;
        ret1=get+solve(pos+get,mov-1);
    }
    ret2=solve(pos+1,mov);
    return dp[pos][mov]=max(ret1,ret2);

}
int main()
{
    ll test,t=1;
    sc1(test);
    while(test--)
    {
        memset(dp,-1,sizeof dp);
        V.clear();
        sc3(n,w,k);
        for(ll i=1; i<=n; i++)
        {
            ll x,y;
            sc2(x,y);
            point p;
            p.x=x;
            p.y=y;
            V.pb(p);
        }
        sort(V.begin(),V.end());
        ll ans=solve(0,k);
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
