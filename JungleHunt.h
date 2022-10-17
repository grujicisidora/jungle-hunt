#pragma once

#include "Menu.h"
#include "IntroScene.h"
#include "LevelOne.h"
#include "LevelTwo.h"

void myKeyboardFunc( unsigned char key, int x, int y );
void mySpecialKeyFunc( int key, int x, int y );

void drawScene(void);

void initRendering();
void resizeWindow(int w, int h);
