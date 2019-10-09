/*==================================================================================================
 PROGRAMMERS:			Hailey Martinelli, Quy Pham, Nathan Pasley, Evan Pollite
 TRACE FOLDEER:			Hailey555
 ASSIGNMENT:			Project1
 COURSE:				CSC 525
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	10/15/2019
 DESCRIPTION:			Balls moves around screen erasing background
 NOTE:					N/A
 FILES:					proj1.cpp, (labProject.sln, ...)
 IDE/COMPILER:			MicroSoft Visual Studio 2019
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on labProject folder
    2.		Double click on	labProject.sln  to OPEN the project
	3.		Press Ctrl+F7					to COMPILE
	4.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/
#include<string>
#include <iostream>
#include <GL/glut.h>				// include GLUT library
using namespace std;
//***********************************************************************************
int x, y, btn;
bool clicked = false;

bool scene2 = false;
int delta_x_line = 0;
string message = "Welcome! Press space to start.";


void drawSet1()
{
	glPointSize(1);		// change point size back to 1

	//draw text
	glColor3f(0.5, 0.5, 1);
	glRasterPos2i(-165, 75);
	for (int i = 0; i < message.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
	}

	////draw square
	//glColor3f(1, 0, 0);
	//glBegin(GL_POLYGON);
	//glVertex2i(-20, 20);
	//glVertex2i(20, 20);
	//glVertex2i(20, -20);
	//glVertex2i(-20, -20);
	//glEnd();

}

void drawSet2()
{
	//draw shapes, bitmap, and pixel maps here

	//draw line
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(3.5);
	glBegin(GL_LINE_LOOP);
	glVertex2i(-50 + delta_x_line, -290);
	glVertex2i(50 + delta_x_line, -290);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

void drawEndingSet()
{
	//put pixelmap of a picture that says you won
}

//***********************************************************************************
void myInit()
{glClearColor(0, 0, 0, 0);			// specify a background color: black 
 gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}

//***********************************************************************************
void myInitDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawSet1();


	glFlush(); // flush out the buffer contents
}

void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawSet2();


	glFlush(); // flush out the buffer contents
}


//***********************************************************************************
void mySpecialKeyCallback(int key, int cursorX, int cursorY) {
	if (key == GLUT_KEY_LEFT) {
		delta_x_line += -5;
	}
	if (key == GLUT_KEY_RIGHT) {
		delta_x_line += 5;
	}
	
	myDisplayCallback();
}

void myKeyCallback(unsigned char key, int cursorX, int cursorY) {
	if (key == 32) {
		scene2 = true;
		myDisplayCallback();
	}
}

//***********************************************************************************
//void myMouseCallback(int button, int state, int cursorX, int cursorY) {
//	clicked = true;
//}

//***********************************************************************************
int main(int argc, char ** argv)
{//glutInit(& argc, argv);                  // optional in our environment

 glutInitWindowSize(600, 600);				// specify a window size
 glutInitWindowPosition(100, 0);			// specify a window position
 glutCreateWindow("Project 1");	// create a titled window

 myInit();									// setting up

 if (scene2 == false) {
	 glutDisplayFunc(myInitDisplayCallback);		
 }
 else {
	 glutDisplayFunc(myDisplayCallback);
 }

 //glutMouseFunc(myMouseCallback);
 glutSpecialFunc(mySpecialKeyCallback);
 glutKeyboardFunc(myKeyCallback);


 glutMainLoop();							// get into an infinite loop

 return 0;
}
