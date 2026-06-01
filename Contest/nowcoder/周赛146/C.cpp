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
    int n;cin>>n;
    unordered_map<int,vector<int>> bx,by;
    set<P> s;
    for(int i=1;i<=n;i++){
        int x,y;cin>>x>>y;
        bx[x].emplace_back(y);
        by[y].emplace_back(x);
        s.insert(make_pair(x,y));
    }
    int ans=0;
    for(P p:s)  if(bx.find(p.fr)!=bx.end()){
        for(int y:bx[p.fr]) if(y>p.sc&&(p.sc+y)%2==0){
            int t=(p.sc+y)/2;
            if(by.find(t)!=by.end()){
                for(int it:by[t]) if(it!=p.fr) ans++;
            }
        }
    }
    for(P p:s) if(by.find(p.sc)!=by.end()){
        for(int x:by[p.sc]) if(x>p.fr&&(p.fr+x)%2==0){
            int t=(p.fr+x)/2;
            if(bx.find(t)!=bx.end()){
                for(int it:bx[t]) if(it!=p.sc) ans++;
            }
        }
    }
    ans/=2;
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}