#include <iostream>
#include <GL/glut.h>
#include <math.h>

int df;
int floors=0, src=1;
int src_marked=0, dstn_marked=0;
int src_floor=999, dstn_floor=999;
float src_x, src_y, dstn_x, dstn_y;
GLfloat i, t=0.0;
double ox, oy, oz;

using namespace std;

void display();
void display_ground();
void display_floor();
void display_otherfloors();
void display_info();
void lineloops(float w, float x, float y, float z);
void mouse(int button, int state, int x, int y);

void circle(GLfloat x, GLfloat y, GLfloat r)
{
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x, y);
		for(i=0.0; i>=-360.0; i--)
		{
			t=i*3.142/180;
			glVertex2f((r*cos(t)+x), (r*sin(t)+y));
		}
	glEnd();
}

void drawSource(float x, float y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x, y+0.75);
    glEnd();
    circle(x, y+0.8, 0.2);
    glFlush();
    src=0;
    src_marked=1;
}

void drawDestination(float x, float y)
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(x-0.2, y+0.75);
        glVertex2f(x-0.2, y+0.95);
        glVertex2f(x+0.2, y+0.95);
        glVertex2f(x+0.2, y+0.75);
        glVertex2f(x, y);
    glEnd();
    circle(x, y+0.95, 0.25);
    glColor3f(1.0, 1.0, 1.0);
    circle(x, y+0.95, 0.1);
    glFlush();
    src=999;
    dstn_marked=1;
}

void drawBitmapText(char *string, float x, float y)
{
    char *c;
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    for(c=string; *c!='\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);

}

void smallertext(char *string, float x, float y)
{
    char *c;
    glColor3f(0.0, 0.0, 0.0);
    glRasterPos2f(x, y);
    for(c=string; *c!='\0'; c++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);

}

void setValue(float x, float y)
{
    if (src==1) {
        src_x=x;
        src_y=y;
        src_floor= floors;
        drawSource(src_x, src_y);
    }
    else if (src==0) {
        dstn_x=x;
        dstn_y=y;
        dstn_floor= floors;
        drawDestination(dstn_x, dstn_y);
    }
}

void mouse(int button, int state, int x, int y)
{
    GLint viewport[4];
    GLdouble modelview[16], projection[16];
    GLfloat wx=x, wy, wz;
    glGetIntegerv(GL_VIEWPORT, viewport);
    y=viewport[3]-y;
    wy=y;
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glReadPixels(x, y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &wz);
    gluUnProject(wx, wy, wz, modelview, projection, viewport, &ox, &oy, &oz);
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        //cout<<"points "<<x<<"   "<<y<<endl;
        //cout<<"other points "<<ox<<"   "<<oy<<endl;
        if (ox>=0.0 && ox<=3.0 && oy>=0.0 && oy<=3.0) //1
            setValue(2.5, 2.5);
        else if (ox>=3.0 && ox<=4.0 && oy>=0.0 && oy<=1.5)  //2
            setValue(3.5, 1.6);
        else if (ox>=4.0 && ox<=5.0 && oy>=0.0 && oy<=1.5)  //3
            setValue(4.5, 1.6);
        else if (ox>=5.0 && ox<=6.0 && oy>=0.0 && oy<=1.5)  //4
            setValue(5.5, 1.6);
        else if (ox>=6.0 && ox<=7.0 && oy>=0.0 && oy<=1.5)  //5
            setValue(6.5, 1.6);
        else if (ox>=0.0 && ox<=1.5 && oy>=3.0 && oy<=4.0)  //6
            setValue(1.6, 3.5);
        else if (ox>=0.0 && ox<=1.5 && oy>=4.0 && oy<=5.0)  //7
            setValue(1.6, 4.5);
        else if (ox>=0.0 && ox<=1.5 && oy>=5.0 && oy<=6.0)  //8
            setValue(1.6, 5.5);
        else if (ox>=0.0 && ox<=1.5 && oy>=6.0 && oy<=7.0)  //9
            setValue(1.6, 6.5);
        else if (ox>=5.8 && ox<=7.0 && oy>=4.0 && oy<=4.8)  //11
            setValue(5.6, 4.4);
        else if (ox>=5.8 && ox<=7.0 && oy>=4.8 && oy<=5.6)  //12
            setValue(5.6, 5.2);
        else if (ox>=4.0 && ox<=4.8 && oy>=5.8 && oy<=7.0)  //13
            setValue(4.4, 5.6);
        else if (ox>=4.8 && ox<=5.6 && oy>=5.8 && oy<=7.0)  //14
            setValue(5.2, 5.6);
        else if (ox>=7.0 && ox<=7.9 && oy>=5.6 && oy<=6.6)  //15
            setValue(7.4, 6.8);
        else if (ox>=7.9 && ox<=8.75 && oy>=5.6 && oy<=6.6)  //16
            setValue(8.3, 6.8);
        else if (ox>=8.75 && ox<=9.6 && oy>=5.6 && oy<=6.6)  //17
            setValue(9.2, 6.8);
        else if (ox>=9.6 && ox<=10.5 && oy>=5.6 && oy<=6.6)  //18
            setValue(10.1, 6.8);
        else if (ox>=7.0 && ox<=8.75 && oy>=1.5 && oy<=4.0)  //19
            setValue(6.8, 3.0);
        else if (ox>=8.75 && ox<=10.5 && oy>=1.5 && oy<=4.0)  //20
            setValue(10.7, 3.0);
        else if (ox>=11.5 && ox<=14.5 && oy>=3.5 && oy<=6.6)  //21
            setValue(11.3, 6.0);
        else if (ox>=14.5 && ox<=17.5 && oy>=3.5 && oy<=6.6)  //22
            setValue(17.7, 6.0);
        else if (ox>=17.5 && ox<=19.0 && oy>=3.0 && oy<=4.9)  //23
            setValue(18.25, 5.1);
        else if (ox>=19.0 && ox<=23.0 && oy>=0.0 && oy<=5.5)  //24
            setValue(20.5, 5.7);
        else if (ox>=20.0 && ox<=23.0 && oy>=7.5 && oy<=12.8)  //25
            setValue(21.0, 7.2);
        else if (ox>=17.5 && ox<=19.0 && oy>=7.0 && oy<=9.0)  //26
            setValue(18.25, 7.2);
        else if (ox>=5.6 && ox<=6.6 && oy>=7.0 && oy<=7.87)  //27
            setValue(6.8, 7.4);
        else if (ox>=5.6 && ox<=6.6 && oy>=7.87 && oy<=8.75)  //28
            setValue(6.8, 8.3);
        else if (ox>=5.6 && ox<=6.6 && oy>=8.75 && oy<=9.62)  //29
            setValue(6.8, 9.2);
        else if (ox>=5.6 && ox<=6.6 && oy>=9.62 && oy<=10.5)  //30
            setValue(6.8, 10.1);
        else if (ox>=2.0 && ox<=4.0 && oy>=9.0 && oy<=10.5)  //31
            setValue(3.0, 10.7);
        else if (ox>=2.0 && ox<=4.0 && oy>=7.0 && oy<=8.0)  //32
            setValue(2.75, 6.8);
        else if (ox>=3.5 && ox<=6.5 && oy>=11.5 && oy<=14.5)  //33
            setValue(5.7, 11.3);
        else if (ox>=3.5 && ox<=6.5 && oy>=14.5 && oy<=17.5)  //34                             v
            setValue(5.7, 17.7);
        else if (ox>=3.0 && ox<=4.9 && oy>=17.5 && oy<=19.0)  //35
            setValue(5.1, 18.25);
        else if (ox>=0.0 && ox<=5.5 && oy>=19.0 && oy<=23.0)  //36
            setValue(5.7, 20.5);
        else if (ox>=7.5 && ox<=12.8 && oy>=20.0 && oy<=23.0)  //37
            setValue(7.3, 21.0);
        else if (ox>=7.0 && ox<=9.0 && oy>=17.5 && oy<=19.0)  //38
            setValue(7.0, 18.25);
        else if (ox>=12.8 && ox<=13.5 && oy>=20.0 && oy<=21.0 && floor==0)  //atm
            setValue(13.25, 19.8);
        else if (ox>=14.5 && ox<=17.5 && oy>=19.0 && oy<=22.0 && floor==0)  //bank
            setValue(15.0, 19.0);
        else if (ox>=18.5 && ox<=23.0 && oy>=15.0 && oy<=17.0 && floor==0)  //office
            setValue(19.0, 15.0);
        else if (ox>=14.5 && ox<=23.0 && oy>=14.5 && oy<=23.0 && floor!=0)  //library or canteen
            setValue(17.0, 17.0);
    }
}

void keyboard(unsigned char key,int x,int y)
{

    if ((df==1 && key==32) || key==105)
    {
        df=0;
        display_info();
    }
    else if (key == 113)
        display_ground();
    else
        glutPostRedisplay();
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        floors++;
        display_otherfloors();
    }
    else if (key == GLUT_KEY_DOWN && floor==0)
        display_ground();
    else if (key == GLUT_KEY_DOWN)
    {
        floors--;
        if (floors == 0)
            display_ground();
        else
            display_otherfloors();
    }
    else
        glutPostRedisplay();

}

void lineloops(float w, float x, float y, float z)
{
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(w, x);
        glVertex2f(y, x);
        glVertex2f(y, z);
        glVertex2f(w, z);
    glEnd();
}

void polygons(float w, float x, float y, float z)
{
    glBegin(GL_POLYGON);
        glVertex2f(w, x);
        glVertex2f(y, x);
        glVertex2f(y, z);
        glVertex2f(w, z);
    glEnd();
}

void display_floor()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBitmapText("FLOOR ", -10.5, 25.5);
    if (floors == 0)
        drawBitmapText("0", -6.5, 25.5);
    else if (floors == 1)
        drawBitmapText("1", -6.5, 25.5);
    else if (floors == 2)
        drawBitmapText("2", -6.5, 25.5);
    else if (floors == 3)
        drawBitmapText("3", -6.5, 25.5);
    else if (floors == 4)
        drawBitmapText("4", -6.5, 25.5);
    else if (floors == 5)
        drawBitmapText("5", -6.5, 25.5);
    else
        drawBitmapText("6", -6.5, 25.5);

	// hole 1
	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
        glVertex2f(3.3, 2.2);
        glVertex2f(5.3, 2.2);
        glVertex2f(5.3, 4.2);
        glVertex2f(4.2, 5.3);
        glVertex2f(2.2, 5.3);
        glVertex2f(2.2, 3.3);
    glEnd();
    glColor3f(1.0, 0.49, 0.31);
	glBegin(GL_LINE_LOOP);
        glVertex2f(3.3, 2.2);
        glVertex2f(5.3, 2.2);
        glVertex2f(5.3, 4.2);
        glVertex2f(4.2, 5.3);
        glVertex2f(2.2, 5.3);
        glVertex2f(2.2, 3.3);
    glEnd();
	// 1
	glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.0, 0.0);
        glVertex2f(3.0, 0.0);
        glVertex2f(3.0, 1.5);
        glVertex2f(1.5, 3.0);
        glVertex2f(0.0, 3.0);
    glEnd();
    // 2
    glColor3f(0.94, 1.0, 1.0);
    polygons(3.0, 0.0, 4.0, 1.5);
    lineloops(3.0,0.0,4.0,1.5);
    smallertext("S09", 3.1, 0.75);
    // 3
    glColor3f(0.94, 1.0, 1.0);
    polygons(4.0,0.0,5.0,1.5);
    lineloops(4.0,0.0,5.0,1.5);
    smallertext("S08", 4.1, 0.75);
    // 4
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.0,0.0,6.0,1.5);
    lineloops(5.0,0.0,6.0,1.5);
    smallertext("S07", 5.1, 0.75);
    // 5
    glColor3f(0.94, 1.0, 1.0);
    polygons(6.0,0.0,7.0,1.5);
    lineloops(6.0,0.0,7.0,1.5);
    // line connecting 5 and 19
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(7.0, 1.5);
        glVertex2f(7.0, 2.0);
    glEnd();
    // 6
    glColor3f(0.94, 1.0, 1.0);
    polygons(0.0,3.0,1.5,4.0);
    lineloops(0.0,3.0,1.5,4.0);
    smallertext("S10", 0.1, 3.5);
    // 7
    glColor3f(0.94, 1.0, 1.0);
    polygons(0.0,4.0,1.5,5.0);
    lineloops(0.0,4.0,1.5,5.0);
    smallertext("S11", 0.1, 4.5);
    // 8
    glColor3f(0.94, 1.0, 1.0);
    polygons(0.0,5.0,1.5,6.0);
    lineloops(0.0,5.0,1.5,6.0);
    smallertext("S12", 0.1, 5.5);
    // 9
    glColor3f(0.94, 1.0, 1.0);
    polygons(0.0,6.0,1.5,7.0);
    lineloops(0.0,6.0,1.5,7.0);
    smallertext("HOD", 0.1, 6.5);
    // line connecting 9 and 32
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(1.5, 7.0);
        glVertex2f(2.0, 7.0);
    glEnd();
    // 11
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.8,4.0,7.0,4.8);
    lineloops(5.8,4.0,7.0,4.8);
    smallertext("S06", 5.9, 4.4);
    // 12
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.8,4.8,7.0,5.6);
    lineloops(5.8,4.8,7.0,5.6);
    smallertext("S05", 5.9, 5.2);
    // 13
    glColor3f(0.94, 1.0, 1.0);
    polygons(4.0,5.8,4.8,7.0);
    lineloops(4.0,5.8,4.8,7.0);
    smallertext("S13", 4.1, 6.4);
    // 14
    glColor3f(0.94, 1.0, 1.0);
    polygons(4.8,5.8,5.6,7.0);
    lineloops(4.8,5.8,5.6,7.0);
    smallertext("S14", 4.9, 6.4);
    // 15
    glColor3f(0.94, 1.0, 1.0);
    polygons(7.0,5.6,7.87,6.6);
    lineloops(7.0,5.6,7.87,6.6);
    smallertext("S04", 7.1, 6.1);
	// 16
	glColor3f(0.94, 1.0, 1.0);
    polygons(7.87,5.6,8.75,6.6);
	lineloops(7.87,5.6,8.75,6.6);
	smallertext("S03", 7.9, 6.1);
    // 17
    glColor3f(0.94, 1.0, 1.0);
    polygons(8.75,5.6,9.62,6.6);
    lineloops(8.75,5.6,9.62,6.6);
    smallertext("S02", 8.8, 6.1);
    // 18
    glColor3f(0.94, 1.0, 1.0);
    polygons(9.62,5.6,10.5,6.6);
    lineloops(9.62,5.6,10.5,6.6);
    smallertext("S01", 9.7, 6.1);
    // 19
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7.0, 2.0);
        glVertex2f(8.0, 2.0);
        glVertex2f(8.0, 3.0);
        glVertex2f(8.75, 3.0);
        glVertex2f(8.75, 4.0);
        glVertex2f(7.0, 4.0);
    glEnd();
    smallertext("WR-", 7.1, 3.5);
    smallertext("Faculty", 7.1, 3.1);
    // 20
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(8.75, 3.0);
        glVertex2f(9.0, 3.0);
        glVertex2f(9.0, 2.0);
        glVertex2f(10.5, 2.0);
        glVertex2f(10.5, 4.0);
        glVertex2f(8.75, 4.0);
    glEnd();
    smallertext("WR-", 9.0, 3.5);
    smallertext("Girls", 9.0, 3.1);
    //21
	glColor3f(1.0, 0.94, 0.96);
    polygons(11.5,3.5,14.5, 6.6);
	lineloops(11.5,3.5,14.5, 6.6);
	smallertext("CR - 02", 12.3, 5.0);
	//22
	glColor3f(1.0, 0.94, 0.96);
    polygons(14.5,3.5,17.5,6.6);
	lineloops(14.5,3.5,17.5,6.6);
	smallertext("CR - 01", 15.0, 5.0);
	//23
	glColor3f(1.0, 0.49, 0.31);
	glBegin(GL_LINES);
        glVertex2f(16.5, 3.5);
        glVertex2f(16.5, 3);
        glVertex2f(16.5, 3);
        glVertex2f(19, 3);
        glVertex2f(17.5,4.9);
        glVertex2f(19,4.9);
    glEnd();
    smallertext("Stairs", 17.6, 3.7);
    //24
    if (floors == 0)
    {
    glColor3f(1.0, 0.98, 0.8);
        polygons(19.0,0.0,23.0,5.5);
        smallertext("Seminar Hall", 20.0, 2.5);
    }
    else if (floors == 1)
    {
        glColor3f(1.0, 0.94, 0.96);
        polygons(20.0, 2.5, 23.0, 5.5);
        glColor3f(1.0, 0.49, 0.31);
        glBegin(GL_LINES);
            glVertex2f(19.0, 2.5);
            glVertex2f(23.0, 2.5);
        glEnd();
        glColor3f(1.0, 0.94, 0.96);
        polygons(19.0, 0.0, 23.0, 2.5);
        glColor3f(1.0, 0.49, 0.31);
        glBegin(GL_LINES);
            glVertex2f(20.0, 2.5);
            glVertex2f(20.0, 5.5);
        glEnd();
        smallertext("CR - 00A", 20.5, 4.0);
        smallertext("CR - 00B", 20.0, 1.5);
    }
    else if (floors == 2 || floors == 3)
    {
        glColor3f(1.0, 0.98, 0.8);
        polygons(19.0,0.0,23.0,5.5);
        smallertext("Laborotory", 20.0, 2.5);
    }
    else if (floors == 4)
    {
        glColor3f(1.0, 0.98, 0.8);
        polygons(19.0,0.0,23.0,5.5);
        smallertext("Sports Room", 20.0, 2.5);
    }
    lineloops(19.0,0.0,23.0,5.5);
    //20-21
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_STRIP);
        glVertex2f(10.5, 2);
        glVertex2f(12, 2);
        glVertex2f(12, 3.5);
    glEnd();
    //22-23
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(16.5, 3.5);
        glVertex2f(16.5, 3.0);
        glVertex2f(16.5, 3.0);
        glVertex2f(19,3);
        glVertex2f(17.5, 4.9);
        glVertex2f(19,4.9);
    glEnd();
    //24-25
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(22,5.5);
        glVertex2f(22,7.5);
    glEnd();
    //25
    glColor3f(1.0, 0.98, 0.8);
    polygons(20,7.5,23,12.8);
    lineloops(20,7.5,23,12.8);
    smallertext("Laborotory", 20.5, 10.0);
    // 26
	lineloops(17.5, 7.4, 19.0, 9.4);
	smallertext("Lift", 17.6, 8.5);
    // 27
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.6,7.0,6.6,7.87);
    lineloops(5.6,7.0,6.6,7.87);
    smallertext("S15", 5.7, 7.4);
    // 28
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.6,7.87,6.6,8.75);
    lineloops(5.6,7.87,6.6,8.75);
    smallertext("S16", 5.7, 8.3);
    // 29
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.6,8.75,6.6,9.62);
    lineloops(5.6,8.75,6.6,9.62);
    smallertext("S17", 5.7, 9.2);
    // 30
    glColor3f(0.94, 1.0, 1.0);
    polygons(5.6,9.62,6.6,10.5);
    lineloops(5.6,9.62,6.6,10.5);
    smallertext("S18", 5.7, 10.1);
    // 31
    lineloops(2.0,9.0,4.0,10.5);
    smallertext("WR-", 2.2, 10.0);
    smallertext("Boys", 2.2, 9.6);
    //31-33
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_STRIP);
        glVertex2f(2,10.5);
        glVertex2f(2,12);
        glVertex2f(3.5,12);
    glEnd();
    // 32
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.0, 7.0);
    glVertex2f(3.5, 7.0);
    glVertex2f(3.5, 9.0);
    glVertex2f(3.0, 9.0);
    glVertex2f(3.0, 8.0);
    glVertex2f(2.0, 8.0);
    glEnd();
    // 33
    glColor3f(1.0, 0.94, 0.96);
    polygons(3.5, 11.5, 6.5, 14.5);
    lineloops(3.5, 11.5, 6.5, 14.5);
    smallertext("CR - 03", 4.1, 13.0);
    // 34
    glColor3f(1.0, 0.94, 0.96);
    polygons(3.5, 14.5, 6.5, 17.5);
    lineloops(3.5, 14.5, 6.5, 17.5);
    smallertext("CR - 04", 4.1, 16.0);
    // 35
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.0, 16.3);
        glVertex2f(3.5, 16.3);
        glVertex2f(3.5, 17.5);
        glVertex2f(4.9, 17.5);
        glVertex2f(4.9, 19.0);
        glVertex2f(3.0, 19.0);
    glEnd();
    smallertext("Stairs", 3.2, 18.25);
    // 36
    glColor3f(1.0, 0.98, 0.8);
    polygons(0.0, 19.0, 5.5, 23.0);
    lineloops(0.0, 19.0, 5.5, 23.0);
    if (floor==0)
        smallertext("Seminar Hall", 1.5, 21.0);
    // line between 36 and 37
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(5.5, 22.0);
        glVertex2f(7.5, 22.0);
    glEnd();
    // 37
    glColor3f(1.0, 0.98, 0.8);
    polygons(7.5, 20.0, 12.8, 23.0);
    lineloops(7.5, 20.0, 12.8, 23.0);
    smallertext("Laborotory", 9.0, 21);
    // 38
    lineloops(7.4, 17.5, 9.4, 19.0);
    smallertext("Lift", 7.7, 18.25);
    // hole 2
    glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_POLYGON);
        glVertex2f(4.0, 7.05);
        glVertex2f(5.5, 7.05);
        glVertex2f(5.5, 10.5);
        glVertex2f(4.0, 10.5);
	glEnd();
    glColor3f(1.0, 0.49, 0.31);
	glBegin(GL_LINE_LOOP);
        glVertex2f(4.0, 7.0);
        glVertex2f(5.6, 7.0);
        glVertex2f(5.6, 10.5);
        glVertex2f(4.0, 10.5);
	glEnd();
    // hole 3
    glColor3f(0.9, 0.9, 0.9);
    glBegin(GL_POLYGON);
        glVertex2f(7.05, 4.05);
        glVertex2f(10.5, 4.05);
        glVertex2f(10.5, 5.5);
        glVertex2f(7.05, 5.5);
	glEnd();
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(10.5, 5.55);
        glVertex2f(10.5, 4.0);
    glEnd();
	// hole 4
    glColor3f(0.9, 0.9, 0.9);
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
	glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(7.4, 8.75);
        glVertex2f(8.75, 7.4);
        glVertex2f(19.0, 7.4);
        glVertex2f(19.0, 13.5);
        glVertex2f(13.5, 19.0);
        glVertex2f(7.4, 19.0);
    glEnd();

}

void display_ground()
{
    display_floor();
    //48
    lineloops(20,12.8,23,14.5);
    //44
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(20,14.5);
        glVertex2f(23, 14.5);
        glVertex2f(20,17.5);
        glVertex2f(18.5,16);
    glEnd();
    smallertext("Office", 19.5, 16.0);
    //47,46,45,43,44,42,41
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_STRIP);
        glVertex2f(23,12.8);
        glVertex2f(24.5,12.8);
        glVertex2f(21.5,20);
        glVertex2f(21.9,20.4);
        glVertex2f(26.5,20.4);
        glVertex2f(26.5,23);
        glVertex2f(24.3,23);
        glVertex2f(23,24.3);
        glVertex2f(23,26.5);
        glVertex2f(20.4,26.5);
        glVertex2f(20.4,21.9);
        glVertex2f(20,21.5);
        glVertex2f(12.8,24.5);
        glVertex2f(12.8,23);
    glEnd();
    //39
    lineloops(12.8, 20, 13.5, 21);
    smallertext("atm", 12.8, 20.4);
    //39-40
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINES);
        glVertex2f(13.5, 20);
        glVertex2f(14.5, 20);
    glEnd();
    //40
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(14.5, 20);
        glVertex2f(14.5, 23);
        glVertex2f(17.5, 20);
        glVertex2f(16, 18.5);
    glEnd();
    smallertext("Bank", 15.5, 20.0);
	glFlush();
	glutSpecialFunc(special);
	glutMouseFunc(mouse);
	if (src_marked == 1 && src_floor==floors)
        drawSource(src_x, src_y);
    if (dstn_marked == 1 && dstn_floor==floors)
        drawDestination(dstn_x, dstn_y);
}

void display_otherfloors()
{
    display_floor();
    glColor3f(1.0, 0.49, 0.31);
    glBegin(GL_LINE_LOOP);
        glVertex2f(12.8, 20.0);
        glVertex2f(14.5, 20.0);
        glVertex2f(20.0, 14.5);
        glVertex2f(20.0, 12.8);
        glVertex2f(24.5, 12.8);
        glVertex2f(21.5, 20.0);
        glVertex2f(20.0, 21.5);
        glVertex2f(12.8, 24.5);
    glEnd();
    if (floors == 1 || floors == 2)
        smallertext("Library", 18.0, 18.0);
    else if (floors == 3)
        smallertext("APU Library", 18.0, 18.0);
    else if (floors == 4 || floors == 5)
        smallertext("Canteen", 18.0, 18.0);
    glFlush();
    if (src_marked == 1 && src_floor==floors)
        drawSource(src_x, src_y);
    if (dstn_marked == 1 && dstn_floor==floors)
        drawDestination(dstn_x, dstn_y);
  	glutSpecialFunc(special);
    glutMouseFunc(mouse);
}

void display_info()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,1.0,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(-13.0,21.0);
        glVertex2f(-13.0,26.0);
        glVertex2f(43.0,26.0);
        glVertex2f(43.0,21.0);
    glEnd();
    drawBitmapText("INFORMATION", 8.0,23.0);
    drawBitmapText("Instructions:", -7.0, 18.0);
    drawBitmapText("Choose the location that you are currently in. Then choose the location that you want to go to.", -5.0, 16.5);
    drawBitmapText("Arrow keys can be used to navigate from one floor to another.", -5 .0, 15.5);
    drawBitmapText("Abbrevations used:", -7.0, 14.0);
    drawBitmapText("CR     -  Class room", -5.0, 12.5);
    drawBitmapText("S        -  Staff room", -5.0, 11.5);
    drawBitmapText("WR    -  Wash room", -5.0, 10.5);
    drawBitmapText("q: quit from this page", -7.0, -2.0);
    drawBitmapText("i: open this page again", 23.0, -2.0);
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5,1.0,0.5);
    glBegin(GL_POLYGON);
        glVertex2f(-13.0,15.0);
        glVertex2f(-13.0,20.0);
        glVertex2f(43.0,20.0);
        glVertex2f(43.0,15.0);
    glEnd();
   	glColor3f(0.0,0.5,0.0);
	drawBitmapText("COLLEGE GUIDE", 8.0,17.0);
    glColor3f(0.5,1.0,0.0);
	drawBitmapText("press spacebar to continue", 7.0,13.5);
    glColor3f(0.0,0.5,0.0);
	drawBitmapText("Krishnan Nandita         - 1PE14CS057", 5.0,3.0);
    glColor3f(0.0,0.5,0.0);
    drawBitmapText("Mamta Mariam Harris - 1PE14CS069", 5.0,1.5);
	glutSwapBuffers();
    df=1;
	glFlush();
}

void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-13.0, 42.0, -3.0, 28.0);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(350.0, 0.0);
	glutCreateWindow("College Guide");
    glLineWidth(2.3);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	myinit();
	glutMainLoop();
	return 0;
}


