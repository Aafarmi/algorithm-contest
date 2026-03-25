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
const int mod=1e9+7;
const int N=2e5+7;
int qpow(int x,int y){
    if(y==0) return 1;
    int res=qpow(x,y/2);
    if(y&1) return res*res%mod*x%mod;
    else return res*res%mod;
}
void Srend(){
    cout<<qpow(2,1012);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}