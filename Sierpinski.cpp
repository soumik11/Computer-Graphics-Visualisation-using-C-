#include<iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

void Ref();
int n,i;
float theta, m1,n1,m,c;
void Polygon(void)
{
unsigned int retTime;
int j,p2x,p2y;
int range=glGenLists(2);
int Xi[3]={-500,500,0};
int Yi[3]={-100,-100,766};
	int a,index;
	index = random()%3;
	p2x=Xi[index];
	p2y=Yi[index];
    glColor3f(0.0,7.0,0.0);
	glBegin(GL_POINTS);
	for(a=0;a<80000;a++)
	{
		glVertex2i(p2x, p2y);
		index = random()%3;
		p2x = (p2x + Xi[index])/2;
		p2y = (p2y + Yi[index])/2;
	}
	glEnd();
	glFlush();
}

void Init()
{
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(-800 , 800 , -800 , 800);
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0); 
  glutInitWindowSize(800,800);
  glutCreateWindow("PolyGon Reflect");
  Init();
  glutDisplayFunc(Polygon);
  glutMainLoop();
return 0;
}

