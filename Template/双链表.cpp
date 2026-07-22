#include <iostream>
#include <cstdlib>
struct Dnode{
    int data;
    Dnode *prior,*next;
};
typedef Dnode* Dlinklist;
bool InitDlinklist(Dlinklist &L){
    L=(Dlinklist)malloc(sizeof(Dnode));
    if(L==nullptr) return false;
    L->prior=nullptr;
    L->next=nullptr;
    L->data=0;
    return true;
}
bool NextInsert(Dnode* p,int e){
    Dnode* t=(Dnode*)malloc(sizeof(Dnode));
    if(t==nullptr||p==nullptr) return false;
    t->data=e;
    t->prior=p;
    if(p->next!=nullptr) t->next=p->next,t->next->prior=t;
    else t->next=nullptr;
    p->next=t;
    return true;
}
bool PriorInsert(Dnode* p,int e){
    Dnode* t=(Dnode*)malloc(sizeof(Dnode));
    if(t==nullptr||p==nullptr) return false;
    t->data=e;
    t->next=p;
    if(p->prior!=nullptr) t->prior=p->prior,t->prior->next=t;
    else t->prior=nullptr;
    p->prior=t;
    return true;
}
bool DeleteNode(Dnode* p){
    if(p==nullptr) return false;
    if(p->prior!=nullptr) p->prior->next=p->next;
    if(p->next!=nullptr) p->next->prior=p->prior;
    free(p);
    return true; 
}
bool PrintList(Dlinklist L){
    if(L==nullptr) return false;
    Dnode* p=L->next;
    while(p!=nullptr){
        std::cout<<p->data<<" \n"[p->next==nullptr];
        p=p->next;
    }
    return true;
}
int main(){
    
}