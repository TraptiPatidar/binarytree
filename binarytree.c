#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *left;
	struct node *right;
};
struct node *root;
struct node *insert(){
	int x;
	printf("\nEnter data and press 0 to stop making a node = ");
	scanf("%d",&x);
	if(x==0)
		return NULL;
	struct node *p;
	p=(struct node*)malloc(sizeof(struct node));
	p->num=x;
	printf("creating left node of %d",p->num);
	p->left=insert();
	printf("Creating right node of %d",p->num);
	p->right=insert();
	return p;
}
void *preorder(struct node *p){
	if(p!=NULL){
		printf("%d\n",p->num);
		preorder(p->left);
		preorder(p->right);
	}
}
void *postorder(struct node *p){
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
	int choice=0;
	while(choice!=5){
		printf("1.insert a node in tree\n2.preorder transverse\n3.postorder transverse\n4.inorder transverse\n5.Exit");
		printf("\nenter your choice = ");
		scanf("%d",&choice);
		switch(choice){
			case 1:root=insert();
			continue;
			case 2:preorder(root);
			continue;
			case 3:postorder(root);
			continue;
			case 4:inorder(root);
			continue;
		}
	}
	return 0;
}
