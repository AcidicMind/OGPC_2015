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
    //Renders sprites
    spriteRenderer->clear();
    spriteRenderer->update(ofGetElapsedTimeMillis());

	if(sprites.size()>0)
	{
		for(int i=sprites.size()-1;i>=0;i--)
		{
				spriteRenderer->addCenteredTile(&sprites[i].animation, sprites[i].pos.x, sprites[i].pos.y);
		}
	}

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
            
    sprites.clear(); //Makes sure that the vector does not overload on sprites. This will delete the previous sprites so that there will be room for new ones.
    
    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {

            if (matrix[i][ii] == 0)
            {
                ofSetColor(184,138,0);//wall
            }
            else if (matrix[i][ii] == 1)
            {
                ofSetColor(255,204,51);//floor
            }
            else if (matrix[i][ii] == 2)
            {
                ofSetColor(255,102,51);//destructable object
                dTileSprite newSprite; //Creates a sprite where destructable objects will be
                newSprite.pos.set((i+boardExtenderx) * (squareSize + gapSize) + ((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60) + 30,(ii+boardExtedery) * (squareSize + gapSize) + 30);
                newSprite.animation = walkAnimation;
                sprites.push_back(newSprite);
            }
            else if (matrix[i][ii] == 3)
            {
                ofSetColor(105,255,51);//key
            }
            else if (matrix[i][ii] == 4 and player1.hasKey == true)
            {
                ofSetColor(255,0,0);//exit
            }
            else if (matrix[i][ii] == 4 and player1.hasKey == false)
            {
                ofSetColor(255,204,51);
            }

            //-----------------------------------------------------------------------
            if (((i+boardExtenderx)<ofGetScreenWidth()/squareSize) and ((ii+boardExtedery)<ofGetScreenHeight()/squareSize)and((i+boardExtenderx)>=0) and ((ii+boardExtedery>=0)))
            {

                 ofRect((i+boardExtenderx) * (squareSize + gapSize) + ((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(ii+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
            }
            //--------------------------------------------------------------------------------------------------------------------------------------------

        }
    }
    //ofRect((exitX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(exitY.playery+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
    //exit
    spriteRenderer->draw(); //Draws the sprites

 }
 void board::tileSetup ()
 {
     int keyX = ofRandom(N);
     exitX = ofRandom(N);
     int keyY = ofRandom(N);
     exitY = ofRandom(N);
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
                wallcount = 2;
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
    //for(int i = 0; i < keyX; ++i)
    //{
    //    for(int j = 0; j < keyY; ++j)
    //    {
    //         matrix[i][j]=1;
    //    }
    //}
    int i=0;
    int j=0;
    while ((i<keyX))
    {
        i++;
        //j++;
        //cout<< i<<endl;
        if (i==keyX)
        {
            break;
        }
        if (matrix[i][j]==0)
        {
            matrix[i][j]=1;
        }
        //matrix[i][j+1]=1;
    }
    while ((j<keyY))
    {
        //i++;
        j++;
        //cout<< j<<endl;
        if (j==keyY)
        {
            break;
        }
        if (matrix[i][j]==0)
        {
            matrix[i][j]=1;
        }

    }
    int k=0;
    int l=0;
    while ((k<exitX))
    {
        k++;

        if (k==exitX)
        {
            break;
        }
        if (matrix[k][l]==0)
        {
            matrix[k][l]=1;
        }
    }
    while ((l<exitY))
    {
        l++;
        if (l==exitY)
        {
            break;
        }
        if (matrix[k][l]==0)
        {
            matrix[k][l]=1;
        }
    }
    //Setup for renderer
    spriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    spriteRenderer->loadTexture("spriteSheetExample.png", 256, GL_NEAREST);
    ofEnableAlphaBlending();

 }
 void player::playerController (int key,Matrix matrix,int N)
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
void Enemy::aiMovement (int key,int playerx,int playery,int N,Matrix matrix,int moves)
 {
     if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd') or (key == 'W') or (key =='A') or (key == 'S') or ( key == 'D'))
     {
         if ((abs(playerx-EnemyX) < 2) and (abs(playery-EnemyY) < 2))
         {
            if (playerx > EnemyX and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0) and (matrix[EnemyX+1][EnemyY] != 2))
            {
                EnemyX++;
            }
            else if (playerx < EnemyX and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
            {
                EnemyX--;
            }
            else if (playery < EnemyY and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1] != 0) and (matrix[EnemyX][EnemyY-1] != 2))
            {
                EnemyY--;
            }
            else if (playery > EnemyY and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
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
            else if ((direction == 1) and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
            {
                EnemyX--;
            }
            else if ((direction==2) and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1]!=0) and (matrix[EnemyX][EnemyY-1] != 2))
            {
                EnemyY--;
            }
            else if ((direction == 3) and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
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
void Enemies::setup(int N)
{
    for (int k=0; k<N/5; k++)
    {
        Enemy enemy;
        enemylist.push_back(enemy);
        enemylist[k].EnemyX = ofRandom(0,N);
        enemylist[k].EnemyY = ofRandom(0,N);
    }
}
void Enemies::updater(int key,int playerx,int playery,const int N,Matrix matrix,int moves)
{
    for(int i=0; i<enemylist.size(); i++)
    {
        enemiesX=enemylist[i].EnemyX;
        enemiesY=enemylist[i].EnemyY;
        enemylist[i].aiMovement(key,playerx,playery,N,matrix,moves);
        for (int j=0; j<enemylist.size(); j++)
        {
            if (((enemylist[i].EnemyX==enemylist[j].EnemyX)and(enemylist[i].EnemyY==enemylist[j].EnemyY)and(i!=j))or((enemylist[i].EnemyX==playerx)and(enemylist[i].EnemyY==playery)and(i!=j)))
            {
                enemylist[i].EnemyX=enemiesX;
                enemylist[i].EnemyY=enemiesY;
            }
        }
    }
}
void Game::levelSetup()
{
    for (int k=0; k<levelNumber; k++)
    {
        level Level;
        Level.board1.N=20+k*2;
        Level.Setup();
        levelList.push_back(Level);
    }
    cout <<"setup success";
}
void Game::newLevel()
{
    if ((levelList[currentLevel].board1.exitX==levelList[currentLevel].board1.player1.playerx) and (levelList[currentLevel].board1.exitY==levelList[currentLevel].board1.player1.playery)and(levelList[currentLevel].board1.player1.hasKey == true))
    {
        currentLevel++;
    }

}
//--------------------------------------------------------------
void ofApp::setup()
{
    ofSeedRandom();
    ofSetFrameRate(30);
    game1.levelSetup();
}

//--------------------------------------------------------------
void ofApp::update()
{


}

//--------------------------------------------------------------
void ofApp::draw()
{
    game1.levelList[game1.currentLevel].gameplay();
    //level1.gameplay();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    //if (pressedBool==true)
    //{
        game1.levelList[game1.currentLevel].key = key;
        game1.levelList[game1.currentLevel].keyPressed(key);
        game1.newLevel();
        pressedBool=false;
    //}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
   // pressedBool=true;

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
    int xCoord = ((x - ((ofGetScreenWidth() - (ofGetScreenWidth()/16)) % 60) ) / game1.levelList[game1.currentLevel].board1.squareSize) - game1.levelList[game1.currentLevel].board1.boardExtenderx;
    int yCoord = (y / game1.levelList[game1.currentLevel].board1.squareSize) - game1.levelList[game1.currentLevel].board1.boardExtedery;
    cout << "mousePressed: " << xCoord << ", " << yCoord << " button: " << button << endl;
    game1.levelList[game1.currentLevel].mousePressed(xCoord,yCoord);
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
