#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=5e5+7;
struct MakeTree{
    vector<int> p;
    MakeTree(int n): p(n,0){}
    public:
        void add(int x,int val);
        int query(int k);
};
void MakeTree::add(int x,int val){
    for(;x<p.size();x+=(x&-x)) p[x]+=val;
}
int MakeTree::query(int x){
    int sum=0;
    while(x>0){
        sum+=p[x];
        x=x-(x&-x);
    }
    return sum;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n);
    for(int& x:a) cin>>x;
    vector<int> tmp=a;
    ranges::sort(tmp);
    tmp.erase(unique(all(tmp)),tmp.end());
    for(int& x:a){
        x=lower_bound(all(tmp),x)-tmp.begin()+1;
    }
    MakeTree tr(n+2);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(i-tr.query(a[i]));
        tr.add(a[i],1);
    }
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}