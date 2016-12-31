#include<conio.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
	int data;
	int h;
	struct node* pre;
	struct node* left;
	struct node* right;
};

int max(int x,int y){
	if(x<y){
		return y;
	}
	else 
		return x;
}

struct tv{
	struct node* a;
	int hi;
};

struct node* LL(struct node* root){
	struct node* temp;
	temp = root->right;
	temp1 = temp->left;
	temp->pre= root->pre;
	root->right=NULL;
	temp->left=root;
	root->right=temp1;
	return root;
}

struct node* LL(struct node* root){
	struct node* temp;
	temp = root->left;
	temp1 = temp->right;
	temp->pre= root->pre;
	root->left=NULL;
	temp->right=root;
	root->left=temp1;
	return root;
}

struct node* LR(struct node* root){
	struct node* temp = root->right;
	root->right = NULL;
	root ->right = temp->left;
	root->right->pre= root;
	root->right->right= temp;
	return LL(root);
}

struct node* RL(struct node* root){
	struct node* temp = root->left;
	root->left = NULL;
	root ->left = temp->right;
	root->left->pre= root;
	root->left->left= temp;
	return RR(root);
}


int height(struct node* tree){
	if(tree==NULL){
		tree->h = -1;
	}
	else{
		if(tree->left==NULL && tree->right==NULL){
			tree->h = 0;
		}
		else if(tree->left!=NULL && tree->right!=NULL){
			
		}
		else if(tree->left!=NULL){
			if(tree->left->h>-2){
				tree->h = (tree->left->h)+1;
			}
			else
				tree->h = height(tree->left) + 1;
		}
		else{
			if(tree->right->h>-2){
				tree->h = (tree->right->h)+1;
			}
			else
				tree->h = height(tree->right)+1;
		}
	}
	return tree->h;
}

struct node* check(struct node* tree){
	if(tree==NULL){
		return tree;
	}	
	else if(tree->left==NULL && tree->right==NULL){
		return tree;
	}
	else{
		int diff , left ,eq;
		if(tree->right->h  > tree->left->h ){
			left = 0;
			diff = tree->right->h - tree->left->h;
		}
		else if(tree->left->h > tree->right->h){
			left = 1;
			diff = tree->left->h - tree->right->h;
		}
		else{
			eq = 1;
		}
		if(eq!=1 && diff>1){
			if(left==1){
				if(tree->left->left!=NULL){
						tree = LL(tree);
				}
				else{
					tree = LR(tree);
				}
			}
			else {
				if(tree->right->right!= NULL){
					tree = RR(tree);
				}
				else{
					tree = RL(tree);
				}
			}
		}
		tree->left = check(tree->left);
		tree->right = check(tree->right);	
	}
	return tree;
}

struct node* find(struct node* tree,int value){
	if(tree==NULL){
		return tree;
	}
	else if(tree->data==value){
		return tree;
	}
	else if(tree->data < value){
		if(tree->right==NULL){
			return tree;
		}
		else 
			return find(tree->right,value);
	}
	else{
		if(tree->left==NULL){
			return tree;
		}
		else
			return find(tree->left,value);
	}
}

struct node* insert(struct node* tree,int value){
	struct node* point = find(tree,value);
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data= value;
	nn->left= NULL;
	nn->right= NULL;
	nn->h = -2;
	if(point == NULL){
		nn->pre= NULL;
		tree = nn;
		return tree;
	}
	else if(point->data==value){
		
	}
	else if(point->data < value){
		point->right = nn;
		nn->pre=point;
		int hi = height(tree);
		return check(tree);
	}
	else{
		point->left = nn;
		nn->pre= point;
		int hi = height(tree);
		printf("h = %d \n",hi);
		return check(tree);
	}
}

void display(struct node* root){
	if(root!=NULL){
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}


int main(){
	struct node* tree = NULL;
	int n = 1;
	while(n){
		int value;
		printf("Enter element\n");
		scanf("%d",&value);
		tree = insert(tree,value);
		printf("for exit press 0 ,otherwise enter any other key");
		scanf("%d",&n);
	}
	display(tree);
	return 0;
}

