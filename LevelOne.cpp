#include "Glut.h"
#include <math.h>
#include "LevelOne.h"

	
float stepAngle = 3.14 / 100000.0;
float maxAngle = 3.14 / 400.0;
float minAngle = 3.14 / 400.0 * (-1.0);
float x_coordsTreetops[20] = { 1040.0, 1000.0, 980.0, 940.0, 900.0, 860.0, 820.0, 770.0, 730.0, 690.0, 610.0, 550.0, 490.0, 420.0, 300.0, 260.0, 200.0, 150.0, 80.0, 0.0 };
float y_coordsTreetops[20] = { 500.0, 480.0, 500.0, 480.0, 530.0, 500.0, 520.0, 490.0, 500.0, 480.0, 490.0, 480.0, 500.0, 480.0, 490.0, 470.0, 490.0, 480.0, 500.0, 490.0 };
	

LevelOne::LevelOne(int setLives, int setScore) {
	jumping = false;
	hit = false;
	nextLevelSignal = false;
	currentColorGrass = 0;
	startColorGrass = 0;
	currentColorTreetops = 0;
	startColorTreetops = 0;
	nextLianaIndex = 1;
	lives = setLives;
	score = setScore;
	step = 0.0;
	angle = 0.0;
	lianaStep = 0.0;
	explorerPosition = Point(780.0, 380.0);
	explorerLianaPosition = Point(780.0, 380.0);
	explorerMaxX = 480.0;
	explorerMaxY = 50.0;
	explorerStepX = 1.0;
	explorerStepY = explorerMaxY / (explorerMaxX / 2.0);
	explorerPositionControlY = 0.0;
	for (int i = 0; i < 22; i++) {
		if (i == 0) {
			startPointPool[i] = Point(x_coordsTreetops[i], y_coordsTreetops[i]);
			currentPointPool[i] = Point(x_coordsTreetops[i], y_coordsTreetops[i]);
		}
		else if (i == 1) {
			float deltaY = y_coordsTreetops[0] - y_coordsTreetops[1];
			float deltaX = x_coordsTreetops[0] - x_coordsTreetops[1];
			float length = sqrt(deltaX * deltaX + deltaY * deltaY);
			float cosAngle = deltaX / length;
			float newLength = 1.0 / cosAngle;
			float newDeltaY = sqrt(newLength * newLength - 1.0);
			float tempX = x_coordsTreetops[0] - 1.0;
			float tempY = y_coordsTreetops[0] - newDeltaY;
			startPointPool[i] = Point(tempX, tempY);
		}
		else if (i == 21) {
			startPointPool[i] = Point(0.0, 490.0);
			currentPointPool[i] = Point(0.0, 490.0);
		}
		else
		{
			startPointPool[i] = Point(x_coordsTreetops[i - 1], y_coordsTreetops[i - 1]);
			currentPointPool[i] = Point(x_coordsTreetops[i - 1], y_coordsTreetops[i - 1]);
		}
	}
	for (int i = 0; i < 21; i++)
	{
		lianaSeeds[i] = 780.0 - i * 520.0;
	}
	for (int i = 0; i < 26; i++) {
		lianaPointPool[i] = 500.0 - i * 10.0;
	}
}

float LevelOne::getStep() {
	return step;
}

int LevelOne::getScore() {
	return score;
}

int LevelOne::getLives() {
	return lives;
}

bool LevelOne::getNextLevelSignal() {
	return nextLevelSignal;
}


void LevelOne::setJumping(bool value) {
	jumping = value;
}

void LevelOne::drawTheSky() {

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

void LevelOne::drawTheGrass() {
	
	int a = 10;
	int x = 1040 / a; 
	int y = 110 / a; 
	float colorCoord[] = { 0.5, 1.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.5, 0.0, 0.0, 1.0, 0.5, 0.5, 1.0, 0.5, 0.5, 1.0, 0.5, 0.0, 0.5, 0.5, 0.0, 0.5, 0.5, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0 };
	int numColors = 10;

	if (hit == true) {
		int help = startColorGrass + 9;
		startColorGrass = help % numColors;
	}
	currentColorGrass = startColorGrass;
	int l, m, n;

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			currentColorGrass = currentColorGrass % numColors;

			l = currentColorGrass * 3;
			m = l + 1;
			n = l + 2;
			glBegin(GL_QUADS);
			glColor3f(colorCoord[l], colorCoord[m], colorCoord[n]);
			glVertex3f(i * a, j * a, 0.0);
			glVertex3f(i * a, j * a + a, 0.0);
			glVertex3f(i * a + a, j * a + a, 0.0);
			glVertex3f(i * a + a, j * a, 0.0);
			glEnd();

			currentColorGrass++;
		}

	glFlush();
}

void LevelOne::drawTreetops() {

	glBegin(GL_POLYGON);

	glColor3f(0.0, 1.0, 0.0);

	glVertex3f(0.0, 600.0, 0.0);
	glVertex3f(1040.0, 600.0, 0.0);

	for (int i = 0; i < 22; i++) {
		if (hit == true) {
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

		glColor3f(0.0, 0.5, 0.0);

		if (currentPointPool[i].y == 0.0) 
			continue;
		else
			glVertex3f(currentPointPool[i].x, currentPointPool[i].y, 0.0);

		startPointPool[i] = Point(currentPointPool[i].x, currentPointPool[i].y);
	}

	glEnd();

	glFlush();

}


void LevelOne::drawLiana(float position, bool initDirection) {

	float direction;
	if (initDirection == true)
	{
		direction = 1.0;
	}
	else
	{
		direction = -1.0;
	}

	glPushMatrix();

	glTranslatef(position, 0.0, 0.0);

	glEnable(GL_LINE_SMOOTH);
	glLineWidth(7.0);
	glBegin(GL_LINE_STRIP);
	glColor3f(0.5, 0.5, 0.0);

	glVertex3f(0.0, 600.0, 0.0);
	glVertex3f(0.0, 510.0, 0.0);


	for (int i = 0; i < 26; i++) {
		float h = 600.0 - lianaPointPool[i];
		float newAngle = (i + 1) * angle;
		float newX = direction * h * sin(newAngle);
		float newY = 600.0 - cos(newAngle) * h;
		glVertex3f(newX, newY, 0.0);
	}

	glEnd();

	glPopMatrix();

}

void LevelOne::drawLianas() {
	
	if (step == 520.0)
	{
		hit = false;
		step = 0.0;
	}

	if (hit == true) {
		jumping = false;
		lianaStep = lianaStep + 1.0;
		if (step < 520.0)
		{
			step = step + 1.0;
		}
	}

	for (int i = 0; i < 21; i++)
	{
		bool setDirection;
		if (i % 2 == 0)
			setDirection = true;
		else
			setDirection = false;

		drawLiana(lianaSeeds[i] + lianaStep, setDirection);
	}

	angle = angle + stepAngle;

	if (angle >= maxAngle || angle <= minAngle)
		stepAngle = -1.0 * stepAngle;

}


void LevelOne::addTheExplorer() {

	glPushMatrix();

	if (hit == true) {
		jumping = false; 
		explorerPositionControlY = 0.0;
		explorerLianaPosition.x = explorerLianaPosition.x + 1.0;
	}


	if (jumping == false) {
		if (step == 520.0 && nextLianaIndex == 21)
			nextLevelSignal = true;
		float h = 600.0 - explorerLianaPosition.y; 
		float factor;
		for (int i = 0; i < 26; i++) {
			if (lianaPointPool[i] == explorerLianaPosition.y)
			{
				factor = i;
			}
		}
		float newAngle = (factor + 1) * angle;
		float direction;
		if (nextLianaIndex % 2 == 1) {
			direction = 1.0;
		}
		else
		{
			direction = -1.0;
		}
		float newX = direction * h * sin(newAngle);  
		explorerPosition.x = explorerLianaPosition.x + newX;
		explorerPosition.y = 600.0 - cos(newAngle) * h;
		glTranslatef(explorerPosition.x, explorerPosition.y, 0.0); 
		jumpingExplorer.drawTheExplorerLevel1(jumping);
	}
	else {
		explorerPosition.x = explorerPosition.x - explorerStepX;
		if (explorerPositionControlY >= 50.0) {
			explorerPosition.y = explorerPosition.y - explorerStepY;
		}
		else
		{
			explorerPosition.y = explorerPosition.y + explorerStepY;
			explorerPositionControlY = explorerPositionControlY + explorerStepY;
		}
		glTranslatef(explorerPosition.x, explorerPosition.y, 0.0);
		jumpingExplorer.drawTheExplorerLevel1(jumping);

		float direction;
		if (nextLianaIndex % 2 == 0)
		{
			direction = 1.0;
		}
		else
		{
			direction = -1.0;
		}

		for (int i = 0; i < 26; i++) {
			float h = 600.0 - lianaPointPool[i];
			float newAngle = (i + 1) * angle;
			nextLianaPositions[i].x = 260.0 + direction * h * sin(newAngle);
			nextLianaPositions[i].y = 600.0 - cos(newAngle) * h;
		}

		if (explorerPosition.y < nextLianaPositions[25].y)
		{
			lives--;
			jumping = false;
			explorerPositionControlY = 0.0;
			explorerLianaPosition.x = 780.0;
			explorerLianaPosition.y = 400.0;
		}

		for (int i = 0; i < 24; i++) 
		{
			if ((direction == -1.0 && angle <= 0.0) || (direction == 1.0 && angle >= 0.0)) {
				if (explorerPosition.x >= nextLianaPositions[i].x && explorerPosition.x <= nextLianaPositions[i + 2].x && explorerPosition.y < nextLianaPositions[i].y && explorerPosition.y > nextLianaPositions[i + 2].y) {
					hit = true;
					nextLianaIndex++;
					score = score + 100;
					explorerLianaPosition.x = 260.0;
					explorerLianaPosition.y = lianaPointPool[i + 1]; 
					break;
				}
			}
			else if ((direction == -1.0 && angle > 0.0) || (direction == 1.0 && angle < 0.0))
			{
				if (explorerPosition.x <= nextLianaPositions[i].x && explorerPosition.x >= nextLianaPositions[i + 2].x && explorerPosition.y < nextLianaPositions[i].y && explorerPosition.y > nextLianaPositions[i + 2].y) {
					hit = true;
					nextLianaIndex++;
					score = score + 100;
					explorerLianaPosition.x = 260.0;
					explorerLianaPosition.y = lianaPointPool[i + 1]; 
					break;
				}
			}
			else
			{
				continue;
			}

		}
	}
	glPopMatrix();

}
