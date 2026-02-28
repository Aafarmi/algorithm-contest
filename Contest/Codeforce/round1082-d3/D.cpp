#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void Srend(){
    int n,x,y;cin>>n>>x>>y;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<int> l,m,r;
    int mi=x+1;
    for(int i=x+1;i<=y;i++){
        if(a[i]<a[mi]) mi=i;
    }
    for(int i=mi;i<=y;i++) m.emplace_back(a[i]);
    for(int i=x+1;i<mi;i++) m.emplace_back(a[i]);
    bool found=false;
    for(int i=1;i<=n;i++){
        if(x+1<=i&&i<=y) continue;
        if(!found){
            if(a[i]<m[0]){
                l.emplace_back(a[i]);
            }else{
                found=true;
                r.emplace_back(a[i]);
            }
        }else{
            r.emplace_back(a[i]);
        }
    }
    for(int p:l) cout<<p<<" ";
    for(int p:m) cout<<p<<" ";
    for(int p:r) cout<<p<<" ";
    cout<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}