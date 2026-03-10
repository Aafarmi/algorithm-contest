//dp，回文串处理
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
typedef vector<vector<int>> matrix;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int N=2e5+7;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    s='#'+s;
    vector<vector<bool>> h(n+3,vector<bool>(n+3,false));
    for(int i=1;i<=n;i++){
        h[i][i]=true;
        if(i+1<=n&&s[i]==s[i+1]) h[i][i+1]=true;
    }
    for(int len=3;len<=n;len++){
        for(int l=1;l<=n-len+1;l++){
            int r=len+l-1;
            if(s[r]==s[l]&&h[l+1][r-1]) h[l][r]=true;
        }
    }
    vector<int> f(n+1,0),b(n+2,0);
    f[0]=1;b[n+1]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(h[j+1][i]) f[i]=(f[i]+f[j])%mod;
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n+1;j++){
            if(h[i][j-1]) b[i]=(b[i]+b[j])%mod;
        }
    }
    int ans=0;
    for(int len=1;len<=n;len++){
        int w=len*len;
        for(int l=1;l<=n-len+1;l++){
            int r=len+l-1;
            if(h[l][r]){
                int res=(l==0?1:f[l-1])*(r==n-1?1:b[r+1])%mod*w%mod;
                ans=(ans+res)%mod;
            }
        }
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}
