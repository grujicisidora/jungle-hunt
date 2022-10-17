#include <math.h>		
#include <stdio.h>
#include <stdlib.h>
#include "Glut.h"
#include "JungleHunt.h"


const double Xmin = 0.0, Xmax = 1040.0;
const double Ymin = 0.0, Ymax = 600.0;

int level = 0;
int lives = 3;
int score = 0;
Menu menu;
IntroScene introScene;
TheExplorer explorer;
LevelOne lvl1 = LevelOne(lives, score);
LevelTwo lvl2 = LevelTwo(lives, score);

void myKeyboardFunc(unsigned char key, int x, int y)
{
	if (key == 27) exit(1);
	if (key == 13) {
		if (level == 0)
		{
			if (menu.getOption() == 1)
				exit(1);
			else
				level = 1;
		}
		if (level == -1 || level == 3)
		{
			if (menu.getOption() == 1)
				exit(1);
			else {
				lives = 3;
				score = 0;
				lvl1 = LevelOne(lives, score);
				lvl2 = LevelTwo(lives, score);
				level = 1;
			}			
		}
		if (level == 2)
		{
			lvl2.setStart(true);
		}
	}
	if (key == 32) {
		if (level == 1 && lvl1.getStep() == 0.0) 
			lvl1.setJumping(true);
		if (level == 2 && lvl2.getCrocodile().x >= 400) 
			lvl2.setPunch(true);
	}
}

void mySpecialKeyFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_DOWN:
		if(level == 0)
			if (menu.getOption() == 0)
				menu.setOption(1);
		if(level == -1)
			if (menu.getOption() == 0)
				menu.setOption(1);
		if (level == 3)
			if (menu.getOption() == 0)
				menu.setOption(1);
		if (level == 2)
			lvl2.moveDown();
		break;
	case GLUT_KEY_UP:
		if (level == 0)
			if (menu.getOption() == 1)
				menu.setOption(0);
		if (level == -1)
			if (menu.getOption() == 1)
				menu.setOption(0);
		if (level == 3)
			if (menu.getOption() == 1)
				menu.setOption(0);
		if (level == 2)
			lvl2.moveUp();
		break;
	}
}



void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	
	if (level == 0) {
		menu.drawStartMenu();
		explorer.drawTheExplorerIntro(true);
		introScene.drawTheGrass();
		introScene.drawTreetops();
		introScene.drawTheSky();
	}
	else if(level == 1)
	{
		score = lvl1.getScore();
		lives = lvl1.getLives();
		menu.drawLegend(score, lives, level);
		lvl1.addTheExplorer();
		lvl1.drawTreetops();
		lvl1.drawLianas();
		lvl1.drawTheGrass();
		lvl1.drawTheSky();
		if (lvl1.getLives() == 0)
			level = -1;
		if (lvl1.getNextLevelSignal() == true) {
			level = 2;
		}	
	}
	else if (level == 2) {
		if (lvl2.getStart() == false) {
			lvl2.setScore(score);
			lvl2.setLives(lives);
		}
		menu.drawLegend(score, lives, level);
		lvl2.addTheExplorer();
		lvl2.drawCrocodiles();
		lvl2.drawTheWater();
		lvl2.drawTheSky();
		score = lvl2.getScore();
		lives = lvl2.getLives();
		if (lvl2.getLives() == 0)
			level = -1;
		if (lvl2.getWin() == true) {
			level = 3;
			score = score + lives * 100;
		}
	}
	else if(level == -1)
	{
		menu.drawEndMenu(score);
		explorer.drawTheExplorerIntro(true);
		introScene.drawTheGrass();
		introScene.drawTreetops();
		introScene.drawTheSky();
	}
	else
	{
		menu.drawWinMenu(score);
		explorer.drawTheExplorerIntro(true);
		introScene.drawTheGrass();
		introScene.drawTreetops();
		introScene.drawTheSky();
	}

	glFlush();
	glutSwapBuffers();


	if (true)
		glutPostRedisplay();
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void resizeWindow(int w, int h)
{
	double scale, center;
	double windowXmin, windowXmax, windowYmin, windowYmax;

	glViewport(0, 0, w, h);

	w = (w == 0) ? 1 : w;
	h = (h == 0) ? 1 : h;
	if ((Xmax - Xmin) / w < (Ymax - Ymin) / h) {
		scale = ((Ymax - Ymin) / h) / ((Xmax - Xmin) / w);
		center = (Xmax + Xmin) / 2;
		windowXmin = center - (center - Xmin)*scale;
		windowXmax = center + (Xmax - center)*scale;
		windowYmin = Ymin;
		windowYmax = Ymax;
	}
	else {
		scale = ((Xmax - Xmin) / w) / ((Ymax - Ymin) / h);
		center = (Ymax + Ymin) / 2;
		windowYmin = center - (center - Ymin)*scale;
		windowYmax = center + (Ymax - center)*scale;
		windowXmin = Xmin;
		windowXmax = Xmax;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(windowXmin, windowXmax, windowYmin, windowYmax, -1, 1);

	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(60, 60);
	glutInitWindowSize(1040, 600);

	glutCreateWindow("Jungle Hunt - Isidora Grujic 619/2017");
	
	initRendering();

	glutKeyboardFunc(myKeyboardFunc);
	glutSpecialFunc(mySpecialKeyFunc);


	glutReshapeFunc(resizeWindow);

	glutDisplayFunc(drawScene);

	glutMainLoop();

	return(0);
}

