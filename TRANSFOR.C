#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main(){
int x1,y1,x2,y2,tx,ty,xt1,yt1,xt2,yt2,r,gd =DETECT,gm;
float sx,sy,rx,xr1,yr1,xr2,yr2,xs1,ys1,xs2,ys2;
initgraph(&gd, &gm, "C://TURBOC3//BGI");
clrscr();
printf("\n Enter the first co ordinate ?");
scanf("%d %d",&x1,&y1);
printf("\n Enter the second co ordinate ?");
scanf("%d %d",&x2,&y2);
//setcolor(15);
printf("\n The Original Line is");
line(x1,y1,x2,y2);
getch();
printf("\n TRANSLATION \n");
printf("\n Enter the Translation Factor ?");
scanf("%d %d",&tx,&ty);
xt1=x1+tx;
yt1=y1+ty;
xt2=x2+tx;
yt2=y2+ty;
line(xt1,yt1,xt2,yt2);
getch();
printf("\n SCALING \n");
printf("\n Enter the Scaling Factor ?");
scanf("%f %f",&sx,&sy);
xs1=x1*sx;
ys1=y1*sy;
xs2=x2*sx;
ys2=y2*sy;
line(xs1,ys1,xs2,ys2);
getch();
printf("\n ROTATION \n");
printf("\n Enter the Rotation Factor ?");
scanf("%d",&r);
rx=(3.14*r)/180;
xr1=abs(x1*sin(rx)-y1*cos(rx));
yr1=abs(x1*cos(rx)+y1*sin(rx));
xr2=abs(x2*sin(rx)-y2*cos(rx));
yr2=abs(x2*cos(rx)+y2*sin(rx));
line(xr1,yr1,xr2,yr2);
getch();
closegraph();
}