#include <iostream>
#include <fstream>
#include <GL/glut.h>
struct Point
{
	GLfloat x,y;
	
};
struct Point p[10000];
int count=0;
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
	//std::ifstream iFile("input.txt", std::ios::in);
	int i=0;
	glClearColor(1.0,1.0,1.0,0.0); //it sets the backgroungd color
	glClear(GL_COLOR_BUFFER_BIT); // it will clear the space for the above colors.
	glColor3f(0.0,0.0,1.0); // pen color like we have used in the point.
	glPointSize(10); // 
	glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0); // for the projection of points.
	glBegin(GL_POINTS);
		while(i<count)
		{
			glVertex2f(p[i].x,p[i].y);
			i++;
		}
	glEnd();
	glFlush(); // it will empty all the buffers
}

int main(int argc,char ** argv)
{
	glutInit(&argc,argv); // initialize all the glut libraries
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,500); // fix the window size
	readFile();
	glutInitWindowPosition(100,100); // window position
	glutCreateWindow("OpenGL - First Window"); // create a window with this capiton
	glutDisplayFunc(renderFunc); // it will display the render function
	glutMainLoop(); // it is necessary  for the end of the program
	
	return 0;
	
}
