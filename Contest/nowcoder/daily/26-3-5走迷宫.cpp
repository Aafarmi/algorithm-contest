/*https://www.nowcoder.com/practice/e88b41dc6e764b2893bc4221777ffe64?channelPut=tracker2*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
const int INF=INT_MAX;
const int N=1e6+7;
const ll mod=998244353;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
bool vis[1007][1007];
int t;int n,m;int xs,ys,xe,ye;
struct dd{
    int x,y,d;
    dd(int a,int b,int c){x=a;y=b;d=c;}
};
int bfs(int x,int y,vector<vector<char>>&a){
    queue<dd> q;
    q.push(dd(x,y,0));
    vis[x][y]=1;
    while(!q.empty()){
        dd x=q.front();
        q.pop();
        if(x.x==xe&&x.y==ye){
            return x.d;
        }
        for(int i=0;i<4;i++){
            int xx=x.x+dx[i],yy=x.y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m) continue;
            if(vis[xx][yy]) continue;
            if(a[xx][yy]=='*') continue;
            vis[xx][yy]=1;
            q.push(dd(xx,yy,x.d+1));
        }
    }
    return -1;
}
void solve(){
    cin>>n>>m;
    vector<vector<char>> a(n+1,vector<char>(m+1));
    cin>>xs>>ys>>xe>>ye;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }
    int ans=bfs(xs,ys,a);
    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cin>>t;
    t=1;
    while(t--) solve();
}
