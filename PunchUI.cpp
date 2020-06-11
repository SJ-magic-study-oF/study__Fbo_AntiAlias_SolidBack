/************************************************************
************************************************************/
#include "PunchUI.h"

/************************************************************
************************************************************/

/******************************
******************************/
PUNCH_UI::PUNCH_UI()
{
}

/******************************
******************************/
PUNCH_UI::~PUNCH_UI()
{
}

/******************************
******************************/
void PUNCH_UI::setup()
{
	for(int i = 0; i < NUM_UI_PARTS; i++){
		char buf[256];
		sprintf(buf, "PunchUI-%02d.png", i);
		image[i].load(buf);	
	}
	
	fbo.allocate(WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, 0);

	fbo_TextureSyphonServer.setName("GolemPunchUI");
}

/******************************
******************************/
void PUNCH_UI::update()
{
	drawToFbo();
}

/******************************
******************************/
void PUNCH_UI::draw()
{
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	/*
	ofDisableAlphaBlending();
	ofEnableSmoothing();
	*/
	ofEnableSmoothing();
	
	if(State == STATE__STATIC){
		ofSetColor(255, 255, 255, 255);
	}else{
		float T = 800.0;
		
		int Alpha;
		int dt = ofGetElapsedTimeMillis() - t_from;
		
		if(T <= dt) Alpha = 0;
		else		Alpha = (int)(-(255.0) * dt / T + 255.0);
		
		ofSetColor(255, 255, 255, Alpha);
		printf("%5d\r", Alpha);
		fflush(stdout);
	}
	
	fbo.draw(0, 0, ofGetWidth(), ofGetHeight());
}

/******************************
******************************/
void PUNCH_UI::SendSyphon()
{
	ofTexture tex = fbo.getTextureReference();
	fbo_TextureSyphonServer.publishTexture(&tex);
}

/******************************
******************************/
void PUNCH_UI::drawToFbo()
{
	ofDisableSmoothing();
	
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
	float ElapsedTime_sec = (float)ofGetElapsedTimeMillis() / 1000;
	fbo.begin();
		if(b_SolidBack)	ofClear(0, 0, 0, 255);
		else			ofClear(0, 0, 0, 0);
		
		ofSetColor(255, 255, 255, 255);
		
		for(int i = 0; i < NUM_UI_PARTS; i++){
			ofPushMatrix();
				ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
				
				if(param[i].get__b_ClockWise())	ofRotate(  param[i].get__Theta_deg(ElapsedTime_sec) );
				else							ofRotate( -param[i].get__Theta_deg(ElapsedTime_sec) );
				
				image[i].setAnchorPercent(0.5, 0.5);
				image[i].draw(0, 0, fbo.getWidth(), fbo.getHeight());
			ofPopMatrix();
		}
	fbo.end();
}


/******************************
******************************/
void PUNCH_UI::Toggle_SolidBack()
{
	b_SolidBack = !b_SolidBack;
	
	if(b_SolidBack)	printf("Solid Back\n");
	else			printf("Transparent Back\n");
	
	fflush(stdout);
}

/******************************
******************************/
void PUNCH_UI::StateChart_Static()
{
	State = STATE__STATIC;	
}

/******************************
******************************/
void PUNCH_UI::StateChart_Dynamic()
{
	State = STATE__DYNAMIC;
	t_from = ofGetElapsedTimeMillis();
}


