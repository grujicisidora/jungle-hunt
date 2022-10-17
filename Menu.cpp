#include "Glut.h"
#include <math.h>
#include "Menu.h"



 Menu::Menu() {
	option = 0;
}

 int Menu::getOption() {
	 return option;
 }

 void Menu::setOption(int value) {
	 option = value;
 }

 void Menu::drawStartMenu() {

	 char title[] = "JUNGLE HUNT";
	 char start[] = "START GAME";
	 char exit[] = "EXIT";

	 glPushMatrix();
	 glTranslatef(60, 400, 0);
	 for (int i = 0; i < 11; i++) {
		 glColor3f(0.0, 0.0, 0.0);
		 glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
	 }

	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(320, 250, 0);
	 glScalef(0.4, 0.4, 1);
	 for (int i = 0; i < 10; i++)
		 glutStrokeCharacter(GLUT_STROKE_ROMAN, start[i]);

	 glPopMatrix();

	 glPushMatrix();
	 glTranslatef(460, 170, 0);
	 glScalef(0.4, 0.4, 1);
	 for (int i = 0; i < 4; i++)
		 glutStrokeCharacter(GLUT_STROKE_ROMAN, exit[i]);

	 glPopMatrix();

	 float yoffset = 270;
	 if (option == 1) yoffset = 185;

	 glPushMatrix();
	 glTranslatef(250, yoffset, 0);
	 glScalef(30, 30, 1);
	 glBegin(GL_TRIANGLES);
	 glVertex2f(-1, -0.5);
	 glVertex2f(-1, 0.5);
	 glVertex2f(1, 0);
	 glEnd();

	 glPopMatrix();
}

 
char* Menu::intToChar(int number) {

	char* numberArray = new char[10];
	int i = 9;
	while (number != 0) {
		numberArray[i--] = '0' + (number % 10);
		number = number / 10;
	}
	numberArray[i] = 27;
	return numberArray;
}


void Menu::drawLegend(int score, int lives, int level)
{
	for (int i = 0; i < lives; i++) {
		glPushMatrix();
		glTranslatef(40 + i * 40, 530, 0);
		explorer.drawTheExplorerIntro(false);
		glPopMatrix();
	}
	
	glLineWidth(1.0);
	
	glPushMatrix();
	glTranslatef(400, 540, 0);
	glColor3f(0.0, 0.0, 0.0);
	glScalef(0.2, 0.2, 1);
	char theScore[] = "SCORE: ";
	for (int i = 0; i < 7; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, theScore[i]);
	}
	glPopMatrix();

	glPushMatrix();
	char* scoreValue = intToChar(score);
	glTranslatef(500, 540, 0);
	glScalef(0.2, 0.2, 1);
	if (score == 0) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
	}
	else {
		int index = 0;
		while (scoreValue[index] != 27) index++;
		for (int i = index; i < 10; i++) {
			glutStrokeCharacter(GLUT_STROKE_ROMAN, scoreValue[i]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(800, 540, 0);
	glScalef(0.2, 0.2, 1);
	char theLevel[] = "LEVEL: ";
	for (int i = 0; i < 7; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, theLevel[i]);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(900, 540, 0);
	glScalef(0.2, 0.2, 1);
	char* levelValue = intToChar(level);
	int index = 0;
	while (levelValue[index] != 27) index++;
	for (int i = index; i < 10; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, levelValue[i]);
	}
	glPopMatrix();
}

void Menu::drawEndMenu(int scoreValue)
{
	char title[] = "GAME OVER";
	char playAgain[] = "PLAY AGAIN";
	char theScore[] = "SCORE: ";
	char exit[] = "EXIT";
	glPushMatrix();
	glTranslatef(140, 400, 0);
	glLineWidth(1.0);
	glColor3f(0.0, 0.0, 0.0);
	for (int i = 0; i < 9; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
	}

	glPopMatrix();

	glPushMatrix();
	glTranslatef(370, 310, 0);
	glScalef(0.45, 0.45, 1);
	for (int i = 0; i < 7; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, theScore[i]);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(580, 310, 0);
	char* score = intToChar(scoreValue);
	glScalef(0.45, 0.45, 1);
	if (scoreValue == 0) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
	}
	else {
		int index = 0;
		while (score[index] != 27) index++;
		for (int i = index; i < 10; i++) {
			glutStrokeCharacter(GLUT_STROKE_ROMAN, score[i]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 200, 0);
	glScalef(0.4, 0.4, 1);
	for (int i = 0; i < 10; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, playAgain[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(450, 120, 0);
	glScalef(0.4, 0.4, 1);
	for (int i = 0; i < 4; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, exit[i]);

	glPopMatrix();

	float yoffset;
	if (option == 0)
		yoffset = 220;
	else
		yoffset = 140;

	glPushMatrix();
	glTranslatef(300, yoffset, 0);
	glScalef(25, 25, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1, -0.5);
	glVertex2f(-1, 0.5);
	glVertex2f(1, 0);
	glEnd();

	glPopMatrix();

}


void Menu::drawWinMenu(int scoreValue)
{
	char title[] = "YOU WON!";
	char playAgain[] = "PLAY AGAIN";
	char theScore[] = "SCORE: ";
	char exit[] = "EXIT";
	glPushMatrix();
	glTranslatef(170, 400, 0);
	glColor3f(0.0, 0.0, 0.0);

	for (int i = 0; i < 8; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, title[i]);
	}

	glPopMatrix();

	glPushMatrix();
	glTranslatef(370, 310, 0);
	glScalef(0.45, 0.45, 1);
	for (int i = 0; i < 7; i++) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, theScore[i]);
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(580, 310, 0);

	char* score = intToChar(scoreValue);

	glScalef(0.45, 0.45, 1);
	if (scoreValue == 0) {
		glutStrokeCharacter(GLUT_STROKE_ROMAN, '0');
	}
	else {
		int index = 0;
		while (score[index] != 27) index++;
		for (int i = index; i < 10; i++) {
			glutStrokeCharacter(GLUT_STROKE_ROMAN, score[i]);
		}
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 200, 0);
	glScalef(0.4, 0.4, 1);
	for (int i = 0; i < 10; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, playAgain[i]);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(450, 120, 0);
	glScalef(0.4, 0.4, 1);
	for (int i = 0; i < 4; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, exit[i]);

	glPopMatrix();

	float yoffset;
	if (option == 0)
		yoffset = 220;
	else
		yoffset = 140;

	glPushMatrix();
	glTranslatef(300, yoffset, 0);
	glScalef(25, 25, 1);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1, -0.5);
	glVertex2f(-1, 0.5);
	glVertex2f(1, 0);
	glEnd();

	glPopMatrix();

}
