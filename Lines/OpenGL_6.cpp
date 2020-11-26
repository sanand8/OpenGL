#include<iostream>
#include<GL/glut.h>
#include<fstream>

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

void renderFunction()
{
	int i = 0;
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(5);
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
	
	glBegin(GL_LINES);
		while(i<count-1)
		{
			int j = i + 1;
			while(j<count)
			{
				glBegin(GL_LINES);
					glVertex2f(p[i].x,p[i].y);
					glVertex2f(p[j].x,p[j].y);
				glEnd();
				j++;
			}
			i++;
		}
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
	glutCreateWindow("The POLYGON");
	glutDisplayFunc(renderFunction);
	glutMainLoop();
	
	return 0;
}

