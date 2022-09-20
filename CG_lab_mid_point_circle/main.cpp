#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
float xc , yc , r ;
void circle_midpoint(float XC, float YC, float RAD){
    float x = 0;
    float y = RAD;
    float p;
    p = 1 - RAD;
    glBegin(GL_LINES);
    glVertex2f(xc, yc+r);
    glVertex2f(xc, yc-r);
    glEnd();
    glFlush();
    glBegin(GL_LINES);
    glVertex2f(xc+r, yc);
    glVertex2f(xc-r, yc);
    glEnd();
    glFlush();
    while(x <= y){
        glBegin(GL_POINTS);
        glVertex2f(XC + x, YC + y);
        glVertex2f(XC + y, YC + x);
        glVertex2f(XC - y, YC + x);
        glVertex2f(XC - x, YC + y);
        glVertex2f(XC - x, YC - y);
        glVertex2f(XC - y, YC - x);
        glVertex2f(XC + y, YC - x);
        glVertex2f(XC + x, YC - y);
        if (p<0){
            p += (2*x)+3;
            x++;}
        else{
            p += 2*(x-y) + 5;
            x++;
            y--;}}
    glEnd();
    glFlush();}
void display(void){
    circle_midpoint(xc, yc, r);
}
void init(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}
int main(int argc, char** argv){
    scanf("%f",&xc);
    scanf("%f",&yc);
    scanf("%f",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow ("Mid point circle algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
