#include <iostream>
#include <string>
#include <vector>

using namespace std ;

void fill_region ( vector < string > & pixels , int row , int col );
void fill_region ( vector < string > & pixels , int row , int col )
{/*
            if (maze.isOutside(start)) return true;
            if (maze.isMarked(start)) return false;
            maze.markSquare(start);
            pause(200);
            for(Direction dir=NORTH; dir<=WEST; dir++) {
                if (!maze.wallExists(start, dir)) {
                    if (solveMaze(maze, adjacentPoint(start, dir))){
                        return true;
                    }
                }
            }
            maze.unmarkSquare(start);
            return false;
*/
    if (pixels[row][col] != '+'){
        pixels[row][col] = '+';
        for(int f=-1; f< 2; f++) {
            for (int c=-1; c< 2; c++)
                if (((f+c == -1)||(f+c == 1)) && (row+f < 3) && (row+f >= 0 ) && (col+c < 3) && (col+c >=0)){
                    if (pixels[row+f][col+c] == '-'){
                        fill_region(pixels,row+f,col+c);
                    }
                }
        }
    }
}

int main ()
{
    vector < string > pixels ;
    string row ;

    //while ( cin >> row )
    //    pixels . push_back ( row );
    pixels[0] = "-+-";
    pixels[1] = "+-+";
    pixels[2] = "+++";

    fill_region ( pixels , 1 ,1);

    for ( int i = 0; i < pixels.size(); i ++)
        cout << pixels [ i ] << endl ;

    return 0;
}
