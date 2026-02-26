#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e6+7;
struct edge{
    int from,to,w;
};
int n,E;//点数，边数
int f[N][N];
void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[N][N]=INF;
        }
    }
    for(int i=1;i<=E;i++){
        int u,v;cin>>u>>v;
        cin>>f[u][v];
    }
}
void Floyd(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
}
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<n;i++)
        a[0]=gcd(a[0],a[i]);
    ll x=a[0]*n;
    cout<<x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve();
}
