/*
To create ADT that implements the SET concept. 
a. Add (newElement) -Place a value into the set   
b. Remove (element) Remove the value  
c. Contains (element) Return true if element is in collection  
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection 
e. Intersection  of two sets, 
f. Union of two sets,  
g. Difference between two sets, 
h. Subset 
*/

#include<iostream>
using namespace std;

class set
{
   public:
   int a[10],cnt;
   set()
   {
      cnt=0;
   }
   
   void add();
   void remove();
   void search(int key);
   void size();  
   void display();
};

void set::add()
{
   if(cnt!=10)
   {
   cout<<"\nEnter element : ";
   cin>>a[cnt];
      cnt++;
   }
   else
   cout<<"\nSpace not available !!!!!";
}

void set::remove()
{
   if(cnt>0)
   {
   cout<<"\nDeleted Element is : "<<a[--cnt];
   cnt++;//only for restoring 
   cnt--;
   }
   else
   cout<<"\nSet is empty !!!!";
}

void set::display()
{
    cout<<"\nSet = ";
    for(int i=0;i<cnt;i++)
        cout<<a[i]<<" ";
    
}

void set::search(int key)
{
   for(int i=0;i<cnt;i++)
   {
       if(a[i]==key)
       {
          cout<<"\nElement found at location :"<<++i;
          break;
       }
   }
}

void set::size()
{
//   int size=cnt+1;
   cout<<"\nSize of set is :"<<cnt;
}

class set_op
{
   public:
      int c[10];

    void Union(int [],int,int [],int);
    void Intersect(int [],int,int [],int);
    void difference(int [],int,int [],int);
    void subset(int [],int,int [],int);

};

void set_op::Union(int a[10],int cnt1,int b[10],int cnt2)
{
           int i,j,flag=0,cnt3;

           for(cnt3=0;cnt3<cnt1;cnt3++)
           c[cnt3]=a[cnt3];
           
           for(i=0;i<cnt2;i++)
           {
           	   for(j=0;j<cnt1;j++)
           	   {
           	   	   if(b[i]==c[j])
           	   	   flag=1;
           	   }

           	   if(flag==0)
           	   {
           	   	c[cnt3]=b[i];
                cnt3++;
           	   }
           	   flag=0;
           }   
           cout<<"Union of sets is : ";
           for(i=0;i<cnt3;i++)
           	cout<<" "<<c[i];
}

void set_op::Intersect(int a[10],int cnt1,int b[10],int cnt2)
{
	int i,j,cnt3=0;

	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			if(a[i]==b[j])
			{
				c[cnt3]=a[i];
				cnt3++;
			}
		}
	}
    cout<<"Intersection of sets is : ";
	for(i=0;i<cnt3;i++)
		cout<<" "<<c[i];
}

void set_op::difference(int a[10],int cnt1,int b[10],int cnt2)
{
	int i,j,cnt3=0,flag;
	
	for(i=0;i<cnt1;i++)
	{
		flag=0;
		for(j=0;j<cnt2;j++)
		{
			if(a[i]==b[j])
			{
              flag=1;
			}
		}
		if(flag==0)
		{
		c[cnt3]=a[i];
		cnt3++;
		}
	}		
        cout<<"Difference of set A and B is : ";
		for(i=0;i<cnt3;i++)
		cout<<" "<<c[i];
}

void set_op::subset(int a[10],int cnt1,int b[10],int cnt2)
{
	int i,j,flag=0;
	
	for(i=0;i<cnt1;i++)
	{
		for(j=0;j<cnt2;j++)
		{
			if(a[i]==b[j])
			{
				flag=1;
				break;
			}
			else 
				flag=0;
		}
	}		
    
    cout<<"A is a subset of B";
}

int main()
{
    int ch,key;
    set a,b;
    set_op c;
    do
    {
        
        cout<<"\nMenu\n\nFOR SET A\n1. Add element\n2. Remove\n3. Search\n4. Size\n5. Display\n\nFOR SET B\n6. Add element\n7. Remove\n8. Search\n9. Size\n10. Display\n\n11. Union\n12. Intersect\n13. Difference between set A and B\n14. Subset\n15. Exit\nEnter choice :";
        cin>>ch;
        switch(ch)
        {
           case 1:
             a.add();
           break;
           
           case 2:
             a.remove();
           break;
           
           case 3:
              cout<<"\nEnter key : ";
              cin>>key;
              a.search(key);
           break;
           
           case 4:
              a.size();
           break;

           case 5:
              a.display();
           break;

           case 6:
             b.add();
           break;
           
           case 7:
             b.remove();
           break;
           
           case 8:
              cout<<"\nEnter key : ";
              cin>>key;
              b.search(key);
           break;
           
           case 9:
              b.size();
           break;
           
           case 10:
              b.display();
           break;

           case 11:
              c.Union(a.a,a.cnt,b.a,b.cnt);
           break;

           case 12:
              c.Intersect(a.a,a.cnt,b.a,b.cnt);
           break;

           case 13:
              c.difference(a.a,a.cnt,b.a,b.cnt);
           break;

           case 14:
              c.subset(a.a,a.cnt,b.a,b.cnt);
           break;
        }
      
    }while(ch!=15);

}

