#include <iostream>
#include <cstdlib>
struct linklist{
    int data;
    linklist* next;
};
//初始化
bool initlink(linklist*& head){
    head=(linklist*)malloc(sizeof(linklist));
    if(head==nullptr) return false;
    head->next=nullptr;
    head->data=0;
    return true;
}
//后插
bool nextinsert(linklist* p,int e){
    if(p==nullptr) return false;
    linklist* tmp=(linklist*)malloc(sizeof(linklist));
    tmp->data=e;
    tmp->next=p->next;
    p->next=tmp;
    return true;
}
//前插
bool priorinsert(linklist* p,int e){
    if(p==nullptr) return false;
    if(nextinsert(p,p->data)){
        p->data=e;
        return true;
    }
    return false;
}
//按位插入
bool insertList(linklist*& head,int pos,int e){
    //pos,ele
    if(pos<1) return false;
    linklist* p=head;
    for(int i=0;i<pos-1;i++) p=p->next;
    return nextinsert(p,e);
}
//删除节点
bool deletenode(linklist* p){
    if(p==nullptr) return false;
    linklist* tmp=p->next;
    if(tmp!=nullptr) p->data=tmp->data;
    p->next=tmp->next;
    free(tmp);
    return true;
}
//按位删除
bool deleteList(linklist*& head,int pos){
    if(pos<1) return false;
    linklist* p=head;
    for(int i=0;i<pos-1;i++) p=p->next;
    return deletenode(p->next);
}
int getLength(linklist* L){
    int len=0;
    linklist* p=L;
    while(p->next!=nullptr){
        p=p->next;
        len++;
    }
    return len;
}
linklist* getlist(int* a,int n){
    linklist* L=(linklist*)malloc(sizeof(linklist));
    linklist *s,*r=L;
    for(int i=0;i<n;i++){
        s=(linklist*)malloc(sizeof(linklist));
        s->data=a[i];
        r->next=s;
        r=s;
    }
    r->next=nullptr;
    return L;
}
int main(){
    return 0;
}