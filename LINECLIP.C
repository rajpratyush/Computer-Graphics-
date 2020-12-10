#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main(){
int gd=DETECT, gm;
float i,xmax,ymax,xmin,ymin,x1,y1,x2,y2,m;
float start[4], end[4], code[4];
initgraph(&gd,&gm,"C://TURBOC3//BGI");
clrscr();
printf("\nEnter the Co ordinate of bottom left\t");
scanf("%f %f",&xmin,&ymin);
printf("\nEnter the Co ordinate of top right\t");
scanf("%f %f",&xmax,&ymax);
printf("\nEnter the value of x1\t");
scanf("%f",&x1);
printf("\nEnter the value of y1\t");
scanf("%f",&y1);
printf("\nEnter the value of x2\t");
scanf("%f ",&x2);
printf("\nEnter the value of y2\t");
scanf("%f",&y2);
for (i=0;i<4;i++) {
start[i]=0;
end[i]=0;
}
m=(y2-y1)/(x2-x1);
if(x1<xmin) start[0]=1;
if(x1>xmax) start[1]=1;
if(y1<ymin) start[2]=1;
if(y1>ymax) start[3]=1;
if(x2<xmin) end[0]=1;
if(x2>xmax) end[1]=1;
if(y2<ymin) end[2]=1;
if(y2>ymax) end[3]=1;
for(i=0;i<4;i++)
code[i]=start[i] && end[i];
if ((code[0]==0)&&(code[1]==0)&&(code[2]==0)&&(code[3]==0))
{
if ((start[0]==0)&&(end[0]==0)&&(start[1]==0)&&(end[1]==0)&&(start[2]==0)&&(end[2]==0)&&(start[3]==0)&&(end[3]==0))
{
cleardevice();
printf("\nThe Line is Completely Visible");
printf("\nDraw the Line");
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
getch();
}
else{
cleardevice();
printf("\nThe Line is Partially Visible");
printf("\nDraw the Line");
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
getch();
if((start[2]==0)&&(start[3]==1))
{
x1=x1+(ymin-y1)/m;
y1=ymin;
}
if((end[2]==0)&&(end[3]==1))
{
x2=x2+(ymin-y2)/m;
y2=ymin;
}
if((start[2]==1)&&(start[3]==0))
{
x1=x1+(ymax-y1)/m;
y1=ymax;
}
if((end[2]==1)&&(end[3]==0))
{
x2=x2+(ymax-y2)/m;
y2=ymax;
}
if((start[1]==0)&&(start[0]==1))
{
y1=y1+(xmin-x1)*m;
x1=xmin;
}
if((end[1]==0)&&(end[0]==1))
{
y2=y2+(xmin-x2)*m;
x2=xmin;
}
if((start[1]==1)&&(start[0]==0))
{
y1=y1+(xmax-x1)*m;
x1=xmax;
}
if((end[1]==1)&&(end[0]==0))
{
y2=y2+(xmax-x2)*m;
x2=xmax;
}
clrscr();
cleardevice();
printf("\n After  Clipping");
printf("\n Draw the Line");
rectangle(xmin,ymin,xmax,ymax);
line(x1,y1,x2,y2);
getch();
}}
else
{
cleardevice();
printf("\nThe Line is Completely Invisible");
rectangle(xmin,ymin,xmax,ymax);
getch();
}
closegraph();
}









