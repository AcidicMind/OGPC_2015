#pragma once

#include "ofMain.h"

class menu{

public:
    void setup();
    void draw();
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);

        bool optionson =false;
		bool abouton =false;

		ofImage bg;
		ofImage sound;
		ofImage mute;

		ofTrueTypeFont titlefont;
		ofTrueTypeFont textfont;
		ofTrueTypeFont smalltextfont;
		ofTrueTypeFont smalltextfont2;

		int winheight, winwidth, LRpadding, TBpadding, interiorpadding;
		int textsize, smalltextsize, smalltextsize2;

		ofColor Adventurerext;
		ofColor Adventurerint;
		ofColor Builderext;
		ofColor Builderint;
		ofColor Singleext;
		ofColor Singleint;
            int AdventurerExtopacity=40;
            int AdventurerIntopacity=120;
            int BuilderExtopacity=40;
            int BuilderIntopacity=120;
            int SingleExtopacity =40;
            int SingleIntopacity =120;
            int Aboutopacity;
            int Optionsopacity;
            int advred=40;
            int bldrred=40;
            int singred=40;
            int allopacity =0;
            int containeropacity =20;

        ofRectangle TwoPcontainer;
        ofRectangle OnePcontainer;
        ofRectangle Titlecontainer;
        ofRectangle SinglePlayer1;
        ofRectangle SinglePlayer2;
		ofRectangle Adventurer1;
		ofRectangle Adventurer2;
		ofRectangle Builder1;
		ofRectangle Builder2;
		ofRectangle About;
		ofRectangle Options;
		ofRectangle Optionsdropdown;
		ofRectangle Orangegender;
		ofRectangle Purplegender;
		ofRectangle Greengender;
		ofRectangle fxslider;
		ofRectangle musicslider;
		ofRectangle masterslider;

		int fxpercent=.5;
        int fxpixels;
        bool fxpressed =false;
        int musicpercent =50;
        int musicpixels;
        bool musicpressed =false;
        int masterpercent=50;
        int masterpixels;
        bool masterpressed =false;


};

class ofApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		void singleplayer();
		void builder();
		void adventurer();

};
