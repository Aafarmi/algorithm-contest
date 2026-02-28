#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void Srend(){
    int n;cin>>n;
    string s;cin>>s;
    stack<char> st;
    for(auto c:s){
        if(st.empty()){
            st.push(c);
            continue;
        }
        if(c==st.top()) st.pop();
        else st.push(c);
    }
    if(st.empty()) cout<<"YES\n";
    else cout<<"NO\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}