/*题目：https://www.nowcoder.com/practice/c949564b181f42348e4d08d0a9fbc092?channelPut=tracker2*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
typedef vector<vector<int>> matrix;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
matrix multiply(const matrix&a,const matrix& b){
    matrix c(3,vector<int>(3,0));
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                int tmp=a[i][k]*b[k][j];
                c[i][j]=(c[i][j]+tmp%mod+mod)%mod;
            }
        }
    }
    return c;
}
matrix mpow(matrix base,int exp){
    matrix res(3,vector<int>(3,0));
    for(int i=0;i<3;i++){
        res[i][i]=1;
    }
    while(exp>0){
        if(exp&1) res=multiply(res,base);
        base=multiply(base,base);
        exp/=2;
    }
    return res;
}
void Srend(){
    int n;cin>>n;
    if(n<=3){
        printf("1\n");
        return;
    }
    matrix T=
    {
        {1,0,1},
        {1,0,0},
        {0,1,0}
    };
    matrix tpow=mpow(T,n-3);
    int ans=(tpow[0][0]+tpow[0][1]+tpow[0][2])%mod;
    printf("%lld\n",ans);
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) Srend();
}