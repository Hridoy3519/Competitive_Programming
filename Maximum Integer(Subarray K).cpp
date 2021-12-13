
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
int main()
{
    Fast_Input

    int t;cin >> t;

    while(t--){
        int n, k;cin >> n >> k;

        int arr[n+1];
        for(int i=1;i<=n;i++)cin >> arr[i];

        deque<int>d;

        for(int i=1;i<=n;i++){

            while(!d.empty() && arr[i]>=arr[d.back()]){
                d.pop_back();
            }
            d.push_back(i);

            while(!d.empty() && d.front()<=i-k){
                d.pop_front();
            }

            if(i>=k)cout << arr[d.front()] << " ";
        }

        cout << "\n";
    }
    return 0;
}
