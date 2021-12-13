#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
int main()
{
    Fast_Input

    int n;cin >> n;

    while(n--){
        string s;cin >> s;

        stack<char>st;

        bool isValid = true;
        for(int i=0;i<s.size();i++){
            if(s[i]=='{' || s[i]=='(' || s[i]=='['){
                st.push(s[i]);
                continue;
            }

            if(st.empty()){
                isValid=false;
                break;
            }

            char poppedBracket = st.top();
            st.pop();
            if((s[i]=='}' && poppedBracket!='{') || (s[i]==']' && poppedBracket!='[') || (s[i]==')' && poppedBracket!='(')){
                isValid = false;
                break;
            }
        }

        if(isValid && st.empty())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
