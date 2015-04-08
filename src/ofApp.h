
#pragma once
#include "ofMain.h"
#include "ofxSpriteSheetRenderer.h"

static animation_t blockAnimation =
{	0,	/* index		*/
	0,	/* frame		*/
	1,	/* totalframes	*/
	1,	/* width		*/
	1,	/* height		*/
	100,	/* frameduration*/
	0,	/* nexttick		*/
	-1,	/* loops		*/
	-1,	/* finalindex	*/
	1	/* frameskip	*/
};

struct dTileSprite {
	animation_t animation;
	ofPoint pos;
};

typedef vector< vector<int> > Matrix;
typedef vector<int> Row;
typedef vector<dTileSprite *> tilerow;
class weapon
{
public:

};

class statbar // Display of various information in a corner hovering above the main screen
{
public:
    void mainbar(int health,int mana, int steps,bool hasKey); // function for drawing and updating the statbar's info
};


class Enemy
{
public:
    void aiMovement(int key,int playerx,int playery,int N,Matrix matrix,int moves);// typedef not declared yet
    int Phealth=false;
    int direction=0;
    int EnemyX=10;
    int EnemyY=10;
    int health=2;
    int startFrame=0;
    int endFrame=0;
    int leveltimer=0;
    int enemytimer=0;
};
class board
{
public:
    void boardDrawer(int playerx,int playery,/*bool hasKey,*/int key,int moves,bool pressedCheck);
    void tileSetup();
    int wallcount = 0;
    int keyCount = 0;//number of keys checker -- supposed to be only one
    int exitCount = 0;//number of exits checker -- supposed to be only one
    int N = 50; // the dimension of the matrix
    int gapSize = 0;
    int squareSize = 60;
    int boardExtenderx=0;
    int boardExtedery=0;
    int exitX=0;
    int exitY=0;
    int keyX=0;
    int keyY=0;

    vector<int>wall;
    Matrix matrix;
    //Matrix level;
    statbar statbar1;

    ofxSpriteSheetRenderer * BlockSpriteRenderer;
    vector<vector<dTileSprite *> > sprites;

    int j=0;
    bool mousepressed=false;
    //vector<blocksprite *>
};
class Enemies
{
    public:
    void setup(int N);
    void updater(int key,int playerx,int playery,int N,Matrix matrix,int moves,int health);
    void drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery);
    vector<Enemy> enemylist;
    //bool playerDamaged=false;
    int enemiesX=0;
    int enemiesY=0;

    ofxSpriteSheetRenderer * EnemySpriteRenderer;
    vector<dTileSprite *> sprites;
};
class bomb
{
public:
    void bombTimer();
    int bombX=0;
    int bombY=0;
    int explosionRadius=0;
    int bombTime=0;
};
class player
{
public:
    void playerController(int key,Matrix matrix,int N);
    void attack(vector<Enemy> enemylist,int key);
    void playerDrawer();
    int playerx = 0;
    int playery = 0;
    int variableForGettingRidOfKeySpaceWhenYouCollectIt = 0;
    bool hasKey = false;//do we have the key yet???
    int health = 100;
    int steps = 0;
    int mana = 10; //magic power
    int startFrame=0;
    int endFrame=0;
    int previousKey=0;
    vector <bomb> bombList;
};
class level
{
public:
    void gameplay();
    void updater();
    void Setup();
    void keyPressed(int key);
    void keyReleased(int key);
    void mousePressed(int x, int y);
    int moves = 0;
    int key;
    bool setup=true;
    bool pressedCheck = true;
    bool previousKeyCheck = false;
    board board1;
    Enemies enemies1;
    player player1;
    ofxSpriteSheetRenderer * CharacterSpriteRenderer;
    vector<dTileSprite *> sprite;
    int i=0;
};
class Game
{
public:
    void levelSetup();
    void newLevel();
    int levelNumber=5;
    int currentLevel=0;
    vector<level> levelList;
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
    Game game1;
    bool pressedBool=true;
};
