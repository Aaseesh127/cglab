#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

float m,x0,x1,z0,z1;

void draw_pixel(int x,int y)
{
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}

void linedraw1(float x0,float z0,float x1,float z1,float m)
{
	if(x0 > x1)
	 {
		int temp1=x0;
		x0 = x1;
		x1=temp1;
		
		int temp2=z0;
		z0=z1;
		z1=temp2;
	 }
	int dx=abs(x1-x0);
	int dy=abs(z1-z0);
	int p=(2*dy)-dx;
	int pneg=2*dy;
	int ppos=2*(dy-dx);
	int x=x0;
	int y=z0;
	draw_pixel(x,y);
	while(x<x1)
	 {
		x++;
		if(p<0)
		 {
			p=p+pneg;
		 }
		else
		 {
			if(m<0)
			y--;
			else
			y++;
			p=p+ppos;
		}
		draw_pixel(x,y);
	 }
}
void linedraw2(float x0,float z0,float x1,float z1,float m)
{
	if(z0 > z1)
	 {
		int temp1=z0;
		z0 = z1;
		z1=temp1;
		
		int temp2=x0;
		x0=x1;
		x1=temp2;
	 }
	int dx=abs(x1-x0);
	int dy=abs(z1-z0);
	int p=(2*dx)-dy;
	int pneg=2*dx;
	int ppos=2*(dx-dy);
	int x=x0;
	int y=z0;
	draw_pixel(x,y);
	while(y<z1)
	 {
		y++;
		if(p<0)
		 {
			p=p+pneg;
		 }
		else
		 {
			if(m<0)
			x--;
			else
			x++;
			p=p+ppos;
		}
		draw_pixel(x,y);
	 }
}
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	m=(z1-z0)/(float)(x1-x0);
	if(fabs(m)<1)
	linedraw1(x0,z0,x1,z1,m);
	else
	linedraw2(x0,z0,x1,z1,m);
	glFlush();
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}	
void main(int argc,char **argv)
{
	printf("Enter the starting vertex:");
	scanf("%f\t%f",&x0,&z0);
	printf("Enter the ending vertex:");
	scanf("%f\t%f",&x1,&z1);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("prog2");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
