#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
int gd = DETECT,gm;
int x1, y1, x2, y2, dx, dy, i, length;
float xiner, yiner, x, y;
initgraph(&gd, &gm,"C://TURBOC3//BGI");
printf("\n Enter the value of x1");
scanf("%d",&x1);
printf("\n Enter the value of y1");
scanf("%d",&y1);
printf("\n Enter the value of x2");
scanf("%d",&x2);
printf("\n Enter the value of y2");
scanf("%d",&y2);
dx=x2-x1;
dy=y2-y1;
if(abs(dx)>abs(dy))
length=abs(dx);
else
length=abs(dy);
xiner= dx/(float)length;
yiner= dy/(float)length;
x=x1;
y=y1;
i=1;
putpixel(x,y,13);
while(i<=length){
putpixel(x,y,13);
x=x+xiner;
y=y+yiner;
i=i+1;
printf("\n (%f, %f) ",x,y);
}
getch();
closegraph();
return 0;
}