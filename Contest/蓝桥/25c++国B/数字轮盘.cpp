#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
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
    int n,k;cin>>n>>k;
    int p=(n-1+k)%n;p=n-1-p;
    int ans=-1;
    int dist=n-p;
    if(dist==n) dist=0;
    if(n&1){
        if(dist&1) ans=(n+1)/2+(dist-1)/2;
        else ans=dist/2;
    }
    else{
        if(!(dist&1)) ans=dist/2;
    }
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}