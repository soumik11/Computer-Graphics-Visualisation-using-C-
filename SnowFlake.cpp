#include <GL/glut.h>
#include <math.h>

GLfloat oldx=-0.7,oldy=0.5;

void drawkoch(GLfloat dir,GLfloat len,GLint iter) {
	GLdouble dirRad = 0.0174533 * dir;  
	GLfloat newX = oldx + len * cos(dirRad);
	GLfloat newY = oldy + len * sin(dirRad);
	if (iter==0) {
		glVertex2f(oldx, oldy);
		glVertex2f(newX, newY);
		oldx = newX;
		oldy = newY;
	}
	else {
		iter--;
		//draw the four parts of the side _/\_ 
		drawkoch(dir, len, iter);// _

		dir += 60.0;
		drawkoch(dir, len, iter);// /

		dir -= 120.0;
		drawkoch(dir, len, iter);// \

		dir += 60.0;
		drawkoch(dir, len, iter);// _
	}
}

void mydisplay(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 0.0, 0.0);
	 drawkoch(0.0,-0.05,1);
	 drawkoch(-120.0, -0.05, 1);
	 drawkoch(120.0,-0.05,1);

	 glEnd();
	 glColor3f(0.0, 1.0, 0.0);
	 glBegin(GL_POINTS);
     glVertex2f(oldx,oldy);
	 glEnd();
	 glFlush(); 
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
	glutInitWindowSize(500,500);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Snowflake");     
	glutDisplayFunc(mydisplay);  
	glutMainLoop();
}
