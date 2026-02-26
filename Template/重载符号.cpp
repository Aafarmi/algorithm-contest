#include <bits/stdc++.h>
using namespace std;
struct lid{
	string name;
	int val;
/*	bool operator>(const lid& a)const{
		if(val==a.val) return name>a.name;
		else return val>a.val;
	}*/
};
//自定义比较规则 comp(a,b),若comp为true返回a>b 
bool comp(const lid& a,const lid& b){
	if(a.val==b.val){
		return a.name<b.name;
	}else return a.val>b.val;
}
//重载符号，全局生效此处定义lid的符号不影响comp中大于号 
bool operator>(const lid& a,const lid& b) {
	if(a.val!=b.val) return a.val>b.val;
	else return a.name<b.name;
}
int main(){
	vector<lid> a;
	a.reserve(3);
	a={{"b",2},{"a",4},{"c",0},{"d",0},{"e",0}};
	sort(a.begin(),a.end(),comp);//sort(a.begin(),a.end(),grater<lid>())
	for(auto v:a){
		cout<<v.name<<" ";
	}
	
		
	
}
