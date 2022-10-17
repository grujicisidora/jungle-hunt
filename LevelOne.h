#pragma once

#include "Point.h"
#include "TheExplorer.h"

class LevelOne {

	private:
		bool hit;
		bool jumping;
		bool nextLevelSignal;
		int currentColorGrass;
		int startColorGrass;
		int currentColorTreetops;
		int startColorTreetops;
		int nextLianaIndex;
		int lives;
		int score;
		float step;
		float lianaStep;
		float angle;
		float lianaSeeds[21];
		float lianaPointPool[26];
		float explorerStepX;
		float explorerStepY;
		float explorerMaxX;
		float explorerMaxY;
		float explorerPositionControlY;
		Point currentPointPool[22];
		Point startPointPool[22];
		Point nextLianaPositions[26];
		Point explorerPosition;
		Point explorerLianaPosition;
		TheExplorer jumpingExplorer;

	public:
		LevelOne(int setLives, int setScore);
		float getStep();
		int getScore();
		int getLives();
		bool getNextLevelSignal();
		void setJumping(bool value);
		void drawTheSky();
		void drawTheGrass();
		void drawTreetops();
		void drawLiana(float position, bool initDirection);
		void drawLianas();
		void addTheExplorer();


};