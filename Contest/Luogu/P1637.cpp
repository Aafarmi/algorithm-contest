#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin()+1,arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
struct MakeTree{
    vector<int> p;
    MakeTree(int size): p(size+1,0){}
    public:
        void add(int idx,int val);
        int query(int x);
};
inline int lowbit(int x){
    return x&(-x);
}
void MakeTree::add(int idx,int val){
    for(;idx<p.size();idx+=lowbit(idx)) p[idx]+=val;
}
int MakeTree::query(int x){
    int sum=0;
    for(;x>=1;x-=lowbit(x)) sum+=p[x];
    return sum;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
    MakeTree tr_pre(mx),tr_back(mx);
    vector<int> pre(n+1,0),back(n+1,0);
    for(int i=1;i<=n;i++){
        tr_pre.add(a[i],1);
        if(i==1) continue;
        pre[i]=tr_pre.query(a[i]-1);
    }
    for(int i=n;i>=1;i--){
        tr_back.add(a[i],1);
        if(i==n) continue;
        back[i]=n-i+1-tr_back.query(a[i]);
    }
    int ans=0;
    for(int i=2;i<n;i++){
        ans+=pre[i]*back[i];
        //cerr<<pre[i]<<" "<<back[i]<<endl;
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