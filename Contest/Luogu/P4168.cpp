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
const int N=4e4+7;
struct Node{
    int l,r,z;
    vector<int> g;
}b[207];
vector<int> a(N),pos(N);
unordered_map<int,vector<int>> mp;
int query(int l,int r){
    unordered_set<int> res;
    for(int i=pos[l];i<=pos[r];i++){
        if(l<=b[i].l&&b[i].r<=r){
            res.insert(b[i].z);
            continue;
        }
        int mi=max(l,b[i].l);
        int mx=min(r,b[i].r);
        for(int j=mi;j<=mx;j++) res.insert(a[j]);
    }
    int cnt=0,ans;
    for(int it:res){
        int tmp=upper_bound(all(mp[it]),r)-lower_bound(all(mp[it]),l);
        if(tmp>cnt){
            cnt=tmp;
            ans=it;
        }
    }
    return ans;
}
void Srend(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]].emplace_back(i);
    }
    int sz=sqrt(n),num=sz+(n%sz!=0);
    for(int i=1;i<=num;i++){
        int l=(i-1)*sz+1;
        int r=min(n,i*sz);
        b[i].l=l;b[i].r=r;
        unordered_map<int,int> tmp;
        for(int j=l;j<=r;j++){
            pos[j]=i;
            b[i].g.emplace_back(a[i]);
            tmp[a[i]]++;
        }
        int mx=0;
        for(auto [fr,sc]:tmp) if(sc>mx) b[i].z=fr;
    }
    int x=0;
    while(m--){
        int l,r;cin>>l>>r;
        l=((l+x-1)%n)+1;r=((r+x-1)%n)+1;
        if(l>r) swap(l,r);
        x=query(l,r);
        cout<<x<<endl;
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}