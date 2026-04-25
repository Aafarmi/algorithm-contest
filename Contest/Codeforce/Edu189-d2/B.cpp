#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
void Srend(){
    string s;cin>>s;
    int cnt=0;
    for(int i=1;i<s.size();i++){
        char a=s[i],b=s[i-1];
        if(!(i&1)) a=(a=='a'?'b':'a');
        if(!((i-1)&1)) b=(b=='a'?'b':'a');
        if(a!=b) cnt++;
    }
    if(cnt>=3) cout<<"NO\n";
    else cout<<"YES\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}