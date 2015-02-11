
#include "ofApp.h"
#include <math.h>
void board::boardDrawer ()
 {
    for (int i = 0; i < N; i++)
    {
        for (int ii = 0; ii < N; ii++)
        {
            if (matrix[i][ii] == 0)
            {
                ofSetColor(200,50,255);//wall
            }
            if (matrix[i][ii] == 1)
            {
                ofSetColor(255,150,0);//floor
            }
            if (matrix[i][ii] == 2)
            {
                ofSetColor(0,255 , 255);//destructable object
            }
            if (matrix[i][ii] == 3)
            {
                ofSetColor(105,255,51);//key
            }
            if (matrix[i][ii] == 4)
            {
                ofSetColor(255,99,51);//exit
            }
            if (matrix[i][ii] == 5)
            {
                ofSetColor(0,0,0);//player

            }
            if (matrix[i][ii] == 6)
            {
                ofSetColor(0,46,184);
            }
            ofRect(i * (squareSize + gapSize),ii * (squareSize + gapSize),squareSize,squareSize);
            if(matrix[i][ii] == 5)
            {
                if (hasKey == true)
                {
                    ofSetColor(255,255,255);
                    ofDrawBitmapString("key",i * (squareSize + gapSize) + (squareSize / 4),ii * (squareSize + gapSize) + (squareSize / 2));
                }

            }
        }
    }
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

        cout << endl;
    }
 }
 void board::playerController ()
 {
    matrix[enemy1.EnemyX][enemy1.EnemyY]=PreviousEnemy;
    matrix[enemy2.EnemyX][enemy2.EnemyY]=PreviousEnemy2;
//    matrix[enemy3.EnemyX][enemy3.EnemyY]=PreviousEnemy3;
//    matrix[enemy4.EnemyX][enemy4.EnemyY]=PreviousEnemy4;
//    matrix[enemy5.EnemyX][enemy5.EnemyY]=PreviousEnemy5;
    enemy1.aiMovement(key,playerx,playery,N,matrix,moves);
    enemy2.aiMovement(key,playerx,playery,N,matrix,moves);
//    enemy3.aiMovement(key,playerx,playery,N,matrix);
//    enemy4.aiMovement(key,playerx,playery,N,matrix);
//    enemy5.aiMovement(key,playerx,playery,N,matrix);

    matrix[playerx][playery] = Previous;
     if (((key == 'D')or(key == 'd')) and (playerx < N - 1) and (matrix[playerx + 1][playery] !=0))
    {
        if (matrix[playerx + 1][playery] == 3 and keyCheckIfItHasIt == 0)
        {
            hasKey = true;
            keyCheckIfItHasIt++;
        }
        playerx++;
    }
    if (((key == 'A')or(key == 'a')) and (playerx > 0) and (matrix[playerx - 1][playery] !=0))
    {
        if (matrix[playerx - 1][playery] == 3 and keyCheckIfItHasIt == 0)
        {
            hasKey = true;
            keyCheckIfItHasIt++;
        }
        playerx--;
    }
    if (((key == 'W')or(key == 'w')) and (playery > 0) and (matrix[playerx][playery - 1] !=0))
    {
        if (matrix[playerx][playery - 1] == 3 and keyCheckIfItHasIt == 0)
        {
            hasKey = true;
            keyCheckIfItHasIt++;
        }
        playery--;
    }
    if (((key == 'S')or(key == 's')) and (playery < N - 1) and (matrix[playerx][playery + 1] !=0))
    {
        if (matrix[playerx][playery + 1] == 3 and keyCheckIfItHasIt == 0)
        {
            hasKey = true;
            keyCheckIfItHasIt++;
        }
        playery++;
    }
    if (hasKey == true and keyCheckIfItHasIt == 1)
    {
        matrix[playerx][playery] = 1;
        keyCheckIfItHasIt--;
    }
    Previous = matrix[playerx][playery];
    cout << "Player X" << playerx << endl;
    cout << "Player Y" << playery << "\n" << endl;
    matrix[playerx][playery] = 5;

    PreviousEnemy = matrix[enemy1.EnemyX][enemy1.EnemyY];
    PreviousEnemy2 = matrix[enemy2.EnemyX][enemy2.EnemyY];
//    PreviousEnemy3 =  matrix[enemy3.EnemyX][enemy3.EnemyY];
//    PreviousEnemy4 = matrix[enemy4.EnemyX][enemy4.EnemyY];
//    PreviousEnemy5 = matrix[enemy5.EnemyX][enemy5.EnemyY];
    matrix[enemy1.EnemyX][enemy1.EnemyY] = 6;
    matrix[enemy2.EnemyX][enemy2.EnemyY] = 6;
//    matrix[enemy3.EnemyX][enemy3.EnemyY] = 6;
//    matrix[enemy4.EnemyX][enemy4.EnemyY] = 6;
//    matrix[enemy5.EnemyX][enemy5.EnemyY] = 6;
 }
void Enemy::aiMovement (int key,int playerx,int playery,const size_t N,Matrix matrix,int moves)
 {
     if (moves == 0)
     {
         EnemyX = ofRandom(N);
         EnemyY = ofRandom(N);
     }
     if((key == 'w') or (key =='a') or (key == 's') or ( key == 'd') or (key == 'W') or (key =='A') or (key == 'S') or ( key == 'D'))
     {
         if ((abs(playerx-EnemyX) < 4) and (abs(playery-EnemyY) < 4))
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
            direction = ofRandom(4);
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
         cout << "x--"<< EnemyX<<"\ty--"<<EnemyY<<endl;
     }
 }
//--------------------------------------------------------------
void ofApp::setup()
{
    board1.tileSetup();

}

//--------------------------------------------------------------
void ofApp::update()
{
    //board1.matrix[board1.Previousplayerx][board1.Previousplayery]=board1.Previous;

}

//--------------------------------------------------------------
void ofApp::draw()
{
    board1.boardDrawer();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    board1.key=key;
    //enemy1.aiMovement();
    board1.playerController();
    board1.moves++;
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
//    board1.matrix[board1.playerx][board1.playery] = board1.Previous;
//    cout << "mousePressed: " << x / (board1.squareSize + board1.gapSize) << ", " << y / (board1.squareSize + board1.gapSize) << " button: " << button << endl;
//    int xCoord = x / (board1.squareSize + board1.gapSize);
//    int yCoord = y / (board1.squareSize + board1.gapSize);
//    if (board1.playerx == xCoord)
//    {
//        if (board1.playery + 1 == yCoord and board1.matrix[board1.playerx][board1.playery + 1] != 0)
//        {
//            //if (board1.matrix[board1.playery + 1][board1.playery] != 0)
//            //{
//            board1.playery = yCoord;
//            //}
//        }
//        if (board1.playery - 1 == yCoord and board1.matrix[board1.playerx][board1.playery - 1] != 0)
//        {
//            board1.playery = yCoord;
//        }
//    }
//    if (board1.playery == yCoord)
//    {
//        if (board1.playerx + 1 == xCoord and board1.matrix[board1.playerx + 1][board1.playery] != 0)
//        {
//            board1.playerx = xCoord;
//        }
//        if (board1.playerx - 1 == xCoord and board1.matrix[board1.playerx - 1][board1.playery] != 0)
//        {
//            board1.playerx = xCoord;
//        }
//    }
//    board1.Previous = board1.matrix[board1.playerx][board1.playery];
//    board1.matrix[board1.playerx][board1.playery] = 5;
    if (board1.hasKey)
    {
        cout << "Tu tienes el keyo" << endl;
    }
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
