#include<iostream>
#include <vector>
 using namespace std;
 string convert(string s, int numRows) 
    {
        if (s.length() <= numRows || numRows == 1) return s;

        int groupSize = numRows + numRows - 2;
        int numOfGroups = (s.length() + groupSize - 1) / groupSize;
        int colsPerGroup = 1 + groupSize - numRows;
        int numCols = numOfGroups * colsPerGroup;

        vector<vector<char>> grid(numRows, vector<char>(numCols, '#'));

        int idx = 0;
        int col = 0;
        while (idx < s.length()) {
            // go vertical down
            for (int r=0; r<numRows && idx < s.length(); r++) {
                grid[r][col] = s[idx];
                idx++;
            } 
            col++;

            // go up right
            for (int r=numRows-2; r>=1 && idx < s.length(); r--) {
                grid[r][col] = s[idx];
                idx++;
                col++;
            }
        }

        // read the grid

        string res = "";
        for (int r=0; r<numRows; r++) {
            for (int c=0; c<numCols; c++) {
                if (grid[r][c] != '#') {
                    res += grid[r][c];
                }
            }
        }
        return res;
    }
    int main()
    {

        string s="paypalishiring";
        int rows=2;
        cout<<convert(s,rows);
    }