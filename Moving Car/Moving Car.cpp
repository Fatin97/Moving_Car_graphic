
#include "stdafx.h"
#include <GL/glut.h>
#include <GL/glu.h>
#include "timer.h"

Timer timer; // timer variable to adjust car and wheels rotating


void DrawGround()
{

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);

	// upper layer parts
	glColor3f(0.0, 0.5, 0.0);
	gluDisk(gluNewQuadric(), 0, 30, 50, 3); // green inside
	glColor3f(0.7, 0.7, 0.7);
	gluDisk(gluNewQuadric(), 30, 80, 50, 3); // gray in middle
	glColor3f(0.0, 0.5, 0.1);
	gluDisk(gluNewQuadric(), 80, 100, 50, 3); // green out

	glTranslatef(0 , 0 , -8);
	gluCylinder(gluNewQuadric(), 100, 100, 8, 50, 3); // side layer
	gluDisk(gluNewQuadric(), 0, 100, 50, 3);          //lower layer
	    
	glPopMatrix();

}  // wW

void DrawTree1()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 3.5, 3.5, 15, 50, 20); // trunk

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 15);
	glutSolidCone(10, 35, 50, 20);  // leaves

	glPopMatrix();

}

void DrawTree2()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(90, 0, 0);
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 2.5, 2.5, 15, 50, 20);

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 15);
	glutSolidCone(8, 30, 50, 20);
	
	glPopMatrix();

}

void DrawTree3()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-45, 0, 80);
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 2.5, 2.5, 15, 50, 20);

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 15);
	glutSolidCone(8, 30, 50, 20);

	glPopMatrix();
}

void DrawTree4()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-55, 0, 75);
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 2, 2, 8, 50, 20);

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 8);
	glutSolidCone(5, 15, 50, 20);

	glPopMatrix();
}

void DrawTree5()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-55, 0, -75);
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 2, 2, 8, 50, 20);

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 8);
	glutSolidCone(5, 15, 50, 20);

	glPopMatrix();
}

void DrawTree6()
{
	GLUquadric* quadric = gluNewQuadric();
	glPushMatrix();
	glTranslatef(-50, 0, -80);
	glRotatef(-90, 1, 0, 0);

	glColor3f(0.7, 0.3, 0.3);
	gluCylinder(quadric, 2, 2, 8, 50, 20);

	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(0, 0, 8);
	glutSolidCone(5, 15, 50, 20);

	glPopMatrix();
}

void DrawCar(GLfloat time)
{


	glPushMatrix();

	glColor3f(1.0, 0.0, 0.0); 
	glRotatef(-time * 75, 0, 1, 0);
	glTranslatef(0, 0, 55);

	// ---------------- Left face ---------------------
	glBegin(GL_POLYGON);
	glVertex3f(-20, 7, 8);
	glVertex3f(-20, 13, 8);
	glVertex3f(0, 13, 8);
	glVertex3f(0, 22, 8);
	glVertex3f(20, 22, 8);
	glVertex3f(20, 7, 8);
	glEnd();
	
	// ---------------- Front and upper pieces ---------------------
	glBegin(GL_QUADS);
	glVertex3f(-20, 7, 8);
	glVertex3f(-20, 7, -8);
	glVertex3f(-20, 13, -8);
	glVertex3f(-20, 13, 8);

	glVertex3f(-20, 13, 8);
	glVertex3f(-20, 13, -8);
	glVertex3f(0, 13, -8);
	glVertex3f(0, 13, 8);

	glVertex3f(0, 13, 8);
	glVertex3f(0, 13, -8);
	glVertex3f(0, 22, -8);
	glVertex3f(0, 22, 8);

	glVertex3f(0, 22, 8);
	glVertex3f(0, 22, -8);
	glVertex3f(20, 22, -8);
	glVertex3f(20, 22, 8);

	glVertex3f(20, 7, 8);
	glVertex3f(20, 7, -8);
	glVertex3f(20, 22, -8);
	glVertex3f(20, 22, 8);

	glEnd();
	
	// ---------------- Right face ---------------------
	glBegin(GL_POLYGON);
	glVertex3f(-20, 7, -8);
	glVertex3f(-20, 13, -8);
	glVertex3f(0, 13, -8);
	glVertex3f(0, 22, -8);
	glVertex3f(20, 22, -8);
	glVertex3f(20, 7, -8);
	glEnd();


	// ---------------- Wheels ---------------------
	
	//------ Wheel 1 ---------
	glPushMatrix();
	glTranslatef(-12, 6, 8);
	glRotatef(time * 500, 0, 0, 1);

	// spokes
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(-4, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 4, 0);
	glVertex3f(0, -4, 0);

	glVertex3f(-4, -4, 0);
	glVertex3f(4, 4, 0);

	glVertex3f(-4, 4, 0);
	glVertex3f(4, -4, 0);
	glEnd();

	//wheel
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTorus(1.5, 5, 50, 20);
	glPopMatrix();

	//------ Wheel 2 ---------
	glPushMatrix();
	glTranslatef(12, 6, 8);
	glRotatef(time * 500, 0, 0, 1);

	// spokes
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(-4, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 4, 0);
	glVertex3f(0, -4, 0);

	glVertex3f(-4, -4, 0);
	glVertex3f(4, 4, 0);

	glVertex3f(-4, 4, 0);
	glVertex3f(4, -4, 0);
	glEnd();

	//wheel
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTorus(1.5, 5, 50, 20);
	glPopMatrix();

	//------ Wheel 3 ---------
	glPushMatrix();
	glTranslatef(-12, 6, -8);
	glRotatef(time * 500, 0, 0, 1);

	// spokes
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(-4, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 4, 0);
	glVertex3f(0, -4, 0);

	glVertex3f(-4, -4, 0);
	glVertex3f(4, 4, 0);

	glVertex3f(-4, 4, 0);
	glVertex3f(4, -4, 0);
	glEnd();

	//wheel
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTorus(1.5, 5, 50, 20);
	glPopMatrix();

	//------ Wheel 4 ---------
	glPushMatrix();
	glTranslatef(12, 6, -8);
	glRotatef(time * 500, 0, 0, 1);

	// spokes
	glColor3f(1.0, 1.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(-4, 0, 0);
	glVertex3f(4, 0, 0);

	glVertex3f(0, 4, 0);
	glVertex3f(0, -4, 0);

	glVertex3f(-4, -4, 0);
	glVertex3f(4, 4, 0);

	glVertex3f(-4, 4, 0);
	glVertex3f(4, -4, 0);
	glEnd();

	//wheel
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTorus(1.5, 5, 50, 20);
	glPopMatrix();


	// ---------------- Lights ---------------------
	glColor3f(1.0, 1.0, 0.0); 

	// ------Light 1 -------- -
	glPushMatrix();
	glTranslatef(-20, 10, 4); 
	glScalef(0.4, 1.0, 1.0);
	glutSolidSphere(3, 20, 7); 
	glPopMatrix();

	// ------Light 2 -------- -
	glPushMatrix();
	glTranslatef(-20, 10, -4);
	glScalef(0.4, 1.0, 1.0);
	glutSolidSphere(3, 20, 7);
	glPopMatrix();

	glPopMatrix();


}


void render(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0, 100, 200, 0, 0, 0, 0, 1, 0);
	
	GLfloat time = timer.getTime(); // get current timer count

	DrawGround();
	DrawTree1();
	DrawTree2();
	DrawTree3();
	DrawTree4();
	DrawTree5();
	DrawTree6();
	DrawCar(time);

	glutSwapBuffers();
}


void init(void)
{

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);

}

void initLighting()
{
	GLfloat position[] = {0.0 , 50.0 , 20.0 , 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);
}

void reshape(int w, int h)
{
	glViewport(0 ,0 ,w ,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(25, 25);
	glutCreateWindow("OpenGL - Moving Car");
	init();
	initLighting();
	glutReshapeFunc(reshape);
	glutDisplayFunc(render);
	glutIdleFunc(render);
	glutMainLoop();
}

