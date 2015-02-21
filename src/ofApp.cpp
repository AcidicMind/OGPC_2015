#include "ofApp.h"
#include <math.h>

void statbar::mainbar (int health, int mana, int steps,bool hasKey)
{
    int heartSpacing = 100;
    int manaSpacing = 100;
    ofSetColor(0,0,0);
    ofSetCircleResolution(100);
    ofRect(ofGetScreenWidth()-(ofGetScreenWidth()/16),0,(ofGetScreenWidth()/16),ofGetScreenHeight());
    ofSetColor(255,0,0);
    for(int h = 0; h != health; h++)//draws health icons
    {
        ofSetColor(255,0,0);
        ofCircle(ofGetScreenWidth()-(((ofGetScreenWidth()/16)/3)*2),heartSpacing,10);
        heartSpacing = heartSpacing + 30;
    }
    for(int h = 0; h != mana; h++)//draws mana icons
    {
        ofSetColor(0,255,0);
        ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/3),manaSpacing,10);
        manaSpacing = manaSpacing + 30;
    }
    if (hasKey == true)
    {
        ofSetColor(245,184,0);
        ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/2),300,30);
    }

    //nothing harmful
}
void board::boardDrawer (int key,int moves,bool pressedCheck)
 {

    if (pressedCheck == previousKeyCheck)
    {

        player1.playerController(key,matrix,N);

        if (player1.hasKey == true and player1.variableForGettingRidOfKeySpaceWhenYouCollectIt == 1)
        {
            matrix[player1.playerx][player1.playery] = 1;
            player1.variableForGettingRidOfKeySpaceWhenYouCollectIt--;
        }

        if (previousKeyCheck == true)
        {
            previousKeyCheck = false;
        }
        else if (previousKeyCheck == false)
        {
            previousKeyCheck = true;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {
            if (matrix[i][ii] == 0)
            {
                ofSetColor(184,138,0);//wall
            }
            if (matrix[i][ii] == 1)
            {
                ofSetColor(255,204,51);//floor
            }
            if (matrix[i][ii] == 2)
            {
                ofSetColor(255,102,51);//destructable object
            }
            if (matrix[i][ii] == 3)
            {
                ofSetColor(105,255,51);//key
            }
            if (matrix[i][ii] == 4 and player1.hasKey == true)
            {
                ofSetColor(255,0,0);//exit
            }
            else if (matrix[i][ii] == 4 and player1.hasKey == false)
            {
                ofSetColor(255,204,51);
            }

            //-----------------------------------------------------------------------
            boardExtenderx;
            boardExtedery;
            if (player1.playerx > ((ofGetScreenWidth()-120-(squareSize/2))/(squareSize))/2-1 and (ofGetScreenWidth()-ofGetScreenWidth()/16) < N*(squareSize) and player1.playerx + ((((ofGetScreenWidth()-ofGetScreenWidth()/16-(squareSize/2))/(squareSize))+1)/2) < N)
            {
                boardExtenderx=(player1.playerx-(((ofGetScreenWidth()-ofGetScreenWidth()/16-squareSize/2)/(squareSize))/2))*-1;
            }
            if (player1.playery > (ofGetScreenHeight()/(squareSize))/2-1 and ofGetScreenHeight() < N*(squareSize) and player1.playery + (((ofGetScreenHeight()/(squareSize))-1)/2) < N)
            {
                boardExtedery=(player1.playery-((ofGetScreenHeight()/squareSize)/2))*-1;
            }
            //--------------------------------------------------------------------------------------------------------------------------------------------
            ofRect((i+boardExtenderx)*squareSize + ((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(ii+boardExtedery)*squareSize,squareSize,squareSize);
        }
    }

    //player rectangle

 }
 void board::tileSetup ()
 {
     ofSeedRandom();
     int keyX = ofRandom(N);
     int exitX = ofRandom(N);
     int keyY = ofRandom(N);
     int exitY = ofRandom(N);
    for(size_t i = 0; i < N; ++i)
    {
        Row row(N);
        wallcount = 0;

        for(size_t j = 0; j < N; ++j)
        {
            wallcount--;
            if (wallcount > 0)
            {
                row[j] = 1;
            }
            else
            {
                row[j] = ofRandom(0,3);// Picking a random tile!
            }
            if ((row[j] == 1) and (wallcount < 1))
            {
                //row[j]=1;
                wallcount = 3;
            }
            if (keyX == i and keyY == j)//placing key
            {
                row[j] = 3;
            }
            if (exitX == i and exitY == j)//placing exit
            {
                row[j] = 4;
            }
        }
        matrix.push_back(row); // push each row after you fill it
        level.push_back(row);
    }
    // Once you fill the matrix, you can use it like native arrays
    for(size_t i = 0; i < N; ++i)
    {
        for(size_t j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << " ";
        }

       // cout << endl;
    }
 }
 void player::playerController (int key,Matrix matrix,const size_t N)
 {

     if (((key == 'd') or (key == 'D')) and (playerx < N - 1) and (matrix[playerx + 1][playery] !=0) and (matrix[playerx + 1][playery] != 2))
    {
        if (matrix[playerx + 1][playery] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playerx++;
    }
    if (((key == 'a') or (key == 'A')) and (playerx > 0) and (matrix[playerx - 1][playery] !=0) and (matrix[playerx - 1][playery] != 2))
    {
        if (matrix[playerx - 1][playery] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playerx--;
    }
    if (((key == 'w') or (key == 'W')) and (playery > 0) and (matrix[playerx][playery - 1] != 0) and (matrix[playerx][playery - 1] != 2))
    {
        if (matrix[playerx][playery - 1] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playery--;
    }
    if (((key == 's') or (key == 'S')) and (playery < N - 1) and (matrix[playerx][playery + 1] != 0) and (matrix[playerx][playery + 1] != 2))
    {
        if (matrix[playerx][playery + 1] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playery++;
    }

 }
void Enemy::aiMovement (int key,int playerx,int playery,const size_t N,Matrix matrix,int moves)
 {
     if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd') or (key == 'W') or (key =='A') or (key == 'S') or ( key == 'D'))
     {
         if ((abs(playerx-EnemyX) < 2) and (abs(playery-EnemyY) < 2))
         {
            if (playerx > EnemyX and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0) and (matrix[EnemyX+1][EnemyY] != 2))
            {
                EnemyX++;
            }
            if (playerx < EnemyX and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
            {
                EnemyX--;
            }
            if (playery < EnemyY and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1] != 0) and (matrix[EnemyX][EnemyY-1] != 2))
            {
                EnemyY--;
            }
            if (playery > EnemyY and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
            {
                EnemyY++;
            }
         }
         else
         {
            direction = ofRandom(0,4);
            if ((direction == 0) and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0) and (matrix[EnemyX+1][EnemyY] != 2))
            {
                EnemyX++;
            }
            if ((direction == 1) and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
            {
                EnemyX--;
            }
            if ((direction==2) and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1]!=0) and (matrix[EnemyX][EnemyY-1] != 2))
            {
                EnemyY--;
            }
            if ((direction == 3) and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
            {
                EnemyY++;
            }
         }
     }
     //x++;
 }
void level::Setup()
{
    board1.tileSetup();
    enemies1.setup(board1.N);
}
 void level::gameplay()
{

    board1.boardDrawer(key,moves,pressedCheck);
    enemies1.drawer(board1.boardExtenderx,board1.squareSize,board1.gapSize,board1.boardExtedery);
        ofSetColor(0,0,0);
    ofRect((board1.player1.playerx+board1.boardExtenderx) * (board1.squareSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(board1.player1.playery+board1.boardExtedery) * (board1.squareSize),board1.squareSize,board1.squareSize);
    board1.statbar1.mainbar(board1.player1.health,board1.player1.mana,board1.player1.steps,board1.player1.hasKey);

    if (ofGetScreenHeight() % 60 != 0)//these two if statements are here to make the screen adjust for weird resoluitions
    {
        ofSetColor(0,0,0);
        ofRect(0,ofGetScreenHeight() - (ofGetScreenHeight() % 60),ofGetScreenWidth(),ofGetScreenHeight() % 60);
    }
    if ((ofGetScreenWidth() - (ofGetScreenWidth()/16)) % 60 != 0)
    {
        ofSetColor(0,0,0);
        ofRect(0,0,((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),ofGetScreenHeight());
    }
}
void level::keyPressed(int key)
{
    moves++;
    if (pressedCheck == true)
    {
        pressedCheck = false;
    }
    else if (pressedCheck == false)
    {
        pressedCheck = true;
    }
    enemies1.updater(key,board1.player1.playerx,board1.player1.playery,board1.N,board1.matrix,moves);
}
void level::mousePressed(int x, int y)
{
    if (board1.matrix[x][y] == 2 and board1.player1.mana != 0 and (((board1.player1.playerx+1 == x or board1.player1.playerx-1== x) and (board1.player1.playery == y or board1.player1.playery == y)) or ((board1.player1.playerx == x or board1.player1.playerx== x) and (board1.player1.playery-1 == y or board1.player1.playery+1 == y))))//check if destructable block and then check if the player has mana
    {
        board1.matrix[x][y] = 1;//destroy the destructable block
        board1.player1.mana--;//lose mana when destroyed a block
    }
}
void Enemies::drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery)
{
    ofSetColor(255,99,255);
    for(int i=0; i<enemylist.size(); i++)
    {
        ofRect((enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
    }
}
void Enemies::setup(const size_t N)
{
    for (int k=0; k<9; k++)
    {
        Enemy enemy;
        enemylist.push_back(enemy);
        enemylist[k].EnemyX = ofRandom(0,N);
        enemylist[k].EnemyY = ofRandom(0,N);
    }
}
void Enemies::updater(int key,int playerx,int playery,const size_t N,Matrix matrix,int moves)
{
    ofSeedRandom();
    for(int i=0; i<enemylist.size(); i++)
    {
        enemylist[i].aiMovement(key,playerx,playery,N,matrix,moves);
    }
}
//--------------------------------------------------------------
void ofApp::setup()
{
    level1.Setup();
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    level1.gameplay();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    level1.key = key;
    level1.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    int xCoord = ((x - ((ofGetScreenWidth() - (ofGetScreenWidth()/16)) % 60) ) / level1.board1.squareSize) - level1.board1.boardExtenderx;
    int yCoord = (y / level1.board1.squareSize) - level1.board1.boardExtedery;
    cout << "mousePressed: " << xCoord << ", " << yCoord << " button: " << button << endl;
    level1.mousePressed(xCoord,yCoord);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
