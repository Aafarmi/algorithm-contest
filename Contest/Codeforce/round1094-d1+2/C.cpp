#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin()+1,arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> sa=a;
    sort(all(sa));
    int m=sa[(n+1)/2];
    vector<int> sml(n+1,0),cm(n+1,0);
    if(a[1]<m) sml[1]=1;
    if(a[1]==m) cm[1]=1;
    for(int i=2;i<=n;i++){
        sml[i]=sml[i-1];
        cm[i]=cm[i-1];
        if(a[i]<m) sml[i]++;
        if(a[i]==m) cm[i]++;
    }
    vector<int> dp(n+1,-1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int mx=-1;
        for(int j=0;j<i;j++){
            if(dp[j]==-1) continue;
            int t1=sml[i]-sml[j];
            int t2=cm[i]-cm[j];
            int len=i-j;
            if((len&1)&&t1<(len+1)/2&&t1+t2>=(len+1)/2){
                if(dp[j]+1>mx){
                    mx=dp[j]+1;
                }
            }
        }
        dp[i]=mx;
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