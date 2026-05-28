#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<db,string> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
bool same(db a,db b){
    if(abs(a-b)<=0.0001) return true;
    else return false;
}
void bfs(db a,db b){
    queue<P> q;
    q.push({a,""});
    while(q.size()){
        P u=q.front();q.pop();
        if(same(u.fr,b)){
            //cout<<u.fr<<endl;
            cout<<u.sc<<endl;
            return;
        }
        db t1=u.fr/2,t2=t1+0.5;
        q.push({t1,u.sc+'1'});
        q.push({t2,u.sc+'2'});
    }
}
void Srend(){
    db a,b;cin>>a>>b;
    string ans;
    int i=0;
    while(i<50){
        b*=2;
        if(b>=1){
            b--;
            ans+='2';
        }else ans+='1';
        i++;
    }
    reverse(all(ans));
    cout<<ans<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}