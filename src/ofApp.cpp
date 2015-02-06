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
            if(matrix[i][ii] == 4)
            {
                ofSetColor(0,0,0);//player
            }
            ofRect(i * (squareSize + gapSize),ii * (squareSize + gapSize),squareSize,squareSize);
        }
    }
 }
 void board::tileSetup ()
 {ofSeedRandom();
    for(size_t i = 0; i < N; ++i)
    {
        Row row(N);

        for(size_t j = 0; j < N; ++j)
        {
            wallcount--;
            if (wallcount > 0)
            {//cout <<"wallcount"<<endl;
                row[j] = 1;
            }
            else
            {//cout <<"not count"<<endl;
                row[j] = ofRandom(0,4);/* random value! */;
            }
            if ((row[j] == 1) and (wallcount < 1))
            {
                //row[j]=1;
                wallcount = 3;
            }
            if (row[j] == 3 and keyCount == 0)
            {
                keyCount++;
            }
            else if (row[j] == 3 and keyCount > 0)
            {
                row[j] = ofRandom(0,3);
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
     if ((key == OF_KEY_RIGHT) and (playerx < N - 1) and (matrix[playerx + 1][playery] !=0))
    {
        playerx++;
    }
    if ((key == OF_KEY_LEFT) and (playerx > 0) and (matrix[playerx - 1][playery] !=0))
    {
        playerx--;
    }
    if ((key == OF_KEY_UP) and (playery > 0) and (matrix[playerx][playery - 1] !=0))
    {
        playery--;
    }
    if ((key == OF_KEY_DOWN) and (playery < N - 1) and (matrix[playerx][playery + 1] !=0))
    {
        playery++;
    }
    Previous = matrix[playerx][playery];
    matrix[playerx][playery] = 4;
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
    board1.key=key;
    //enemy1.aiMovement();
    board1.playerController();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

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
    cout << "mousePressed: " << x / (board1.squareSize + board1.gapSize) << ", " << y / (board1.squareSize + board1.gapSize) << " button: " << button << endl;

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
