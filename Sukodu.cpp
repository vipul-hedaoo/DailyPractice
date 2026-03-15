# include<iostream>
# include<vector>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
        // bool box[10]={false};
        // bool row[10]={false};
        // int j=0;
        // for(int i=0;i<9;i++)
        // {
        //     while(j<9)
        //     {
        //         char c=board[i][j];
        //         if(c!='.')
        //         {
        //             int n=c-'0';
        //             if(row[n]) return false;
        //             if(j<4 && box[n]) return false;
        //             box[n]=true;
        //             row[n]=true;
        //         }
        //         j++;
        //     }
        //     fill(row, row + 10, false);

        //     if((i + 1) % 3 == 0)
        //     {
        //         fill(box, box + 10, false);
        //     }
        // }
        // return true;

    bool row[9][9] = {false};
    bool col[9][9] = {false};
    bool box[9][9] = {false};

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
                continue;

            int num = board[i][j] - '1';
            int boxIndex = (i/3)*3 + j/3;

            if(row[i][num] || col[j][num] || box[boxIndex][num])
                return false;

            row[i][num] = true;
            col[j][num] = true;
            box[boxIndex][num] = true;
        }
    }

    return true;


    }

int main()
{
  vector<vector<char>> board = {
{'5','3','.','.','7','.','.','.','.'},
{'6','.','.','1','9','5','.','.','.'},
{'.','9','8','.','.','.','.','6','.'},
{'5','.','.','.','6','.','.','.','3'},
{'4','.','.','8','.','3','.','.','1'},
{'7','.','.','.','2','.','.','.','6'},
{'.','6','.','.','.','.','2','8','.'},
{'.','.','.','4','1','9','.','.','5'},
{'.','.','.','.','8','.','.','7','9'}
};
cout<< isValidSudoku(board);
}


