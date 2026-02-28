/*https://codeforces.com/contest/2205/problem/B*/
#include <iostream>
#include <vector>
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
int qpow(int a,int b){
    if(b==0) return 1;
    int res=qpow(a,b/2);
    if(b&1) return res*res*a;
    else return res*res;
}
void Srend(){
    int n;cin>>n;
    int k=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) k*=i;
        while(n%i==0) n/=i;
    }
    if(n!=1) k*=n;
    printf("%lld\n",k);
} 
signed main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--) Srend();
}