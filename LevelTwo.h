#pragma once

#include "Point.h"
#include "TheExplorer.h"

class LevelTwo {

	private:
		int lives;
		int score;
		int crocodileIndex;
		bool start;
		bool moveScene;
		bool explorerMode;
		bool punch;
		bool win;
		float explorerStepX;
		float explorerStepY;
		float explorerPositionXMovement;
		float explorerPositionYMovement;
		float minYCoord;
		float maxYCoord;
		float crocodileStep;
		bool crocodileModes[20];
		Point crocodileSeeds[20];
		Point currentPointPool[22];
		Point startPointPool[22];
		TheExplorer explorer;

	public:
		LevelTwo(int setLives, int setScore);
		void setStart(bool value);
		void setPunch(bool value);
		void setScore(int value);
		void setLives(int value);
		bool getStart();
		bool getWin();
		int getScore();
		int getLives();
		Point getCrocodile();
		bool collision(Point crocodilePosition, Point explorerPosition);
		void drawTheSky();
		void drawTheWater();
		void addTheExplorer();
		void moveDown();
		void moveUp();
		void drawACrocodile(bool mode, Point position);
		void drawCrocodiles();
};