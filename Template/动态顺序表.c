#include <stdio.h>
#include <stdlib.h>
#define maxsize 1
typedef struct{
    int *data;
    int size;
} sqlist;
void initlist(sqlist *L){
    L->data=malloc(sizeof(int)*maxsize);
    for(int i=0;i<10;i++) L->data[i]=0;
    L->size=maxsize;
}
void increasesize(sqlist *L,int x){
    int *old=L->data;
    L->data=malloc(sizeof(int)*(L->size+x));
    for(int i=0;i<L->size+x;i++){
        if(i<L->size) L->data[i]=old[i];
        else L->data[i]=0;
    }
    L->size+=x;
    free(old);
}
void printlist(sqlist* L){
    for(int i=0;i<L->size;i++) printf("%d",L->data[i]);
}
int main(){

    return 0;
}
