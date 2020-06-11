/************************************************************
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include <ofMain.h>

#include "sj_common.h"
#include "PunchUI.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	enum{
		WINDOW_WIDTH = 500,
		WINDOW_HEIGHT = 500,
	};
	
	PUNCH_UI PunchUI;
	
	enum{
		NUM_UI_PARTS = 4,
	};
	
	ofImage image[NUM_UI_PARTS];
	
	
	
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
};
