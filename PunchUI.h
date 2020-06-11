/************************************************************
************************************************************/
#pragma once

#include <ofMain.h>
#include "ofxSyphon.h"

#include "sj_common.h"

/************************************************************
************************************************************/

/**************************************************
**************************************************/
class PUNCH_UI{
private:
	class PARAM{
	private:
		bool b_ClockWise = true;
		float DegPerSec = 0;
		
	public:
		float get__Theta_deg(float ElapsedTime_sec){
			return ElapsedTime_sec * DegPerSec;
		}
		
		PARAM(bool _b_ClockWise, float _DegPerSec)
		: b_ClockWise(_b_ClockWise), DegPerSec(_DegPerSec)
		{
		}
		
		bool get__b_ClockWise() { return b_ClockWise; }
		
	};
	
	enum STATE{
		STATE__STATIC,
		STATE__DYNAMIC,
	};
	
	STATE State = STATE__STATIC;
	int t_from = 0;
	
	enum{
		NUM_UI_PARTS = 4,
	};
	
	ofxSyphonServer fbo_TextureSyphonServer;
	ofFbo fbo;
	
	ofImage image[NUM_UI_PARTS];
	bool b_SolidBack = true;
	
	PARAM param[NUM_UI_PARTS] = {
		PARAM(false,	60),
		PARAM(false,	33),
		PARAM(true,	20),		
		PARAM(false,		5),
	};
	
	
	void drawToFbo();
	
public:
	PUNCH_UI();
	~PUNCH_UI();
	
	void setup();
	void update();
	void draw();
	void SendSyphon();
	void Toggle_SolidBack();
	
	void StateChart_Static();
	void StateChart_Dynamic();
};
