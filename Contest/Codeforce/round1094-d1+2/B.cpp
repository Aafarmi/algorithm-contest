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
    int n,m;cin>>n>>m;
    vector<int> a(n+1),x(m+1);
    vector<P> r;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        r.push_back({a[i],i});
    }
    for(int i=1;i<=m;i++) cin>>x[i];
    vector<int> odd,even;
    sort(all(r),greater<P>());
    for(P it:r){
        if(it.sc&1) odd.emplace_back(it.fr);
        else even.emplace_back(it.fr);
    }
    // for(int p:odd) cout<<p<<" ";
    // cout<<"|";
    // for(int p:even) cout<<p<<" ";
    // cout<<"|";
    int p_odd=0,p_even=0;
    for(int i=1;i<=m;i++){
        if(x[i]&1){
            if(p_odd>=odd.size()) continue;
            if(odd[p_odd]>0) sum-=odd[p_odd];
            else{
                if(odd[0]<0&&p_odd==0) sum-=odd[p_odd];
            }
            p_odd++;
        }else{
            if(p_even>=even.size()) continue;
            if(even[p_even]>0) sum-=even[p_even];
            else{
                if(even[0]<0&&p_even==0) sum-=even[p_even];
            }
            p_even++;
        }
    }
    cout<<sum<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}