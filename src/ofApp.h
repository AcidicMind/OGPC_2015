#pragma once
#include "ofMain.h"

typedef vector< vector<int> > Matrix;
typedef vector<int> Row;

class Enemy
{
    public:
    void aiMovement(int key,int playerx,int playery,const size_t N,Matrix matrix);// typedef not declared yet
    void test(int key);
    int direction=0;
    int EnemyX = 9;
    int EnemyY = 9;
    int health=10;
};

class board
{
    public:
    void boardDrawer();
    void tileSetup();
    void playerController(int key);
    int playerx = 0;
    int playery = 0;
    int Previous = 0;
    int PreviousEnemy = 1;
//    int PreviousEnemy2 = 1;
//    int PreviousEnemy3 = 1;
//    int PreviousEnemy4 = 1;
//    int PreviousEnemy5 = 1;
    int wallcount = 0;
    //int key = 0; //key pressed
    int keyCount = 0;//number of keys checker -- supposed to be only one
    int exitCount = 0;//number of exits checker -- supposed to be only one
    bool hasKey = false;//do we have the key yet???
    int keyCheckIfItHasIt = 0;
    const size_t N = 12; // the dimension of the matrix
    int gapSize = 5;
    int squareSize = 60;
    vector<int>wall;
    Matrix matrix;
    Matrix level;
    Enemy enemy1;
//    Enemy enemy2;
//    Enemy enemy3;
//    Enemy enemy4;
//    Enemy enemy5;
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
        board board1;
};
