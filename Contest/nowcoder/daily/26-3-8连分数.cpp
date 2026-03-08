/*https://www.nowcoder.com/practice/8e225697ad4043b5a2669f890ae90974?channelPut=tracker2*/
#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define ll long long
#define fr first
#define sc second
#define endl '\n'
typedef pair<int,int> P;
typedef vector<vector<int>> matrix;
const int INF=0x3f3f3f3f;
const int mod=1e9+7;
const int N=2e5+7;
void solve(){
    int p,q;cin>>p>>q;
    int a=p,b=q;
    vector<int> res;
    while(p%q!=0){
        res.emplace_back(p/q);
        p=p%q;
        swap(p,q);
    }
    res.emplace_back(p/q);
    int sz=res.size();
    printf("%d/%d = ",a,b);
    for(int i=0;i<sz;i++){
        if(i==sz-1){
            printf("%d",res[i]);
            break;
        }
        printf("%d+1/",res[i]);
        if(i!=sz-2) printf("{");
    }
    for(int i=1;i<=sz-2;i++) printf("}");
    printf("\n");
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--) solve();
}
