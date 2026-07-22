#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Maxsize 10
typedef struct{
    int size;
    int data[Maxsize];
    int maxsize;
} sqlist;
void initlist(sqlist *L){
    for(int i=0;i<Maxsize;i++) L->data[i]=0;
    L->size=0;
    L->maxsize=10;
}
bool insertlist(sqlist *L,int p,int e){
    //p位置e数值
    if(p<0||p>L->size) return false;
    if(L->size>=L->maxsize) return false;
    for(int i=L->size;i>p;i--)
        L->data[i]=L->data[i-1];
    L->data[p]=e;
    L->size++;
    return true;
}
bool deletelist(sqlist *L,int p){
    //p位置
    if(p<0||p>=L->size) return false;
    if(L->size==0) return false;
    L->size--;
    for(int i=p;i<L->size;i++)
        L->data[i]=L->data[i+1];
    L->data[L->size]=0;
    return true;
}
bool getelem(sqlist L,int p,int *val){
    if(p<0||p>=L.size) return false;
    *val=L.data[p];
    return true;
}
bool locateelem(sqlist L,int e,int *pos){
    bool find=false;
    for(int i=0;i<L.size;i++) if(L.data[i]==e){
        *pos=i;
        find=true;
        break;
    }
    return find;
}
void printlist(sqlist L){
    for(int i=0;i<L.size;i++) printf("%d ",L.data[i]);
    printf("\n");
}
int main(){
    sqlist L;
    initlist(&L);
    for(int i=1;i<=9;i++) insertlist(&L,i-1,i);
    deletelist(&L,4);
    printlist(L);
    return 0;
}
