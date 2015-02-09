#pragma once
#include "ofMain.h"

class board
{
    public:
    //Enemy enemy1;
    int gapSize = 5;
    void boardDrawer();
    void tileSetup();
    void playerController();
    int squareSize = 50;
    int playerx = 0;
    int Previous = 0;
    int playery = 0;
    int wallcount = 0;
    int key = 0; //key pressed
    int keyCount = 0;//number of keys -- supposed to be only one
    typedef vector< vector<int> > Matrix;
    typedef vector<int> Row;
    vector<int>wall;
    const size_t N = 10; // the dimension of the matrix
    Matrix matrix;
    Matrix level;
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
