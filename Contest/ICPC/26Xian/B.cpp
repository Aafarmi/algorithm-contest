#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define db double
#define fr first
#define sc second
//#define endl '\n'
#define all(arr) arr.begin(),arr.end()
typedef pair<int,int> P;
const int INF=0x3f3f3f3f;
const ll mod=1e9+7;
const ll _mod=998244353;
const int N=2e5+7;
bool check(int need,int k,int k2,int r2){
    if(need<0) return false;
    if(k==0) return need<=r2;
    int l1=(need-r2+k-1)/k,l2=(need+k)/(k+1);
    int R1=need/k,R2=((k2-r2)+need)/(k+1);
    int l=max(l1,l2),r=min(R1,R2);
    return l<=r;
}
void Srend(){
    int n,x,y;
    string s;
    cin>>n>>x>>y>>s;
    int k=(x+y)/n,r=(x+y)%n;
    string df="000";
    //------------
    if(x+y==0){
        for(char c:s)
            if(c=='1') cout<<'1';
            else cout<<'0';
        cout<<endl;
        return;
    }
    if(r==0){
        r=n;k--;
        k=max(k,0LL);
    }
    int k0=0,k1=0;
    int r0=0,r1=0;
    int k2=0,r2=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            k0++;
            if(i<r) r0++;
            df[0]='1';
        }
        else if(s[i]=='1'){
            k1++;
            if(i<r) r1++;
            df[1]='1';
        }
        else{
            k2++;
            if(i<r) r2++;
            df[2]='1';
        }
    }
    //-----------
    for(int i=0;i<n;i++){
        if(s[i]=='2'){
            int need=x-(k*(k0+1)+r0+(i<r));
            if(check(need,k,k2-1,r2-(i<r))){
                s[i]='0';
                k0++;r0+=(i<r);
                k2--;r2=r2-(i<r);
            }else{
                s[i]='1';
                k1++;r1+=(i<r);
                k2--;r2=r2-(i<r);
            }
        }
    }
    int need=x-(k*k0+r0);
    if(check(need,k,k2,r2)){
        cout<<s<<endl;
    }else cout<<-1<<endl;
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}