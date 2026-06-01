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
const ll _mod=1e9+7;
const ll mod=998244353;
const int N=2e5+7;
void Srend(){
    int n;string s;
    cin>>n>>s;
    vector<vector<int>> f(n,vector<int>(3,0));
    vector<int> ans(n,0);
    int op=(s[0]-'0')%3;
    if(op==0) f[0][0]++;
    else if(op==1) f[0][1]++;
    else f[0][2]++;
    if(s[0]=='6'||s[0]=='0') ans[0]++;
    for(int i=1;i<n;i++){
        int d=s[i]-'0',t=(s[i]-'0')%3;
        if(t==0){
            f[i][0]=f[i-1][0]+f[i-1][0];
            f[i][1]=f[i-1][1]+f[i-1][1];
            f[i][2]=f[i-1][2]+f[i-1][2];
        }else if(t==1){
            f[i][0]=f[i-1][0]+f[i-1][2];
            f[i][1]=f[i-1][1]+f[i-1][0];
            f[i][2]=f[i-1][2]+f[i-1][1];
        }else{
            f[i][0]=f[i-1][0]+f[i-1][1];
            f[i][1]=f[i-1][1]+f[i-1][2];
            f[i][2]=f[i-1][2]+f[i-1][0];
        }
        f[i][0]%=mod;
        f[i][1]%=mod;
        f[i][2]%=mod;
        if(d&1){
            ans[i]=ans[i-1]%mod;
        }else{
            int dd=(3-t)%3;
            ans[i]=(ans[i-1]+f[i-1][dd])%mod;
        }
    }
    cout<<ans[n-1];
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}