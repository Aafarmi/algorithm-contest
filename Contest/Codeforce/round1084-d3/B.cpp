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
    vector<int> a(n+1);
    bool ok=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i-1>=1&&a[i]<a[i-1]) ok=true;
    }
    if(ok) cout<<"1\n";
    else cout<<n<<'\n';
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}