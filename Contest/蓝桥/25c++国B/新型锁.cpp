/*https://www.nowcoder.com/practice/4fb04151cbb4418e9f6593166b105e92?tpId=391&contestId=125587&channelPut=tracker1*/
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
const int mod_=9;
const int N=2e5+7;
void Srend(){
    int f3_0=4,f3_1=1;
    int f5_0=2,f5_1=1;
    for(int i=2;i<=2025;i++){
        int t0=f3_1*4%mod,t1=(f3_1+f3_0)%mod;
        f3_0=t0;f3_1=t1;
        t0=f5_1*2%mod;t1=(f5_1+f5_0)%mod;
        f5_0=t0;f5_1=t1;
    }
    int ans=(f3_1+f3_0)*(f5_1+f5_0)%mod;
    cout<<ans;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}