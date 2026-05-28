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
    int n;string s;
    cin>>n>>s;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //dp[0][0]=1;
    for(int i=1;i<n;i++){
        //dp[i][i]=1;
        int l=i-1,r=i;
        if(s[l]==s[r]) dp[l][r]=2;
    }
    for(int len=3;len<=n;len++){
        for(int L=0;L<=n-len;L++){
            int R=len+L-1;
            int l=L+1,r=R-1;
            dp[L][R]=dp[l][r]+(s[L]==s[R]);
        }
    }
    cerr<<dp[1][5];
    int pl=0,pr=n-1;
    while(pl<n&&s[pl]!='(') pl++;
    while(pr>=0&&s[pr]!=')') pr--;
    if(pl>=n||pr<0||pl>pr){
        cout<<'0'<<endl;
        return;
    }
    int ans=dp[pl][pr]+2;
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}