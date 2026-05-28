#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db long double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin()+1,arr.end()
typedef pair<int,int> P;
const int INF=1e18+1;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e6+7;
void Srend(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int c=a[1]-a[0]+n;
    c=c%n;
    for(int i=1;i<n;i++)if((a[i]-a[i-1]+n)%n!=c){
        cout<<"-1\n";
        return;
    }
    if(c==0){
        if(a[0]==0) cout<<'0'<<endl;
        else cout<<n+1<<endl;
    }else{
        if(a[0]!=0) c++;
        cout<<c<<endl;
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--){
        Srend();
    }
}