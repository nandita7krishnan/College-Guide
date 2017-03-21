#include <iostream>
#include <GL/glut.h>
int df, flag=0;

using namespace std;

void display_dest();
void display_ground();

void drawBitmapText(char *string, float x, float y)
{
    char *c;
    glRasterPos2f(x, y);
    for(c=string; *c!='\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        display_dest();
    else if (button == GLUT_RIGHT_BUTTON)  // Just for now :P
        display_ground();

}

void display_ground()
{
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.9, 0.9, 0.9);
	// hole 1
	glBegin(GL_POLYGON);
    glVertex2f(3.3, 2.2);
    glVertex2f(5.3, 2.2);
    glVertex2f(5.3, 4.2);
    glVertex2f(4.2, 5.3);
    glVertex2f(2.2, 5.3);
    glVertex2f(2.2, 3.3);
    glEnd();
    glColor3f(1.0, 0.0, 1.0);
	// 1
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 0.0);
    glVertex2f(3.0, 0.0);
    glVertex2f(3.0, 1.5);
    glVertex2f(1.5, 3.0);
    glVertex2f(0.0, 3.0);
    glEnd();
    // 2
    glBegin(GL_LINE_LOOP);
    glVertex2f(3.0, 0.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(4.0, 1.5);
    glVertex2f(3.0, 1.5);
    glEnd();
    // 3
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.0, 0.0);
    glVertex2f(5.0, 0.0);
    glVertex2f(5.0, 1.5);
    glVertex2f(4.0, 1.5);
    glEnd();
    // 4
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.0, 0.0);
    glVertex2f(6.0, 0.0);
    glVertex2f(6.0, 1.5);
    glVertex2f(5.0, 1.5);
    glEnd();
    // 5
    glBegin(GL_LINE_LOOP);
    glVertex2f(6.0, 0.0);
    glVertex2f(7.0, 0.0);
    glVertex2f(7.0, 1.5);
    glVertex2f(6.0, 1.5);
    glEnd();
    // line connecting 5 and 19
    glBegin(GL_LINES);
    glVertex2f(7.0, 1.5);
    glVertex2f(7.0, 2.0);
    glEnd();
    // 6
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 3.0);
    glVertex2f(1.5, 3.0);
    glVertex2f(1.5, 4.0);
    glVertex2f(0.0, 4.0);
    glEnd();
    // 7
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 4.0);
    glVertex2f(1.5, 4.0);
    glVertex2f(1.5, 5.0);
    glVertex2f(0.0, 5.0);
    glEnd();
    // 8
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 5.0);
    glVertex2f(1.5, 5.0);
    glVertex2f(1.5, 6.0);
    glVertex2f(0.0, 6.0);
    glEnd();
    // 9
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0, 6.0);
    glVertex2f(1.5, 6.0);
    glVertex2f(1.5, 7.0);
    glVertex2f(0.0, 7.0);
    glEnd();
    // line connecting 9 and 32
    glBegin(GL_LINES);
    glVertex2f(1.5, 7.0);
    glVertex2f(2.0, 7.0);
    glEnd();
    // 11
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.8, 4.0);
    glVertex2f(7.0, 4.0);
    glVertex2f(7.0, 4.8);
    glVertex2f(5.8, 4.8);
    glEnd();
    // 12
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.8, 4.8);
    glVertex2f(7.0, 4.8);
    glVertex2f(7.0, 5.6);
    glVertex2f(5.8, 5.6);
    glEnd();
    // 13
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.0, 5.8);
    glVertex2f(4.8, 5.8);
    glVertex2f(4.8, 7.0);
    glVertex2f(4.0, 7.0);
    glEnd();
    // 14
    glBegin(GL_LINE_LOOP);
    glVertex2f(4.8, 5.8);
    glVertex2f(5.6, 5.8);
    glVertex2f(5.6, 7.0);
    glVertex2f(4.8, 7.0);
    glEnd();
	// 15
	glBegin(GL_LINE_LOOP);
    glVertex2f(7.0, 5.6);
    glVertex2f(7.87, 5.6);
    glVertex2f(7.87, 6.6);
    glVertex2f(7.0, 6.6);
    glEnd();
	// 16
	glBegin(GL_LINE_LOOP);
    glVertex2f(7.87, 5.6);
    glVertex2f(8.75, 5.6);
    glVertex2f(8.75, 6.6);
    glVertex2f(7.87, 6.6);
    glEnd();
    // 17
    glBegin(GL_LINE_LOOP);
    glVertex2f(8.75, 5.6);
    glVertex2f(9.62, 5.6);
    glVertex2f(9.62, 6.6);
    glVertex2f(8.75, 6.6);
    glEnd();
	// 18
	glBegin(GL_LINE_LOOP);
    glVertex2f(9.62, 5.6);
    glVertex2f(10.5, 5.6);
    glVertex2f(10.5, 6.6);
    glVertex2f(9.62, 6.6);
    glEnd();
    // 19
    glBegin(GL_LINE_LOOP);
    glVertex2f(7.0, 2.0);
    glVertex2f(8.0, 2.0);
    glVertex2f(8.0, 3.0);
    glVertex2f(8.75, 3.0);
    glVertex2f(8.75, 4.0);
    glVertex2f(7.0, 4.0);
    glEnd();
    // 20
    glBegin(GL_LINE_LOOP);
    glVertex2f(8.75, 3.0);
    glVertex2f(9.0, 3.0);
    glVertex2f(9.0, 2.0);
    glVertex2f(10.5, 2.0);
    glVertex2f(10.5, 4.0);
    glVertex2f(8.75, 4.0);
    glEnd();
    // 27
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.6, 7.0);
    glVertex2f(6.6, 7.0);
    glVertex2f(6.6, 7.87);
    glVertex2f(5.6, 7.87);
    glEnd();
    // 28
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.6, 7.87);
    glVertex2f(6.6, 7.87);
    glVertex2f(6.6, 8.75);
    glVertex2f(5.6, 8.75);
    glEnd();
    // 29
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.6, 8.75);
    glVertex2f(6.6, 8.75);
    glVertex2f(6.6, 9.62);
    glVertex2f(5.6, 9.62);
    glEnd();
    // 30
    glBegin(GL_LINE_LOOP);
    glVertex2f(5.6, 9.62);
    glVertex2f(6.6, 9.62);
    glVertex2f(6.6, 10.5);
    glVertex2f(5.6, 10.5);
    glEnd();
    // 31
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.0, 9.0);
    glVertex2f(4.0, 9.0);
    glVertex2f(4.0, 10.5);
    glVertex2f(2.0, 10.5);
    glEnd();
    // 32
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.0, 7.0);
    glVertex2f(3.5, 7.0);
    glVertex2f(3.5, 9.0);
    glVertex2f(3.0, 9.0);
    glVertex2f(3.0, 8.0);
    glVertex2f(2.0, 8.0);
    glEnd();
    // hole 2
    glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
	glVertex2f(4.0, 7.05);
	glVertex2f(5.5, 7.05);
	glVertex2f(5.5, 10.5);
	glVertex2f(4.0, 10.5);
	glEnd();
    // hole 3
    glBegin(GL_POLYGON);
	glVertex2f(7.05, 4.05);
	glVertex2f(10.5, 4.05);
	glVertex2f(10.5, 5.6);
	glVertex2f(7.05, 5.6);
	glEnd();
	glFlush();
}

void rooms()
{
    drawBitmapText("Bank", 0.0, 21.5);
	drawBitmapText("CADD Laborotory", 0.0, 20.0);
	drawBitmapText("Chemistry Laborotory", 0.0, 18.5);
	drawBitmapText("Class Room 001", 0.0, 17.0);
	drawBitmapText("Class Room 002", 0.0, 15.5);
	drawBitmapText("Class Room 003", 0.0, 14.0);
	drawBitmapText("Class Room 004", 0.0, 12.5);
	drawBitmapText("HOD's Cabin", 0.0, 11.0);
	drawBitmapText("Ofiice", 0.0, 9.5);
	drawBitmapText("Seminar Hall 1", 0.0, 8.0);
	drawBitmapText("Seminar hall 2", 0.0, 6.5);
	drawBitmapText("Washroom - Boys", 0.0, 5.0);
	drawBitmapText("Washroom - Girls", 0.0, 3.5);
	drawBitmapText("Staff Room 001", 0.0, 2.0);
	drawBitmapText("Staff Room 002", 0.0, 0.5);
	drawBitmapText("Staff Room 003", 0.0, -1.0);
	drawBitmapText("Staff Room 004", 16.0, 21.5);
	drawBitmapText("Staff Room 005", 16.0, 20.0);
	drawBitmapText("Staff Room 006", 16.0, 18.5);
	drawBitmapText("Staff Room 007", 16.0, 17.0);
	drawBitmapText("Staff Room 008", 16.0, 15.5);
	drawBitmapText("Staff Room 009", 16.0, 14.0);
	drawBitmapText("Staff Room 010", 16.0, 12.5);
	drawBitmapText("Staff Room 011", 16.0, 11.0);
	drawBitmapText("Staff Room 012", 16.0, 9.5);
	drawBitmapText("Staff Room 013", 16.0, 8.0);
	drawBitmapText("Staff Room 014", 16.0, 6.5);
	drawBitmapText("Staff Room 015", 16.0, 5.0);
	drawBitmapText("Staff Room 016", 16.0, 3.5);
	drawBitmapText("Staff Room 017", 16.0, 2.0);
	drawBitmapText("Staff Room 018", 16.0, 0.5);

}

void display_dest()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.5,0.0);
    drawBitmapText("Choose where you want to go...", 7.0,26.0);
	rooms();
	glutSwapBuffers();
	glutMouseFunc(mouse);
	//glFlush;
}

void display_src()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.5,0.0);
    drawBitmapText("Choose your location...", 8.0,26.0);
	rooms();
	glutSwapBuffers();
	glutMouseFunc(mouse);
	//glFlush;
}

void keyboard(unsigned char key,int x,int y)
{

    if(df==1 && key==32)
    {
        df=0;
        display_src();
    }
    else
        glutPostRedisplay ();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.5,0.0);
	drawBitmapText("COLLEGE GUIDE", 8.0,15.0);
	glBegin(GL_POLYGON);
	    glVertex2f(6.0,12.5);
        glVertex2f(6.0,14.0);
        glVertex2f(19.7,14.0);
        glVertex2f(19.7,12.5);
    glEnd();
	glColor3f(0.5,1.0,0.5);
	drawBitmapText("Press Spacebar to Continue", 7.0,13.0);
	glColor3f(0.5,1.0,0.0);
	drawBitmapText("Nandita Krishnan         - 1PE14CS057", 2.0,3.0);
	glColor3f(0.5,1.0,0.0);
	drawBitmapText("Mamta Mariam Harris - 1PE14CS069", 2.0,2.0);
	glutSwapBuffers();
    df=1;
	glFlush();
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-3.0, 30.0, -3.0, 30.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);

	glutInitWindowSize(720, 720);
	glutInitWindowPosition(350.0, 0.0);
	glutCreateWindow("College Guide");

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	if (flag == 1)
        display_dest();
	myinit();
	glutMainLoop();
	return 0;
}


