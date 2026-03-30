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
const int mod=998244353;
const int N=2e5+7;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1),b(n+1),g(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<n;i++){
        g[i]=gcd(a[i],a[i+1]);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int tmp;
        if(i==1) tmp=g[1];
        else if(i==n) tmp=g[i-1];
        else tmp=g[i-1]*g[i]/gcd(g[i-1],g[i]);
        if(tmp<b[i]) ans++;
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