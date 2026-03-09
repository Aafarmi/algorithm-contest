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
    vector<int> d(n);
    for(int i=0;i<n;i++) cin>>d[i];
    int mi=INF,cnt=0;
    for(int i=0;i<n;i++){
        if(d[i]<mi) mi=d[i];
    }
    for(int i=n-1;i>0;i--){
        if(cnt<d[i]) cnt++;
    }
    cout<<cnt<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}
