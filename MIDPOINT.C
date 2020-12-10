#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
int main(){
int gd = DETECT, gm, i, r, x=0, y, xc, yc ;
float d;
initgraph(&gd, &gm,"C://TURBOC3//BGI");
printf("\n Enter the value of radius");
scanf("%d",&r);
printf("\n Enter the value of centre");
scanf("%d %d",&xc, &yc);
d=1-r;
y=r;
while(x<=y){
putpixel(xc+x,yc+y,13);
putpixel(xc-y,yc-x,13);
putpixel(xc+y,yc-x,13);
putpixel(xc-y,yc+x,13);
putpixel(xc+y,yc+x,13);
putpixel(xc-x,yc-y,13);
putpixel(xc+x,yc-y,13);
putpixel(xc-x,yc+y,13);

if(d<0.0){

d=d+2*x+3;

}
else{
y--;
d=d+2*(x-y)+5;
}
x++;

}
getch();
closegraph();
return 0;
}