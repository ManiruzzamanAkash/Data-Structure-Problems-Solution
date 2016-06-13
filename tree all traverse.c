/** CODE BY MANIRUZZAMAN AKASH **/

#include<stdio.h>
#include<stdlib.h>

typedef struct BSTnode{
	int data;
	struct BSTnode *left;
	struct BSTnode *right;
};


//create  a binary search tree using the algorithm of BST--->
                    //all of the components of left subtree will be smaller than the right subtree &
                    //all of the components of right subtree will be greater than the left subtree
struct BSTnode *insert(struct BSTnode *root, int value){
	if(root == NULL){
		root = (struct BSTnode*)malloc(sizeof(struct BSTnode));
		root->left = root->right = NULL;
		root->data = value;
		return root;
	}else{
		if(value < root->data){
			root->left = insert(root->left, value); //applying recursive function to get all of the data which is less than root
		}else{
			if(value > root->data){
				root->right = insert(root->right, value);  //applying recursive function to get all of the data which is greater than root
			}else{

			}
		}
		return root;
	}

};

//making display inorder --> using inorder algorithm
                //--># left -> root -> right
void inorder(struct BSTnode *root){
	if(root != NULL){
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}
//making display preorder --> using preorder algorithm
                //--># root -> left -> right
void preorder(struct BSTnode *root){
	if(root != NULL){
		printf("%d\t", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


//making display postorder --> using postorder algorithm
                // left -> right -> root
void postorder(struct BSTnode *root){
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->data);
	}
}


//get minimum value which is in the left subtree and apply while loop to get last value in the left subtree
int minValue(struct BSTnode* node) {
	struct BSTnode* current = node;

	while (current->left != NULL) {
		current = current->left;
	}
	return(current->data);
}


//get maximum value which is in the right subtree and apply while loop to get last value in the right subtree
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
	printf("Maximum value in the tree is : %d", maxValue(root));

	printf("\n----------------------------------\n");
	printf("Minimum value in the tree is : %d", minValue(root));



	printf("\n----------------------------------\n");
}
