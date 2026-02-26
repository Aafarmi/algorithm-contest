#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
const int mod=1e9+7;
void solve(){
    int n;cin>>n;
    vector<int> a(n);
    unordered_set<int> mp;
    for(int i=0;i<n;i++) cin>>a[i];
    auto it=remove_if(a.begin(),a.end(),[&](int x){return !mp.insert(x).sc;});
    //会将使得lambda返回true的元素"移除"到末尾
    //实际上是把需要保留的元素前移，返回新的逻辑终点迭代器
    a.erase(it,a.end());
    for(auto p:a) cout<<p<<" ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) solve();
}