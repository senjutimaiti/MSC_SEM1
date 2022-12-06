#include<stdio.h>
#include<stdlib.h>
#define MAX 50

typedef struct Tree{
	int key;
	struct Tree *left;
	struct Tree *right;
} NODE;

NODE* getnode(int k){
	NODE *ptr = (NODE*)malloc(sizeof(NODE));
	ptr->key = k;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

NODE* create(NODE *root, int k){
	NODE *ptr = getnode(k);
	if(root == NULL){
		return ptr;
	}
	else{
		NODE *p,*head = root;
		while(head != NULL){
			p = head;
			if(head->key > k){
				head = head->left;
			}
			else{
				head = head->right;
			}
		}
		if(p->key > k){
			p->left = ptr;
		}
		else{
			p->right = ptr;
		}
		return root;
	}
}


void postorder(NODE *root){
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d, ",root->key);
	}
}

void Postorder(NODE *root){
	NODE *p = root, *stk[MAX], *stack[MAX];
	int top1 = -1, top2 = -1;
	stk[++top1] = p;
	while(1){
		if(top1 != -1){
			p = stk[top1--];
			stack[++top2] = p;
			if(p->left != NULL){
				stk[++top1] = p->left;
			}
			if(p->right != NULL){
				stk[++top1] = p->right;
			}
		}
		else{
			break;
		}
	}
	while(1){
		if(top2 != -1){
			p = stack[top2--];
			printf("%d, ",p->key);
		}
		else{
			break;
		}
	}
}

int main(){
	int k,c=1;
	NODE *root = NULL;
	while(c){
		printf("Enter a value ");
		scanf("%d",&k);
		root = create(root,k);
		printf("Enter 0 to exit ");
		scanf("%d",&c);
	}
	
	postorder(root);
	printf("\n");
	
	Postorder(root);
	printf("\n");
	
	return 0;
}
