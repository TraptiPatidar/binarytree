#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *left;
	struct node *right;
};
struct node *root;
struct node *findm(struct node *root){
	if(root==NULL) return NULL;
	else if(root->left!=NULL) return findm(root->left);
	return root;
}
struct node *deletenode(int x,struct node *root){
	if(root==NULL) return NULL;
	else if(x<root->num) root->left=deletenode(x,root->left);
	else if(x>root->num) root->right=deletenode(x,root->right);
	else{
		if(root->left==NULL && root->right==NULL){
			free(root);
			root =NULL;
		}
		else if(root->left==NULL){
			struct node *temp;
			temp=root;
			root=root->right;
			free(temp);

		}
		else if(root->right==NULL){
			struct node *temp;
			temp=root;
			root=root->left;
			free(temp);
		}
		else{
			struct node *temp;
			temp=findm(root->right);
			root->num=temp->num;
			root->right=deletenode(temp->num,root->right);
		}
	}
	return root;
}
void search(struct node *p,int x){
	if(p==NULL){
		printf("number does not exist\n");
	}
	else if(p->num==x)
		printf("number found\n");
	else if(x<p->num){
		search(p->left,x);
	}
	else
	search(p->right,x);
}
struct node *insert(struct node *p,int x){
	if(p==NULL){
		p=(struct node*)malloc(sizeof(struct node));
		p->num=x;
		p->left=NULL;
		p->right =NULL;
	}
	else if(x<p->num){
		p->left=insert(p->left,x);
	}
	else if(x>p->num){
		p->right=insert(p->right,x);
	}
	else if(x==p->num){
		printf("duplicate nodes");
		exit(0);
	}
	return p;
}
void preorder(struct node *p){
	if(p!=NULL){
		printf("%d\n",p->num);
		preorder(p->left);
		preorder(p->right);
	}
}
void postorder(struct node *p){
	if(p!=NULL){
		postorder(p->left);
		postorder(p->right);
		printf("%d\n",p->num);
	}
}
void inorder(struct node *p){
	if(p!=NULL){
		inorder(p->left);
		printf("%d\n",p->num );
		inorder(p->right);
	}
}
int main(){
	root=NULL;
	int choice=0,x;
	while(choice!=7){
		printf("1.insert a node in tree\n2.preorder transverse\n3.postorder transverse\n4.inorder transverse\n5.search a node in bst\n6.delete a node\n7.Exit");
		printf("\nenter your choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("\nEnter data and press 0 to stop making a node = ");
			scanf("%d",&x);
			while(x!=0){
				root=insert(root,x);
				printf("\nEnter data and press 0 to stop making a node = ");
				scanf("%d",&x);
			}
			continue;
			case 2:preorder(root);
			continue;
			case 3:postorder(root);
			continue;
			case 4:inorder(root);
			continue;
			case 5:printf("enter node to be searched ");
			scanf("%d",&x);
			search(root,x);
			continue;
			case 6:printf("enter node to be deleted");
			scanf("%d",&x);
			root=deletenode(x,root);
			printf("deleted successfully");
			continue;
		}
	}
	return 0;
}