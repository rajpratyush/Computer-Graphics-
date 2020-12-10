#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
int r;
float rx;
void main(){
int x1,y1,z1,x2,y2,z2,gd =DETECT,gm;
int tx,ty,tz,xt1,yt1,zt1,xt2,yt2,zt2;
float sx,sy,sz,xs1,ys1,zs1,xs2,ys2,zs2;
float xr1,yr1,zr1,xr2,yr2,zr2;
char ch;
initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
clrscr();
printf("\n Enter the first co ordinate ?");
scanf("%d %d %d",&x1,&y1,&z1);
printf("\n Enter the second co ordinate ?");
scanf("%d %d %d",&x2,&y2,&z2);
setcolor(13);
printf("\n The Original Line is");
bar3d(x1,y1,x2,y2,z2-z1,5);
getch();
printf("\n TRANSLATION \n");
printf("\n Enter the Translation Factor ?");
scanf("%d %d %d",&tx,&ty,&tz);
xt1=x1+tx;
yt1=y1+ty;
zt1=z1+tz;
xt2=x2+tx;
yt2=y2+ty;
zt2=z2+tz;
bar3d(xt1,yt1,xt2,yt2,zt2-zt1,5);
getch();
printf("\n SCALING \n");
printf("\n Enter the Scaling Factor ?");
scanf("%f %f %f",&sx,&sy,&sz);
xs1=x1*sx;
ys1=y1*sy;
zs1=z1*sz;
xs2=x2*sx;
ys2=y2*sy;
zs2=z2*sz;
bar3d(xs1,ys1,xs2,ys2,zs2-zs1,5);
getch();
//cleardevice();
//clrscr();
printf("\n ROTATION \n");
printf("\n Enter the axis of rotation among x , y ,z");
scanf(" %c",&ch);
if(ch=='z'){
printf("\n Enter the Rotation Factor ?");
scanf("%d",&r);
rx=(3.14*r)/180;
xr1=abs(x1*cos(rx)-y1*sin(rx));
yr1=abs(x1*sin(rx)+y1*cos(rx));
zr1=z1;
xr2=abs(x2*cos(rx)-y2*sin(rx));
yr2=abs(x2*sin(rx)+y2*cos(rx));
zr2=z2;
bar3d(xr1,yr1,xr2,yr2,zr2-zr1,5);
getch(); }
else if (ch=='y'){
printf("\n Enter the Rotation Factor ?");
scanf("%d",&r);
rx=(3.14*r)/180;
xr1=abs(z1*cos(rx)-x1*sin(rx));
yr1=abs(z1*sin(rx)+x1*cos(rx));
yr1=y1;
xr2=abs(z2*cos(rx)-x2*sin(rx));
yr2=abs(z2*sin(rx)+x2*cos(rx));
yr2=y2;
bar3d(xr1,yr1,xr2,yr2,zr2-zr1,5);
getch(); }
else if (ch=='x'){
printf("\n Enter the Rotation Factor ?");
scanf("%d",&r);
rx=(3.14*r)/180;
xr1=x1;
yr1=abs(y1*cos(rx)-z1*sin(rx));
zr1=abs(y1*sin(rx)+z1*cos(rx));
xr2=abs(y2*cos(rx)-z2*sin(rx));
zr2=abs(y2*sin(rx)+z2*cos(rx));
xr2=x2;
bar3d(xr1,yr1,xr2,yr2,zr2-zr1,5);
getch(); }
else
{
printf("\n Wrong Choice Entered ");
}
closegraph();
}