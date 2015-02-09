#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    board board1;
	ofSetupOpenGL((board1.squareSize + board1.gapSize) * board1.N,(board1.squareSize + board1.gapSize) * board1.N,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
