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

void lineloops(float w, float x, float y, float z)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(w, x);
        glVertex2f(y, x);
        glVertex2f(y, z);
        glVertex2f(w, z);

    glEnd();
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
   /* glBegin(GL_LINE_LOOP);
    glVertex2f(3.0, 0.0);
    glVertex2f(4.0, 0.0);
    glVertex2f(4.0, 1.5);
    glVertex2f(3.0, 1.5);
    glEnd();
    */
    lineloops(3.0,0.0,4.0,1.5);
    // 3
    lineloops(4.0,0.0,5.0,1.5);
    // 4
    lineloops(5.0,0.0,6.0,1.5);
    // 5
    lineloops(6.0,0.0,7.0,1.5);
    // line connecting 5 and 19
    glBegin(GL_LINES);
    glVertex2f(7.0, 1.5);
    glVertex2f(7.0, 2.0);
    glEnd();
    // 6
    lineloops(0.0,3.0,1.5,4.0);
    // 7
    lineloops(0.0,4.0,1.5,5.0);
    // 8
    lineloops(0.0,5.0,1.5,6.0);
    // 9
    lineloops(0.0,6.0,1.5,7.0);
    // line connecting 9 and 32
    glBegin(GL_LINES);
    glVertex2f(1.5, 7.0);
    glVertex2f(2.0, 7.0);
    glEnd();
    // 11
    lineloops(5.8,4.0,7.0,4.8);
    // 12
    lineloops(5.8,4.8,7.0,5.6);
    // 13
    lineloops(4.0,5.8,4.8,7.0);
    // 14
    lineloops(4.8,5.8,5.6,7.0);
    // 15
    lineloops(7.0,5.6,7.87,6.6);
	// 16
	lineloops(7.87,5.6,8.75,6.6);
    // 17
    lineloops(8.75,5.6,9.62,6.6);
    // 18
    lineloops(9.62,5.6,10.5,6.6);
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
    lineloops(5.6,7.0,6.6,7.87);
    // 28
    lineloops(5.6,7.87,6.6,8.75);
    // 29
    lineloops(5.6,8.75,6.6,9.62);
    // 30
    lineloops(5.6,9.62,6.6,10.5);
    // 31
    lineloops(2.0,9.0,4.0,10.5);
    // 32
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.0, 7.0);
    glVertex2f(3.5, 7.0);
    glVertex2f(3.5, 9.0);
    glVertex2f(3.0, 9.0);
    glVertex2f(3.0, 8.0);
    glVertex2f(2.0, 8.0);
    glEnd();
    // 33
    lineloops(3.5, 11.5, 6.5, 14.5);
    // 34
    lineloops(3.5, 14.5, 6.5, 17.5);
    // 35
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0, 16.3);
        glVertex2f(3.5, 16.3);
        glVertex2f(3.5, 17.5);
        glVertex2f(4.9, 17.5);
        glVertex2f(4.9, 19.0);
        glVertex2f(3.0, 19.0);
    glEnd();
    // 36
    lineloops(0.0, 19.0, 5.5, 23.0);
    // line between 36 and 37
    glBegin(GL_LINES);
        glVertex2f(5.5, 22.0);
        glVertex2f(7.5, 22.0);
    glEnd();
    // 37
    lineloops(7.5, 20.0, 12.8, 23.0);
    // 38
    lineloops(7.4, 17.5, 9.4, 19.0);

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
	// hole 4
	glBegin(GL_TRIANGLE_STRIP);
        glVertex2f(7.4, 8.75);
        glVertex2f(8.75, 7.4);
        glVertex2f(7.4, 17.4);
        glVertex2f(17.4, 7.4);
        glVertex2f(9.4, 17.4);
        glVertex2f(17.4, 9.4);
        glVertex2f(9.4, 19.0);
        glVertex2f(19.0, 9.4);
        glVertex2f(13.5, 19.0);
        glVertex2f(19.0, 13.5);
	glEnd();
	glColor3f(1.0, 0.0, 1.0);
	// 26
	lineloops(17.5, 7.4, 19.0, 9.4);
	//21
	lineloops(11.5,3.5,14.5, 6.6);
	//22
	lineloops(14.5,3.5,17.5,6.6);
	//23
	glBegin(GL_LINES);
        glVertex2f(16.5, 3.5);
        glVertex2f(16.5, 3);
        glVertex2f(16.5, 3);
        glVertex2f(19, 3);
        glVertex2f(17.5,4.9);
        glVertex2f(19,4.9);
    glEnd();
    //24
    lineloops(19.0,0.0,23.0,5.5);





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
    glColor3f(0.5,1.0,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-3.0,15.0);
    glVertex2f(-3.0,20.0);
    glVertex2f(30.0,20.0);
    glVertex2f(30.0,15.0);
    glEnd();
	glColor3f(0.0,0.5,0.0);
	drawBitmapText("COLLEGE GUIDE", 8.0,17.0);
    glColor3f(0.5,1.0,0.0);
	drawBitmapText("press spacebar to continue", 7.0,13.5);
    glColor3f(0.0,0.5,0.0);
	drawBitmapText("Krishnan Nandita         - 1PE14CS057", -1.0,3.0);
    glColor3f(0.0,0.5,0.0);
    drawBitmapText("Mamta Mariam Harris - 1PE14CS069", -1.0,1.5);
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


