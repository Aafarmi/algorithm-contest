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
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(sum%n){
        cout<<-1<<endl;
        return;
    }
    int avg=sum/n;
    vector<int> c(n+1,0);
    for(int i=1;i<n;i++){
        int tmp=avg-a[i];
        if(tmp<0){
            cout<<-1<<endl;
            return;
        }else{
            c[i]=tmp;
            a[i+1]-=tmp;
        }
    }
    int ans=c[1]+c[2];
    for(int i=3;i<=n;i++){
        int k=max(0,c[i]-c[i-2]);
        ans+=k;
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