#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../include/MainHeaderFile.h"
#include"../include/BinarySearchTreeFile.h"

struct bst * search_bst(struct bst *r, char *n){
	
	struct bst *node;
//	printf("Search 1 BST Root : %s\n",BST_Root->data);
	node = r;
//	printf("Search 2 BST Root : %s\n",BST_Root->data);
	char *loc_bst; 
	loc_bst = malloc(100);
	strcpy(loc_bst,n);
	memmove(loc_bst,loc_bst+1,strlen(loc_bst)); //to remove the '/' at the beginning
//	memmove(n,n+1,strlen(n)); //to remove the '/' at the beginning

/*		if(n[strlen(n) - 1] == '/')
//	if(strcmp(parent_path,VFS_Root->data) != 0)
	{
		n[strlen(n) - 1] = '\0';
	}
	*/
//	printf("To be searched in bst : %s\n",loc_bst);
	while(node!=NULL){
	
//		printf("node data : %s\n",node->data);
		if((strcmp(node->data,loc_bst))>0 )
		{
//			printf("Check left_child\n");
			node = node->left_child;
		}
		else if((strcmp(node->data,loc_bst))<0)
		{
//			printf("Check right_child\n");
			node = node->right_child;
//			printf("Check right_child\n");
		}
		else if((strcmp(node->data,loc_bst))==0)
		{
//			printf("Found it!!\n");
			return node;
		}
	}
//	if(NULL == node)
//		printf("NULL NULL NULL \n");
	return NULL;
}

void inorder ( struct bst * tree ) {
	if ( tree != NULL ) {
	
	inorder ( tree -> left_child );
	printf("\t %s",tree->data);
	inorder ( tree -> right_child );
}
}

struct bst* insert_in_bst(struct bst *head, char b[1000]){

	
//	printf("Enter insert bst %s\n",b);
	struct bst *temp;
	struct bst *r;
	temp = (struct bst *)malloc(sizeof(struct bst));
	temp->right_child=NULL;
	temp->left_child=NULL;
	temp->parent=NULL;
	strcpy(temp->data,b);
	
//	printf("Insert data : %s\n", temp->data);
	//strcpy(temp->fd->path,b);
	r = head;
				
	if(NULL == r){
//	printf("Inserted root\n");
		r=temp;
//		printf("Insert data : %s\n", r->data);
		
		return r;
	}
	else if(r!=NULL){
		if((r->left_child==NULL)){
		if((strcmp(r->data,temp->data))>0){
//		printf("%s  >>  %s\n",r->data,temp->data);
//		printf("Inserted left\n");
		r->left_child=temp;
		temp->parent = r;
	}
	}	
	else if((r->left_child!=NULL)&&((strcmp(r->data,temp->data))>0))
	{
//	printf("Insert in left\n");
//	printf("At %s left : %s\n",r->data,temp->data);
		insert_in_bst(r->left_child,temp->data);
		}
	if((r->right_child==NULL)&&((strcmp(r->data,temp->data))<0)){
		r->right_child=temp;
//		printf("%s  <<  %s\n",r->data,temp->data);
//		printf("Inserted right\n");
		temp->parent = r;
	}
	else if((r->right_child!=NULL)&&((strcmp(r->data,temp->data))<0))
	{
//	printf("Insert in right\n");
//	printf("At %s right : %s\n",r->data,temp->data);
		insert_in_bst(r->right_child,temp->data);
		}
}
//printf("INsert funct : BST Root %s\n",BST_Root -> data);
return head;
}

void transplant_bst(struct bst *r, struct bst *u, struct bst *v){
	if((v->parent)==NULL)
		r = v;
	else if(u==(u->parent->left_child))
		u->parent->left_child = v;
	else u->parent->right_child = v;
	if(v!=NULL)
		v->parent = u->parent;
}

struct bst *tree_min_bst(struct bst *z){
	while((z->left_child)!=NULL)
		z = z->left_child;
	return z;
}

void delete_bst(struct bst *r, char a[1000]){
	struct bst *x,*t;
	t = search_bst(r,a);
	if(((t->left_child)==NULL)&&((t->right_child)==NULL)){
		if(t==t->parent->left_child)
			t->parent->left_child = NULL;
		else
			t->parent->right_child = NULL;
	}
	else if(t->left_child == NULL)
		transplant_bst(r,t,t->right_child);
	else if(t->right_child == NULL)
		transplant_bst(r,t,t->left_child);
	else{
		x=tree_min_bst(t->right_child);
		if(x->parent!=NULL){
			transplant_bst(r,x,x->right_child);
			x->right_child = t->right_child;
			x->right_child->parent = x;
		}
		transplant_bst(r,t,x);
		x->left_child = t->left_child;
		x->left_child->parent = x;
	}	
}


