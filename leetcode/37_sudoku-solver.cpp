#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool blockHasNum[3][3][10]; // blockHasNum[i][j][n]:第i行j列个大格子中是否有数字n
    bool colHasNum[9][10]; // colHasNum[j][n] 
    bool rowHasNum[9][10]; // rowHasNum[i][n]  第i行的各小格子里是否有数字n
    using Index = pair<int,int>;
    vector<Index> positions;

    bool dfs(vector<vector<char>>& board, int position) {
        if (position == positions.size()) {
            return true;
        }

        auto [row, col] = positions[position];
        for (int fill = 1; fill <= 9; fill++) {
            if (blockHasNum[row/3][col/3][fill] || colHasNum[col][fill] || rowHasNum[row][fill]) {
                continue; // 用过数字了
            }
            blockHasNum[row/3][col/3][fill] = colHasNum[col][fill] = rowHasNum[row][fill] = true;
            board[row][col] = '0' + fill;
            // cout << "fill (" << row << "," << col << ") with " << fill << endl;
            if(dfs(board, position+1)) return true;
            board[row][col] = '.';
            blockHasNum[row/3][col/3][fill] = colHasNum[col][fill] = rowHasNum[row][fill] = false;

        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(blockHasNum, false, sizeof(blockHasNum));
        memset(rowHasNum, false, sizeof(rowHasNum));
        memset(colHasNum, false, sizeof(colHasNum));
        // 初始化输入的数据
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    positions.emplace_back(make_pair(i,j));
                }
                else {
                    int cellNum = board[i][j] - '0';
                    colHasNum[j][cellNum] = true;
                    rowHasNum[i][cellNum] = true;
                    blockHasNum[i/3][j/3][cellNum] = true;
                }
            }
        }

        dfs(board, 0);
        for (auto &v : board) {
            for (char ch : v) {
                cout << ch << " ";
            }
            cout << endl;
        }

    }
};
/* // 逐个格子*逐个数字dfs,超时
class Solution {
public:
    
    bool blockHasNum[3][3][10]; // blockHasNum[i][j][n]:第i行j列个大格子中是否有数字n
    bool colHasNum[9][10]; // colHasNum[j][n] 
    bool rowHasNum[9][10]; // rowHasNum[i][n]  第i行的各小格子里是否有数字n
    int remainNum = 81; // 剩余几个格子要填
    bool done = false;
    // 返回是否找到
    bool dfs(vector<vector<char>> &board, int row, int remain) {
        if (remain == 0) {
            done = true;
            for (auto &v : board) {
                for (char ch : v) {
                    cout << ch << " ";
                }
                cout << endl;
            }
            return true;
        }
        if (row >= 9) return false;

        // 填充一行
        for (int col = 0; col < 9; col++) {
            if (board[row][col] != '.') continue;
            for (int fill = 1; fill <= 9; fill++) {
                if (blockHasNum[row/3][col/3][fill] || colHasNum[col][fill] || rowHasNum[row][fill]) {
                    continue; // 用过数字了
                }
                blockHasNum[row/3][col/3][fill] = colHasNum[col][fill] = rowHasNum[row][fill] = true;
                board[row][col] = '0' + fill;
//                cout << "fill (" << row << "," << col << ") with " << fill << endl;
                if(dfs(board, row+1, remain-1)) return true;
                board[row][col] = '.';
                blockHasNum[row/3][col/3][fill] = colHasNum[col][fill] = rowHasNum[row][fill] = false;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        memset(blockHasNum, false, sizeof(blockHasNum));
        memset(rowHasNum, false, sizeof(rowHasNum));
        memset(colHasNum, false, sizeof(colHasNum));
        // 初始化输入的数据
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                remainNum--;
                int cellNum = board[i][j] - '0';
                colHasNum[j][cellNum] = true;
                rowHasNum[i][cellNum] = true;
                blockHasNum[i/3][j/3][cellNum] = true;
            }
        }

        dfs(board, 0, remainNum);
    }
};
*/

int main() {
     vector<vector<char>> board{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    // vector<vector<char>> board{{'5','3','4','6','7','8','9','1','2'},{'6','7','2','1','9','5','3','4','8'},{'1','9','8','3','4','2','5','6','7'},{'8','5','9','7','6','1','4','2','3'},{'4','2','6','8','5','3','7','9','1'},{'7','1','3','9','2','4','8','5','6'},{'9','6','1','5','3','7','2','8','4'},{'2','8','7','4','1','9','6','3','5'},{'3','4','5','2','8','6','1','7','9'}};
     //vector<vector<char>> board{{'.','3','4','6','7','8','9','1','2'},{'.','7','2','1','9','5','3','4','8'},{'.','9','8','3','4','2','5','6','7'},{'.','5','9','7','6','1','4','2','3'},{'.','2','6','8','5','3','7','9','1'},{'.','1','3','9','2','4','8','5','6'},{'.','6','1','5','3','7','2','8','4'},{'.','8','7','4','1','9','6','3','5'},{'.','4','5','2','8','6','1','7','9'}};
    Solution().solveSudoku(board);

}
