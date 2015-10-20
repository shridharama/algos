#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void gameOfLife(vector< vector<int> >& board) {
        int m = board.size();
        int n = board[0].size();
        vector< vector<int> > temp_board(m, vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int neighbour_count = 0;
                //row above current cell
                if(i-1>=0){
                    neighbour_count+=board[i-1][j];
                    if(j+1 < n)
                        neighbour_count+=board[i-1][j+1];
                    if(j-1>=0)
                        neighbour_count+=board[i-1][j-1];
                }
                //row below current cell
                if(i+1 <m){
                    neighbour_count+=board[i+1][j];
                    if(j+1 < n)
                        neighbour_count+=board[i+1][j+1];
                    if(j-1>=0)
                        neighbour_count+=board[i+1][j-1];
                }
                //row of current cell
                if(j+1 < n)
                    neighbour_count+=board[i][j+1];
                if(j-1>=0)
                    neighbour_count+=board[i][j-1];
                
                //updates according to rules
                if(neighbour_count < 2 || neighbour_count > 3){
                    temp_board[i][j] = 0;
                } else if(board[i][j] == 1 && (neighbour_count == 2 || neighbour_count == 3)){
                    temp_board[i][j] = 1;
                } else if(board[i][j] == 0 && neighbour_count == 3){
                    temp_board[i][j] = 1;
                }
                
            }
        }
        
        //copy back to board
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                board[i][j] = temp_board[i][j];
            }
        }
        
    }
};
