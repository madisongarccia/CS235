#include <iostream>
#include<fstream>
#include<vector>

#include "Grid.h"

using namespace std;

std::vector<std::vector<std::vector<bool> > > visited;

bool solveMaze(Grid maze, int r, int c, int l, std::vector<std::vector<int> >& path){
    //base case(s)
    //we are out of bounds
    if ((r < 0 || r >= maze.height()) || (c < 0 || c >= maze.width()) || l <0 || l >= maze.depth()){
        return false;
    }
    //at a location that is 0
    if (maze.at(r,c,l) == 0){
        return false;
    }
    //we are at the end - meaning we solved it - so it is solvable
    if (r == maze.height() - 1 && c == maze.width() - 1 && l == maze.depth() - 1){
        vector<int> location;
        location.push_back(r);
        location.push_back(c);
        location.push_back(l);
        path.push_back(location);
        visited[r][c][l] = false;
        return true;
    }
    //if I have been here before then return false
    if (visited[r][c][l]){
        return false;
    }

    visited[r][c][l] = true;

    if (solveMaze(maze, r+1, c, l, path) || //could I solve the maze by going down one row
    solveMaze(maze, r-1, c, l, path) ||  //could I solve the maze by going up one row
    solveMaze(maze, r, c+1, l, path) ||  //could I solve the maze by going right one row
    solveMaze(maze, r, c-1, l, path) ||
    solveMaze(maze, r, c, l+1, path) ||
    solveMaze(maze, r, c, l-1, path)){  //could I solve the maze by going left one row
        vector<int> location;
        location.push_back(r);
        location.push_back(c);
        location.push_back(l);
        path.push_back(location);
        return true;
    }
    visited[r][c][l] = false;

    return false;
}

using namespace std;

int main(int argc, char* argv[]) {
    Grid maze;

    ifstream file(argv[1]);
    if (file.is_open()){
        file >> maze;
        visited.resize(maze.height(), vector<vector<bool> >(maze.width(), vector<bool>(maze.depth(), false)));
        std::vector<std::vector<int> > path;
        bool result = solveMaze(maze, 0, 0, 0, path);
        if (result){
            ofstream outFile(argv[2]);
            if (outFile.is_open()){
                outFile << "SOLUTION\n";
                for (int i = path.size()-1; i >= 0; i--){
                    outFile << path[i][0] << " " << path[i][1] << " " << path[i][2] << endl;
                }
                outFile.close();
            }
        }else{
            ofstream outFile(argv[2]);
            outFile << "NO SOLUTION\n";
            outFile.close();
        }
        file.close();
    }
    return 0;

}

