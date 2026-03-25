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
int qpow(int a,int b){
    if(b==0) return 1;
    int res=qpow(a,b/2);
    if(b&1) return res*res%mod*a%mod;
    else return res*res%mod;
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    int sum=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        sum=(sum^a[i])%mod;
        if(i==n) ans=(ans+sum)%mod;
        else ans=(ans+2*qpow(3,n-i-1)%mod*sum%mod)%mod;
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