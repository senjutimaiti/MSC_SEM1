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

int search(NODE *root, int k){
	if(root == NULL){
		return 0;
	}
	if(root->key == k){
		return 1;
	}
	else if(root->key > k){
		return search(root->left, k);
	}
	else if(root->key < k){
		return search(root->right, k);
	}
	return 0;
}

int search1(NODE *root,int k){
	while(root != NULL){
		if(root->key > k){
			root = root->left;
		}
		else if(root->key < k){
			root = root-> right;
		}
		else{
			return 1;
		}
	}
	return 0;
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
	
	printf("\nEnter a value to be searched ");
	scanf("%d",&k);
	int f = search1(root, k);
	if(f){
		printf("Found\n");
	}
	else{
		printf("NOT Found\n");
	}
	return 0;
}
