#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
float rot[3][3]={{0},{0},{0}};
float result[3][3]={{0},{0},{0}};
float triangle[3][3]={{100,150,200},{100,200,100},{1,1,1}};
float theta=0;
float m=0,n=0,h=100,k=100;

void multiply()
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			result[i][j]=0;
			for(int k=0;k<3;k++)
			{
				result[i][j]+=rot[i][k]*triangle[k][j];
			}
		}
	}
}

void rotate(float m,float n)
{
	rot[0][0]=cos(theta);
	rot[0][1]=-sin(theta);
	rot[0][2]=m;
	rot[1][0]=sin(theta);
	rot[1][1]=cos(theta);
	rot[1][2]=n;
	rot[2][0]=0;
	rot[2][2]=0;
	rot[2][2]=1;
	multiply();
}

void drawtriangle(float a[3][3])
{
	glBegin(GL_POLYGON);
		glVertex2f(a[0][0],a[1][0]);
		glVertex2f(a[0][1],a[1][1]);
		glVertex2f(a[0][2],a[1][2]);
	glEnd();
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glColor3f(1,0,0);
	drawtriangle(triangle);
	
	glColor3f(0,1,0);
	rotate(0,0);
	drawtriangle(result);	
		
	glColor3f(0,0,1);
	m=-h*(cos(theta)-1)+k*(sin(theta));
	n=-k*(cos(theta)-1)-h*(sin(theta));
	rotate(m,n);
	drawtriangle(result);
	glFlush();
}
void init(){
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300,300,-300,300);
	glMatrixMode(GL_MODELVIEW);
}


void main(int argc,char **argv){
	printf("enter theta value");
	scanf("%f",&theta);
	theta=theta*(3.141/180);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("prog3");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

