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
    int n;cin>>n;
    vector<int> a(n+1),cnt(4,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    a[0]=INF;
    int ans=INF;
    for(int k=0;k<4;k++){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(a[i]+k)%4;
        }
        for(int i=0;i<4;i++){
            if(((sum%4)+i)%4==k){
                a[0]=i;
                break;
            }
        }
        ans=min(ans,sum+a[0]);
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