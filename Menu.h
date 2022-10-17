#pragma once

#include "TheExplorer.h"

class Menu {

	private:
		int option;
		TheExplorer explorer;

	public:
		Menu();
		int getOption();
		void setOption(int value);
		void drawStartMenu();
		char* intToChar(int num);
		void drawLegend(int score, int lives, int level);
		void drawEndMenu(int scoreValue);
		void drawWinMenu(int scoreValue);

};
