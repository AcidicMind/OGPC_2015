#pragma once
#include "ofMain.h"

class board
{
    public:
    void boardDrawer();
    void tileSetup();
    void playerController();
    int playerx = 0;
    int playery = 0;
    int Previous = 0;
    int wallcount = 0;
    int key = 0; //key pressed
    int keyCount = 0;//number of keys checker -- supposed to be only one
    int exitCount = 0;//number of exits checker -- supposed to be only one
    bool hasKey = false;//do we have the key yet???
    const size_t N = 12; // the dimension of the matrix
    int gapSize = 5;
    int squareSize = 60;
    typedef vector< vector<int> > Matrix;
    typedef vector<int> Row;
    vector<int>wall;
    Matrix matrix;
    Matrix level;
    //Enemy enemy1;
};
//class Enemy
//{
//    public:
//    //board board1;
//    void aiMovement();
//    int direction=0;
//    int EnemyX=9;
//    int EnemyY=9;
//    int health=10;
//};
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
        board board1;
        //Enemy enemy1;
};
