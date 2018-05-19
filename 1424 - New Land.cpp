#include <bits/stdc++.h>

using namespace std;
int arr[2001][2001];
int n,m;
int sum[2001][2001];
void calc()
{
    for(int i=0; i<m; i++)
    {
        int cnt=0;
        for(int j=0; j<n; j++)
        {
            if(arr[j][i]==1)
            {
                sum[j][i]=0;
                cnt=0;
            }
            else
            {
                cnt++;
                sum[j][i]=cnt;
            }
        }
    }


}
int solve(int r)
{
    stack<int>S;
    //S.push(0);
    int mx=0;
    S.push(0);
    int area;
    for(int i=1; i<m; i++)
    {
        if(sum[r][S.top()]<=sum[r][i])
        {
            S.push(i);
        }
        else
        {
            while(!S.empty()&&sum[r][S.top()]>sum[r][i])
            {
                int tt=S.top();
                S.pop();
                //cout<<tt<<endl;
                if(S.empty())
                {
                    area=sum[r][tt]*i;
                }
                else
                {
                    area=sum[r][tt]*(i-S.top()-1);
                }
                mx=max(area,mx);
            }
            S.push(i);
        }
        //cout<<mx<<endl;
    }
    int i=m;
    while(!S.empty())
    {
        int tt=S.top();
        S.pop();
        //cout<<tt<<endl;
        if(S.empty())
        {
            area=sum[r][tt]*i;
            //cout<<area<<endl;
        }
        else
        {
            area=sum[r][tt]*(i-S.top()-1);
        }
        mx=max(area,mx);
        //cout<<mx<<endl;
    }
    //cout<<"\n";
    return mx;
}
int main()
{
    int test,t=1;
    scanf("%d",&test);
    while(test--)
    {
        //int n,m;
        scanf("%d%d",&n,&m);

        for(int i=0; i<n; i++)
        {
            getchar();
            for(int j=0; j<m; j++)
            {
                char c;
                scanf("%c",&c);
                //scanf("%d",&arr[i][j]);
                arr[i][j]=c-'0';
            }
        }
        calc();

        int ans=0;
        for(int i=n-1; i>=0; i--)
        {
            int now=solve(i);
            //cout<<now<<endl;
            ans=max(ans,now);
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
/*
2
5 7
0110110
0000010
1000001
0100001
1100010
3 3
001
100
101
*/
