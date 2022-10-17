#include "Glut.h"
#include "IntroScene.h"


IntroScene::IntroScene() { }


void IntroScene::drawTheGrass() {
	int a = 10;
	int x = 1040 / a;
	int y = 110 / a;
	float colorCoord[] = { 0.5, 1.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.0, 0.5, 0.5, 0.0, 0.5, 0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0 };
	int numColors = 10;
	int currentColor = 0;
	int l, m, n;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			if (currentColor == numColors)
				currentColor = 0;

			l = currentColor * 3;
			m = l + 1;
			n = l + 2;

			glBegin(GL_QUADS);
			glColor3f(colorCoord[l], colorCoord[m], colorCoord[n]);
			glVertex3f(i * a, j * a, 0.0);
			glVertex3f(i * a, j * a + a, 0.0);
			glVertex3f(i * a + a, j * a + a, 0.0);
			glVertex3f(i * a + a, j * a, 0.0);
			glEnd();

			currentColor++;
		}

	glFlush();
}
		  

void IntroScene::drawTheSky() {
		  
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 1.0);
	glVertex3f(0.0, 600.0, 0.0);
	glVertex3f(1040.0, 600.0, 0.0);

	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(1040.0, 0.0, 0.0);
	glEnd();

	glFlush();

}

void IntroScene::drawTreetops() {

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 600.0, 0.0);

	glVertex3f(1040.0, 600.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(1040.0, 500.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1000.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(980.0, 500.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(940.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(900.0, 530.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(860.0, 500.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(820.0, 520.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(770.0, 490.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(730.0, 500.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(690.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(610.0, 490.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(550.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(490.0, 500.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(420.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(300.0, 490.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(260.0, 470.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(200.0, 490.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(150.0, 480.0, 0.0);

	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(80.0, 500.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 490.0, 0.0);

	glEnd();

	glFlush();

}