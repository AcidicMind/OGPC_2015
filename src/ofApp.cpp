
#include "ofApp.h"
#include <math.h>

void statbar::mainbar (int health, int mana, int steps,bool hasKey)
{
    //int heartSpacing = 100;
    int manaSpacing = 100;
    ofSetColor(0,0,0);
    ofSetCircleResolution(100);
    ofRect(ofGetScreenWidth()-(ofGetScreenWidth()/16),0,(ofGetScreenWidth()/16),ofGetScreenHeight());
    ofSetColor(255,0,0);
    ofRect((ofGetScreenWidth()-(((ofGetScreenWidth()/16)/3)*3)),100,20,health);
//    for(int h = 0; h != health; h++)//draws health icons
//    {
//        ofSetColor(255,0,0);
//        ofCircle(ofGetScreenWidth()-(((ofGetScreenWidth()/16)/3)*2),heartSpacing,10);
//        heartSpacing = heartSpacing + 30;
//    }
    for(int h = 0; h != mana; h++)//draws mana icons
    {
        ofSetColor(0,255,0);
        ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/3),manaSpacing,10);
        manaSpacing = manaSpacing + 30;
    }
    if (hasKey == true)
    {
        ofSetColor(245,184,0);
        ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/2),manaSpacing+30,30);
    }

    //nothing harmful
}
void board::boardDrawer (int key,int moves,bool pressedCheck)
 {
    //Renders sprites
    BlockSpriteRenderer->clear();
    BlockSpriteRenderer->update(ofGetElapsedTimeMillis());
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

    //sprites.clear(); //Makes sure that the vector does not overload on sprites. This will delete the previous sprites so that there will be room for new ones.
    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {

              BlockSpriteRenderer->addCenteredTile(&sprites[i][ii]->animation,((i+boardExtenderx) * (squareSize + gapSize) + ((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60) + 30),(((ii+boardExtedery) * (squareSize + gapSize) + 30)));
        }
    }
    BlockSpriteRenderer->draw(); //Draws the sprites
 }
 void board::tileSetup ()
 {
     keyX = ofRandom(N);
     exitX = ofRandom(N);
     keyY = ofRandom(N);
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
        //level.push_back(row);
    }
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
    BlockSpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    BlockSpriteRenderer->loadTexture("Block_Sheet.png", 180, GL_NEAREST);
    ofEnableAlphaBlending();
    for (int i = 0; i < N; i++)
    {
        tilerow row(N);
        for (int ii = 0; ii < N; ii++)
        {

            dTileSprite * blockSprite = new dTileSprite();//Creates a sprite where wall blocks will be
            //blockSprite->pos.set((i+boardExtenderx) * (squareSize + gapSize) + ((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60) + 30,(ii+boardExtedery) * (squareSize + gapSize) + 30); //set its position
            blockSprite->animation = blockAnimation;
            if (matrix[i][ii] == 0)
            {
                //wall
                blockSprite->animation.frame = 0;

            }
            else if (matrix[i][ii] == 1)
            {
                //floor
                blockSprite->animation.frame = 1;
            }
            else if (matrix[i][ii] == 2)
            {
                //destructable block
                blockSprite->animation.frame = 2;
            }
            else if (matrix[i][ii] == 3)
            {
                //key
                blockSprite->animation.frame = 5;
            }
            row[ii]=blockSprite;
            //tilerow.push_back(blockSprite); //add our sprite to the vector
        }
        sprites.push_back(row);
    }
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
        startFrame=4;
        endFrame=6;
        playerx++;
        //startFrame=0;
        //endFrame=2;
    }
    if (((key == 'a') or (key == 'A')) and (playerx > 0) and (matrix[playerx - 1][playery] !=0) and (matrix[playerx - 1][playery] != 2))
    {
        if (matrix[playerx - 1][playery] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        startFrame=8;
        endFrame=10;
        playerx--;
        //startFrame=3;
        //endFrame=5;
    }
    if (((key == 'w') or (key == 'W')) and (playery > 0) and (matrix[playerx][playery - 1] != 0) and (matrix[playerx][playery - 1] != 2))
    {
        if (matrix[playerx][playery - 1] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        startFrame=12;
        endFrame=14;
        playery--;
        //startFrame=6;
        //endFrame=8;
    }
    if (((key == 's') or (key == 'S')) and (playery < N - 1) and (matrix[playerx][playery + 1] != 0) and (matrix[playerx][playery + 1] != 2))
    {
        if (matrix[playerx][playery + 1] == 3 and hasKey == false)
        {
            hasKey = true;
            variableForGettingRidOfKeySpaceWhenYouCollectIt++;
        }
        startFrame=0;
        endFrame=2;
        playery++;
        //startFrame=9;
        //endFrame=11;
    }

 }
void Enemy::aiMovement (int key,int playerx,int playery,int N,Matrix matrix,int moves)
 {
     if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd') or (key == 'W') or (key =='A') or (key == 'S') or ( key == 'D'))
     {
         if ((abs(playerx-EnemyX) < 3) and (abs(playery-EnemyY) < 3))
         {
            if (playerx > EnemyX and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0) and (matrix[EnemyX+1][EnemyY] != 2))
            {
                startFrame=4;
                endFrame=6;
                EnemyX++;
            }
            else if (playerx < EnemyX and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
            {
                startFrame=8;
                endFrame=10;
                EnemyX--;
            }
            else if (playery < EnemyY and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1] != 0) and (matrix[EnemyX][EnemyY-1] != 2))
            {
                startFrame=12;
                endFrame=14;
                EnemyY--;
            }
            else if (playery > EnemyY and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
            {
                startFrame=0;
                endFrame=2;
                EnemyY++;
            }
         }
         else
         {
            for (int i=0; i<4; i++)
            {
                direction = ofRandom(0,4);
                if ((direction == 0) and (EnemyX<N-1) and (matrix[EnemyX+1][EnemyY] != 0) and (matrix[EnemyX+1][EnemyY] != 2))
                {
                    startFrame=4;
                    endFrame=6;
                    EnemyX++;
                    break;
                }
                else if ((direction == 1) and (EnemyX > 0) and (matrix[EnemyX-1][EnemyY]!=0) and (matrix[EnemyX-1][EnemyY] != 2))
                {
                    startFrame=8;
                    endFrame=10;
                    EnemyX--;
                    break;
                }
                else if ((direction==2) and (EnemyY > 0) and (matrix[EnemyX][EnemyY-1]!=0) and (matrix[EnemyX][EnemyY-1] != 2))
                {
                    startFrame=12;
                    endFrame=14;
                    EnemyY--;
                    break;
                }
                else if ((direction == 3) and (EnemyY < N-1) and (matrix[EnemyX][EnemyY+1] != 0) and (matrix[EnemyX][EnemyY+1] != 2))
                {
                    startFrame=0;
                    endFrame=2;
                    EnemyY++;
                    break;
                }
            }
         }
     }
     //x++;
 }
void level::Setup()
{
    CharacterSpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    CharacterSpriteRenderer->loadTexture("Mummy_Sprite_Sheet.png", 240, GL_NEAREST);
    //dTileSprite * mummySprite = sprite;//Creates a sprite where the exit will be

    dTileSprite * mummySprite = new dTileSprite();//Creates a sprite where the exit will be
    mummySprite->animation = blockAnimation;
    //blockAnimation.frame = 3;
    //mummySprite->animation.frame_skip = 1;

    mummySprite->animation.index = 4;
    mummySprite->animation.final_index = 6;
    mummySprite->animation.total_frames = 3;

    sprite.push_back(mummySprite); //add our sprite to the vector/


    ofEnableAlphaBlending();
    board1.tileSetup();
    enemies1.setup(board1.N);
}
 void level::gameplay()
{

    CharacterSpriteRenderer->clear();
    CharacterSpriteRenderer->update(ofGetElapsedTimeMillis());


    board1.boardDrawer(key,moves,pressedCheck);
    enemies1.drawer(board1.boardExtenderx,board1.squareSize,board1.gapSize,board1.boardExtedery);

    //if (board1.player1.startFrame<=board1.player1.endFrame)
    //{
    //    board1.player1.startFrame++;
    //}
    //sprite[0]->animation.frame = board1.player1.startFrame;
    sprite[0]->animation.index = board1.player1.startFrame;
    sprite[0]->animation.final_index = board1.player1.endFrame;
    CharacterSpriteRenderer->addTile(&sprite[0]->animation,(board1.player1.playerx+board1.boardExtenderx) * (board1.squareSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(board1.player1.playery+board1.boardExtedery) * (board1.squareSize));


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


    CharacterSpriteRenderer->draw(); //Draws the sprites
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
    if (board1.player1.hasKey == true)
    {
        //open door
        board1.sprites[board1.exitX][board1.exitY]->animation.frame = 3;
        board1.sprites[board1.keyX][board1.keyY]->animation.frame = 1;
    }
    else if (board1.player1.hasKey == false)
    {
        //closed door
        board1.sprites[board1.exitX][board1.exitY]->animation.frame = 4;
        board1.sprites[board1.keyX][board1.keyY]->animation.frame = 5;
    }
    enemies1.updater(key,board1.player1.playerx,board1.player1.playery,board1.N,board1.matrix,moves,board1.player1.health);
    if (enemies1.playerDamaged==true)
    {
        board1.player1.health--;
        enemies1.playerDamaged=false;
    }



}
void level::mousePressed(int x, int y)
{
    if (board1.matrix[x][y] == 2 and board1.player1.mana != 0 and (((board1.player1.playerx+1 == x or board1.player1.playerx-1== x) and (board1.player1.playery == y or board1.player1.playery == y)) or ((board1.player1.playerx == x or board1.player1.playerx== x) and (board1.player1.playery-1 == y or board1.player1.playery+1 == y))))//check if destructable block and then check if the player has mana
    {
        board1.matrix[x][y] = 1;//destroy the destructable block
        board1.player1.mana--;//lose mana when destroyed a block
        board1.sprites[x][y]->animation.frame = 1;
    }
}
void Enemies::drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery)
{
    EnemySpriteRenderer->clear();
    EnemySpriteRenderer->update(ofGetElapsedTimeMillis());
    //ofSetColor(255,99,255);
    for(int i=0; i<enemylist.size(); i++)
    {
        sprites[i]->animation.index = enemylist[i].startFrame;
        sprites[i]->animation.final_index = enemylist[i].endFrame;
        EnemySpriteRenderer->addTile(&sprites[i]->animation,(enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize));
        //ofRect((enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize),squareSize,squareSize);
    }
    EnemySpriteRenderer->draw();
}
void Enemies::setup(int N)
{
    EnemySpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    EnemySpriteRenderer->loadTexture("Scarab_Sheet.png", 240, GL_NEAREST);
    //dTileSprite * mummySprite = sprite;//Creates a sprite where the exit will be

    ofEnableAlphaBlending();

    for (int k=0; k<N/5+5; k++)
    {
        Enemy enemy;
        enemylist.push_back(enemy);
        enemylist[k].EnemyX = ofRandom(0,N);
        enemylist[k].EnemyY = ofRandom(0,N);

        dTileSprite * enemySprite = new dTileSprite();
        enemySprite->animation = blockAnimation;
        enemySprite->animation.index = 4;
        enemySprite->animation.final_index = 6;
        enemySprite->animation.total_frames = 3;
        sprites.push_back(enemySprite); //add our sprite to the vector/
    }
}
void Enemies::updater(int key,int playerx,int playery,const int N,Matrix matrix,int moves,int health)
{
    for(int i=0; i<enemylist.size(); i++)
    {
        enemiesX=enemylist[i].EnemyX;
        enemiesY=enemylist[i].EnemyY;
        enemylist[i].aiMovement(key,playerx,playery,N,matrix,moves);
        for (int j=0; j<enemylist.size(); j++)
        {
            if ((enemylist[i].EnemyX==enemylist[j].EnemyX)and(enemylist[i].EnemyY==enemylist[j].EnemyY)and(i!=j))
            {
                enemylist[i].EnemyX=enemiesX;
                enemylist[i].EnemyY=enemiesY;
            }
            if ((enemylist[i].EnemyX==playerx)and(enemylist[i].EnemyY==playery)and(i!=j))
            {
                enemylist[i].EnemyX=enemiesX;
                enemylist[i].EnemyY=enemiesY;
                if (health>0)
                {
                    playerDamaged=true;
                }
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
        levelList[currentLevel].board1.sprites.clear();
        levelList[currentLevel].sprite.clear();
        levelList[currentLevel].enemies1.sprites.clear();
        currentLevel++;
        //levelList.pop_back();
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
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
        game1.levelList[game1.currentLevel].key = key;
        game1.levelList[game1.currentLevel].keyPressed(key);
        game1.newLevel();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
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
