#include<iostream>
#include<graphics.h>
using namespace std;
#define START_X 300
#define START_Y 300
class pattern
{
	int side;
	float inrad;
	float outrad;
	public:
		pattern(int s)
		{
			side=s;
			inrad=outrad=0;
		}
		void calculate()
		{
			inrad=side/(2*sqrt(3));
			cout<<inrad;
			outrad=side/(sqrt(3));	
			cout<<outrad;
		}
		void draw()
		{
			int gd=DETECT,gm;
			initgraph(&gd,&gm,NULL);
			float height=sqrt(3)/2*side;
			line(START_X,START_Y,START_X+side/2,START_Y-height);
			line(START_X+side/2,START_Y-height,START_X+side,START_Y);
			line(START_X+side,START_Y,START_X,START_Y);
			delay(300);
			circle(START_X+side/2,START_Y-inrad,inrad);	
			circle(START_X+side/2,START_Y-inrad,outrad);		
			getch();
			closegraph();
		}
};
int main()
{
	pattern p(40);
	p.calculate();
	p.draw();
}
