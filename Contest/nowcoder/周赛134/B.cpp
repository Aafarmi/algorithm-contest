#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
typedef vector<vector<int>> matrix;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void solve(){
    int a,b,c,x,y;cin>>c>>b>>a>>x>>y;
    while(true){
        b+=a/x;
        a%=x;
        if(b/y==0) break;
        c+=b/y;
        a+=b/y;
        b%=y;
    }
    cout<<c;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
