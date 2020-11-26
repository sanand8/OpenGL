#include<iostream>
#include<fstream>
#include <GL/glut.h>

void renderFunc()
{
	std::ifstream iFile("input3.txt", std::ios::in);
	float r,g,b,a;
	iFile>>r;
	iFile>>g;
	iFile>>b;
	iFile>>a;
	glClearColor(r,g,b,a);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL - First Window");
	glutDisplayFunc(renderFunc);
	glutMainLoop();
	
	return 0;
	
}
