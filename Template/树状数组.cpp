//LuoGuP1168
//树状数组：高效维护前缀信息，可以实现动态log(n)维护
//差分实现：单点查询，区间查询
//前缀查询，单点修改，logn
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
const int N=1e5+7;
struct MakeTree{
    vector<int> p;
    MakeTree(int n): p(n+1,0){}
    public:
        void add(int x,int val);
        int query(int k);
        int get_sum(int k);
};
inline int lowbit(int x){
    return x&(-x);
}
void MakeTree::add(int x,int val){
    for(;x<p.size();x+=lowbit(x)) p[x]+=val;
}
int MakeTree::query(int k){
    //log(n)实现寻找第k小
    int idx=0;
    for(int i=1<<18;i>=1;i>>=1){
        if(idx+i<p.size()&&p[idx+i]<k){
            idx+=i;
            k-=p[idx];
        }
    }
    return idx+1;
}
int MakeTree::get_sum(int k){
    //二分log(n)*log(n)
    int sum=0;
    while(k){
        sum+=p[k];
        k-=lowbit(k);
    }
    return sum;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> tmp=a;
    sort(tmp.begin()+1,tmp.end());
    tmp.erase(unique(tmp.begin()+1,tmp.end()),tmp.end());
    for(int i=1;i<=n;i++){
        int idx=lower_bound(tmp.begin()+1,tmp.end(),a[i])-tmp.begin();
        a[i]=idx;
    }
    MakeTree tr(tmp.size()-1);
    for(int i=1;i<=n;i++){
        tr.add(a[i],1);
        if(i&1){
            //int idx=tr.query(i);
            int l=1,r=n,idx=0;
            while(l<=r){
                int mid=(l+r)/2;
                if(tr.get_sum(mid)>=(i+1)/2) r=mid-1,idx=mid;
                else l=mid+1;
            }
            cout<<tmp[idx]<<endl;
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