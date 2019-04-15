/*
  Beginning with an empty binary search tree, Construct binary search tree by inserting the values in the order given. 
  After constructing a binary tree - 
  i. Insert new node 
  ii. Find number of nodes in longest path  
  iii. Minimum data value found in the tree  
  iv. Change a tree so that the roles of the left and right pointers are swapped at every node  
  v.  Search a value
*/

#include<iostream>
#include<cstdlib>
using namespace std;

class node
{
  public:
       int data;
       node *left;
       node *right;
};

class bst
{
 public:
       node *root;
 
       bst()
       {
       root=NULL;
       }
 
       void insert();
       void inorder(node *);
       void preorder(node *);
       void postorder(node *);
       void lowest(node *);  
       void greatest(node *);
       void search(node *,int);
       int height(node *);
       void mirror(node *);
};

void bst::insert()
{
       node *newnode=new node();
       node *current;
  
       cout<<"enter data : ";
       cin>>newnode->data;
       newnode->left=newnode->right=NULL;
 
       if(root==NULL)
       root=newnode;
       else
       {
         current=root;
   
       while(current!=NULL)
       {
         if(newnode->data<current->data)
          {   
            if(current->left==NULL)
              {
                current->left=newnode;
                break;
              }
            else
         current=current->left;
     }
     else if(newnode->data>current->data)
     {
       if(current->right==NULL)
         {
          current->right=newnode;
          break;
         }
       else
         current=current->right;       
     }  
   }
 }
}

void bst::inorder(node *current)
{ 
  if(current!=NULL)
  {
  inorder(current->left);
  cout<<current->data<<" ";
  inorder(current->right);
  }
}

void bst::preorder(node *current)
{ 
  if(current!=NULL)
  {
  cout<<current->data<<" ";
  inorder(current->left);
  inorder(current->right);
  }
}

void bst::postorder(node *current)
{ 
  if(current!=NULL)
  {
  inorder(current->left);
  inorder(current->right);
  cout<<current->data<<" ";
  }
}

void bst::lowest(node *current)
{ 
  if(current!=NULL)
  {
  while(current->left!=NULL)
  current=current->left;
  cout<<"\nlowest : "<<current->data;
  }
  else
  	cout<<"\nno lowest element !!!";
}

void bst::greatest(node *current)
{
  if(current!=NULL)
  {
  while(current->right!=NULL)
  current=current->right;
  cout<<"\ngreatest : "<<current->data;
  }
  else
  	cout<<"\nno greatest element !!!";
}

void bst::search(node *current,int key)
{
  if(current==NULL)
  cout<<"\nElement not present !!!!";
  else if(key==current->data)
  cout<<"\nelement is present";
  else if(key<current->data)
  search(current->left,key);
  else if(key>current->data)
  search(current->right,key);
}

int bst::height(node *R)
{
  int lheight,rheight;
  if(R==NULL)
  return 0;
  if(R->left==NULL && R->right==NULL)
  return 0;
  
  lheight=height(R->left);
  rheight=height(R->right);
  
  if(rheight>lheight)
         return (rheight+1);
  else
         return (lheight+1);

}

void bst::mirror(node *R)
{
  node *temp;
    if(R!=NULL)
      {
        temp=R->left;
        R->left=R->right;
        R->right=temp;
        mirror(R->left);
        mirror(R->right);
      }
}

int main()
{
   int ch=1,ch0;
   int key,ht;
   bst obj;
 
   do
   {
       cout<<"\n*****************MENU********************";
       cout<<"\n1.insert\n2.inorder\n3.preorder\n4.postorder\n5.lowest\n6.greatest\n7.search\n8.height\n9.mirror\n10.exit";
       cout<<"\n*****************************************\n";
       cin>>ch0;
       switch(ch0)
       {
              case 1:
                     while(ch)
                     { 
                            cout<<"Do you want to enter(1/0) : ";
                            cin>>ch;
                            if(ch)
                            obj.insert();
                      }
              break;
    
              case 2:
                            cout<<"\ninorder : ";
                            obj.inorder(obj.root);
              break;
     
              case 3:
                            cout<<"\npreorder : ";
                            obj.preorder(obj.root);
              break;
              
              case 4:
                            cout<<"\npostorder : ";
                            obj.postorder(obj.root);
              break;
              
              case 5:
                            obj.lowest(obj.root);
              break;
              
              case 6:
                            obj.greatest(obj.root);       
              break;
              
              case 7:
                            cout<<"\nEnter data to search : ";
                            cin>>key;
                            obj.search(obj.root,key);
              break;
              
              case 8:
                            ht=obj.height(obj.root);
                            cout<<"\nheight of tree : "<<ht;
              break;
              
              case 9:
                            cout<<"\nBefore mirror ";
                            cout<<"\ninorder : ";
                            obj.inorder(obj.root);
                            obj.mirror(obj.root);
                            cout<<"\nafter mirror ";
                            cout<<"\ninorder : ";
                            obj.inorder(obj.root);
                            
              break;
              
              case 10:
              exit(0);              
        }
       
    }while(1);

}
