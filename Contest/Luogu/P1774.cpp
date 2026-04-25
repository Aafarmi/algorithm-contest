#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
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
    for(;idx<p.size();idx+=lowbit(idx)){
        p[idx]+=val;
    }
    return;
}
int MakeTree::query(int x){
    int sum=0;
    for(;x>=1;x-=lowbit(x)) sum+=p[x];
    return sum;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> tmp=a;
    sort(tmp.begin()+1,tmp.end());
    tmp.erase(unique(tmp.begin()+1,tmp.end()),tmp.end());
    int mx=tmp.size()-1;
    for(int i=1;i<=n;i++){
        a[i]=lower_bound(tmp.begin()+1,tmp.end(),a[i])-tmp.begin();
    }
    MakeTree tr(mx);
    int ans=0;
    for(int i=1;i<=n;i++){
        tr.add(a[i],1);
        int pre=tr.query(a[i]),al=tr.query(mx);
        ans+=al-pre;
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
    return 0;
}