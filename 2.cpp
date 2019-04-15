/*
For given expression eg. a-b*c-d/e+f construct inorder sequence and traverse it using postorder traversal(non recursive). 
*/

#include<iostream>
#include<cstdlib>
#include<cstring>
#define size 20
using namespace std;

class node
{
       public:
       char data;
       node *left;
       node *right;
};

class stack
{
  int top;
  public:
       
       node *s[size];
       
       stack()
       {
         top=-1;
       }
       void push(node *data)
       {
         if(top>=size)
         cout<<"\nstack overflow !!!!!!!!!!";
         else
         {
           top++;
           s[top]=data;
         }
       }
       
       node * pop()
       {
         node *t;
         if(top==-1)
         cout<<"\nstack underflow!!!!!!!!!!";
         else
         {
           t=s[top];
           top--;         
         }           
         return t;
       }
};

class etree
{
  public:
  node *root;
  
  void create(string str)
  {
    stack s;
     
     for(int i=0;i<str.length();i++)
     {
        if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
        {
          node *newnode=new node();
          newnode->data=str[i];
          
          newnode->right=s.pop();
          newnode->left=s.pop();
          s.push(newnode);
        }
        else
        {
          node *newnode=new node();
          newnode->left=newnode->right=NULL;
          newnode->data=str[i];
          s.push(newnode);      
        }
     }     
     root=s.pop();  
  }
  
  void inorder(node *temp)
  {
        if(temp!=NULL)
        {
            inorder(temp->left);
            cout<<temp->data<<" ";
            inorder(temp->right);
        }  
  }
  
  void preorder(node *temp)
  { 
        if(temp!=NULL)
        {
            cout<<temp->data<<" ";
            preorder(temp->left);
            preorder(temp->right);
        }
  }

  void postorder(node *temp)
  { 
        if(temp!=NULL)
        {
            postorder(temp->left);
            postorder(temp->right);
            cout<<temp->data<<" ";
        }
  }
};

int main()
{
  etree obj;
  string str;
  cout<<"Enter postfix expression : ";
  cin>>str;
  obj.create(str); 
  cout<<"\ninfix expression : ";
  obj.inorder(obj.root); 
  cout<<"\nprefix expression : ";
  obj.preorder(obj.root); 
  cout<<"\npostfix expression : ";
  obj.postorder(obj.root); 


}


