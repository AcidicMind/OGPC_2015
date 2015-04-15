
#include "ofApp.h"
void soundTrackPlayer::musicSetup()
{
    bossTheme.setVolume(.9f);
    mainTheme.setVolume(.9f);
    //mainTheme.setLoop(true);
    bossTheme.loadSound("Boss Music 1.mp3");
    mainTheme.loadSound("Ben song A.mp3");
    //Add sound trakcs here
}

void soundTrackPlayer::musicSelection(int tNumber)
{
    if(currentTrack != tNumber)
    {
        cout << " " << endl;
        cout << "Music Change: ";
        if(tNumber == 1)
        {
            if (bossTheme.getIsPlaying() == true) {
                bossTheme.stop();
            }
            cout << "Track 1" << endl;
            mainTheme.play();
           // mainTheme.setLoop();
        }
        if(tNumber == 2)
        {
            if (mainTheme.getIsPlaying() == true) {
                mainTheme.stop();
            }
            bossTheme.play();
            //bossTheme.setLoop();
            cout << "Track 2" << endl;
        }

        //Add sound tracks here

        currentTrack = tNumber;
    }
    mainTheme.play();
}

void statbar::mainBarSetup()
{
    damageNoise.setVolume(0.05f);
    magicNoise.setVolume(0.05f);
    pickUpNoise.setVolume(0.05f);
    magicNoise.loadSound("Randomize2.WAV");
    damageNoise.loadSound("Randomize2.WAV");
    pickUpNoise.loadSound("Pickup_Coin.WAV");

    statBarSpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 45);
    statBarSpriteRenderer->loadTexture("Ankh.png", 180, GL_NEAREST);
    ofEnableAlphaBlending();

    barEnd.loadImage("scrollend.png");
    barEndLow.loadImage("scrollendupsidedown.png");
    barMid.loadImage("scrollmid.png");
}
void statbar::mainbar (int health, int mana, int steps,bool hasKey)
{
    if(onceDraw == 1)
    {
        ofSetColor(255,255,255);
        barMid.draw(ofGetScreenWidth()-(ofGetScreenWidth()/9.45),0);
        barEnd.draw(ofGetScreenWidth()-(ofGetScreenWidth()/9),-20);
        barEndLow.draw(ofGetScreenWidth()-(ofGetScreenWidth()/9),(ofGetScreenHeight())-110);
    }

    //int heartSpacing = 100;
    int manaSpacing = 100;
    ofSetColor(0,0,0);
    //ofSetCircleResolution(100);
    //ofRect(ofGetScreenWidth()-(ofGetScreenWidth()/16),0,(ofGetScreenWidth()/16),ofGetScreenHeight());
    //ofSetColor(255,0,0);
    //ofRect((ofGetScreenWidth()-(((ofGetScreenWidth()/16)/3)*3)),100,20,health);
    for(int h = 0; h != health; h++)//draws health icons
    {
        if(health != healthLossCheck)
        {
            damageNoise.play();
            healthLossCheck = health;
        }
        ofSetColor(255,0,0);
        ofCircle(ofGetScreenWidth()-(((ofGetScreenWidth()/9)/3)*2),manaSpacing + 40,10);
        manaSpacing = manaSpacing + 30;
    }
    manaSpacing = 100;
    for(int h = 0; h != mana; h++)//draws mana icons
    {
        if(mana != manaLossCheck)
        {
            magicNoise.play();
            manaLossCheck = mana;
        }
        //ofSetColor(0,255,0);
        //ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/3),manaSpacing,10);
        manaSpacing = manaSpacing + 50;

        dTileSprite * manaSprite = new dTileSprite();
        manaSprite->animation = blockAnimation;
        manaSprite->animation.frame = 0;
        manaSprite->pos.set(ofGetScreenWidth()-((ofGetScreenWidth()/14)/3), manaSpacing);
        sprites.push_back(manaSprite);
    }

    if (hasKey == true)
    {
        if(keyCheck == 0)
        {
            pickUpNoise.play();
            keyCheck = 1;
        }
        ofSetColor(245,184,0);
        ofCircle(ofGetScreenWidth()-((ofGetScreenWidth()/16)/2),manaSpacing+30,30);
    }

    statBarSpriteRenderer->clear();
    statBarSpriteRenderer->update(ofGetElapsedTimeMillis());

    for (int i = 0; i != mana; i++)
    {

        statBarSpriteRenderer->addCenteredTile(&sprites[i]->animation, sprites[i]->pos.x, sprites[i]->pos.y);
    }

    statBarSpriteRenderer->draw(); //Draws the sprites
}

void board::boardDrawer (int playerx,int playery, int key,int moves,bool pressedCheck)
 {
    //Renders sprites
    BlockSpriteRenderer->clear();
    BlockSpriteRenderer->update(ofGetElapsedTimeMillis());
            boardExtenderx;
            boardExtedery;
            if (playerx > ((ofGetScreenWidth()-120-(squareSize/2))/(squareSize))/2-1 and (ofGetScreenWidth()-ofGetScreenWidth()/16) < N*(squareSize) and playerx + ((((ofGetScreenWidth()-ofGetScreenWidth()/16-(squareSize/2))/(squareSize))+1)/2) < N)
            {
                boardExtenderx=(playerx-(((ofGetScreenWidth()-ofGetScreenWidth()/16-squareSize/2)/(squareSize))/2))*-1;
            }
            if (playery > (ofGetScreenHeight()/(squareSize))/2-1 and ofGetScreenHeight() < N*(squareSize) and playery + (((ofGetScreenHeight()/(squareSize))-1)/2) < N)
            {
                boardExtedery=(playery-((ofGetScreenHeight()/squareSize)/2))*-1;
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
        //level.push_back(row);/
    }
    matrix[0][0]=1;
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
    statbar1.mainBarSetup();
 }
 void player::bombSpriteSetup()
 {
     ExplosionSpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 45);
     ExplosionSpriteRenderer->loadTexture("Explosion_Sheet.png", 180, GL_NEAREST);
 }
 void bomb::bombTimer(Matrix matrix)
 {
     cout<<bombTime-ofGetElapsedTimef()<<endl;
     if((bombTime-ofGetElapsedTimef())<=0)
     {
         cout<<"blagsgs"<<endl;
         bombTimeUp=true;
     }
 }
 void player::bombDrawer(Matrix matrix,int boardExtenderx,int squareSize,int gapSize,int boardExtedery)
 {
     for (int i=0; i < bombList.size(); i++)
     {
         if (bombList[i].bombTimeUp==true)
         {
                //for (int ii=0; ii<5; ii++)
                //{
                //    dTileSprite * blockSprite = new dTileSprite();//Creates a sprite where wall blocks will be
                //    blockSprite->animation = blockAnimation;
                //}
                //BlockSpriteRenderer->clear();
                //BlockSpriteRenderer->update(ofGetElapsedTimeMillis());
                if(bombList[i].explosionTime==5)
                {
                    bombList.erase(bombList.begin()+i);
                }
                else
                {
                    bombList[i].explosionTime++;
                    ofRect((bombList[i].bombX+1+boardExtenderx) * (squareSize+gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(bombList[i].bombY+boardExtedery) * (squareSize + gapSize),60,60);
                    ofRect((bombList[i].bombX-1+boardExtenderx) * (squareSize+gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(bombList[i].bombY+boardExtedery) * (squareSize + gapSize),60,60);
                    ofRect((bombList[i].bombX+boardExtenderx) * (squareSize+gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(bombList[i].bombY+1+boardExtedery) * (squareSize + gapSize),60,60);
                    ofRect((bombList[i].bombX+boardExtenderx) * (squareSize+gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(bombList[i].bombY-1+boardExtedery) * (squareSize + gapSize),60,60);
                }
         }
     }

 }
 void player::attack(vector<Enemy> enemylist,int key,Matrix matrix)
 {
    if(key==' ')
    {
        if (attackChoice==0)
        {
            bomb bomb1;
            bomb1.bombX=playerx;
            bomb1.bombY=playery;
            bomb1.bombTime=ofGetElapsedTimef()+3;
            bombList.push_back(bomb1);
            cout <<bombList.size();
        }
         else if(attackChoice==1)
         {
             if (previousKey == 0)// d
             {
//                    cout <<"blah"<<endl;
//                   bomb1.bombX=playerx+1;
//                   bomb1.bombY=playery;
                 for (int i=0; i<enemylist.size(); i++)
                 {
                     if ((playery==enemylist[i].EnemyY)and((enemylist[i].EnemyX-playerx)>0))
                     {
                         cout<<"dHit"<<endl;
                     }
                 }
             }
             else if (previousKey == 2)//w
             {
//                  cout <<"blah"<<endl;
//                   bomb1.bombX=playerx;
//                   bomb1.bombY=playery-1;
                 for (int i=0; i<enemylist.size(); i++)
                 {
                     if ((playerx==enemylist[i].EnemyX)and((enemylist[i].EnemyY-playery)<0))
                     {
                         cout<<"wHit"<<endl;
                     }
                 }
             }
             else if (previousKey == 1)//a
             {
//                  cout <<"blah"<<endl;
//                   bomb1.bombX=playerx-1;
//                   bomb1.bombY=playery;
                 for (int i=0; i<enemylist.size(); i++)
                 {
                     if ((playery==enemylist[i].EnemyY)and((enemylist[i].EnemyX-playerx)<0))
                     {
                         cout<<"aHit"<<endl;
                     }
                 }
             }
             else if (previousKey == 3)//s
             {
//                  cout <<"blah"<<endl;
//                   bomb1.bombX=playerx;
//                   bomb1.bombY=playery+1;
                 for (int i=0; i<enemylist.size(); i++)
                 {
                     if ((playerx==enemylist[i].EnemyX)and((enemylist[i].EnemyY-playery)>0))
                     {
                         cout<<"sHit"<<endl;
                     }
                 }
             }
         }
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
        playerx++;
    }
    if ((key == 'd') or (key == 'D'))
    {
        previousKey=0;
        startFrame=5;
        endFrame=7;
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
    if ((key == 'a') or (key == 'A'))
    {
        previousKey=1;
        startFrame=10;
        endFrame=12;
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
    if ((key == 'w') or (key == 'W'))
    {
        previousKey=2;
        startFrame=15;
        endFrame=17;
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
    if ((key == 's') or (key == 'S'))
    {
        previousKey=3;
        startFrame=0;
        endFrame=2;
    }
}
void Enemy::aiMovement (int key,int playerx,int playery,int N,Matrix matrix,int moves)
 {
     //if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd') or (key == 'W') or (key =='A') or (key == 'S') or ( key == 'D'))
     if(enemytimer<(ofGetElapsedTimeMillis()/300))
     {
         enemytimer++;
         if (((abs(playerx-EnemyX) <= 1) and (abs(playery-EnemyY) < 1))or((abs(playerx-EnemyX) < 1) and (abs(playery-EnemyY) <= 1)))
         {
             Phealth=true;
         }
         else if ((abs(playerx-EnemyX) < 3) and (abs(playery-EnemyY) < 3))
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
 }
void level::Setup()
{
    CharacterSpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    CharacterSpriteRenderer->loadTexture("Purple_Mummy_Sheet.png", 300, GL_NEAREST);

    dTileSprite * mummySprite = new dTileSprite();//Creates a sprite where the exit will be
    mummySprite->animation = blockAnimation;

    mummySprite->animation.index = 20;
    mummySprite->animation.final_index = 21;
    mummySprite->animation.total_frames = 3;

    sprite.push_back(mummySprite); //add our sprite to the vector/

    ofEnableAlphaBlending();
    board1.tileSetup();
    enemies1.setup(board1.N);
    soundTrackPlayer1.musicSetup();

}
 void level::gameplay()
{
    CharacterSpriteRenderer->clear();
    CharacterSpriteRenderer->update(ofGetElapsedTimeMillis());

    board1.boardDrawer(player1.playerx,player1.playery,key,moves,pressedCheck);
    enemies1.drawer(board1.boardExtenderx,board1.squareSize,board1.gapSize,board1.boardExtedery);
    player1.bombDrawer(board1.matrix,board1.boardExtenderx,board1.squareSize,board1.gapSize,board1.boardExtedery);
    sprite[0]->animation.index = player1.startFrame;
    sprite[0]->animation.final_index = player1.endFrame;

    CharacterSpriteRenderer->addTile(&sprite[0]->animation,(player1.playerx+board1.boardExtenderx) * (board1.squareSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(player1.playery+board1.boardExtedery) * (board1.squareSize));

    board1.statbar1.mainbar(player1.health,player1.mana,player1.steps,player1.hasKey);

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
    sprite[0]->animation.total_frames = 3;
    player1.playerController(key,board1.matrix,board1.N);
    player1.attack(enemies1.enemylist,key,board1.matrix);
    if (player1.hasKey == true and player1.variableForGettingRidOfKeySpaceWhenYouCollectIt == 1)
    {
        board1.matrix[player1.playerx][player1.playery] = 1;
        player1.variableForGettingRidOfKeySpaceWhenYouCollectIt--;
    }
    if (player1.hasKey == true)
    {
        //open door
        board1.sprites[board1.exitX][board1.exitY]->animation.frame = 3;
        board1.sprites[board1.keyX][board1.keyY]->animation.frame = 1;
    }
    else if (player1.hasKey == false)
    {
        //closed door
        board1.sprites[board1.exitX][board1.exitY]->animation.frame = 4;
        board1.sprites[board1.keyX][board1.keyY]->animation.frame = 5;
    }
     keyTime=ofGetElapsedTimef()+3;
}
void level::keyReleased(int key)
{

}
void level::mousePressed(int x, int y)
{
    if (board1.matrix[x][y] == 2 and player1.mana != 0 and (((player1.playerx+1 == x or player1.playerx-1== x) and (player1.playery == y or player1.playery == y)) or ((player1.playerx == x or player1.playerx== x) and (player1.playery-1 == y or player1.playery+1 == y))))//check if destructable block and then check if the player has mana
    {
        board1.matrix[x][y] = 1;//destroy the destructable block
        player1.mana--;//lose mana when destroyed a block
        board1.sprites[x][y]->animation.frame = 1;
    }

    for (int i=0; i<enemies1.enemylist.size(); i++)
    {
        if ((x==enemies1.enemylist[i].EnemyX)and(y==enemies1.enemylist[i].EnemyY))
        {
            player1.mana--;
            enemies1.enemylist[i].health=0;
            //enemies1.enemylist.erase(enemies1.enemylist.begin()+i);
        }
    }
}
void level::updater()
{
    //board1.player1.health=
    for (int i=0; i<enemies1.enemylist.size(); i++)
    {
        if (enemies1.enemylist[i].Phealth==true)
        {
            if (player1.health>0)
            {
                player1.health--;
                //break;
            }
            enemies1.enemylist[i].Phealth=false;
        }
    }
    enemies1.updater(key,player1.playerx,player1.playery,board1.N,board1.matrix,moves,player1.health);
    for(int i=0; i<player1.bombList.size(); i++)
    {
        player1.bombList[i].bombTimer(board1.matrix);
         if (player1.bombList[i].bombTimeUp==true)
         {
             if (board1.matrix[player1.bombList[i].bombX+1][player1.bombList[i].bombY]==2)
             {
                board1.matrix[player1.bombList[i].bombX+1][player1.bombList[i].bombY]=1;
             }
             if (board1.matrix[player1.bombList[i].bombX-1][player1.bombList[i].bombY]==2)
             {
                board1.matrix[player1.bombList[i].bombX-1][player1.bombList[i].bombY]=1;
             }
             if (board1.matrix[player1.bombList[i].bombX][player1.bombList[i].bombY+1]==2)
             {
                board1.matrix[player1.bombList[i].bombX][player1.bombList[i].bombY+1]=1;
             }
             if (board1.matrix[player1.bombList[i].bombX][player1.bombList[i].bombY-1]==2)
             {
                board1.matrix[player1.bombList[i].bombX][player1.bombList[i].bombY-1]=1;
             }
         }
    }
    if((keyTime-ofGetElapsedTimef())<=0)
     {
         //sprite[0]->animation.frame=1;
         sprite[0]->animation.total_frames = 2;
         player1.startFrame=20;
         player1.endFrame = 21;
     }
     soundTrackPlayer1.musicSelection(mTrack); //plays the background music
}
void Enemies::drawer(int boardExtenderx,int squareSize,int gapSize,int boardExtedery)
{
    EnemySpriteRenderer->clear();
    EnemySpriteRenderer->update(ofGetElapsedTimeMillis());

    for(int i=0; i<enemylist.size(); i++)
    {
        sprites[i]->animation.index = enemylist[i].startFrame;
        sprites[i]->animation.final_index = enemylist[i].endFrame;
        EnemySpriteRenderer->addTile(&sprites[i]->animation,(enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize));
        ofSetColor(225,0,0);
        ofRect((enemylist[i].EnemyX+boardExtenderx) * (squareSize + gapSize)+((ofGetScreenWidth()-(ofGetScreenWidth()/16))%60),(enemylist[i].EnemyY+boardExtedery) * (squareSize + gapSize),10,enemylist[i].health*10);
    }
    EnemySpriteRenderer->draw();
}
void Enemies::setup(int N)
{
    EnemySpriteRenderer = new ofxSpriteSheetRenderer(1, 1000, 0, 60);
    EnemySpriteRenderer->loadTexture("Scarab_Sheet.png", 240, GL_NEAREST);

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
        if(enemylist[i].health==0)
        {
            enemylist.erase(enemylist.begin()+i);
        }
        for (int j=0; j<enemylist.size(); j++)
        {
            if ((enemylist[i].EnemyX==enemylist[j].EnemyX)and(enemylist[i].EnemyY==enemylist[j].EnemyY)and(i!=j))
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
        Level.board1.N=30;//k*2;
        Level.Setup();
        levelList.push_back(Level);
    }
    cout <<"setup success";
}
void Game::newLevel()
{
    if ((levelList[currentLevel].board1.exitX==levelList[currentLevel].player1.playerx) and (levelList[currentLevel].board1.exitY==levelList[currentLevel].player1.playery)and(levelList[currentLevel].player1.hasKey == true))
    {
          levelList.erase(levelList.begin()+currentLevel);
          cout<<levelList.size()<<endl;
//        levelList[currentLevel].board1.sprites.clear();
//        levelList[currentLevel].sprite.clear();
//        levelList[currentLevel].enemies1.sprites.clear();
        //currentLevel++;
        for (int i=0; i<levelList[currentLevel].enemies1.enemylist.size(); i++)
        {
            levelList[currentLevel].enemies1.enemylist[i].enemytimer=ofGetElapsedTimeMillis()/300;
        }
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
{game1.levelList[game1.currentLevel].updater();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    game1.levelList[game1.currentLevel].gameplay();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
        //cout<<ofGetElapsedTimeMillis()<<endl;
        game1.levelList[game1.currentLevel].key = key;
        game1.levelList[game1.currentLevel].keyPressed(key);
        game1.newLevel();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
    game1.levelList[game1.currentLevel].keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
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
