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
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
int qpow(int x,int y){
    if(y==0) return 1LL;
    int res=qpow(x,y/2);
    if(y&1) return res*res%_mod*x%_mod;
    else return res*res%_mod;
}
void Srend(){
    int f=1;
    int n=2026;
    for(int i=2;i<=n;i++){
        f=((f+f)%_mod+qpow(2,i-1))%_mod;
    }
    cout<<f;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}