/*
You have a business with several offices; you want to lease phone lines to connect them up with each other;
 and the phone company charges different amounts of money to connect different pairs of cities. 
You want a set of lines that connects all your offices with a minimum total cost. 
Solve the problem by suggesting appropriate data structures. 
*/

#include<iostream>
using namespace std;

class sm
{ 
  public:
  char v1,v2;
  int w;
};

class mst
{

  int count,rcount;
    sm a[10],b[10];
  public:
  mst()
  {
            rcount=0;
  }

  
  void read();
  void display();
  void kruskal();

};

void mst::read()
{
  cout<<"Enter no of cities : ";
  cin>>count;
  cout<<"\nEnter as (cityno cityno charges) eg. 2 3 250\n";
  for(int i=1;i<=count;i++)
  {
    cout<<i<<": ";
    cin>>a[i].v1>>a[i].v2>>a[i].w;
  
  }
}

void mst::kruskal()
{
    int i,j,k,flag=0;
    
    for(i=1;i<=count;)
    {      
         if(flag<2)
         {
              rcount++;
              b[rcount]=a[i];
         }
         i++;flag=0;     
         for(k=1;k<=rcount;k++)
         {
               if(a[i].v1==b[k].v1 || a[i].v1==b[k].v2)
               {
                      flag++;
                      break;
               }
           }
           for(k=1;k<=rcount;k++) 
           {  
               if(a[i].v2==b[k].v1 || a[i].v2==b[k].v2)
               {
                      flag++;
                      break;
               }         
         }
    }

}

void mst::display()
{
  int total=0;
  cout<<"\n\nconnect cities for minimum cost :\n";
  cout<<"city  cityno  cost\n";
  for(int i=1;i<=rcount;i++)
  {
    cout<<b[i].v1<<"     "<<b[i].v2<<"       "<<b[i].w<<endl;  
  }
  
  for(int i=1;i<=rcount;i++)
  	total += b[i].w;

  cout<<"\nTotal cost = "<<total;

}


int main()
{
  mst o1;
  
  o1.read();
  //o1.display();
  o1.kruskal();
   o1.display();
}
