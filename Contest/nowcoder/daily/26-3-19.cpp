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
const int N=3e3+7;
ll f[N],invf[N];
ll qpow(ll a,ll b){
    if(b==0) return 1LL;
    ll res=qpow(a,b/2);
    if(b&1) return res*res%mod*a%mod;
    else return res*res%mod;
}
ll inv(ll x){
    return qpow(x,mod-2);
}
void init(){
    f[0]=1;
    for(int i=1;i<N;i++){
        f[i]=f[i-1]*i%mod;
        invf[i]=inv(f[i]);
    }
}
ll C(ll m,ll n){
    if(n<0||m<0||m-n<0) return 0;
    return f[m]*invf[n]%mod*invf[m-n]%mod;
}
void Srend(){
    ll x,y;cin>>x>>y;
    for(int i=1;i<=x+y;i++){
        if(i==1){
            printf("0\n");
            continue;
        }
        ll x1=i/2,y11=(i+1)/2;
        ll ans1=C(x-1,x1-1)*C(y-1,y11-1)%mod;
        ll x2=(i+1)/2,y2=i/2;
        ll ans2=C(x-1,x2-1)*C(y-1,y2-1)%mod;
        ll ans=(ans1+ans2)%mod;
        printf("%lld\n",ans);
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t=1;
    //cin>>t;
    while(t--) Srend();
}