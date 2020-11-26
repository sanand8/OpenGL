#include<iostream>
#include<fstream>
#include <GL/glut.h>

struct Points
{
	GLfloat x,y;
};
struct Points p[10000];

int count = 0;

void readFile()
{
	std::ifstream iFile("input3.txt", std::ios::in);
	while(iFile>>p[count].x)
	{
		iFile>>p[count].y;
		count++;
	}
}
void renderFunc()
{
	int i = 0;
	glClearColor(1.0,1.0,1.0,1.0);  //it sets the background color as white
	glClear(GL_COLOR_BUFFER_BIT);   // it will clear the space for the above
	glColor3f(0.64,0.64,0.64);			// the color of the pen
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0); // for the projection of points
	glPointSize(10);
	glBegin(GL_LINE);
		while(i<count-1)
		{
			glBegin(GL_LINES);
				glVertex2f(p[i].x,p[i].y);
				glVertex2f(p[i+1].x,p[i+1].y);
				i++;
			glEnd();
		}			
	
	glFlush();
}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	readFile();
	glutCreateWindow("OpenGL - First Window");
	glutDisplayFunc(renderFunc);
	glutMainLoop();
	
	return 0;
	
}
