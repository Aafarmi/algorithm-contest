#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define all(arr) arr.begin(),arr.end()
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+7;
void Srend(){
    ll n;cin>>n;
    set<ll> s;
    unordered_map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        mp[x]++;
        s.insert(x);
        if(x==0){
            cout<<"NO";
            return;
        }
    }
    ll cnt=0,sum=0;
    for(ll p:s){
        if(p<0) continue;
        int r=-p;
        if(mp.find(r)!=mp.end()){
            cnt++;
            sum+=mp[r]+mp[p];
        }
    }
    if(cnt==1&&n==sum) cout<<"NO";
    else cout<<"YES";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}