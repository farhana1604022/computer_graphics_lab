#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
void gasket(float x1,float y1,float x2,float y2,float x3,float y3, int n)
{
    float x12,y12,x13,y13,x23,y23;
    if(n>0)
    {
        x12=(x1+x2)/2;
        y12=(y1+y2)/2;
        x13=(x1+x3)/2;
        y13=(y1+y3)/2;
        x23=(x2+x3)/2;
        y23=(y2+y3)/2;
        gasket(x1,y1,x12,y12,x13,y13,n-1);
        gasket(x12,y12,x2,y2,x23,y23,n-1);
        gasket(x13,y13,x23,y23,x3,y3,n-1);
    }
    else
    {
        glBegin(GL_TRIANGLES);
        glVertex2f(x1,y1);
        glVertex2f(x2,y2);
        glVertex2f(x3,y3);
        glEnd();
    }
    glFlush();
}
void display(void)
{
    float x1=0, y1=0, x2=60, y2=0, x3=30, y3=60; int n=2;
    gasket(x1,y1,x2,y2,x3,y3,n);
}
void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv){


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Sierpinski Gasket");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}
