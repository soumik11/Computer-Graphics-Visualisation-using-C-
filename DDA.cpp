#include<GL/glut.h>
#include <GL/gl.h>
#include<iostream>
#include<math.h>


using namespace std;

struct Point {
	GLint x;
	GLint y;
};
Point P1,P2;

int ROUND(GLfloat x)
{
  GLint y = x + 0.5;
  return y;
}

void dda_func() {
	GLfloat dx = P2.x - P1.x;
	GLfloat dy = P2.y - P1.y;

	GLfloat x = P1.x;
	GLfloat y = P1.y;

	GLfloat step = 0;

	if(abs(dx) > abs(dy)) {
		step = abs(dx);
	} else {
		step = abs(dy);
	}

	GLfloat xInc = dx/step;
	GLfloat yInc = dy/step;
    glBegin(GL_POINTS);
	for(float i = 1; i <= step; i++) {
		
        glVertex2i(ROUND(x),ROUND(y));
		x += xInc;
		y += yInc;
	}
    
glEnd();	
glFlush();
}

void init() {
	 glClearColor (0.0, 0.0, 0.0, 0.0);
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}

void display(void) {
glColor3f (1.0f, 1.0f, 1.0f);	
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POINTS);
	dda_func();
glEnd();	
glFlush();

glColor3f (1.0f, 1.0f, 1.0f);
glBegin(GL_LINES)
   glVertex2i(100,0);
   glVertex2i(-100,0);
   glVertex2i(0,100);
   glVertex2i(0,-100);
glEnd();
glFlush();
glBegin(GL_POINTS);
 for(int i=-2; i<=2 ; i++)
 {
glVertex2i(95+i,4+i);
glVertex2i(95-i,4+i);
 } 
for(int i=0; i<=2 ; i++)
 {
glVertex2i(4+i,95+i);
glVertex2i(4-i,95+i);
glVertex2i(4,95-i);
}
glEnd();
glFlush();
}

int main(int argc, char** argv)
{
	cout<<"Enter co-ordinates of P1:";
        cin>>P1.x>>P1.y;
        cout<<"Enter co-ordinates of P2:";
        cin>>P2.x>>P2.y;
         glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
         glutInitWindowSize (500, 500);
        glutInitWindowPosition (100, 100);
        glutCreateWindow ("DDA");
        init ();
        glutDisplayFunc(display);
       glutMainLoop();
	return 0;
}
