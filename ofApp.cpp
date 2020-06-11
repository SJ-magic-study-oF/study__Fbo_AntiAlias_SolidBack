/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

/******************************
******************************/
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle("GolemPunch");
	
	ofSetWindowShape(WINDOW_WIDTH, WINDOW_HEIGHT);
	/*
	ofSetVerticalSync(false);
	ofSetFrameRate(0);
	/*/
	ofSetVerticalSync(true);
	ofSetFrameRate(30);
    //*/
	
	ofSetEscapeQuitsApp(false);
	
	/********************
	********************/
	PunchUI.setup();
	
	for(int i = 0; i < NUM_UI_PARTS; i++){
		char buf[256];
		sprintf(buf, "PunchUI-%02d.png", i);
		image[i].load(buf);	
	}
}

/******************************
******************************/
void ofApp::update(){
	PunchUI.update();
}

/******************************
******************************/
void ofApp::draw(){
	/********************
	********************/
	ofClear(0, 0, 0, 0);
	
	/********************
	********************/
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	
	ofEnableSmoothing();
	
	/*
	ofDisableAlphaBlending();
	ofEnableSmoothing();
	*/
	
	/********************
	********************/
	PunchUI.draw();
	PunchUI.SendSyphon();
}

/******************************
******************************/
void ofApp::keyPressed(int key){
	switch(key){
		case ' ':
			ofSaveScreen("image.png");
			
			printf("saved screen\n");
			fflush(stdout);
			break;
			
		case 't':
			PunchUI.Toggle_SolidBack();
			break;
			
		case '0':
			PunchUI.StateChart_Static();
			break;
			
		case '1':
			PunchUI.StateChart_Dynamic();
			break;
	}
}

/******************************
******************************/
void ofApp::keyReleased(int key){

}

/******************************
******************************/
void ofApp::mouseMoved(int x, int y ){

}

/******************************
******************************/
void ofApp::mouseDragged(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mousePressed(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseReleased(int x, int y, int button){

}

/******************************
******************************/
void ofApp::mouseEntered(int x, int y){

}

/******************************
******************************/
void ofApp::mouseExited(int x, int y){

}

/******************************
******************************/
void ofApp::windowResized(int w, int h){

}

/******************************
******************************/
void ofApp::gotMessage(ofMessage msg){

}

/******************************
******************************/
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
