#include "stdlib.h"
#include "Glut.h"
#include <math.h>
#include "LevelTwo.h"


float x_coordsWater[20] = { 1040.0, 1000.0, 980.0, 940.0, 900.0, 860.0, 820.0, 770.0, 730.0, 690.0, 610.0, 550.0, 490.0, 420.0, 300.0, 260.0, 200.0, 150.0, 80.0, 0.0 };
float y_coordsWater[20] = { 400.0, 380.0, 400.0, 380.0, 410.0, 400.0, 410.0, 390.0, 400.0, 380.0, 390.0, 380.0, 400.0, 380.0, 390.0, 370.0, 390.0, 380.0, 400.0, 390.0 };


LevelTwo::LevelTwo(int setLives, int setScore) {
	lives = setLives;
	score = setScore;
	crocodileIndex = 0;
	start = false;
	explorerMode = false;
	moveScene = false;
	punch = false;
	win = false;
	explorerStepX = 0.5; 
	explorerStepY = 5.0;
	explorerPositionXMovement = 900.0;
	explorerPositionYMovement = 200.0;
	minYCoord = 20.0;
	maxYCoord = 350.0;
	crocodileStep = 0.5; 
	for (int i = 0; i < 22; i++) {
		if (i == 0) {
			startPointPool[i] = Point(x_coordsWater[i], y_coordsWater[i]);
			currentPointPool[i] = Point(x_coordsWater[i], y_coordsWater[i]);
		}
		else if (i == 1) {
			float deltaY = y_coordsWater[0] - y_coordsWater[1];
			float deltaX = x_coordsWater[0] - x_coordsWater[1];
			float length = sqrt(deltaX * deltaX + deltaY * deltaY);
			float cosAngle = deltaX / length;
			float newLength = 1.0 / cosAngle;
			float newDeltaY = sqrt(newLength * newLength - 1.0);
			float tempX = x_coordsWater[0] - 1.0;
			float tempY = y_coordsWater[0] - newDeltaY;
			startPointPool[i] = Point(tempX, tempY);
		}
		else if (i == 21) {
			startPointPool[i] = Point(0.0, 490.0);
			currentPointPool[i] = Point(0.0, 490.0);
		}
		else
		{
			startPointPool[i] = Point(x_coordsWater[i - 1], y_coordsWater[i - 1]);
			currentPointPool[i] = Point(x_coordsWater[i - 1], y_coordsWater[i - 1]);
		}
	}
	for (int i = 0; i < 20; i++) {
		crocodileSeeds[i].x = -20.0 - i * 520.0;
		float r = (float)rand() / RAND_MAX;
		crocodileSeeds[i].y = minYCoord + (maxYCoord - minYCoord) * r;
	}
	for (int i = 0; i < 20; i++) {
		float r = (float)rand() / RAND_MAX;
		if (r >= 0.5)
			crocodileModes[i] = true;
		else
			crocodileModes[i] = false;
	}
}

void LevelTwo::setStart(bool value) {
	start = value;
}

void LevelTwo::setPunch(bool value){
	punch = value;
}

void LevelTwo::setScore(int value) {
	score = value;
}

void LevelTwo::setLives(int value) {
	lives = value;
}

bool LevelTwo::getStart() {
	return start;
}

bool LevelTwo::getWin() {
	return win;
}

int LevelTwo::getScore() {
	return score;
}

int LevelTwo::getLives() {
	return lives;
}

Point LevelTwo::getCrocodile() {
	return crocodileSeeds[crocodileIndex];
}

void LevelTwo::drawTheSky() {

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


void LevelTwo::drawTheWater() {

	glBegin(GL_POLYGON);

	glColor3f(0.0, 0.0, 0.5);

	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1040.0, 0.0, 0.0);

	for (int i = 0; i < 22; i++) {
		if (moveScene == true) { 
			if (i == 0)
			{
				currentPointPool[i] = Point(startPointPool[1].x + 1.0, startPointPool[1].y);
			}
			else if (i == 1) {
				float indicator = startPointPool[1].x - startPointPool[2].x;
				if (indicator <= 1.0)
					currentPointPool[i] = Point(1039.0, startPointPool[2].y);
				else {
					float tempY;
					float deltaX = startPointPool[0].x - startPointPool[2].x;
					float deltaY = startPointPool[0].y - startPointPool[2].y;
					float length = sqrt(deltaX * deltaX + deltaY * deltaY);
					float cosAngle = deltaX / length;
					float angle = acos(cosAngle);
					float newLength = 1.0 / cosAngle;
					float newDeltaY = sin(angle) * newLength;
					float tempX = 1039.0;
					if (startPointPool[0].y > startPointPool[2].y) {
						tempY = startPointPool[0].y - newDeltaY;
					}
					else
					{
						tempY = startPointPool[0].y + newDeltaY;
					}
					currentPointPool[i] = Point(tempX, tempY);
				}
			}

			else {
				if (i == 21) {
					currentPointPool[i] = Point(0.0, startPointPool[0].y);
				}
				else
				{
					float newX;
					if (startPointPool[2].y == currentPointPool[1].y) 
					{
						newX = startPointPool[i + 1].x + 1.0;
						currentPointPool[i] = Point(newX, startPointPool[i + 1].y);
					}
					else {
						newX = startPointPool[i].x + 1.0;
						currentPointPool[i] = Point(newX, startPointPool[i].y);
					}
				}
			}
		}

	}

	for (int i = 0; i < 22; i++) {

		glColor3f(0.0, 0.5, 1.0);

		if (currentPointPool[i].y == 0.0) 
			continue;
		else
			glVertex3f(currentPointPool[i].x, currentPointPool[i].y, 0.0);

		startPointPool[i] = Point(currentPointPool[i].x, currentPointPool[i].y);
	}

	glEnd();

	glFlush();

}

void LevelTwo::addTheExplorer() {

	if (start == true) {
		if (explorerMode == false)
			explorerMode = true;
		else
			explorerMode = false;
		if (explorerPositionXMovement > 600.0)
		{
			explorerPositionXMovement = explorerPositionXMovement - explorerStepX;
		}
		if (explorerPositionXMovement == 600.0)
			moveScene = true;
	}
	glPushMatrix();
	glTranslatef(explorerPositionXMovement, explorerPositionYMovement, 0.0);
	explorer.drawTheExplorerLevel2(explorerMode);
	glPopMatrix();
}


void LevelTwo::moveDown() {

	if (start == true)
		if (explorerPositionYMovement > minYCoord)
			explorerPositionYMovement = explorerPositionYMovement - explorerStepY;
}

void LevelTwo::moveUp() {

	if (start == true)
		if (explorerPositionYMovement < maxYCoord)
			explorerPositionYMovement = explorerPositionYMovement + explorerStepY;
}

void LevelTwo::drawACrocodile(bool mode, Point position) {
	glPushMatrix();
	glTranslatef(-99.0, -10.5, 0.0); 
	glTranslatef(position.x, position.y, 0.0);
	glScalef(1.5, 1.5, 1.0);
	if (mode == false) {
		glBegin(GL_POLYGON); //usta
		glColor3f(0.0, 0.5, 0.0);
		glVertex3f(52.0, 10.0, 0.0);
		glVertex3f(66.0, 11.0, 0.0);
		glVertex3f(66.0, 15.0, 0.0);
		glVertex3f(52.0, 20.0, 0.0);
		glEnd();
	}
	else {
		glBegin(GL_POLYGON); //gornja vilica
		glColor3f(0.0, 0.5, 0.0);
		glVertex3f(52.0, 20.0, 0.0);
		glVertex3f(65.0, 22.0, 0.0);
		glVertex3f(66.0, 21.0, 0.0);
		glVertex3f(52.0, 13.0, 0.0);
		glEnd();
		glBegin(GL_POLYGON); //donja vilica
		glColor3f(0.0, 0.5, 0.0);
		glVertex3f(52.0, 10.0, 0.0);
		glVertex3f(65.0, 9.0, 0.0);
		glVertex3f(66.0, 11.0, 0.0);
		glVertex3f(52.0, 13.0, 0.0);
		glEnd();
	}
	glBegin(GL_POLYGON); //glava
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(45.0, 20.0, 0.0);
	glVertex3f(47.0, 22.0, 0.0);
	glVertex3f(50.0, 22.0, 0.0);
	glVertex3f(52.0, 20.0, 0.0);
	glVertex3f(52.0, 10.0, 0.0);
	glVertex3f(45.0, 10.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //telo
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(45.0, 10.0, 0.0);
	glVertex3f(45.0, 20.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //zadnja noga
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(21.0, 10.0, 0.0);
	glVertex3f(26.0, 10.0, 0.0);
	glVertex3f(26.0, 7.0, 0.0);
	glVertex3f(21.0, 7.0, 0.0);
	glEnd();
	glBegin(GL_QUADS); //prednja noga
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(36.0, 10.0, 0.0);
	glVertex3f(41.0, 10.0, 0.0);
	glVertex3f(41.0, 7.0, 0.0);
	glVertex3f(36.0, 7.0, 0.0);
	glEnd();
	glBegin(GL_TRIANGLES); //rep
	glColor3f(0.0, 0.5, 0.0);
	glVertex3f(20.0, 10.0, 0.0);
	glVertex3f(20.0, 20.0, 0.0);
	glVertex3f(1.0, 10.0, 0.0);
	glEnd();
	glPopMatrix();
}

void LevelTwo::drawCrocodiles() {
	if (moveScene == true) {
		Point explorerPosition = Point(explorerPositionXMovement, explorerPositionYMovement);
		for (int i = 0; i < 20; i++) {
			drawACrocodile(crocodileModes[i], crocodileSeeds[i]);
			if (crocodileSeeds[i].x == 300.0)
			{
				crocodileIndex = i;
				float r = (float)rand() / RAND_MAX;
				if (r >= 0.5)
					crocodileModes[i] = true;
				else
					crocodileModes[i] = false;
			}

			if (collision(crocodileSeeds[i], explorerPosition) == true) {
				if (punch == true && crocodileModes[i] == false) {
					score = score + 100;
					crocodileSeeds[i].x = 1500.0;
					punch = false;
				}
				else {
					lives = lives - 1;
					explorerPositionXMovement = 600.0;
					explorerPositionYMovement = maxYCoord;
				}
			}
			crocodileSeeds[i].x = crocodileSeeds[i].x + crocodileStep;
		}
	}
	if (crocodileSeeds[19].x >= 1500.0)
		win = true;
}

bool LevelTwo::collision(Point crocodilePosition, Point explorerPosition) {
	float crocodilePositionNew = crocodilePosition.y + 30.0;
	float explorerPositionNew = explorerPosition.y + 35.0;
	if ((crocodilePosition.x - explorerPosition.x) >= 0.0 && (crocodilePosition.x - explorerPosition.x) <= 15.0) {
		if ((explorerPosition.y >= crocodilePosition.y && explorerPosition.y <= crocodilePositionNew) || (crocodilePosition.y >= explorerPosition.y && crocodilePosition.y <= explorerPositionNew))
			return true;
		else
			return false;
	}
	else
		return false;
}