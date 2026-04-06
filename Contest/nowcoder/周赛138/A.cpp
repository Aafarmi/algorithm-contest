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
    int x,y;cin>>x>>y;
    if(x==y){
        cout<<"YES\n";
        return;
    }
    if(x>y){
        int a=x-y;
        a=a/2;
        for(int i=0;i<=100;i++){
            int t=i+a;
            int tmp=x-t*2;
            while(tmp<y){
                tmp+=3;
            }
            if(tmp==y){
                cout<<"YES\n";
                return;
            }
        }
    }else{
        int a=(y-x)/3;
        for(int i=0;i<=100;i++){
            int t=i+a;
            int tmp=x+t*3;
            while(tmp>y){
                tmp-=2;
            }
            if(tmp==y){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}