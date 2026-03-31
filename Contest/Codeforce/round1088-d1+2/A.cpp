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
const ll mod=676767677;
const ll _mod=998244353;
const int N=2e5+7;
void Srend(){
    int x,y;cin>>x>>y;
    if(abs(x-y)<=1){
        cout<<"1\n";
        if(x>y) cout<<"1 ";
        for(int i=1;i<=x;i++) cout<<"-1 1 ";
        if(x<y) cout<<"-1 ";
    }else if(x>y){
        cout<<(x-y)<<'\n';
        for(int i=1;i<=x;i++){
            cout<<"1 ";
            if(i>x-y) cout<<"-1 ";
        }
    }else{
        cout<<(y-x)<<'\n';
        for(int i=1;i<=y;i++){
            cout<<"-1 ";
            if(i>y-x) cout<<"1 ";
        }
    }
    cout<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}