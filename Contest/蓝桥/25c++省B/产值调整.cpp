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
    int c,a,b,k;cin>>a>>b>>c>>k;
    for(int i=1;i<=k;i++){
        if(a==b&&b==c){
            break;
        }
        int x=(b+c)/2,y=(a+c)/2,z=(a+b)/2;
        a=x;b=y;c=z;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}