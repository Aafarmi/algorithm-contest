/*https://codeforces.com/contest/2205/problem/C*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
    vector<vector<int>> a;
    for(int i=1;i<=n;i++){
        int l;cin>>l;
        vector<int> res(l);
        for(int j=0;j<l;j++) cin>>res[j];
        unordered_map<int,int> mp;
        vector<int> _res;
        for(auto it=res.rbegin();it!=res.rend();it++){
            bool ok=mp.insert({*it,1}).sc;
            if(ok) _res.emplace_back(*it);
        }
        a.emplace_back(_res);
    }
    vector<int> ans;
    vector<int> used(n,false);
    unordered_map<int,bool> vis;
    for(int c=0;c<n;c++){
        int idx=-1;
        vector<int> now;
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            vector<int> res;
            for(int p:a[i]){
                if(!vis[p]) res.emplace_back(p);
            }
            if(idx==-1||res<now){
                now=res;
                idx=i;
            }
        }
        used[idx]=true;
        for(int p:now){
            vis[p]=true;
            ans.emplace_back(p);
        }
    }
    for(auto p:ans) printf("%d ",p);
    printf("\n");
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}