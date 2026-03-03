#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(arr) arr.begin(),arr.end()
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=1e5+7;
void bfs(int x1,int y11,int x2,int y2){
    
}
char d[4]={'U','D','L','R'};
void Srend(){
    int n,x1,y11,x2,y2;
    cin>>n>>x1>>y11>>x2>>y2;
    if(abs(x1-x2)+abs(y11-y2)==2||y11==y2){
        cout<<"-1";return;
    }
    int dd=y11-y2;
    if(dd>0) dd=0;
    else dd=1;
    for(int i=1;i<=(n-x1);i++) cout<<d[dd];
    if(x1==1) cout<<d[3];
    else cout<<d[2];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}