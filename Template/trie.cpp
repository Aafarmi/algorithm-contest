#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define fr first
#define sc second
#define endl '\n'
const int inf=INT_MAX;
const int maxn=1e5+7;
struct node{
	int nex[maxn][26],cnt=0;//cnt：节点数
	bool exist[maxn];//以该节点结尾的字符串是否存在 
	public:
		void insert(char* s,int l);//长度l 
		bool find(char *s,int l);
};
node trie;
void node::insert(char* s,int l){//插入
	int p=0;
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!nex[p][c]) nex[p][c]=++cnt;//没有这个节点，插入
		p=nex[p][c];//更新p为下一节点 
	}
	exist[p]=true;//标记存在字符串s
}
bool node::find(char* s,int l){//查找
	int p=0;
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!nex[p][c]) return 0;//没找到直接结束
		p=nex[p][c];
 	}
 	return exist[p];
}
void solve(){
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int t=1;
	//cin>>t;
	while(t--) solve();
}
