#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node{
	struct node* pre;
	struct node* left;
	struct node* right;
	int data;
};

struct rv{
	struct node* a;
	int i;
};

void display(struct node* root){
	if(root!=NULL){
		display(root->left);
		printf("%d ",root->data);
		display(root->right);
	}
}


struct rv* find(struct node* tree,int value,int k ){
	struct rv *val = (struct rv*)malloc(sizeof(struct rv));	
	val->i = 1;
	if(tree==NULL){
		val->a = tree;
		return val; 
	}
	else if(tree->data==value){
		val->a = tree;
		return val; 
	}
	else if(tree->data < value){
		if((value-(tree->data)) < k){
			val->i = 0;
			val->a = tree;
			return val; 
		}
		if(tree->right ==NULL){
			val->a = tree;
			return val; 
		}
		return find(tree->right , value,k);
	}
	else{
		if(((tree->data)-value) < k ){
			val->i = 0;
			val->a = tree;
			return val; 		
		}			
		if(tree->left ==NULL){
			val->a = tree;
			return val; 
		}
		return find(tree->left,value,k);
	}
}

struct node* insert(struct node* tree,int value ,int k){
	struct rv *point = (struct rv*)malloc(sizeof(struct rv));
	point = find(tree,value,k);
	struct node* nn = (struct node*)malloc(sizeof(struct node));
	nn->data = value;
	nn->right= NULL;
	nn->left= NULL;
	if(point->i==1){
		if(point->a==NULL){
			nn->pre = NULL;
			tree = nn;
		}
		else if(point -> a->data == value){
			
		}
		else if(point -> a->data < value){
			nn->pre= point->a;
			point->a->right= nn;
		}
		else{
			nn->pre = point->a;
			point->a->left = nn;
		}
	}
	return tree;
}

int main(){
	struct node* tree = NULL;
	int k;
	printf("Enter k\n");
	scanf("%d",&k);
	int n = 1;
	while(n){
		int value;
		printf("Enter element\n");
		scanf("%d",&value);
		tree = insert(tree,value,k);
		printf("for exit press 0 ,otherwise enter any other key");
		scanf("%d",&n);
	}
	display(tree);
	return 0;
}

