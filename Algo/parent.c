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

int search(NODE *root,int k){
	NODE *p = root;
	while(p){
		if(p->key == k){
			return 1;
		}
		else if(k < p->key){
			p=p->left;
		}
		else{
			p=p->right;
		}
	}
	return 0;
}

void parent(NODE *root, int n)
{
	NODE *p = root;
	NODE *x;
	if(p->key == n){
		printf("It is the root node");
	}
	else if(search(root,n) == 0){
		printf("Node not found");
	}
	else{
		while(p->left != NULL || p->right != NULL){
			if(n < p->key){
				x = p->left;
			}
			else{
				x = p->right;
			}
			if(x->key == n){
				printf("Parent of %d is %d\n", x->key,p->key);
				break;
			}
			p = x;
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
	
	parent(root,11);
	
	return 0;
}
