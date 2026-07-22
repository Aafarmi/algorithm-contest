#include <iostream>
#include <cstdlib>
struct linklist{
    int val;
    linklist* next;
};
bool initlink(linklist*& head){
    head=(linklist*)malloc(sizeof(linklist));
    if(head==nullptr) return false;
    head->next=nullptr;
    head->val=0;
    return true;
}
bool nextinsert(linklist* p,int e){
    if(p==nullptr) return false;
    linklist* tmp=(linklist*)malloc(sizeof(linklist));
    tmp->val=e;
    tmp->next=p->next;
    p->next=tmp;
    return true;
}
bool priorinsert(linklist* p,int e){
    if(p==nullptr) return false;
    if(nextinsert(p,p->val)){
        p->val=e;
        return true;
    }
    return false;
}
bool insertList(linklist*& head,int pos,int e){
    //pos,ele
    if(pos<1) return false;
    linklist* p=head;
    for(int i=0;i<pos-1;i++) p=p->next;
    return nextinsert(p,e);
}
bool deletenode(linklist* p){
    if(p==nullptr) return false;
    linklist* tmp=p->next;
    if(tmp!=nullptr) p->val=tmp->val;
    p->next=tmp->next;
    free(tmp);
    return true;
}
bool deleteList(linklist*& head,int pos){
    if(pos<1) return false;
    linklist* p=head;
    for(int i=0;i<pos-1;i++) p=p->next;
    return deletenode(p->next);
}
int main(){
    return 0;
}