#include <iostream>
#include <fstream>
#include <GL/glut.h>

struct Points
{
	GLfloat x,y,z;
};

struct Points p[10000];
int count = 0;

void readFile()
{
	std::ifstream iFile("input3.txt", std::ios::in);
	while(iFile>>p[count].x)
	{
		iFile>>p[count].y;
		iFile>>p[count].z;
		count++;
	}
}

void renderFunction()
{
	int i = 0;
	glClearColor(0.0,0.0,0.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glPointSize(10);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
		
		glColor3f(1.0,0.0,0.0);
		glBegin(GL_QUADS);
			glVertex3d(p[i].x,p[i].y,p[i].z);
			glVertex3d(p[i+1].x,p[i+1].y,p[i+1].z);
			glVertex3d(p[i+2].x,p[i+2].y,p[i+2].z);
			glVertex3d(p[i+3].x,p[i+3].y,p[i+3].z);
			i=i+4;
			
			glColor3f(0.0,1.0,0.0);
			glVertex3d(p[i].x,p[i].y,p[i].z);
			glVertex3d(p[i+1].x,p[i+1].y,p[i+1].z);
			glVertex3d(p[i+2].x,p[i+2].y,p[i+2].z);
			glVertex3d(p[i+3].x,p[i+3].y,p[i+3].z);
			i=i+4;
			
			glColor3f(0.0,0.0,1.0);
			glVertex3d(p[i].x,p[i].y,p[i].z);
			glVertex3d(p[i+1].x,p[i+1].y,p[i+1].z);
			glVertex3d(p[i+2].x,p[i+2].y,p[i+2].z);
			glVertex3d(p[i+3].x,p[i+3].y,p[i+3].z);
			i=i+4;
			
		glEnd();
		glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	readFile();
	glutInitWindowPosition(100,100);
	glutCreateWindow("Colorful blocks");
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	
	return 0;
}
			
			
			
			
			
			
			
			
			
			
