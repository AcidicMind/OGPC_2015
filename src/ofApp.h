#pragma once
#include "ofMain.h"

typedef vector< vector<int> > Matrix;
typedef vector<int> Row;

class Enemy
{
public:
    void aiMovement(int key,int playerx,int playery,const size_t N,Matrix matrix,int moves);// typedef not declared yet
    int direction=0;
    int EnemyX=10;
    int EnemyY=10;
    int health=10;
    //int x = 0;
};
class statbar // Display of various information in a corner hovering above the main screen
{
public:
    void mainbar(int health,int mana, int steps,bool hasKey); // function for drawing and updating the statbar's info
};

class player
{
public:
    void playerController(int key,Matrix matrix,const size_t N);
    void playerDrawer();
    int playerx = 0;
    int playery = 0;
    int variableForGettingRidOfKeySpaceWhenYouCollectIt = 0;
    bool hasKey = false;//do we have the key yet???
    int health = 3;
    int steps = 0;
    int mana = 10; //magic power

};

class board
{
public:
    void boardDrawer(/*int playerx,int playery,bool hasKey,*/int key,int moves,bool pressedCheck);
    void tileSetup();
    int wallcount = 0;
    int keyCount = 0;//number of keys checker -- supposed to be only one
    int exitCount = 0;//number of exits checker -- supposed to be only one
    const size_t N = 50; // the dimension of the matrix
    int gapSize = 0;
    int squareSize = 60;
    int boardExtenderx=0;
    int boardExtedery=0;

    bool previousKeyCheck = false;

    vector<int>wall;
    Matrix matrix;
    Matrix level;

    player player1;
    statbar statbar1;
};
class Enemies
{
    public:
    void setup(const size_t N);
    void updater(int key,int playerx,int playery,const size_t N,Matrix matrix,int moves);
    void drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery);
    vector<Enemy> enemylist;

};
class level
{
public:
    void gameplay();
    void Setup();
    void keyPressed(int key);
    void mousePressed(int x, int y);
    int moves = 0;
    int key;
    bool setup=true;
    bool pressedCheck = true;
    board board1;
    Enemies enemies1;

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
    bool pressedbool=true;
    level level1;
};
