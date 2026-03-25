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
const int N=1007;
vector<vector<int>> g(N,vector<int>());
int w[N];
bitset<1007> dp[N];
void order(int x,int fa){
    if(g[x].size()==1&&g[x][0]==fa){
        dp[x].set(0);
        dp[x].set(w[x]);
        return;
    }
    bitset<N> now;
    now.set(0);
    for(int it:g[x])if(it!=fa){
        order(it,x);
        bitset<N> tmp;
        for(int i=0;i<=w[x];i++)if(dp[it].test(i))
            tmp|=(now<<i);
        now=tmp;
    }
    dp[x]=now;
    for(int i=w[x]+1;i<=1000;i++) dp[x].reset(i);
    dp[x].set(0);
}
void Srend(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    order(1,-1);
    int ans=0;
    for(int i=w[1];i>=0;i--)if(dp[1].test(i)){
        ans=i;
        break;
    }
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}