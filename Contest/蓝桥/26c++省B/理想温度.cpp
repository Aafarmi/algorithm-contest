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
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),d(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) d[i]=b[i]-a[i];
    for(int len=1;len<=n;len++){
        int mx=0,c0=0;
        map<int,int> mp;
        for(int l=1,r=1;r<=n;){
            while(r<=len){
                mp[d[r++]]++;
            }
            mx=max(mx,)
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