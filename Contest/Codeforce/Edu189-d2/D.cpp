#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll _mod=1e9+7;
const ll mod=998244353;
const int N=2e5+7;
int count(int x,int k){
    int res=(x/4)%mod;
    if(x%4>=k) res++;
    return res%mod;
}
void Srend(){
    int n,x;cin>>n>>x;
    int ans1=count(x-1,1)*(count(n,1)-count(x-1,1)+mod)%mod;
    int ans2=(count(x-1,3)+1)*(count(n,3)-count(x-1,3)+mod)%mod;
    int ans=(ans1+ans2)%mod;
    cout<<ans<<endl;
} 

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}
