#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
int gd = DETECT,gm;
float x1, y1, x2, y2, dx, dy, i1, length, x, y, i2, d, xend;
initgraph(&gd, &gm,"C://TURBOC3//BGI");
printf("\n Enter the value of x1");
scanf("%f",&x1);
printf("\n Enter the value of y1");
scanf("%f",&y1);
printf("\n Enter the value of x2");
scanf("%f",&x2);
printf("\n Enter the value of y2");
scanf("%f",&y2);
dx=abs(x2-x1);
dy=abs(y2-y1);
i1=2*dy;
i2=2*(dy-dx);
d=i1-dx;
if(dx<0){
x=x2;
y=y2;
xend=x1;
}
else{
x=x1;
y=y1;
xend=x2;
}
while(x<xend){
putpixel(x, y, 13);
if(d<0)
d=d+i1;
else{
d=d+i2;
y=y+1;
}
x=x+1;
printf("\n (%f, %f)",x,y);
}
getch();
closegraph();
return 0;
}

