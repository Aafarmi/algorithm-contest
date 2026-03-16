/*https://www.nowcoder.com/practice/48bee29fc274423ca6e5099788eee294?tpId=391&contestId=129582&channelPut=tracker1*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
//#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=998244353;
const int N=2e5+7;
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    vector<bool> b(n+1,true);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<"YES\n";
        return;
    }
    if(n==2){
        if(a[1]==1) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    if(n==3){
        if(a[2]==2) cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    for(int i=2;i<=n;i++){
        if(a[i]==i-1) b[i]=false;
        if(a[i-1]==i) b[i-1]=false;
        if(b[i-1]){
            cout<<"YES\n";
            return;
        }
    }
    if(b[n]) cout<<"YES\n";
    else cout<<"NO\n";
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}