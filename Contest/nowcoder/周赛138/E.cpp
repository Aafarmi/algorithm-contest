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
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1),pos(n+1);
    vector<P> ji,ou;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]&1){
            ji.emplace_back(make_pair(i,a[i]));
            pos[i]=ji.size()-1;
        }else{
            ou.emplace_back(make_pair(i,a[i]));
            pos[i]=ou.size()-1;
        }
    }
    int mxji=-INF,mxou=-INF;
    vector<int> dp(n+1,0);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(a[i]&1){
            if(mxji!=-INF) dp[i]=max(dp[i],mxji+a[i]);
            mxji=max(dp[i-1]+a[i],mxji);
        }
        else{
            if(mxou!=-INF) dp[i]=max(dp[i],mxou+a[i]);
            mxou=max(dp[i-1]+a[i],mxou);
        }
    }
    cout<<dp[n]<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}