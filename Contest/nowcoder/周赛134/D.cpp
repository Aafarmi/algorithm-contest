#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void solve(){
    int n;cin>>n;
    int ans=0;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int mx=a[i],mi=a[i],stop=i;
        for(int j=i+1;j<n;j++){
            mx=max(mx,a[j]);
            mi=min(mi,a[j]);
            if(mx-mi>1){
                stop=j;
                break;
            }
        }
        ans+=stop-i;
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}
