#include<iostream>
#define size 10
using namespace std;

class node
{
	public:
		int data;
		node * next;
		node(){
			next=NULL;
			data=0;
		}
};

class graph
{
	public:
	node *head[size];
	int adjm[size][size],i,j,v;
	
	graph(){
		for(i=0;i<size;i++){
		head[i]=NULL;
		}
		for(i=0;i<size;i++){
			for(j=0;j<size;j++){
				adjm[i][j]=0;
				
			}
		}
	}
	
	void accept();
	void display_adjm();
	void display_adjl();
};

void graph::accept(){
	node *temp;
	cout<<"Enter no. of vertices:";
	cin>>v;
	int n,ver;
	for(i=0;i<v;i++){
		cout<<"Enter no. of edges connected to "<<i+1<<": ";
		cin>>n;
		while(n!=0){
			cout<<"Enter vertice:";
			cin>>ver;
			adjm[i][ver-1]=1;
			adjm[ver-1][i]=1;
			
			node *newnode = new node();
			newnode->data=ver;
			newnode->next=NULL;
			
			if(head[i]==NULL)
				head[i]=newnode;
			else{
				temp=head[i];
				while(temp->next!=NULL)
					temp=temp->next;
				temp->next=newnode;
			}
			n--;
		}
	}
}

void graph::display_adjm(){
	for(i=0;i<v;i++)
		cout<<"\t"<<i+1;
	
	for(i=0;i<v;i++){
		cout<<"\n"<<i+1;
		for(j=0;j<v;j++){
			cout<<"\t";
			cout<<adjm[i][j];
		}
	}
	cout<<"\n\n";
}

void graph::display_adjl(){
	for(i=0;i<v;i++){
		cout<<i+1<<" : ";
		node *temp = head[i];
		while(temp!=NULL){
			cout<<temp->data<<" - ";
			temp=temp->next;
		}
		cout<<"\b\b\b\b\b\b\n";
	}
}

int main()
{
	graph obj;
	obj.accept();
	obj.display_adjm();	
	obj.display_adjl();
	return 0;
}
