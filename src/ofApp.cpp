
#include "ofApp.h"
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
            if(matrix[i][ii] == 5)
            {
                ofSetColor(0,0,0);//player

            }
            ofRect(i * (squareSize + gapSize),ii * (squareSize + gapSize),squareSize,squareSize);
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
    //enemy1.aiMovement();
    matrix[playerx][playery] = Previous;
     if ((key == 'd') and (playerx < N - 1) and (matrix[playerx + 1][playery] !=0))
    {
        if (matrix[playerx + 1][playery] == 3)
        {
            hasKey = true;
        }
        playerx++;
    }
    if ((key == 'a') and (playerx > 0) and (matrix[playerx - 1][playery] !=0))
    {
        if (matrix[playerx - 1][playery] == 3)
        {
            hasKey = true;
        }
        playerx--;
    }
    if ((key == 'w') and (playery > 0) and (matrix[playerx][playery - 1] !=0))
    {
        if (matrix[playerx][playery - 1] == 3)
        {
            hasKey = true;
        }
        playery--;
    }
    if ((key == 's') and (playery < N - 1) and (matrix[playerx][playery + 1] !=0))
    {
        if (matrix[playerx][playery + 1] == 3)
        {
            hasKey = true;
        }
        playery++;
    }
    Previous = matrix[playerx][playery];
    cout << "Player X" << playerx << endl;
    cout << "Player Y" << playery << "\n" << endl;
    matrix[playerx][playery] = 5;
 }
// void Enemy::aiMovement ()
// {
//     cout<<"blah"<<board1.playerx-1<< endl;
//     if((board1.key == OF_KEY_RIGHT)or(board1.key == OF_KEY_LEFT)or(board1.key == OF_KEY_UP)or(board1.key == OF_KEY_DOWN))
//     {
//         if (abs(board1.playerx-EnemyX)or(abs(board1.playery-EnemyY)))
//         {
//
//         }
//         else
//         {
//            direction=ofRandom(0,3);
//            if ((direction == 0)and (EnemyX<board1.N-1)and(board1.matrix[EnemyX+1][EnemyY]!=0))
//            {
//                EnemyX++;
//            }
//            if ((direction == 1)and (EnemyX>0)and(board1.matrix[EnemyX-1][EnemyY]!=0))
//            {
//                EnemyX--;
//            }
//            if ((direction==2)and(EnemyY>0)and(board1.matrix[EnemyX][EnemyY-1]!=0))
//            {
//                EnemyY++;
//            }
//            if ((direction == 3)and (EnemyY<board1.N-1)and(board1.matrix[EnemyX][EnemyY+1]!=0))
//            {
//                EnemyY++;
//            }
//         }
//         board1.matrix[EnemyX][EnemyY]=3;
//         cout << EnemyX<< "x"<<EnemyY<<"y"<<endl;
//     }
// }
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
