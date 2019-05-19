#include<GL/glut.h>
#include<stdio.h>

float v[4][3] = {{0,0,1},{0,1,-1},{-1,-1,-1},{1,-1,-1}};
int m;
void triangle(float a[3],float b[3],float c[3])
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_triangle(float *a,float *b,float *c,int m)
{
	float v1[3],v2[3],v3[3];
	if(m>0)
	  {
		for(int j=0;j<3;j++)
		  {
			v1[j] = (a[j]+b[j])/2;
			v2[j] = (b[j]+c[j])/2;
			v3[j] = (a[j]+c[j])/2;
		  }
		divide_triangle(a,v1,v3,m-1);
		divide_triangle(v1,b,v2,m-1);
		divide_triangle(v3,v2,c,m-1);
	  }
	else
		triangle(a,b,c);
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2,2,-2,2,-10,10);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(1,1,1,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1,0,0);
	divide_triangle(v[0],v[1],v[2],m);
	glColor3f(0,1,0);
	divide_triangle(v[0],v[1],v[3],m);
	glColor3f(0,0,1);
	divide_triangle(v[0],v[2],v[3],m);
	glColor3f(1,1,0);
	divide_triangle(v[1],v[2],v[3],m);
	glFlush();

}
void main(int argc,char **argv)
{
	printf("Enter the value of m:");
	scanf("%d",&m);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutCreateWindow("prog1");
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	init();
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
}




