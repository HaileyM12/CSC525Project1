/*==================================================================================================
 PROGRAMMERS:			Hailey Martinelli, Quy Pham, Nathan Pasley, Evan Pollite
 TRACE FOLDEER:			Hailey555
 ASSIGNMENT:			Project1
 COURSE:				CSC 525
 MODIFIED BY:			N/A
 LAST MODIFIED DATE:	10/15/2019
 DESCRIPTION:			Ball moves around screen trying to hit a polygon
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
#include <fstream>
#include <GL/glut.h>				// include GLUT library
using namespace std;
//***********************************************************************************
int x, y, btn;
float radius = 10.0;
int paddleLeft, paddleRight;
bool clicked = false;
bool lose = false;
bool win = false;
double ballX, ballY;
bool scene2 = false, down = true, leftMove = false;
int delta_x_line = 0;
string message = "Welcome! Press space to start.";
string gameover = "GAME OVER!";
string winner = "Congratulations! You won!";
double PI = 3.141592;
double positionY = 0, positionX = 0, speed = 2.5;

//GLfloat win[512][512][3];
//GLfloat gameover[512][512][3];

GLubyte myPattern[] =
{
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,

	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,

	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,

	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,

	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,

	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,

	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
	0x0F, 0x0F, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,

	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,
	0x00, 0xF0, 0xFF, 0xFF, 0xF0, 0xF0, 0x00,

	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,
	0x00, 0x0F, 0x0F, 0xFF, 0x0F, 0x00, 0x00,

	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,
	0x00, 0x00, 0xF0, 0x00, 0xF0, 0x00, 0x00,

	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x0F, 0xFF, 0x00, 0x00, 0x00,

	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

void drawBall() {
	for (double angle = 0.0; angle <= 2.0 * PI; angle += 0.005)
	{
		glColor3f(1, 1, 1);
		ballX = ((radius) * cos(angle)) + 200;
		ballY = ((radius) * sin(angle)) - 60;
		glBegin(GL_POINTS);
		glVertex2f(ballX + positionX, ballY + positionY);
		glEnd();
	}
	glColor3f(0, 1, 0);
}

void drawBitmap() {
	//draw bitmap
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glColor3f(.5, .5, 1);
	glRasterPos2i(50, 50);
	glBitmap(52, 52, 0, 0, 56, 56, myPattern);
}

void drawPaddle() {
	//draw line
	glEnable(GL_LINE_STIPPLE);
	glLineWidth(3.5);
	paddleLeft = -50 + delta_x_line;
	paddleRight = 50 + delta_x_line;
	glBegin(GL_LINE_LOOP);
	glVertex2i(paddleLeft, -290);
	glVertex2i(paddleRight, -290);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

void drawPolygon() {
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2i(-250, 275);
	glColor3f(0, 1, 0);
	glVertex2i(-200, 275);
	glColor3f(1, 0, 0);
	glVertex2i(-200, 220);
	glColor3f(1, 1, 0);
	glVertex2i(-250, 220);
	glEnd();
}

void updateFrame() { // Function that moves the ball

	if (ballY + positionY > -320 && down) { // Ball keeps going if it is not within the paddle width.
		drawBall();
		positionY -= speed;
		if (ballY + positionY <= -280 && ballX + positionX < paddleRight && ballX + positionX > paddleLeft + 50.0) { // if ball is within the paddle width and at -280 height collision is detected
			down = false;
			leftMove = false;
		}
		if (ballY + positionY <= -280 && ballX + positionX < paddleRight - 50.0 && ballX + positionX > paddleLeft) { // if ball is within the paddle width and at -280 height collision is detected
			down = false;
			leftMove = true;
		}
		if (ballY + positionY <= -295) { // Check for loss
			lose = true;
		}
	}
	else {
		drawBall();
		positionY += speed;
		if (ballY + positionY >= 290) {
			down = true;
		}
	}
	if (ballX + positionX < 300 && !leftMove) {
		drawBall();
		positionX += speed;
		if (ballX + positionX >= 300) {
			leftMove = true;
		}
	}
	else {
		drawBall();
		positionX -= speed;
		if (ballX + positionX <= -285) {
			leftMove = false;
		}
	}
	if (ballX + positionX <= -200 && ballX + positionX >= -250 && ballY + positionY >= 220 && ballY + positionY <= 275) {
		win = true;
	}
	if (ballX + positionX >= 50 && ballX + positionX <= 106 && ballY + positionY >= 50 && ballY + positionY <= 106) {
		radius += 0.5;
	}

}

void drawSet1()
{
	// change point size back to 1
	glPointSize(1);

	//draw text
	glColor3f(0.5, 0.5, 1);
	glRasterPos2i(-165, 75);
	for (int i = 0; i < message.length(); i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, message[i]);
	}
}

void drawSet2()
{
	drawBitmap();
	drawPaddle();
	drawBall();
	drawPolygon();

}

void drawEndingSet()
{
	//glRasterPos2i(-256, -256);
	//glDrawPixels(512, 512, GL_RGB, GL_FLOAT, gameover);
	//draw text
	if (lose) {
		glColor3f(0.5, 0.5, 1);
		glRasterPos2i(-100, 75);
		for (int i = 0; i < gameover.length(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, gameover[i]);
		}
	}
	if (win) {
		glColor3f(0.5, 0.5, 1);
		glRasterPos2i(-165, 75);
		for (int i = 0; i < winner.length(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, winner[i]);
		}
	}

}

//***********************************************************************************
void myInit()
{
	glClearColor(0, 0, 0, 0);			// specify a background color: black 
	gluOrtho2D(-300, 300, -300, 300);  // specify a viewing area
}
//***********************************************************************************

void myInitDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawSet1();

	glFlush(); // flush out the buffer contents
}
//***********************************************************************************

void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	if (lose || win) {
		drawEndingSet();
	}
	else {
		drawSet2();
	}

	glFlush(); // flush out the buffer contents
}
//***********************************************************************************

void timerFunction(int timerId) { // timer that redisplays and calls the update function

	updateFrame();
	glutTimerFunc(30, timerFunction, 0);
	if (scene2 == false) {
		glutDisplayFunc(myInitDisplayCallback);
	}
	else {
		glutDisplayFunc(myDisplayCallback);
	}
	glutPostRedisplay();

}

void mySpecialKeyCallback(int key, int cursorX, int cursorY) {
	if (key == GLUT_KEY_LEFT) {
		if (paddleLeft >= -295) {
			delta_x_line += -5;
		}
	}
	if (key == GLUT_KEY_RIGHT) {
		if (paddleRight <= 295) {
			delta_x_line += 5;
		}
	}

	myDisplayCallback();
}
//***********************************************************************************

void myKeyCallback(unsigned char key, int cursorX, int cursorY) {
	if (key == 32) {
		scene2 = true;
		myDisplayCallback();
	}
}
//***********************************************************************************



//***********************************************************************************
int main(int argc, char** argv)
{
	glutInit(&argc, argv);                  // optional in our environment

	glutInitWindowSize(600, 600);				// specify a window size
	glutInitWindowPosition(100, 0);			// specify a window position
	glutCreateWindow("Project 1");				// create a titled window

	myInit();									// setting up

	if (scene2 == false) {
		glutDisplayFunc(myInitDisplayCallback);
	}
	else {
		glutDisplayFunc(myDisplayCallback);
	}

	glutSpecialFunc(mySpecialKeyCallback);
	glutKeyboardFunc(myKeyCallback);

	glutTimerFunc(30, timerFunction, 0);

	//ifstream fin;
	////get win data
	//fin.open("C:\\Temp\\win.txt");
	//for (int i = 0; i < 512; i++) {
	//	for (int j = 0; j < 512; j++) {
	//		for (int m = 0; m < 3; m++) {
	//			fin >> win[i][j][m];
	//		}
	//	}
	//}
	//fin.close();
	////get game over data
	//fin.open("C:\\Temp\\gameover.txt");
	////read win data
	//for (int i = 0; i < 512; i++) {
	//	for (int j = 0; j < 512; j++) {
	//		for (int m = 0; m < 3; m++) {
	//			fin >> gameover[i][j][m];
	//		}
	//	}
	//}
	//fin.close();

	glutMainLoop();							// get into an infinite loop

	return 0;
}
