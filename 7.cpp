/*
Implement all the functions of a dictionary (ADT) using hashing. 
Data:  Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable, Keys must be unique Standard Operations:  
Insert(key, value), Find(key), Delete(key)
*/

#include<iostream>
#define M 10
using namespace std;

class hash
{
    public:
      int a[M];
      hash();
      void insert();
      void search();
      void Delete();  
};

hash::hash()
{
     for(int i=0;i<M;i++)
     a[i]=-1;
}

void hash::insert()
{
     int key,index;
     cout<<"\nEnter key value : ";
     cin>>key;
     
     index=key%M;
     
     if(a[index]==-1)
        a[index]=key;
     else
     {
          while(a[index]!=-1)
          {  
              if(index==M-1)
              index=-1;
              
              index++;
              index=index%M;
          }
          a[index]=key;
     }
}

void hash::search()
{
     int key,index,flag=1;
     cout<<"\nEnter key value : ";
     cin>>key;
     
     index=key%M;
     
     if(a[index]==key)
        cout<<"\nElement found..........";
     else
     {
        for(int i=index;i<M+index && a[i]!=-1;i++,i=i%M)
        {
           if(a[i]==key)
           {
               cout<<"\nElement found...........";
               flag=0;
               break;
           }
         }
     }  
     
     if(flag!=0)
     cout<<"\nElement not found !!!!!!";   
}

void hash::Delete()
{
     int key,index,flag=0;
     cout<<"\nEnter key value : ";
     cin>>key;
     
     index=key%M;
     
     if(a[index]==key)
        {
            a[index]=-1;
            cout<<"\nElement Deleted successfully ....";
        }
     else
     {
        for(int i=index;i<M+index && a[i]!=-1;i++,i=i%M)
        {
           if(a[i]==key)
           {
            a[index]=-1;
            cout<<"\nElement Deleted successfully ....";
            flag=1
            break;
           }
        }
     }  
     if(flag!=1)
     cout<<"\nElement not found !!!!!!";      
}

int main()
{
    hash o;
    int ch=0;
    
    do
    {
        cout<<"\n---------MENU----------\n1. Insert\n2. Search\n3. Delete\n4. Exit\nEnter choice : ";
        cin>>ch;
        switch(ch)
        {
             case 1:
                  o.insert();
                  break;
             case 2:
                  o.search();
                  break;
             case 3:
                  o.Delete();
                  break;               
        }
    }while(ch!=4);

}
