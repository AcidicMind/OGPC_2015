#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    img.loadImage("water.jpg");







}

//--------------------------------------------------------------
void ofApp::update(){

    winheight =ofGetWindowHeight();
    winwidth =ofGetWindowWidth();
    LRpadding =winwidth*.05;
    TBpadding =winheight*.05;
    interiorpadding =winwidth/20;
    textsize =(winheight*winwidth)*.000035;
    smalltextsize = (winheight*winwidth)*.000017;

    titlefont.loadFont("DALEK___.ttf",winheight/15);
    textfont.loadFont("DIOGENES.ttf",textsize);
    smalltextfont.loadFont("DIOGENES.ttf",smalltextsize);

//    Titlecontainer.x =(winwidth*.175);
//    Titlecontainer.y = TBpadding;
//    Titlecontainer.width = (winwidth*.65);
//    Titlecontainer.height = winheight*.15;

    TwoPcontainer.x = LRpadding;
    TwoPcontainer.y = (winheight*.7);
    TwoPcontainer.width = (winwidth-(LRpadding*2));
    TwoPcontainer.height = (winheight-TwoPcontainer.y-(TBpadding)+winheight*.03);

    OnePcontainer.x = winwidth*.225+LRpadding;
    OnePcontainer.y = (winheight*.41);
    OnePcontainer.width = TwoPcontainer.width/2;
    OnePcontainer.height = TwoPcontainer.height;


    About.x = LRpadding/3;
    About.y = TBpadding/3;
    About.width = winwidth*.08;
    About.height = winheight*.04;

    Options.x = winwidth-winwidth*.08-LRpadding/3;
    Options.y = TBpadding/3;
    Options.width = winwidth*.08;
    Options.height = winheight*.04;


//-----------------------Adventurer option button-------------------------------------
    Adventurer1.x = LRpadding*1.25;
    Adventurer1.y = (winheight*.73);
    Adventurer1.width = winwidth/2-LRpadding*1.25-(interiorpadding/2);
    Adventurer1.height = (winheight-Adventurer1.y-TBpadding);              //dimensions and padding for adventurer button

    Adventurer2.x = (LRpadding*1.25+(.05*Adventurer1.width));
    Adventurer2.y = (Adventurer1.y+(.05*Adventurer1.height));
    Adventurer2.width = (.9*Adventurer1.width);
    Adventurer2.height = (.9*Adventurer1.height);
//----------------------Builder option button---------------------------------------
    Builder1.x = (winwidth/2+interiorpadding/2);
    Builder1.y = (winheight*.73);
    Builder1.width = Adventurer1.width;                   //dimensions and padding for builder button
    Builder1.height = Adventurer1.height;

    Builder2.x = (Builder1.x+(.05*Builder1.width));
    Builder2.y = (Builder1.y+(.05*Builder1.height));
    Builder2.width = Adventurer2.width;
    Builder2.height = Adventurer2.height;

//-----------------------Single player adventurer option button-------------------------------------
    SinglePlayer1.x = (OnePcontainer.x+winwidth*.016);
    SinglePlayer1.y = (winheight*.44);
    SinglePlayer1.width = Builder1.width;
    SinglePlayer1.height =Builder1.height;

    SinglePlayer2.x = (SinglePlayer1.x+(.05*SinglePlayer1.width));
    SinglePlayer2.y = (SinglePlayer1.y+(.05*SinglePlayer1.height));
    SinglePlayer2.width = Builder2.width;
    SinglePlayer2.height = Builder2.height;
}

//--------------------------------------------------------------
void ofApp::draw(){
img.resize(winwidth,winheight);
 img.draw(0,0);

    ofColor colorOne;
    ofColor colorTwo;

    colorOne.set (0, 0, 0);
    colorTwo.set (255, 100, 50);

   // ofBackgroundGradient(colorTwo, colorOne, OF_GRADIENT_CIRCULAR);

    ofSetColor(230,230,230,10);
    ofRectRounded(Titlecontainer, 20);

    ofSetColor(180,180,180,20);
    ofRectRounded(OnePcontainer, 16);

    ofSetColor(180,180,180,20);
    ofRectRounded(TwoPcontainer, 16);

    ofSetColor(100,100,100,Aboutopacity);
    ofRectRounded(About,8);

    ofSetColor(100,100,100,Optionsopacity);
    ofRectRounded(Options,8);


//----------------------Adventurer option button-------------------------------
    Adventurerext.r= 230;
    Adventurerext.g= 230;
    Adventurerext.b= 230;

    Adventurerint.r= advred;
    Adventurerint.g= 40;
    Adventurerint.b= 40;

    ofSetColor(Adventurerext,AdventurerExtopacity);
    ofRectRounded(Adventurer1, 8);                                   //fix the corners

    ofSetColor(Adventurerint,AdventurerIntopacity);
    ofRectRounded(Adventurer2, 8);

//----------------------Builder option button-------------------------------

    Builderext.r= 230;
    Builderext.g= 230;
    Builderext.b= 230;

    Builderint.r= bldrred;
    Builderint.g= 40;
    Builderint.b= 40;

    ofSetColor(Builderext,BuilderExtopacity);
    ofRectRounded(Builder1, 8);

    ofSetColor(Builderint,BuilderIntopacity);
    ofRectRounded(Builder2, 8);



//----------------------Single Player option button-------------------------------

    Singleext.r= 230;
    Singleext.g= 230;
    Singleext.b= 230;

    Singleint.r= singred;
    Singleint.g= 40;
    Singleint.b= 40;

    ofSetColor(Singleext,SingleExtopacity);
    ofRectRounded(SinglePlayer1, 8);

    ofSetColor(Singleint,SingleIntopacity);
    ofRectRounded(SinglePlayer2, 8);

//-----------------------------------BUTTON TEXT-------------------------------------------
    ofSetColor(210,210,210);
    titlefont.drawString("PHARAOH",(winwidth/2-.46*titlefont.getSize()*7),(winheight*.08+(titlefont.getSize()/2)));

    textfont.drawString("Single Player",(SinglePlayer2.x+.5*SinglePlayer2.width-(.52*textfont.getSize()*6.5)),(SinglePlayer2.y+.5*SinglePlayer2.height+(textfont.getSize()/2)));

    textfont.drawString("Adventurer",(Adventurer2.x+.5*Adventurer2.width-(.6*textfont.getSize()*5)),(Adventurer2.y+.5*Adventurer2.height+(textfont.getSize()/2)));

    textfont.drawString("Builder",(Builder2.x+.5*Builder2.width-(.52*textfont.getSize()*3.5)),(Builder2.y+.5*Builder2.height+(textfont.getSize()/2)));

    smalltextfont.drawString("About",(About.x+.5*About.width-(.68*smalltextfont.getSize()*2.5)),(About.y+.5*About.height+(smalltextfont.getSize()/2)));

    smalltextfont.drawString("Options",(Options.x+.5*Options.width-(.62*smalltextfont.getSize()*3.5)),(Options.y+.5*Options.height+(smalltextfont.getSize()/2)));



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){


//-----------------------------HOVER FEATURE------------------------------------------

    //adventurer button
    if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height))){
        AdventurerExtopacity=120;
        AdventurerIntopacity=500;
        advred=50;
    }
    else{
        AdventurerExtopacity=40;
        AdventurerIntopacity=150;
        advred=40;
    }

    //builder button
    if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height))){
        BuilderExtopacity=120;
        BuilderIntopacity=500;
        bldrred=50;
    }
    else{
        BuilderExtopacity=40;
        BuilderIntopacity=150;
        bldrred=40;
    }

    //single player button
    if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height))){
        SingleExtopacity=120;
        SingleIntopacity=500;
        singred=50;
    }
    else{
        SingleExtopacity=40;
        SingleIntopacity=150;
        singred=40;
    }
    //about button
    if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height))){
        Aboutopacity=40;
    }
    else{
        Aboutopacity=20;
    }

    //options button
    if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))){
        Optionsopacity=40;
    }
    else{
        Optionsopacity=20;
    }

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height))){
        AdventurerExtopacity=200;
        AdventurerIntopacity=500;
        advred=100;
    }
     if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height))){
        BuilderExtopacity=200;
        BuilderIntopacity=500;
        bldrred=100;
    }
     if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height))){
        SingleExtopacity=200;
        SingleIntopacity=500;
        singred=100;
    }
    //about button
    if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height))){
        Aboutopacity=200;
    }

    //options button
    if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))){
        Optionsopacity=200;
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height))){
        AdventurerExtopacity=120;
        AdventurerIntopacity=500;
        advred=50;
    }
    if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height))){
        BuilderExtopacity=120;
        BuilderIntopacity=500;
        bldrred=50;
    }
    if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height))){
        SingleExtopacity=120;
        SingleIntopacity=500;
        singred=50;
    }

    if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height))){
        Aboutopacity=40;
    }

    //options button
    if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))){
        Optionsopacity=40;
    }
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
