//
// Created by 01 on 2025/7/9.
//
#include<iostream>
#include<vector>

using namespace std;

int positions[8][2] = { {1,0},{-1,0},{0,1},{0,-1},
                        {1,1},{1,-1},{-1,1},{-1,-1} };

void gameOfLife(vector<vector<int>>& board) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> copy_board(board);
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            int count = 0;
            for (auto position:positions) {
                int newi = i + position[0];
                int newj = j + position[1];
                if (newi >= 0 && newi < row && newj >= 0 && newj < col) {
                    if (copy_board[newi][newj]==1) count++;
                }
            }
            if (copy_board[i][j]) {
                if (count < 2 || count>3) board[i][j]=0;
                else board[i][j]=1;
            }
            else {
                if (count == 3)  board[i][j]=1;
            }
        }
    }

}
int main() {}