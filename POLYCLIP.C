#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void clip(float, float, float);
int i,j=0,n,rx1,ry1,rx2,ry2;
float x1[20],y1[20];

int main()
{ //input values 20 20 250 300 150 100
	int gd=DETECT, gm, i, n;
	float x[20], y[20],m;

	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	printf("\n Enter the Co ordinates of bottom left corner of the Rectangle ");
	scanf(" %d %d ",&rx1,&ry1);
	printf("\n Enter the Co ordinates of top right corner of the Rectangle ");
	scanf(" %d %d",&rx2,&ry2);
	printf("\n No of Sides of the Polygon");
	scanf("%d", &n);

	for (i=0;i<n;i++)
	{
		printf("\n Enter the Co ordinates of point number %d",i);
		scanf("%f %f",&x[i],&y[i]);
	}

	cleardevice();
	outtextxy(10,10,"Before the Clipping");
	outtextxy(10,670,"Press a key");
	rectangle(rx1,ry1,rx2,ry2);

	printf("\nDrawing the Polygon");
	for (i=0;i<n-1;i++)
		line(x[i],y[i],x[i+1],y[i+1]);
	line(x[i],y[i],x[0],y[0]);

	getch();
	cleardevice();
	for(i=0;i<n-1;i++)
	{
		m=(y[i+1]-y[i])/(x[i+1]-x[i]);
		clip(x[i],y[i],m);
		clip(x[i+1],y[i+1],m);
	}
	m=(y[i]-y[0])/(x[i]-x[0]);
	clip(x[i],y[i],m);
	clip(x[0],y[0],m);

	outtextxy(10,10,"After the Clipping");
	outtextxy(10,670,"Press a key");
	rectangle(rx1,ry1,rx2,ry2);

	printf("\nDrawing the Clipped Polygon");
	for (i=0;i<j-1;i++)
		line(x1[i],y1[i],x1[i+1],y1[i+1]);
	getch();
	return 0;
}

void clip(float e,float f, float m)
{
	while (e<rx1||e>rx2|| f<ry1|| f>ry2)
	{
		if(e<rx1)
		{
			f+=m*(rx1-e);
			e=rx1;
		}
		else if(e>rx2)
		{
			f+=m*(rx2-e);
			e=rx2;
		}
		if(f<ry1)
		{
			e+=(ry1-f)/m;
			f=ry1;
		}
		else if(f>ry2)
		{
			e+=(ry2-f)/m;
			f=ry2;
		}
	}
	x1[j]=e;
	y1[j]=f;
	j++;
}
