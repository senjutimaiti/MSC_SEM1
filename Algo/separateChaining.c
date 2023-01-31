#include<stdio.h>
#include<string.h>
#include<malloc.h>
#define N 10

struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;

NODE* getnode(int info){
	NODE *newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->data = info;
	newnode->next = NULL;
	return(newnode);
}

void traverse(NODE *head){
	if(head == NULL){
		printf("EMPTY");
	}
	else{
		while(head != NULL){
			printf("%d ",head->data);
			head = head->next;
		}
	}
}

NODE* insert(NODE* head, int info){
	NODE* ptr;
	ptr = getnode(info);
	ptr->next = head;
	head = ptr;
	return head;
}

void hashing(int k[], NODE* a[]){
	int i, pos;
	for(i=0; i<N; i++){
		pos = k[i]%N;
		a[pos] = insert(a[pos], k[i]);
	}
}

int main(){
	int keys[]={28,93,26,27,13,38,04,45,77,63}, i;
	
	NODE* a[N];
	for(i=0; i<N; i++){
		a[i]=NULL;
	}
	
	hashing(keys, a);
	
	for(i=0; i<N; i++){
		printf("i = %d ",i);
		traverse(a[i]);
		printf("\n");
	}	
		
	return 0;
}
