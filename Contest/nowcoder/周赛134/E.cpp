#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    int n;cin>>n;
    string s;cin>>s;
    bool all=true,c1=false;
    for(int i=0;i<n;i++){
        if(s[i]=='1') c1=true;
        if(s[i]=='0') all=false;
    }
    if(all){
        cout<<n<<endl;
        return;
    }
    if(c1) cout<<n-1<<endl;
    else cout<<0<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
