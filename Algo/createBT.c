#include<stdio.h>
#include<stdlib.h>

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
		int f;
		NODE *p,*head = root;
		while(head != NULL){
			p = head;
			printf("left = 0, right = 1\n");
			scanf("%d",&f);
			if(f == 0){
				head = head->left;
			}
			else{
				head = head->right;
			}
		}
		if(f == 0){
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
	return 0;
}
