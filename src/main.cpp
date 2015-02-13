
#include "ofMain.h"
#include "ofApp.h"
#include <math.h>

//========================================================================
int main( ){
    board board1;
	ofSetupOpenGL(1000,700,OF_FULLSCREEN);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
