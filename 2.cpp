#include<iostream>
#include<graphics.h>
int xmid, ymid;
using namespace std;

class pixel
{
	public:
		int x,y,r;
		float d;
		
};

class bresc:public pixel
{
	public:
		void bresenhamc(int,int,int);
};

void bresc::bresenhamc(int x1,int y1,int rad)
{
	x=0, y=rad;
	d=3-2*rad;
	
	do{
		
		putpixel(x1+x,y1+y,WHITE);
		putpixel(x1+x,y1-y,WHITE);
		putpixel(x1-x,y1+y,WHITE);
		putpixel(x1-x,y1-y,WHITE);
		putpixel(x1+y,y1+x,WHITE);
		putpixel(x1+y,y1-x,WHITE);
		putpixel(x1-y,y1+x,WHITE);
		putpixel(x1-y,y1-x,WHITE);	

	if(d<=0){
		d=d+(4*x)+6;
	}
	else{
	y--;
		d=d+(4*x-4*y)+10;
	}	
	x++;	
	}while(x<=y);
}

int main()
{
	int gd=DETECT, gm;

	initgraph(&gd,&gm,NULL);
	xmid=getmaxx()/2;
	ymid=getmaxy()/2;
	line(xmid,0,xmid,2*ymid);
	line(0,ymid,xmid*2,ymid);
	bresc obj1;
	
		obj1.bresenhamc(50+xmid,ymid-50,30);
	delay(5000);
	closegraph();

}
