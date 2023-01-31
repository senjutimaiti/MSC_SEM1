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


void inorder(NODE *root){
	if(root!=NULL){
		inorder(root->left);
		printf("%d, ",root->key);
		inorder(root->right);
	}
}

NODE* search(NODE *root,int n){
	NODE *p = root;
	while(p){
		if(p->key == n){
			return p;
		}
		else if(n < p->key){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	return NULL;
}

void insuc(NODE *root,int n)
{
	NODE *r = search(root,n), *p;
	if(r == NULL){
		printf("Node not found");
		return;
	}
	if(r->left && r->right){
		p = r->right;
		while(p->left){
			p=p->left;
		}
		printf("Inorder Successor of %d is %d\n",r->key,p->key);
	}
	else
	printf("Invalid node");
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
	
	inorder(root);
	printf("\n");
	
	insuc(root,4);
	
	return 0;
}
