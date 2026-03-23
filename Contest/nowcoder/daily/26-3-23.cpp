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
const int mod=998244353;
const int N=1e5+7;
struct Node{
    int l,r,lz=0;
    vector<int> g;
}b[400];
void rebuild(int i,vector<int>& a){
    b[i].g.clear();
    for(int j=b[i].l;j<=b[i].r;j++)
        b[i].g.emplace_back(a[j]);
    sort(all(b[i].g));
    return;
}
void add(int l,int r,int k,int num,vector<int>& a){
    for(int i=1;i<=num;i++){
        if(b[i].r<l||r<b[i].l) continue;
        if(l<=b[i].l&&b[i].r<=r){
            b[i].lz+=k;
            continue;
        }
        int st=max(l,b[i].l);
        int ed=min(b[i].r,r);
        for(int j=st;j<=ed;j++) a[j]+=k;
        rebuild(i,a);
    }
}
int query(int l,int r,int x,int num,vector<int>& a){
    int ans=0;
    for(int i=1;i<=num;i++){
        if(b[i].r<l||r<b[i].l) continue;
        if(l<=b[i].l&&b[i].r<=r){
            int t=x-b[i].lz;
            int cnt=lower_bound(all(b[i].g),t)-b[i].g.begin();
            ans+=cnt;
            continue;
        }
        int st=max(l,b[i].l);
        int ed=min(b[i].r,r);
        for(int j=st;j<=ed;j++)if(a[j]+b[i].lz<x)
            ans++;
    }
    return ans;
}
void Srend(){
    int n,q;cin>>n>>q;
    vector<int> a(n+1),pos(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int blocksz=sqrt(n);
    int blocknum=n/blocksz+(n%blocksz!=0);
    for(int i=1;i<=blocknum;i++){
        b[i].l=(i-1)*blocksz+1;
        b[i].r=min(n,i*blocksz);
        for(int j=b[i].l;j<=b[i].r;j++){
            b[i].g.emplace_back(a[j]);
        }
        sort(all(b[i].g));
    }
    while(q--){
        int op;cin>>op;
        int l,r,x;cin>>l>>r>>x;
        if(op==1){
            add(l,r,x,blocknum,a);
        }else{
            int ans=query(l,r,x,blocknum,a);
            cout<<ans<<endl;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}