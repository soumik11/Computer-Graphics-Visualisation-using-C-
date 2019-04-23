#include<stdio.h>
#include<GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;

int xc = 320, yc = 240;
void plot_point(int x, int y)
{
  glBegin(GL_POINTS);
  glVertex2i(xc+x, yc+y);
  glEnd();
  glFlush();
}
void Ellipse(void)
{
  int x,y;
  int a=120,b=80;
  glColor3f (1.0f, 1.0f, 1.0f);
  glBegin(GL_LINES);
   glVertex2i(640,240);
   glVertex2i(-640,240);
   glVertex2i(320,480);
   glVertex2i(320,-480);
glEnd();
glFlush();
glColor3f (1.0f, 0.0f, 0.0f);
for(int i=0;i<=360;i++)
	{
	x=a*cos((double)i/50);
	y=b*sin((double)i/50);
	plot_point(x,y);
	}
}
void keyCB(unsigned char key, int x, int y)
{
  if( key == 'q' ) exit(0);
}

void Init()
{
  glClearColor(0.0,0.0,0.0,0);
  glColor3f(1.0,1.0,1.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}

int main(int argc, char **argv)
{
  int x,y;
  cout<<"Enter the x y coordinates of the centre of ellipse: ";
  cin>>x>>y;
  xc = xc + x;
  yc = yc + y;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640,480);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Ellipse");
  Init();
  glutKeyboardFunc(keyCB);
  glutDisplayFunc(Ellipse);
  glutMainLoop();
return 0;
}
