#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode{
	int data;
	struct BSTnode *left;
	struct BSTnode *right;
};

struct BSTnode *insert(struct BSTnode *root, int value){
	if(root == NULL){
		root = (struct BSTnode*)malloc(sizeof(struct BSTnode));
		root->left = root->right = NULL;
		root->data = value;
		return root;
	}else{
		if(value < root->data){
			root->left = insert(root->left, value);
		}else{
			if(value > root->data){
				root->right = insert(root->right, value);
			}else{
				
			}
		}
		return root;
	}
	
};

//making display inorder
void inorder(struct BSTnode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
//making display preorder
void preorder(struct BSTnode *root){
	if(root != NULL){
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
//making display postorder
void postorder(struct BSTnode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}



int minValue(struct BSTnode* node) {
	struct BSTnode* current = node;
	
	while (current->left != NULL) {
		current = current->left;
	}
	return(current->data);
}

int maxValue(struct BSTnode* node) {
	struct BSTnode* current = node;
	
	while (current->right != NULL) {
		current = current->right;
	}
	return(current->data);
}



int main(){
	
	struct BSTnode *root  = NULL;
//	root = (struct BSTnode*)malloc(sizeof(struct BSTnode));
	
	int n,i,x;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	
	
	for(i = 1; i <=n; i++){
		printf("Enter the root : ");
		scanf("%d", &x);
		root = insert(root, x);
	}
	printf("After inorder tree is : \n");
	inorder(root);
	
	printf("\n----------------------------------\n");
	
	printf("After preorder tree is : \n");
	preorder(root);
	printf("\n----------------------------------\n");
	
	printf("After postorder tree is : \n");
	postorder(root);
	printf("\n----------------------------------\n");
	
	printf("%d", maxValue(root));
	
	printf("\n----------------------------------\n");
	
	printf("%d", minValue(root));
	
	
	
	printf("\n----------------------------------\n");
}


