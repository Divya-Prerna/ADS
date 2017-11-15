#include<iostream>
#include<conio.h>

using namespace std;

struct node
{
	int data;
	node *next;
};

void addFirst (node **head,int data);
void display(node *head);
void addLast(node *head,int data);
void display(node *head);
node *reverse(node **head);
node *sortList(node **head);
node *intersection(node *listOne, node *listTwo);

int main()
{
	node *list1=new node;
	node *list2=new node;
	node *intersectionList=new node();
	list1 -> data=2;
	list -> next= NULL;
	list2 -> data=3;
	list2 -> next=NULL;
cout<< Ädd elements of list1<<endl;
cin>>list1;
cout<< Ädd elements of list2<<endl;
cin>>list2;

	cout<< "List1 before sorting<<endl;
	display(list1);
	cout<< "List2 before sorting<<endl;
	display(list2);
	
	sortList(&list1);
	cout<<"List1 after sorting"<<endl;
	display(list1);
	sortList(&list2);
	cout<< "List2 after sorting"<<endl;
	display(list2);
	
	intersectionList=intersection(list1,list2);
	cout<<"intersectionList is ="endl;
	display(intersectionList);
	
	delete list1;
	delete list2;
	getch();
}

void addFirst(node **head,int data)
{
	node *newHead=new node();
	newHead -> data=data;
	newHead -> next=head;
	*head=newHead;
	
}

void addLast(node *head, int data)
{
	node *curr=head;
	node *newHead=new node();
	newHead -> data = data;
	while(cur)
	{
		if(cur -> next==NULL)
		{
			cur->next=newHead;
			newHead -> next=NULL;
			return;
		}
		 cur=cur->next;
	}
}
	
	void display(node *head)
	{
		node *cur=head;
		while(cur)
		{
			if(cur -> next==NULL)
			cout<<cur -> data;
            			
		}
		else
		cout<<cur -> data;
		cur = cur -> next;
	}
	cout<<endl;
	cout<<endl;
}

node *reverse(node **node)
{
	node *parent=*head;
	node *me=parent -> next;
	parent -> next=NULL;
	node *child = me->next;
}







