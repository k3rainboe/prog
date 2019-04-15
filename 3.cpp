/*Convert given binary tree into threaded binary tree.  Analyze time and space complexity of the algorithm.  */
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *right,*left;
	int rbit,lbit;
};

class tbt
{

	public:
       node *root,*head;
	tbt()
	{
         root=head=NULL;
	}
	
	void preorder();
	void inorder();
	node* create()
	{
	       node *temp,*newnode;
		int flag;
		char ans;
		head=new node();
		head->right=head->left=head;
		head->data=999;
		head->lbit=head->rbit=1;
		
		root=new node();
		cout<<"Enter root node = ";
		cin>>root->data;
		root->left=root->right=head;
		root->lbit=root->rbit=1;
		
		do{
		       flag=0;
		       newnode=new node();
		       cout<<"\nEnter data = ";
		       cin>>newnode->data;
		       newnode->lbit=newnode->rbit=1;
		       
		       temp=root;
		       
		       while(flag==0)
		       {
		       
			     if(newnode->data<temp->data)
			     {
			          if(temp->lbit==1)
			          {
			            newnode->left=temp->left;
			            temp->left=newnode;
			            temp->lbit=0;
			            newnode->right=temp;
			            flag++;
			          }
			          else{
			            temp=temp->left;
			          }
			     }
			     else if(newnode->data>temp->data)
			     {
			          if(temp->rbit==1)
			          {
			            newnode->right=temp->right;
			            temp->right=newnode;
			            temp->rbit=0;
			            newnode->left=temp;
			            flag++;
			          }
			          else{
			            temp=temp->right;
			          }			     
			     }
			     else{
			          cout<<"\ndata already present!!!!";
			          flag++;			     
			     }
			
	              }
	              cout<<"\ndo you want to continue (Y/y)";
	              cin>>ans;
	       }while(ans=='Y' || ans=='y'); 
	       
	       return root;   	

          }
};

void tbt::preorder()
{
     node *temp;
     int flag=0;
     temp=root;
     cout<<"\nPreorder = ";
     while(temp!=head)
     {
        if(flag==0)
        cout<<" "<<temp->data;
        if(temp->lbit==0 && flag==0)
        temp=temp->left;
        else if(temp->rbit==0)
        {
          temp=temp->right;
          flag=0;
        }
        else
        {
          temp=temp->right;
          flag=1;        
        }
     }
     cout<<"\n";
}

void tbt::inorder()
{
     node *temp;
     int flag=0;
     temp=root;
     cout<<"\nInorder = ";
     while(temp!=head)
     {
        if(temp->lbit==1 && flag==0)
        temp=temp->left;
        else 
        {
          cout<<" "<<temp->data;
          if(temp->rbit==1)
          {
             temp=temp->right;
             flag=0;
          }
          else
          {
             temp=temp->right;
             flag=1;
          }
        
        }
     }
     cout<<"\n";
}
int main()
{
	node *root;
	tbt obj;
	root=obj.create();
	obj.preorder();
	obj.inorder();
}
