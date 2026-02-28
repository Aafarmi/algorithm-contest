/*https://codeforces.com/contest/2205/my*/
#include <iostream>
#include <vector>
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
void Srend(){
    int n;cin>>n;
    vector<int> a(n+1);
    int mx=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>a[mx]) mx=i;
    }
    if(mx!=1) swap(a[1],a[mx]);
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}