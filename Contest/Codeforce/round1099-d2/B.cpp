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
    vector<int> a(n+1);
    bool sorted=true;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>1&&a[i]<a[i-1]) sorted=false;
    }
    if(sorted) cout<<"YES\n";
    else{
        int mx=0;
        vector<bool> add(n+1,false);
        vector<int> d(n+1);
        for(int i=2;i<=n;i++){
            d[i]=a[i]-a[i-1];
            if(d[i]<0){
                add[i]=true;
                mx=max(mx,-d[i]);
                if(add[i-1]){
                    cout<<"NO\n";
                    return;
                }
            }
        }
        for(int i=2;i<=n;i++)if(a[i]-a[i-1]<0){
            a[i]+=mx;
        }
        bool s=true;
        for(int i=2;i<=n;i++)if(a[i]<a[i-1]) s=false;
        if(s) cout<<"YES\n";
        else cout<<"NO\n";
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}