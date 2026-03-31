#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    int n,k;cin>>n>>k;
    vector<int> a(n+1),b(n+1),pos(N);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1;i<=n;i++) cin>>b[i];
    bool ok=true;
    unordered_map<int,int> mp;
    int l=n+1-k,r=k;
    for(int i=1;i<=n;i++){
        if(!ok) break;
        if(b[i]==-1) continue;
        else{
            if(mp[b[i]]>=1) ok=false;
            mp[b[i]]++;
        }
        if(a[i]!=b[i]){
            bool next=false;
            if(n+1-k<=i&&i<=k)if(n+1-k<=pos[b[i]]&&pos[b[i]]<=k)
                next=true;
            if(next) continue;
            ok=false;
        }
    }
    if(ok) cout<<"YES\n";
    else cout<<"NO\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}