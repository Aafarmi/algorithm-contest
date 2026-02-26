#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fr first
#define sc second
#define endl '\n'
const int N=2e5+7;
int t;
struct Heap{
	int heap[N];
	Heap(){heap[0]=0;}
	public:
	void push(int x);
	int top();
	void pop();
};
Heap a=Heap();
void Heap::push(int x){
	int i=++heap[0];
	while(i>1){
		int pa=i/2;
		if(heap[pa]<=x) break;
		heap[i]=heap[pa];
		i=pa;
	}
	heap[i]=x;
}
int Heap::top(){return heap[1];}
void Heap::pop(){
	int x=heap[--heap[0]];
	int i=1;
	while(2*i<heap[0]){
		int l=2*i,r=2*i+1;
		if(r<heap[0]&&heap[l]>heap[r]) l=r;
		if(heap[l]>=x) break;
		heap[i]=heap[l];
		i=l;
	}
	heap[i]=x;
}

void solve(){
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cin>>t;
    t=1;
    while(t--) solve();
}
