#include<iostream>

#include<GL/glut.h>


int left_button_state=0;
int px=0,py=0;


void renderFunction(){
	if(left_button_state){
		glColor3f(0.0,0.0,0.0);
		glPointSize(5);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(0.0,500.0,0.0,400.0);
		glBegin(GL_POINTS);
			glVertex2f(px,py);
		glEnd();
	}

	glFlush();
}

void mouseClick(int button,int state,int x,int y){
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN){
		right_button_state=0;
		left_button_state=1;
		px=x;
		py=400-y;
	}
	
	glutPostRedisplay();
}

void mouseMove(int x,int y){
	if(left_button_state){
		// left_button_state=1;
		// right_button_state=0;
		px=x;
		py=400-y;
	}
	
	glutPostRedisplay();
}


int main(int argc,char** argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500,400);
	glutInitWindowPosition(10,10);
	glutCreateWindow("OpenGL - First Window demo");
	glClearColor(1.0,1.0,1.0,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(renderFunction);


	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
}
