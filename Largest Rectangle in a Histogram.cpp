#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
    Fast_Input
    int n;

    while(cin >> n && n)
    {
        vector<ll>v;
        ll x,y,mx=-1;
        while(n--)
        {
            cin >> x;
            v.push_back(x);
            mx=max(mx,x);
        }
        deque<pair<ll,ll>>q;
        ll coun;
        for(int i=0; i<v.size(); i++)
        {
            coun = 0;
            while(!q.empty() && v[i]<=q.back().first)
            {
                x = q.back().first;
                y=q.back().second;
                q.pop_back();

                coun+=y;
                if(x==v[i])mx=max(mx,(coun+1)*x);
                else mx=max(mx,coun*x);
            }

            q.push_back({v[i],coun+1});

        }

        coun = 0;
        while(!q.empty())
        {
            x = q.back().first;
            y=q.back().second;
            q.pop_back();
            coun+=y;
            mx=max(mx,coun*x);
        }
        cout << mx << "\n";
    }
    return 0;
}
