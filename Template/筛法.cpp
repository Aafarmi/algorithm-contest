//筛法
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
bool isprime[N];
vector<int> prime;//可以选择用数组存储质数，后续可以不用遍历筛法数组。
void Eratosthene(int n){
    isprime[0]=isprime[1]=false;
    for(int i=2;i<n;i++) prime[i]=true;
    for(int i=2;i<=n;i++){
        if(isprime[i]){
            prime.emplace_back(i);
            if((long long)i*i>n) continue;//ll防止溢出
            for(int j=i*i;j<=n;j+=i) isprime[j]=false;//??
        }
    }
}
/*
bool notprime[N];
vector<int> prime;//可以选择用数组存储质数，后续可以不用遍历筛法数组。
void Euler(int n){
    for(int i=2;i<=n;i++)
        if(!notprime[i]) prime.emplace_back(i);
    for(int j:prime){
        if(i*j>n) break;
        notprime[i*j]=true;
        if(i%j==0) break;//?
    }
}
*/
void Srend(){
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}