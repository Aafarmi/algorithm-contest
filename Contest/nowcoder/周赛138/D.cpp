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
void define(vector<vector<int>>& g,int n){
    vector<bool> vis(n+1);
    vector<vector<int>> res(n+1);
    vis[1]=true;
    queue<int> q;q.push(1);
    while(q.size()){
        int u=q.front();q.pop();
        for(int p:g[u]){
            if(!vis[p]){
                res[u].emplace_back(p);
                vis[p]=true;
                q.push(p);
            }
        }
    }
    g=res;
}
void dfs(int x,int len,int& ans,vector<vector<int>>& g,vector<int>& c){
    ans+=len-1;
    for(int p:g[x]){
        if(c[p]==c[x]) dfs(p,len+1,ans,g,c);
        else dfs(p,1,ans,g,c);
    }
}
void Srend(){
    int n;cin>>n;
    vector<int> c(n+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    vector<vector<int>> g(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    define(g,n);
    int ans=0;
    dfs(1,1,ans,g,c);
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}