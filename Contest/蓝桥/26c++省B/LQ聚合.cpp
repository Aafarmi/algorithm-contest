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
    vector<char> a(n+1);
    int L=0,sum=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]=='L') L++;
        else sum+=L;
    }
    vector<int> b(n+1,0);
    for(int i=n-1;i>=1;i--){
        b[i]=b[i+1];
        if(a[i+1]!='L') b[i]++;
    }
    L=0;ans=max(ans,sum);
    for(int i=1;i<=n;i++){
        if(a[i]=='?'){
            sum=sum-L+b[i];
            L++;
            ans=max(sum,ans);
        }else if(a[i]=='L') L++;
    }
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}