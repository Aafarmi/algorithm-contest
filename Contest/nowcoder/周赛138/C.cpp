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
ll sum(ll x){
    ll res=0;
    while(x>0){
        res+=x%10;
        x/=10;
    }
    return res;
}
void Srend(){
    int n;cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt=0;
    for(int i=n-1;i>=1;i--){
        while(a[i]>a[i+1]){
            cnt++;
            if(a[i]==sum(a[i])){
                cout<<"-1\n";
                return;
            }else a[i]=sum(a[i]);
        }
    }
    cout<<cnt<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}