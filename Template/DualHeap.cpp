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
struct DualHeap{
    multiset<int> l;
    multiset<int> r;
    public:
        void rebalance();
        void push(int x);
        bool erase(int x);
        int getMid();
};
void DualHeap::rebalance(){//O(1)
    if(l.size()>r.size()+1){
        auto it=prev(l.end());
        r.insert(*it);
        l.erase(it);
    }else if(l.size()<r.size()){
        auto it=r.begin();
        l.insert(*it);
        r.erase(it);
    }
}
void DualHeap::push(int x){//O(logn)
    if(l.empty()||x<=*l.rbegin()) l.insert(x);
    else r.insert(x);
    rebalance();
}
bool DualHeap::erase(int x){//O(logn)
    auto it=l.find(x);
    if(it!=l.end()) l.erase(it);
    else{
        it=r.find(x);
        if(it==r.end()) return false;
        r.erase(it);
    }
    rebalance();
    return true;
}
int DualHeap::getMid(){//O(1)
    if(l.empty()) return 0LL;
    if(l.size()>r.size()) return *l.rbegin();
    else return (*l.rbegin()+*r.begin())/2;
}
void Srend(){
    DualHeap dh;
    dh.push(1);
} 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--) Srend();
}