//LINK : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/


class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> dabba(3,vector<char>(3));
        char ch = 'x';
            
        //fill the grid
        for (auto a : moves){
        dabba[a[0]][a[1]] = ch;
            
        if (ch == 'x') ch ='o';
            else ch = 'x';
        }
        
        //Any one player wins...
        
        for (int i = 0; i < 3; i++){
            //checkinging row
            if (dabba[i][0] == 'x' && dabba[i][1] == 'x' && dabba[i][2] == 'x')return "A";
            if (dabba[i][0] == 'o' && dabba[i][1] == 'o' && dabba[i][2] == 'o')return "B";

            //checking columns
            if (dabba[0][i] == 'x' && dabba[1][i] == 'x' && dabba[2][i] == 'x')return "A";
            if (dabba[0][i] == 'o' && dabba[1][i] == 'o' && dabba[2][i] == 'o')return "B";
        }
        
        //checking diagonal 
        if (dabba[0][0] == 'x' && dabba[1][1] == 'x' && dabba[2][2] == 'x')return "A";
        if (dabba[0][2] == 'x' && dabba[1][1] == 'x' && dabba[2][0] == 'x')return "A";
        if (dabba[0][0] == 'o' && dabba[1][1] == 'o' && dabba[2][2] == 'o')return "B";
        if (dabba[0][2] == 'o' && dabba[1][1] == 'o' && dabba[2][0] == 'o')return "B";

        
        //No winner and moves left 
        if (moves.size() < 9)return "Pending";
        
        
        //No winner and no moves left
        return "Draw";      
    }
};
