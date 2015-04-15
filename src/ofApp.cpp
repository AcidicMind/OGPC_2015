#include "ofApp.h"

void menu::draw(){
        //    if (optionson ==true){
    //        ofSetColor(250,250,250,180);
    //        }
    //        bg.resize(winwidth,winheight);
    //        bg.draw(0,0);

        ofColor colorOne;
        ofColor colorTwo;

        colorOne.set (0, 0, 0,500-allopacity);
        colorTwo.set (255, 100, 50, 500-allopacity);

            ofBackgroundGradient(colorTwo, colorOne, OF_GRADIENT_CIRCULAR);

    //    ofSetColor(230,230,230,10-allopacity);
    //    ofRectRounded(Titlecontainer, 20);

        ofSetColor(180,180,180,containeropacity);
        ofRectRounded(OnePcontainer, 16);

        ofSetColor(180,180,180,containeropacity);
        ofRectRounded(TwoPcontainer, 16);

        ofSetColor(40,40,40,Aboutopacity-allopacity);
        ofRectRounded(About,5);

        ofSetColor(60,60,60,Optionsopacity);
        ofRectRounded(Options,5);


    //----------------------Adventurer option button-------------------------------
        Adventurerext.r= 230;
        Adventurerext.g= 230;
        Adventurerext.b= 230;

        Adventurerint.r= advred;
        Adventurerint.g= 40;
        Adventurerint.b= 40;

        ofSetColor(Adventurerext,AdventurerExtopacity-allopacity);
        ofRectRounded(Adventurer1, 8);                                   //fix the corners

        ofSetColor(Adventurerint,AdventurerIntopacity-allopacity);
        ofRectRounded(Adventurer2, 8);

    //----------------------Builder option button-------------------------------

        Builderext.r= 230;
        Builderext.g= 230;
        Builderext.b= 230;

        Builderint.r= bldrred;
        Builderint.g= 40;
        Builderint.b= 40;

        ofSetColor(Builderext,BuilderExtopacity-allopacity);
        ofRectRounded(Builder1, 8);

        ofSetColor(Builderint,BuilderIntopacity-allopacity);
        ofRectRounded(Builder2, 8);



    //----------------------Single Player option button-------------------------------

        Singleext.r= 230;
        Singleext.g= 230;
        Singleext.b= 230;

        Singleint.r= singred;
        Singleint.g= 40;
        Singleint.b= 40;

        ofSetColor(Singleext,SingleExtopacity-allopacity);
        ofRectRounded(SinglePlayer1, 8);

        ofSetColor(Singleint,SingleIntopacity-allopacity);
        ofRectRounded(SinglePlayer2, 8);


    //----------------------Options button-------------------------------
        if (optionson == true)
        {   if (fxpressed ==true){
            cout<<"true"<<endl;
            }
            else {
                cout<<"flase"<<endl;
            }

            ofSetColor(60,60,60);
            ofRectRounded (Optionsdropdown,2);
            ofSetLineWidth(3);
            ofSetColor(200,200,200);



            smalltextfont.drawString("Sound",(Optionsdropdown.x+.5*Optionsdropdown.width-(.6*smalltextfont.getSize()*2.5)),(Optionsdropdown.y+.15*Optionsdropdown.height+(smalltextfont.getSize()/2)));
            smalltextfont2.drawString("FX",(Optionsdropdown.x+.1*Optionsdropdown.width-(.6*smalltextfont2.getSize()*1)),(Optionsdropdown.y+.25*Optionsdropdown.height+(smalltextfont2.getSize()/2)));
            ofLine(Optionsdropdown.x+Optionsdropdown.width*.2,Optionsdropdown.y+Optionsdropdown.height*.25,Optionsdropdown.x+Optionsdropdown.width*.9,Optionsdropdown.y+Optionsdropdown.height*.25);
            ofRectRounded(fxslider,1);
            // MUSIC NOTE
            ofLine(Optionsdropdown.x+Optionsdropdown.width*.2,Optionsdropdown.y+Optionsdropdown.height*.35,Optionsdropdown.x+Optionsdropdown.width*.9,Optionsdropdown.y+Optionsdropdown.height*.35);
            ofRectRounded(musicslider,1);
            sound.resize(smalltextsize2*1.5, smalltextsize2*1.5);
            sound.draw((Optionsdropdown.x+.1*Optionsdropdown.width-(.5*smalltextsize2*1.5*1)),(Optionsdropdown.y+.45*Optionsdropdown.height-(smalltextsize2*1.5)/2));
            ofLine(Optionsdropdown.x+Optionsdropdown.width*.2,Optionsdropdown.y+Optionsdropdown.height*.45,Optionsdropdown.x+Optionsdropdown.width*.9,Optionsdropdown.y+Optionsdropdown.height*.45);
            ofRectRounded(masterslider,1);

            smalltextfont.drawString("Gender",(Optionsdropdown.x+.5*Optionsdropdown.width-(.6*smalltextfont.getSize()*3)),(Optionsdropdown.y+.6*Optionsdropdown.height+(smalltextfont.getSize()/2)));
             ofSetColor(142,5,255);
            ofRect(Purplegender);
             ofSetColor(255,97,0);
            ofRect(Orangegender);
             ofSetColor(19,86,19);
            ofRect(Greengender);
        }
        else{
            ofSetLineWidth(0);
        }

    //-----------------------------------BUTTON TEXT-------------------------------------------
        ofSetColor(210,210,210);
        titlefont.drawString("PHARAOH",(winwidth/2-.46*titlefont.getSize()*7),(winheight*.08+(titlefont.getSize()/2)));

        textfont.drawString("Single Player",(SinglePlayer2.x+.5*SinglePlayer2.width-(.52*textfont.getSize()*6.5)),(SinglePlayer2.y+.5*SinglePlayer2.height+(textfont.getSize()/2)));

        textfont.drawString("Adventurer",(Adventurer2.x+.5*Adventurer2.width-(.6*textfont.getSize()*5)),(Adventurer2.y+.5*Adventurer2.height+(textfont.getSize()/2)));

        textfont.drawString("Builder",(Builder2.x+.5*Builder2.width-(.52*textfont.getSize()*3.5)),(Builder2.y+.5*Builder2.height+(textfont.getSize()/2)));

        smalltextfont.drawString("About",(About.x+.5*About.width-(.68*smalltextfont.getSize()*2.5)),(About.y+.5*About.height+(smalltextfont.getSize()/2)));

        smalltextfont.drawString("Options",(Options.x+.5*Options.width-(.62*smalltextfont.getSize()*3.5)),(Options.y+.5*Options.height+(smalltextfont.getSize()/2)));


}

void menu::setup(){
            bg.loadImage("water.jpg");
            sound.loadImage("Sound.png");
            mute.loadImage("Mute.png");

            winheight =ofGetWindowHeight();
            winwidth =ofGetWindowWidth();
            LRpadding =winwidth*.05;
            TBpadding =winheight*.05;
            interiorpadding =winwidth/20;
            textsize =(winheight*winwidth)*.000035;
            smalltextsize = (winheight*winwidth)*.000017;
            smalltextsize2 = (winheight*winwidth)*.000012;


            titlefont.loadFont("DALEK___.ttf",winheight/15);
            textfont.loadFont("DIOGENES.ttf",textsize);
            smalltextfont.loadFont("DIOGENES.ttf",smalltextsize);
            smalltextfont2.loadFont("DIOGENES.ttf",smalltextsize2);



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

            Optionsdropdown.x =Options.x-winwidth*.08;
            Optionsdropdown.y =Options.y+Options.height-winheight*.02;
            Optionsdropdown.width =winwidth*.08+Options.width;
            Optionsdropdown.height =winheight*.3;

            Purplegender.x = Optionsdropdown.x+Optionsdropdown.width*.0621;
            Purplegender.y = Orangegender.y = Greengender.y = Optionsdropdown.y+Optionsdropdown.height*.7;
            Purplegender.height = Orangegender.height = Greengender.height = Optionsdropdown.width*.25;
            Purplegender.width = Orangegender.width = Greengender.width = Purplegender.height;

            Orangegender.x = Purplegender.x+Purplegender.width+Optionsdropdown.width*.0621;

            Greengender.x = Orangegender.x+Orangegender.width+Optionsdropdown.width*.0621;

            fxpixels=fxpercent*(Optionsdropdown.width*.5);
            fxslider.width = musicslider.width = masterslider.width = Optionsdropdown.width*.03;
            fxslider.height = musicslider.height = masterslider.height = Optionsdropdown.height*.06;
            fxslider.x = Optionsdropdown.x+Optionsdropdown.width*.2+fxpixels;
            fxslider.y =Optionsdropdown.y+Optionsdropdown.height*.22;

            musicslider.x = Optionsdropdown.x+Optionsdropdown.width*.2+fxpixels;
            musicslider.y =Optionsdropdown.y+Optionsdropdown.height*.32;

            masterslider.x = Optionsdropdown.x+Optionsdropdown.width*.2+fxpixels;
            masterslider.y =Optionsdropdown.y+Optionsdropdown.height*.42;


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

void menu::mouseMoved(int x, int y){


    //-----------------------------HOVER FEATURE------------------------------------------

        //adventurer button
        if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height)) and optionson ==false){
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
        if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height)) and optionson ==false){
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
        if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height)) and optionson ==false){
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
        if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height)) and optionson ==false){
            Aboutopacity=40;
        }
        else{
            Aboutopacity=20;
        }

        //options button
        if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))and optionson ==false){
            Optionsopacity=40;
        }
        else if (optionson ==false){
            Optionsopacity=20;
        }
        else if (optionson ==true){
            Optionsopacity=2000;
        }
}

void menu::mouseDragged(int x, int y, int button){

        if (fxpressed ==true){
                fxslider.x = x-.025*Optionsdropdown.width;
                if (fxslider.x <Optionsdropdown.x+Optionsdropdown.width*.2){
                    fxslider.x =Optionsdropdown.x+Optionsdropdown.width*.2;
                }
                if (fxslider.x >Optionsdropdown.x+Optionsdropdown.width*.9){
                    fxslider.x =Optionsdropdown.x+Optionsdropdown.width*.9;
                }
                fxpixels =fxslider.x-Optionsdropdown.x+Optionsdropdown.width*.2;
                fxpercent = (fxpixels/((Optionsdropdown.x+Optionsdropdown.width*.9)-(Optionsdropdown.x+Optionsdropdown.width*.2)));
            }
        if (musicpressed ==true){
                musicslider.x = x-.025*Optionsdropdown.width;
                if (musicslider.x <Optionsdropdown.x+Optionsdropdown.width*.2){
                    musicslider.x =Optionsdropdown.x+Optionsdropdown.width*.2;
                }
                if (musicslider.x >Optionsdropdown.x+Optionsdropdown.width*.9){
                    musicslider.x =Optionsdropdown.x+Optionsdropdown.width*.9;
                }
                musicpixels =musicslider.x-Optionsdropdown.x+Optionsdropdown.width*.2;
                musicpercent = (musicpixels/((Optionsdropdown.x+Optionsdropdown.width*.9)-(Optionsdropdown.x+Optionsdropdown.width*.2)));
            }
        if (masterpressed ==true){
                masterslider.x = x-.025*Optionsdropdown.width;
                if (masterslider.x <Optionsdropdown.x+Optionsdropdown.width*.2){
                    masterslider.x =Optionsdropdown.x+Optionsdropdown.width*.2;
                }
                if (masterslider.x >Optionsdropdown.x+Optionsdropdown.width*.9){
                    masterslider.x =Optionsdropdown.x+Optionsdropdown.width*.9;
                }
                masterpixels =masterslider.x-Optionsdropdown.x+Optionsdropdown.width*.2;
                masterpercent = (masterpixels/((Optionsdropdown.x+Optionsdropdown.width*.9)-(Optionsdropdown.x+Optionsdropdown.width*.2)));
            }
}

void menu::mousePressed(int x, int y, int button){
        if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height)) and optionson ==false){
            AdventurerExtopacity=200;
            AdventurerIntopacity=500;
            advred=100;
        }
         if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height)) and optionson ==false){
            BuilderExtopacity=200;
            BuilderIntopacity=500;
            bldrred=100;
        }
         if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height)) and optionson ==false){
            SingleExtopacity=200;
            SingleIntopacity=500;
            singred=100;
        }
        //about button
        if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height)) and optionson ==false){
            Aboutopacity=200;
        }
        //options button
        if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height)) and optionson ==false){
            Optionsopacity=2000;
            allopacity=30;
            containeropacity =10;
            optionson =true;
        }
        else if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height)) and optionson ==true){
            Optionsopacity=200;
            allopacity =0;
            containeropacity =20;
            optionson =false;
        }
        //sliders
        //fx slider
        if (optionson ==true and (x>fxslider.x) and (x<(fxslider.x+fxslider.width)) and (y>fxslider.y) and (y<(fxslider.y+fxslider.height))){
                    fxpressed =true;
        }
        else {
                fxpressed =false;
            }

        //music slider
        if ((x>musicslider.x) and (x<(musicslider.x+musicslider.width)) and (y>musicslider.y) and (y<(musicslider.y+musicslider.height))){
            if (optionson ==true){
                    musicpressed =true;
        }
            else {
                musicpressed =false;
        }
        }
        //master slider
        if (optionson ==true and (x>masterslider.x) and (x<(masterslider.x+masterslider.width)) and (y>masterslider.y) and (y<(masterslider.y+masterslider.height))){
            masterpressed =true;
        }
        else {
            masterpressed =false;
        }
}

void menu::mouseReleased(int x, int y, int button){

        if ((x>Adventurer1.x) and (x<(Adventurer1.x+Adventurer1.width)) and (y>Adventurer1.y) and (y<(Adventurer1.y+Adventurer1.height)) and optionson ==false){
            AdventurerExtopacity=120;
            AdventurerIntopacity=500;
            advred=50;
        }
        if ((x>Builder1.x) and (x<(Builder1.x+Builder1.width)) and (y>Builder1.y) and (y<(Builder1.y+Builder1.height)) and optionson ==false){
            BuilderExtopacity=120;
            BuilderIntopacity=500;
            bldrred=50;
        }
        if ((x>SinglePlayer1.x) and (x<(SinglePlayer1.x+SinglePlayer1.width)) and (y>SinglePlayer1.y) and (y<(SinglePlayer1.y+SinglePlayer1.height)) and optionson ==false){
            SingleExtopacity=120;
            SingleIntopacity=500;
            singred=50;
        }

        if ((x>About.x) and (x<(About.x+About.width)) and (y>About.y) and (y<(About.y+About.height)) and optionson ==false){
            Aboutopacity=40;
        }

        //options button
        if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))and (optionson ==true)){
            Optionsopacity=1000;
        }
        else if ((x>Options.x) and (x<(Options.x+Options.width)) and (y>Options.y) and (y<(Options.y+Options.height))and (optionson ==false)){
            Optionsopacity=20;
        }

        if (fxpressed ==true){
            fxpressed =false;
        }
        if (musicpressed ==true){
            musicpressed =false;
        }
        if (masterpressed ==true){
            masterpressed =false;
        }
}












//--------------------------------------------------------------
void ofApp::setup(){
    menu::setup();

}

//--------------------------------------------------------------
void ofApp::update(){



}

//--------------------------------------------------------------
void ofApp::draw(){
    menu draw;

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    menu mouseMoved(int x, int y);

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    menu mouseDragged();

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    menu mousePressed();
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    menu mouseReleased();
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
