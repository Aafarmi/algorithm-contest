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
    string s[3];
    cin>>s[1];
    cin>>s[2];
    int n=s[1].size();
    int st=n-1,ed=0;
    for(int i=0;i<n;i++){
        if(s[1][i]=='#'||s[2][i]=='#'){
            st=i;
            break;
        }
    }
    for(int i=n-1;i>=0;i--){
        if(s[1][i]=='#'||s[2][i]=='#'){
            ed=i;
            break;
        }
    }
    if(st>=ed){
        cout<<'0';
        return;
    }
    bool i1=false,i2=false;
    int cnt=0;
    for(int i=st+1;i<=ed;i++){
        if(s[1][i]=='#') i1=true;
        else i1=false;
        if(s[2][i]=='#') i2=true;
        else i2=false;
        if(i1||i2){
            if(i1&&i2) continue;
            if(i1&&s[1][i-1]=='.'){
                s[2][i]='#';
                cnt++;
            }
            if(i2&&s[2][i-1]=='.'){
                s[1][i]='#';
                cnt++;
            }
        }else{
            cnt++;
            if(s[1][i-1]=='#') s[1][i]='#';
            if(s[2][i-1]=='#') s[2][i]='#';
        }
    }
    cout<<cnt<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}