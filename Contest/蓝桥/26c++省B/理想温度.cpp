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
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),d(n+1),pre(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) d[i]=b[i]-a[i];
    pre[1]=(d[1]==0);
    for(int i=2;i<=n;i++){
        pre[i]=pre[i-1]+(d[i]==0);
    }
    vector<P> e;
    for(int i=1;i<=n;i++){
        if(d[i]!=0) e.emplace_back(make_pair(d[i],i));
    }
    sort(e.begin(),e.end());
    int ans=0;
    for(int l=0;l<e.size();){
        int val=e[l].fr;
        int r=l;
        while(r<e.size()&&e[r].fr==val) r++;
        int cur=0,mx=0;
        for(int i=l;i<r;i++){
            cur++;
            if(i>l){
                cur=cur-(pre[e[i].sc]-pre[e[i-1].sc]);
            }
            if(cur<=0) cur=1;
            mx=max(mx,cur);
            ans=max(mx,ans);
        }
        l=r;
    }
    cout<<ans+pre[n]<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}