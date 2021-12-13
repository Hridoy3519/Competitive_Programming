
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int main()
{
    Fast_Input

    int n;cin >> n;

    string a;
    map<ll,int>mp;
    vector<ll>v;
    while(n--){
        cin >> a;

        int arr[27]={0};

        for(int i=0;i<a.size();i++){
            arr[a[i]-'a']++;
        }

        ll sum=0, power =1;
        for(int i=0;i<26;i++){
            if(arr[i]%2){
                sum+=power;
            }
            power*=2;
        }
        v.push_back(sum);
        mp[sum]++;
    }

    ll ans =0,x;
    for(int i=0;i<v.size();i++){
        ans+=mp[v[i]]-1;
        bitset<40>bs(v[i]);
        for(int i=0;i<37;i++){
            bs.flip(i);
            x=bs.to_ullong();
            ans+=mp[x];
            bs.flip(i);
        }
    }

    cout << ans/2 << "\n";
    return 0;
}
