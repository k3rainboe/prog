/*		 Problem Statement: A-7
Consider threading a binary tree using preorder threads rather than inorder threads. Design an algorithm for traversal without using stack and analyze its complexity. 
Div.: SE-A
Roll no.: 		
Batch: SA3
*/


#include<iostream>
using namespace std;

class Tnode
{	
	public:
	int data;
	Tnode *left;
	Tnode *right;
	int lbit, rbit;
};

class TBT : public Tnode
{	
	public:
	Tnode *root;
	Tnode *head;
	TBT()
	{
		root=NULL;
		head=NULL;
	}
	void createTBT();
	void preorder();
};

void TBT :: createTBT()
{
	Tnode *temp, *X;
	char ans;
	head = new Tnode();
	head->left = head;
	head->right = head;
	head->lbit = head->rbit = 1;

	root = new Tnode();
	cout<<"\n\nEnter data for root: ";
	cin>>root->data;
	root->left = head;
	root->right = head;
	root->lbit = root->rbit = 1;
	head->left = root;
	head->lbit=0;
	do
	{
		temp=root;
		X= new Tnode();
		cout<<"\nEnter node: ";
		cin>>X->data;
		X->lbit = X->rbit =1;
		while(1)
		{
			if(X->data < temp->data)
			{
				if(temp->lbit == 1)
				{
					X->left = temp->left;
					temp->left = X;
					temp->lbit = 0;
					X->right = temp;
					break;		
				}
				else
					temp= temp->left;
			}

			else if(X->data > temp->data)
			{
				if(temp->rbit == 1)
				{
					X->right = temp->right;
					temp->right = X;
					temp->rbit = 0;
					X->left = temp;
					break;
				}
				else
					temp= temp->right;
			}
			else
				cout<<"\n\nData already exists";
		}
		cout<<"\nDo you want to add another node? (y/n) ";
		cin>>ans;
	}while(ans=='y' || ans=='Y');
}



void TBT :: preorder()
{
	Tnode *temp;
	int flag=0;
	temp=root;
	while(temp!=head)
	{
		if(flag==0)
			cout<<" "<<temp->data;
		if((temp->lbit==0) && flag==0)
			temp=temp->left;
		else if(temp->rbit==1)
		{
			temp=temp->right;
			flag=1;
		}
		else if(temp->rbit==0)
		{
			temp=temp->right;
			flag=0;
		}
	}
}

int main()
{
	int ch;
	TBT t;
	cout<<"\n\t-----Threaded Binary Tree-----";
	do
	{
		cout<<"\n\n\tMENU\n1.Create\n2.Display Preorder\n3.Exit";
		cout<<"\nYour choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1: t.createTBT();
				  break;
			case 2: cout<<"\nTBT is:";
				  t.preorder();
				  break;
		}
	}while(ch!=3);
	return(0);
}
		
/*gescoe@gescoe:~$ cd Desktop
gescoe@gescoe:~/Desktop$ g++ thread.cpp
gescoe@gescoe:~/Desktop$ ./a.out

	-----Threaded Binary Tree-----

	MENU
1.Create
2.Display Preorder
3.Exit
Your choice: 1


Enter data for root: 50

Enter node: 30

Do you want to add another node? (y/n) y

Enter node: 20

Do you want to add another node? (y/n) y

Enter node: 70

Do you want to add another node? (y/n) y

Enter node: 10

Do you want to add another node? (y/n) y

Enter node: 5

Do you want to add another node? (y/n) y

Enter node: 60

Do you want to add another node? (y/n) y

Enter node: 90

Do you want to add another node? (y/n) n


	MENU
1.Create
2.Display Preorder
3.Exit
Your choice: 2

TBT is: 50 30 20 10 5 70 60 90

	MENU
1.Create
2.Display Preorder
3.Exit
Your choice: 3
gescoe@gescoe:~/Desktop$ */
				


