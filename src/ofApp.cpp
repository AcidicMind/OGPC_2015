
#include "ofApp.h"
#include <math.h>

void statbar::mainbar (int health, int mana, int steps,bool hasKey)
{
    int heartSpacing = 100;
    int manaSpacing = 100;
    ofSetColor(0,0,0);
    ofSetCircleResolution(100);
    ofRect(ofGetScreenWidth()-120,0,120,ofGetScreenHeight());
    ofSetColor(255,0,0);
    for(int h = 0; h != health; h++)//draws health icons
    {
        ofSetColor(255,0,0);
        ofCircle(ofGetScreenWidth()-80,heartSpacing,10);
        heartSpacing = heartSpacing + 30;
    }
    for(int h = 0; h != mana; h++)//draws mana icons
    {
        ofSetColor(0,255,0);
        ofCircle(ofGetScreenWidth()-40,manaSpacing,10);
        manaSpacing = manaSpacing + 30;
    }
    if (hasKey == true)
    {
        ofSetColor(245,184,0);
        ofCircle(ofGetScreenWidth()-60,300,30);
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
                ofSetColor(184,46,0);//destructable object
            }
            if (matrix[i][ii] == 3)
            {
                ofSetColor(105,255,51);//key
            }
            if (matrix[i][ii] == 4)
            {
                ofSetColor(255,99,51);//exit
            }

            //-----------------------------------------------------------------------
            while ((ofGetScreenWidth()-120)%(squareSize+gapSize) != 0 or ofGetScreenHeight()%(squareSize+gapSize) != 0)
            {
                squareSize++;
            }
            boardExtenderx;
            boardExtedery;
            if (player1.playerx > ((ofGetScreenWidth()-120-(squareSize/2))/(squareSize+gapSize))/2-1 and (ofGetScreenWidth()-120) < N*(squareSize+gapSize) and player1.playerx + (((ofGetScreenWidth()-120-(squareSize/2))/(squareSize+gapSize))/2)+1 < N)
            {
                boardExtenderx=(player1.playerx-(((ofGetScreenWidth()-120-(squareSize/2))/(squareSize+gapSize))/2))*-1;
            }
            if (player1.playery > (ofGetScreenHeight()/(squareSize+gapSize))/2-1 and ofGetScreenHeight() < N*(squareSize+gapSize) and player1.playery + ((ofGetScreenHeight()/(squareSize+gapSize))/2)-1 < N)
            {
                boardExtedery=(player1.playery-((ofGetScreenHeight()/(squareSize+gapSize))/2))*-1;
            }
            //-----------------------------------------------------------------------
            ofRect((i+boardExtenderx) * (squareSize + gapSize),(ii+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
            //-----------------------------------------------------------------------
            //if(matrix[i][ii] == 5)
            //{
             //   if (player1.hasKey == true)
             //   {
            //        ofSetColor(255,255,255);
            //        ofDrawBitmapString("key",(i+boardExtenderx) * (squareSize + gapSize) + (squareSize / 4),(ii+boardExtedery) * (squareSize + gapSize) + (squareSize / 2));
             //   }

            //}
            //-----------------------------------------------------------------------
        }
    }
    ofSetColor(0,0,0);
    ofRect((player1.playerx+boardExtenderx) * (squareSize + gapSize),(player1.playery+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
    statbar1.mainbar(player1.health,player1.mana,player1.steps,player1.hasKey);
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

     if ((key == 'd') and (playerx < N - 1) and (matrix[playerx + 1][playery] !=0))
    {
        if (matrix[playerx + 1][playery] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playerx++;
    }
    if ((key == 'a') and (playerx > 0) and (matrix[playerx - 1][playery] !=0))
    {
        if (matrix[playerx - 1][playery] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playerx--;
    }
    if ((key == 'w') and (playery > 0) and (matrix[playerx][playery - 1] !=0))
    {
        if (matrix[playerx][playery - 1] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        playery--;
    }
    if ((key == 's') and (playery < N - 1) and (matrix[playerx][playery + 1] !=0))
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
     if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd'))
     {
         if ((abs(playerx-EnemyX) < 2) and (abs(playery-EnemyY) < 2))
         {
            if (playerx > EnemyX and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0))
            {
                EnemyX++;
            }
            if (playerx < EnemyX and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0))
            {
                EnemyX--;
            }
            if (playery < EnemyY and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1]!=0))
            {
                EnemyY--;
            }
            if (playery > EnemyY and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0))
            {
                EnemyY++;
            }
         }
         else
         {
            direction = ofRandom(0,4);
            if ((direction == 0) and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0))
            {
                EnemyX++;
            }
            if ((direction == 1) and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0))
            {
                EnemyX--;
            }
            if ((direction==2) and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1]!=0))
            {
                EnemyY--;
            }
            if ((direction == 3) and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0))
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
void Enemies::drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery)
{
    ofSetColor(255,255,255);
    for(int i=0; i<enemylist.size(); i++)
    {
        ofRect((enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
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
        //cout <<"enemy number"<<i<<"X"<<enemylist[i].EnemyX<<"Y"<<enemylist[i].EnemyY<<endl;

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

//---------------------------------------const size_t N-----------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
//    int xCoord = x / (board1.squareSize + board1.gapSize);
//    int yCoord = y / (board1.squareSize + board1.gapSize);
//    cout << "mousePressed: " << xCoord << ", " << yCoord << " button: " << button << endl;

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
