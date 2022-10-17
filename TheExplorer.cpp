#include "Glut.h"
#include <math.h>
#include "TheExplorer.h"

TheExplorer::TheExplorer() { }

void TheExplorer::drawTheExplorerIntro(bool mode) {
	glPushMatrix();
	if (mode == true) {
		glTranslatef(900.0, 100.0, 0.0); 
		glScalef(1.5, 1.5, 1.0);
	}
	else { 
		glTranslatef(5.5, 7.0, 0.0);
		glScalef(0.6, 0.6, 1.0);
	}
	
	glBegin(GL_QUADS); //kais
	if (mode == true)
		glColor3f(0.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 20.0, 0.0);
	glVertex3f(25.0, 20.0, 0.0);
	glVertex3f(25.0, 22.0, 0.0);
	glVertex3f(5.0, 22.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //desni rukav
	if(mode == true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(25.0, 30.0, 0.0);
	glVertex3f(25.0, 40.0, 0.0);
	glVertex3f(32.5, 30.0, 0.0);
	glVertex3f(27.5, 26.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //levi rukav
	if(mode == true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 30.0, 0.0);
	glVertex3f(5.0, 40.0, 0.0);
	glVertex3f(-2.5, 30.0, 0.0);
	glVertex3f(2.5, 26.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //torzo
	if (mode == true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 20.0, 0.0);
	glVertex3f(25.0, 20.0, 0.0);
	glVertex3f(25.0, 40.0, 0.0);
	glVertex3f(5.0, 40.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //leva nogavica
	if(mode == true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(10.0, 0.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(5.0, 20.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //desna nogavica
	if (mode == true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 0.0);
	glVertex3f(30.0, 0.0, 0.0);
	glVertex3f(25.0, 20.0, 0.0);
	glVertex3f(10.0, 20.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //kapa
	if(mode==true)
		glColor3f(1.0, 1.0, 1.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(5.0, 48.0, 0.0);
	glVertex3f(25.0, 48.0, 0.0);
	glVertex3f(20.0, 53.0, 0.0);
	glVertex3f(10.0, 53.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //vrat
	if(mode==true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(11.0, 40.0, 0.0);
	glVertex3f(19.0, 40.0, 0.0);
	glVertex3f(19.0, 45.0, 0.0);
	glVertex3f(11.0, 45.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //desna noga 
	if(mode==true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(22.0, 0.0, 0.0);
	glVertex3f(28.0, 0.0, 0.0);
	glVertex3f(28.0, -4.0, 0.0);
	glVertex3f(22.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //leva noga 
	if(mode==true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(2.0, 0.0, 0.0);
	glVertex3f(8.0, 0.0, 0.0);
	glVertex3f(8.0, -4.0, 0.0);
	glVertex3f(2.0, -4.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //desna cipela
	glColor3f(0.0, 0.0, 0.0); 
	glVertex3f(22.0, -4.0, 0.0);
	glVertex3f(28.0, -4.0, 0.0);
	glVertex3f(32.0, -7.0, 0.0);
	glVertex3f(22.0, -7.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //leva cipela
	glColor3f(0.0, 0.0, 0.0); 
	glVertex3f(2.0, -4.0, 0.0);
	glVertex3f(8.0, -4.0, 0.0);
	glVertex3f(8.0, -7.0, 0.0);
	glVertex3f(-2.0, -7.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //desna ruka
	if(mode==true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(31.0, 29.0, 0.0);
	glVertex3f(29.0, 27.0, 0.0);
	glVertex3f(33.5, 20.0, 0.0);
	glVertex3f(35.5, 21.5, 0.0);
	glEnd();
	glBegin(GL_QUADS); //leva ruka
	if(mode==true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-1.0, 29.0, 0.0);
	glVertex3f(1.25, 27.5, 0.0);
	glVertex3f(-3.5, 20.0, 0.0);
	glVertex3f(-5.5, 21.5, 0.0);
	glEnd();
	glTranslatef(15.0, 46.0, 0.0);
	glBegin(GL_POLYGON); //glava
	if(mode == true)
		glColor3f(1.0, 0.5, 0.0);
	else
		glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i < 100; i++) {
		double angle = 2 * 3.14 / 100 * i;
		glVertex3f(6 * cos(angle), 6 * sin(angle), 0.0);
	}
	glEnd();
	glPopMatrix();
}


void TheExplorer::drawTheExplorerLevel1(bool jumping) {
	glPushMatrix();
	if (jumping == false) {
		glTranslatef(-1.5, -51.0, 0.0); 
	}
	else {
		glTranslatef(1.0, -57.5, 0.0);
	}

	glScalef(1.25, 1.25, 1.0); 
	if (jumping == false) {
		glBegin(GL_POLYGON); //šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(1.5 + 2 * cos(angle), 41.0 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //ruka - podlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(0.0, 35.0, 0.0);
		glVertex3f(3.0, 35.0, 0.0);
		glVertex3f(3.0, 42.0, 0.0);
		glVertex3f(0.0, 42.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //ruka - nadlaktica i lakat
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(6.0, 35.0, 0.0);
		glVertex3f(6.0, 32.0, 0.0);
		glVertex3f(1.0, 32.0, 0.0);
		glVertex3f(0.0, 33.0, 0.0);
		glVertex3f(0.0, 35.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //rukav
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(13.0, 37.0, 0.0);
		glVertex3f(13.0, 30.0, 0.0);
		glVertex3f(6.0, 30.0, 0.0);
		glVertex3f(6.0, 37.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); // cipela
		glColor3f(0.0, 0.0, 0.0); 
		glVertex3f(0.0, 5.0, 0.0);
		glVertex3f(4.0, 5.0, 0.0);
		glVertex3f(4.0, 3.0, 0.0);
		glVertex3f(-4.0, 3.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //noga - butina 
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(5.0, 11.0, 0.0);
		glVertex3f(5.0, 17.5, 0.0);
		glVertex3f(4.0, 17.5, 0.0);
		glVertex3f(4.0, 11.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(4.0, 17.5, 0.0);
		glVertex3f(1.0, 17.5, 0.0);
		glVertex3f(0.0, 16.5, 0.0);
		glVertex3f(0.0, 5.0, 0.0);
		glVertex3f(4.0, 5.0, 0.0);
		
		glEnd();
		glBegin(GL_QUADS); //šorts
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(10.0, 18.0, 0.0);
		glVertex3f(10.0, 10.0, 0.0);
		glVertex3f(5.0, 10.0, 0.0);
		glVertex3f(5.0, 18.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //trup
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(20.0, 20.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(18.0, 10.0, 0.0);
		glVertex3f(10.0, 10.0, 0.0);
		glVertex3f(10.0, 20.0, 0.0);
		glEnd();
	}
	else {
		glBegin(GL_POLYGON); //šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(-0.5 + 2 * cos(angle), 46.5 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //ruka 
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(4.0, 39.0, 0.0);
		glVertex3f(6.0, 41.5, 0.0);
		glVertex3f(0.0, 47.0, 0.0);
		glVertex3f(-2.0, 45.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //rukav
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(12.4, 39.0, 0.0);
		glVertex3f(11.0, 31.0, 0.0);
		glVertex3f(2.7, 37.6, 0.0);
		glVertex3f(7.0, 43.0, 0.0); 
		glEnd();
		glBegin(GL_QUADS); // cipela
		glColor3f(0.0, 0.0, 0.0); 
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glVertex3f(1.6, 0.1, 0.0);
		glVertex3f(-4.0, 5.7, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(6.75, 5.25, 0.0); 
		glVertex3f(3.75, 8.25, 0.0); 
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glEnd();
		glBegin(GL_QUADS); //šorts
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(10.0, 18.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(8.5, 3.5, 0.0);
		glVertex3f(2.0, 10.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //trup
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(20.0, 20.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(10.0, 15.0, 0.0);
		glVertex3f(10.0, 20.0, 0.0);
		glEnd();
	}
	glBegin(GL_QUADS); //kais
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 22.0, 0.0);
	glVertex3f(10.0, 22.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON); //torzo
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 35.0, 0.0);
	glVertex3f(19.0, 40.0, 0.0);
	glVertex3f(13.0, 40.0, 0.0);
	glVertex3f(10.0, 35.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //kapa
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, 48.0, 0.0);
	glVertex3f(25.0, 48.0, 0.0);
	glVertex3f(20.0, 53.0, 0.0);
	glVertex3f(10.0, 53.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //vrat
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(13.0, 40.0, 0.0);
	glVertex3f(19.0, 40.0, 0.0);
	glVertex3f(19.0, 45.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();
	glTranslatef(15.0, 46.0, 0.0);
	glBegin(GL_POLYGON); //glava
	glColor3f(1.0, 0.5, 0.0);
	for (int i = 0; i < 100; i++) {
		double angle = 2 * 3.14 / 100 * i;
		glVertex3f(6 * cos(angle), 6 * sin(angle), 0.0);
	}
	glEnd();
	//parametri za nos
	float y1 = 0.0;
	float y2 = -2.0;
	float x1 = (-1.0) * sqrt(36.0 - y1 * y1);
	float x2 = (-1.0) * sqrt(36.0 - y2 * y2);
	float x3 = -6.0 - 1.5;
	glBegin(GL_TRIANGLES); //nos
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x3, y2, 0.0);
	glEnd();
	glPopMatrix();
}

void TheExplorer::drawTheExplorerLevel2(bool mode) {
	glPushMatrix();
	glTranslatef(4.0, 2.0, 0.0);
	glRotatef(90.0, 0.0, 0.0, 1.0);
	glTranslatef(2.0, -74.0, 0.0);
	glScalef(1.5, 1.5, 1.0);
	if (mode == true) {
		glBegin(GL_POLYGON); //leva šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(3.5 + 2 * cos(angle), 50.0 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //leva podlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(2.0, 42.0, 0.0);
		glVertex3f(5.0, 42.0, 0.0);
		glVertex3f(4.75, 50.0, 0.0);
		glVertex3f(2.25, 50.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //leva nadlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(15.0, 36.5, 0.0);
		glVertex3f(15.0, 30.5, 0.0);
		glVertex3f(2.0, 42.0, 0.0);
		glVertex3f(5.0, 43.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //desno stopalo
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(12.5, 0.0, 0.0);
		glVertex3f(17.5, 0.0, 0.0);
		glVertex3f(17.5, -2.0, 0.0);
		glVertex3f(9.0, -2.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); // levo stopalo
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glVertex3f(1.6, 0.1, 0.0);
		glVertex3f(-4.0, 5.7, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //desna noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(12.5, 4.0, 0.0); 
		glVertex3f(17.5, 4.0, 0.0); 
		glVertex3f(17.5, 0.0, 0.0);
		glVertex3f(12.5, 0.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //leva noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(6.75, 5.25, 0.0); 
		glVertex3f(3.75, 8.25, 0.0); 
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glEnd();
		glBegin(GL_QUADS); //šorts - leva nogavica
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(10.0, 18.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(8.5, 3.5, 0.0);
		glVertex3f(2.0, 10.0, 0.0);
		glEnd();	
		glBegin(GL_QUADS); //šorts - desna nogavica
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(10.0, 15.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(20.0, 4.0, 0.0);
		glVertex3f(10.0, 4.0, 0.0);
		glEnd();
	}
	else {
		glBegin(GL_POLYGON); //leva šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(26.5 + 2 * cos(angle), 50.0 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //leva podlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(28.0, 42.0, 0.0);
		glVertex3f(25.0, 42.0, 0.0);
		glVertex3f(25.25, 50.0, 0.0);
		glVertex3f(27.75, 50.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //leva nadlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(15.0, 36.5, 0.0);
		glVertex3f(15.0, 30.5, 0.0);
		glVertex3f(28.0, 42.0, 0.0);
		glVertex3f(25.0, 43.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //levo stopalo
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(12.5, 0.0, 0.0);
		glVertex3f(17.5, 0.0, 0.0);
		glVertex3f(17.5, -2.0, 0.0);
		glVertex3f(8.5, -2.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); // desno stopalo
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glVertex3f(1.6, 0.1, 0.0);
		glVertex3f(-4.0, 5.7, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //leva noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(12.5, 3.0, 0.0); 
		glVertex3f(17.5, 3.0, 0.0); 
		glVertex3f(17.5, -1.0, 0.0);
		glVertex3f(12.5, -1.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //desna noga - list
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(6.75, 5.25, 0.0); 
		glVertex3f(3.75, 8.25, 0.0); 
		glVertex3f(0.0, 4.5, 0.0);
		glVertex3f(3.0, 1.5, 0.0);
		glEnd();
		glBegin(GL_QUADS); //šorts - leva nogavica
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(10.0, 18.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glVertex3f(20.0, 3.0, 0.0);
		glVertex3f(10.0, 3.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //šorts - desna nogavica
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(10.0, 18.0, 0.0);
		glVertex3f(20.0, 15.0, 0.0);
		glColor3f(1.0, 1.0, 1.0);
		glVertex3f(8.5, 3.5, 0.0);
		glVertex3f(2.0, 10.0, 0.0);
		glEnd();
	}
	glBegin(GL_QUADS); //trup
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 15.0, 0.0);
	glVertex3f(10.0, 15.0, 0.0);
	glVertex3f(10.0, 20.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //kais
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 22.0, 0.0);
	glVertex3f(10.0, 22.0, 0.0);
	glEnd();
	glBegin(GL_POLYGON); //torzo
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(10.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(20.0, 35.0, 0.0);
	glVertex3f(19.0, 40.0, 0.0);
	glVertex3f(13.0, 40.0, 0.0);
	glVertex3f(10.0, 35.0, 0.0);
	glEnd();
	if (mode == true) {
		glPushMatrix();
		glScalef(0.975, 0.975, 0.0);
		glBegin(GL_POLYGON); //desna šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(26.5 + 2 * cos(angle), 50.0 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //desna podlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(28.0, 42.0, 0.0);
		glVertex3f(25.0, 42.0, 0.0);
		glVertex3f(25.25, 50.0, 0.0);
		glVertex3f(27.75, 50.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //desna nadlaktica
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(15.0, 36.5, 0.0);
		glVertex3f(15.0, 30.5, 0.0);
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(28.0, 42.0, 0.0);
		glVertex3f(25.0, 43.0, 0.0);
		glEnd();
		glPopMatrix();
	}
	else {
		glPushMatrix();
		glScalef(0.975, 0.975, 0.0);
		glBegin(GL_POLYGON); //desna šaka
		glColor3f(1.0, 0.5, 0.0);
		for (int i = 0; i < 100; i++) {
			double angle = 2 * 3.14 / 100 * i;
			glVertex3f(3.5 + 2 * cos(angle), 50.0 + 2 * sin(angle), 0.0); 
		}
		glEnd();
		glBegin(GL_QUADS); //desna podlaktica
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(2.0, 42.0, 0.0);
		glVertex3f(5.0, 42.0, 0.0);
		glVertex3f(4.75, 50.0, 0.0);
		glVertex3f(2.25, 50.0, 0.0);
		glEnd();
		glBegin(GL_QUADS); //desna nadlaktica
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(15.0, 36.5, 0.0);
		glVertex3f(15.0, 30.5, 0.0);
		glColor3f(1.0, 0.5, 0.0);
		glVertex3f(2.0, 42.0, 0.0);
		glVertex3f(5.0, 43.0, 0.0);
		glEnd();
		glPopMatrix();
	}
	glBegin(GL_QUADS); //vrat
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(13.0, 40.0, 0.0);
	glVertex3f(19.0, 40.0, 0.0);
	glVertex3f(19.0, 45.0, 0.0);
	glVertex3f(13.0, 45.0, 0.0);
	glEnd();
	glTranslatef(15.0, 46.0, 0.0);
	glBegin(GL_POLYGON); //glava
	glColor3f(1.0, 0.5, 0.0);
	for (int i = 0; i < 100; i++) {
		double angle = 2 * 3.14 / 100 * i;
		glVertex3f(6 * cos(angle), 6 * sin(angle), 0.0);
	}
	glEnd();
	//parametri za nos
	float y1 = 0.0;
	float y2 = -2.0;
	float x1 = (-1.0) * sqrt(36.0 - y1 * y1);
	float x2 = (-1.0) * sqrt(36.0 - y2 * y2);
	float x3 = -6.0 - 1.5;
	glBegin(GL_TRIANGLES); //nos
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(x1, y1, 0.0);
	glVertex3f(x2, y2, 0.0);
	glVertex3f(x3, y2, 0.0);
	glEnd();
	glPopMatrix();
}
