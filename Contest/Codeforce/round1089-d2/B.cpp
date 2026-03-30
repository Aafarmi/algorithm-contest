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
    vector<int> p(n+1),a(n+1);
    for(int i=1;i<=n;i++){
        cin>>p[i];
        a[p[i]]=i;
    }
    int mx=0,c=0;
    for(int i=1;i<=n+1;i++){
        mx=max(mx,i-1-c);
        if(i<=n&&a[i]<i) c++;
    }
    cout<<mx<<endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}