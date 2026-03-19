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
const int N=3e3+7;
void Srend(){
    int a,b,c;cin>>a>>b>>c;
    if(c>2*min(a,b)) cout<<"-1";
    else{
        if(a==b&&c==2*min(a,b)){
            cout<<"-1";
            return;
        }
        a-=(c+1)/2;b-=(c+1)/2;
        string ans="";
        for(int i=1;i<=(c+1)/2;i++) ans+="LQ";
        bool addl=false,addq=false;
        if(!(c&1)){
            if(a){
                addl=true;
                a--;
            }else{
                addq=true;
                b--;
            }
        }
        string ans1,ans2;
        if(addq) ans='Q'+ans;
        for(int i=1;i<=a;i++) ans1+='L';
        if(addq) ans1+='Q';
        for(int i=1;i<=b;i++) ans2+='Q';
        if(addl) ans2+='L';
        cout<<ans1<<ans<<ans2;
    }
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}