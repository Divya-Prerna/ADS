#include <stdio.h>
#include <stdlib.h>
struct node
{
	enum {black, red} color;
	int info;
	struct  node *lchild;
	struct  node *rchild;
	struct  node *parent;
};
 
void insert (int);
void insert_balance(struct node *nptr );
void RotateLeft(struct node *ptr);
void RotateRight(struct node *ptr);
void display(struct node *ptr,int level);
 
struct node *root;
struct node *sentinel;
 
int main()
{
int choice,num;
sentinel = (struct node *) malloc(sizeof(struct node));
sentinel->info = -1;
sentinel->color = black;
root = sentinel;
 
while(1)
{
	printf("\n");
	printf("1.Insert\n");
	printf("2.Display\n");
	printf("3.Quit\n");
	printf("\nEnter your choice : ");
	scanf("%d",&choice);
 
	switch(choice)
	{
	 case 1:
	printf("\nEnter the number to be inserted : ");
	scanf("%d",&num);
	insert(num);
	break;
 
	 case 2:
	printf("\n");
	 display(root,0);
	printf("\n");
	 break;
 
	case 3:
	exit(1);
 
 
	 default:
	printf("Wrong choice\n");
 
	}
	}
 
	return 0;
 
}
 
void insert (int ikey )
{
	struct node *tmp, *ptr, *par;
 
	par = sentinel;
	ptr = root;
 
	while( ptr != sentinel )
	{
	par = ptr;
	if( ikey < ptr->info )
	ptr = ptr->lchild;
	else if( ikey > ptr->info )
	ptr = ptr->rchild;
	else
	{
	printf("Duplicate\n");
	return;
	}
	}
	tmp = (struct node *) malloc(sizeof(struct node));
	tmp->info = ikey;
	tmp->lchild = sentinel;
	tmp->rchild = sentinel;
	tmp->color = red;
	tmp->parent = par;
 
	if(par==sentinel)
		root = tmp;
	else if(tmp ->info < par->info )
		par->lchild = tmp;
	else
		par->rchild = tmp;
 
	insert_balance(tmp);
}
void insert_balance(struct node *nptr )
{
	struct node *uncle, *par, *grandPar;
 
	while( nptr->parent->color == red )
	{
	par = nptr->parent;
	grandPar = par->parent;
 
	if( par == grandPar->lchild )
	{
	uncle = grandPar->rchild;
 
	if(uncle->color == red )	
	{
	par->color = black;
	uncle->color = black;
	grandPar->color =red;
	nptr = grandPar;
	}
	else
	{
	if( nptr == par->rchild) 
	{
	RotateLeft(par);
	nptr = par;
	par = nptr->parent;
	}
	par->color = black;	 
	grandPar->color = red;
	RotateRight(grandPar);
	}
	}
	else
	{
	if(par == grandPar->rchild )
	{
	uncle = grandPar->lchild;
 
	if(uncle->color == red )  
	{
	par->color = black;
	uncle->color = black;
	grandPar->color =red;
	nptr = grandPar;
	}
	else	
	{
	if( nptr == par->lchild)   
	{
	RotateRight(par);
	nptr = par;
	par = nptr->parent;
	}
	par->color = black;   
	grandPar->color = red;
	RotateLeft(grandPar);
	}
	}
	}
	}
	root->color = black;
}
 
void RotateLeft(struct node *pptr)
{
	struct node *aptr;
 
	aptr = pptr->rchild;	
	pptr->rchild= aptr->lchild;
 
	if(aptr->lchild !=sentinel)
        aptr->lchild->parent = pptr;
 
	aptr->parent = pptr->parent;
 
	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->lchild )
		pptr->parent->lchild = aptr;
	else
		pptr->parent->rchild = aptr;
    aptr->lchild = pptr;
	pptr->parent = aptr;
}
 
void RotateRight(struct node *pptr)
{
	struct node *aptr;
 
	aptr = pptr->lchild;
	pptr->lchild= aptr->rchild;
 
	if(aptr->rchild !=sentinel )
        aptr->rchild->parent = pptr;
 
	aptr->parent = pptr->parent;
 
	if(pptr->parent == sentinel )
		root = aptr;
	else if( pptr == pptr->parent->rchild )
		pptr->parent->rchild = aptr;
	else
		pptr->parent->lchild = aptr;
 
	aptr->rchild = pptr;
	pptr->parent = aptr;
}
 
void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=sentinel )
	{
		display(ptr->rchild, level+1);
		printf("\n");
		for(i=0; i<level; i++)
			printf("    ");
		printf("%d", ptr->info);
		if(ptr->color==red)
			printf("R");
		else
			printf("B");
		display(ptr->lchild, level+1);
	}
}

