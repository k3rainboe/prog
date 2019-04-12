#include<iostream>
#include<graphics.h>
using namespace std;
 
int xmid, ymid; 
 
class pixel
{
 
	public:
		float x,y,length,dx,dy;
		int p,i;
 
};
 
class pixel1:public pixel
{
	public:		
		void DDA(float,float,float,float);
		void bresen(float,float,float,float);
		int sign(float);
	
};
 
 
 
 
int pixel1::sign(float x)
{
	if(x<0)
	return -1;
	else if(x=0)
	return 0;
	else 
	return 1;
}	
 
void pixel1::DDA(float x1,float y1,float x2,float y2)
{
	dx=abs(x2-x1);
	dy=abs(y2-y1);
 
	if(dx>dy)
	length=dx;
	else
	length=dy;
	
	dx=(x2-x1)/length;
	dy=(y2-y1)/length;
	
	x=x1+0.5*sign(dx);
	y=y1+0.5*sign(dy);
	
	for(int i=0;i<length;i++)
	{
	x=x+dx;
	y=y+dy;
 
	putpixel(xmid+x,ymid-y,WHITE);
 
	}
}
 
void pixel1::bresen(float x1,float y1,float x2,float y2)
{
	int s1, s2, ex, e=0;
	float temp;
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	x=x1;
	y=y1;
	
	if(x2 > x1) 
		s1=1;             
    if(x2 < x1)
        s1=-1;
	if(x2 == x1)
    	s1=0;
              
    if(y2 > y1)
    	s2=1;             
    if(y2 < y1)
        s2=-1;
	if(y2 == y1)
    	s2=0;
             
             if(dy > dx)
             {
                temp = dx;
                dx = dy;
                dy = temp;
                ex = 1;
             }
             e=2*dy-dx; 
             i=1;
             do
             {
                  while(e>=0)
                  {
                     if(ex==1)
                        x = x + s1;
                     else
                        y = y + s2;
                     e = e - 2*dx;
                  }
                  if(ex==1)
                     y = y + s2;
                  else
                     x = x + s1;
                  e = e + 2*dy;
                  i = i + 1;
                 putpixel(xmid+x,ymid-y,WHITE); 
           }while(i<=dx);
}
 
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	
	line(0, ymid, getmaxx(), ymid);
	line(xmid, 0, xmid, getmaxy());
	
	pixel1 s;
	float x1,y1,x2,y2;
	char ans;
	int ch;
 
	
 
	do
	{
	cout<<"\n****MENU****";
	cout<<"\n1.DDA ";
	cout<<"\n2.Bresenham ";
	cout<<"\n3.Exit ";
	cin>>ch;
 
	switch(ch)
	{
		case 1: cout<<"\nEnter co-ordinates of line(x1,y1,x2,y2)";
			cin>>x1>>y1>>x2>>y2;
			s.DDA(x1,y1,x2,y2);
			break;
	
		case 2: cout<<"\nEnter co-ordinates of line(x1,y1,x2,y2)";
			cin>>x1>>y1>>x2>>y2;
			s.bresen(x1,y1,x2,y2);
			break;
 
		case 3: 
			break;
 
	}
	cout<<"\nDo u want to continue...(y/n)";
	cin>>ans;
	}while(ans=='y');
 
 
	delay(10000);
	closegraph();
 
}
