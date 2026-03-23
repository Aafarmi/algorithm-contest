#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<db,db> P;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int N=2e5+7;
void Srend(){
    int n,ans=0;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int l=0,r=0;r<n;r++){
        if(r!=n-1){
            if(abs(a[r]-a[r+1])>1){
                l=r+1;
                continue;
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}