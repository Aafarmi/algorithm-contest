#include <bits/stdc++.h>
using namespace std;
//#define int long long 
#define fr first
#define sc second
#define endl '\n'
const int inf=INT_MAX;
int t;
struct node{
	int nex[500007][26],cnt=0;//自动初始化 
	bool exist[500007];//以该节点结尾的字符串是否存在 
	public:
		void insert(char* s,int l);//长度l 
		bool find(char *s,int l);
};
node trie;
void node::insert(char* s,int l){
	int p=0;
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!nex[p][c]) nex[p][c]=++cnt;
		p=nex[p][c];//更新p为下一节点 
	}
	exist[p]=true;
}
bool node::find(char* s,int l){
	int p=0;
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!nex[p][c]) return 0;
		p=nex[p][c];
 	}
 	return exist[p];
}
void solve(){
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); 
	//cin>>t;
	t=1;
	while(t--) solve();
}
